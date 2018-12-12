int steakX = 0, steakY = 0, valueDiods = 0;
int diod1 = 3, diod2 = 5, diod3 = 9, diod4 = 10, diod5 = 11, migDiod = 0;
bool firstDiodBul = true, activateBul = false, victoryBul = false;
int clicker = 8;

void setup()
{
  Serial.begin(9600);
  randomSeed(5);
}


bool check_butt(int button) {
  if (!digitalRead(button)) {
    return 1;
  }
  else {
    return 0;
  }
}

int getDiodByIndex(int a) {
  if (a == 1) {
    return 3;
  }
  if (a == 2) {
    return 5;
  }
  if (a == 3) {
    return 9;
  }
  if (a == 4) {
    return 10;
  }
}

int getIndexByDiod(int a) {
  if (a == 5) {
    return 2;
  }
  if (a == 9) {
    return 3;
  }
  if (a == 10) {
    return 4;
  }
  if (a == 11) {
    return 5;
  }
}

int checkMinus(int a) {
  if (a > 0) {
    return a;
  } else {
    return 0;
  }
}

void miganie() {
  digitalWrite(migDiod, 0);
  delay(200);
  digitalWrite(migDiod, 1);
  delay(200);
  digitalWrite(migDiod, 0);
  delay(200);
}

void offAllDiods() {
  digitalWrite(diod1, 0);
  digitalWrite(diod2, 0);
  digitalWrite(diod3, 0);
  digitalWrite(diod4, 0);
  digitalWrite(diod5, 0);
}

void miganieAll() {
  digitalWrite(diod1, 0);
  digitalWrite(diod2, 0);
  digitalWrite(diod3, 0);
  digitalWrite(diod4, 0);
  digitalWrite(diod5, 0);
  delay(200);
  digitalWrite(diod1, 1);
  digitalWrite(diod2, 1);
  digitalWrite(diod3, 1);
  digitalWrite(diod4, 1);
  digitalWrite(diod5, 1);
  delay(200);
}

void loop() {
  steakX = analogRead(A0);
  steakY = analogRead(A1);
  if (check_butt(clicker) == 1) {
    activateBul = true;
  }
  if (activateBul) {
    if (firstDiodBul) {
      migDiod = 10;
      firstDiodBul = false;
    }
    miganie();


    if (steakX < 430) {
      while(analogRead(A0) < 430){
        valueDiods += 3;
        delay(20);
      }
    }
    else if (steakX > 530) {
      while(analogRead(A0) > 530){
        valueDiods += 5;
        delay(20);
      }
    }

    if (steakY < 430) {
      while(analogRead(A1) < 430){
        valueDiods += 10;
        delay(20);
      }  
    }
    else if (steakY > 530) {
      while(analogRead(A1) > 530){
        valueDiods += 1;
        delay(20);
      }  
    }

    if ( valueDiods > 255 * (getIndexByDiod(migDiod) - 1) ) {
      activateBul = false;
    }
    else if ( valueDiods > 255 * (getIndexByDiod(migDiod) - 2) + 125 ) {
      activateBul = false;
      victoryBul = true;
    }
    else {
      for (int i = 1; i < getIndexByDiod(migDiod); i++) {
        analogWrite(getDiodByIndex(i), checkMinus( valueDiods - (255 * (i - 1)) ) );
      }
    }


  }
  else if  (victoryBul) {
    miganieAll();
    activateBul = false;
  }
  else {
    offAllDiods();
    activateBul = false;
  }

}
