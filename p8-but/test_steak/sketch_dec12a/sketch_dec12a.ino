int steakX = 0, steakY = 0, clicker = 8;

void setup() {
  Serial.begin(9600);
  pinMode(clicker, INPUT_PULLUP);
}

void loop() {
  steakX = analogRead(A0);
  steakY = analogRead(A1);
  Serial.println("/////");
  Serial.print("x: ");
  Serial.println(steakX);
  Serial.print("y: ");
  Serial.println(steakY);
  Serial.println(digitalRead(clicker));
  Serial.println("/////");
  delay(1500);
}
