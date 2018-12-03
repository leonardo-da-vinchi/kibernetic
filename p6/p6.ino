#include <Ultrasonic.h>
int echoPin = 7; 
int trigPin = 6; 
unsigned long duration, cm=0; 
Ultrasonic sony(6,7);
int lightPin = 1;
int lightValue = 0;
int lightPrevious = 0;
bool lightPreviousBul = true;
int dinamicPin = 5;
int dinamicValue = 0;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;
bool rgbColorBul = true;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
}

void miganie() {
  if (rgbColorBul) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
    rgbColorBul = false;
    }
  else {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
    rgbColorBul = true;
    }
  }
  
void loop()
{
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(20); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); 
    duration = pulseIn(echoPin, HIGH); 
    cm = duration / 58;
    lightValue = analogRead(lightPin);
    if (lightPreviousBul) {
      lightPrevious = (int)lightValue*0.8;
      lightPreviousBul = false;
    }
    if (lightValue <= lightPrevious || cm < 25) {
      tone(dinamicPin, dinamicValue);
      dinamicValue += 80;
      miganie();
      }
    else {
      dinamicValue = 0;
      analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
      }   
    delay(1000);
}
