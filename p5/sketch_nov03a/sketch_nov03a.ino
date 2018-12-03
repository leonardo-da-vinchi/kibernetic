int score = 0;
int process = 10;

int diod1 = 11; //RED
int diod2 = 9; //GREEN
int diod3 = 10; //BLUE

int button1 = 2; //RED
int button2 = 3; //GREEN
int button3 = 4; //BLUE

void setup() {
  randomSeed(0);
  Serial.begin(9600);
}

int check(int currentDiod) {
  if ( ( currentDiod == diod1) && (digitalRead(button1) == 0)
       ||   ( currentDiod == diod2) && (digitalRead(button2) == 0)
       ||   ( currentDiod == diod3) && (digitalRead(button3) == 0) ) {
    return 1;
  }
  else if ( (digitalRead(button1) == 0)
            || (digitalRead(button2) == 0)
            || (digitalRead(button3) == 0) ) {
    return 0;
  }
  return -1;
}

void miganie() {
  int del = 0;
  int diod = random(9, 12);
  if (diod == diod1) {
    analogWrite(diod1, 255);
    analogWrite(diod2, 0);
    analogWrite(diod3, 0);
  }
  else if (diod == diod2) {
    analogWrite(diod1, 0);
    analogWrite(diod2, 255);
    analogWrite(diod3, 0);
  }
  else if (diod == diod3) {
    analogWrite(diod1, 0);
    analogWrite(diod2, 0);
    analogWrite(diod3, 255);
  }

  for (int i = 1; i <= 20; i++) {
    int check_butt = check(diod);
    if (check_butt == 1) {
      score++;
      break;
    }
    else if (check_butt == 0) {
      analogWrite(diod, 0);
      score--;
      break;
    }
    delay(50);
    del = 50*i;
  }
  process--;
  delay(1000-del);       
}

void loop() {
  if (process == 0) {
    analogWrite(diod1, 0);
    analogWrite(diod2, 0);
    analogWrite(diod3, 0);
    Serial.print("Your score: ");
    Serial.println(score);
    if (score <= 4) {
      Serial.write("NUB");
    }
    else if (score <= 7) {
      Serial.write("Not bad");
    }
    else if (score <= 9) {
      Serial.write("Master");
    }
    else if (score == 10) {
      Serial.write("God");
    }
    process = -1;
  }
  else  if (process > 0) {
    miganie();
  }
}
