int steakX = 0, steakY = 0, valueDiods = 0;
int diod1 = 2, diod2 = 3, diod3 = 4, diod4 = 5, diod5 = 6, migDiod = 0;
bool firstDiodBul = true, activateBul = false, victoryBul = false;
int clicker = 7;



void setup() {
  randomSeed(0);
  pinMode(clicker, INPUT);

}

void miganie() {
  delay(20);
  digitalWrite(migDiod, 0);
  delay(20);
  digitalWrite(migDiod, 1);
  delay(20);
}

void offAllDiods() {
  digitalWrite(diod1, 0);
  digitalWrite(diod2, 0);
  digitalWrite(diod3, 0);
  digitalWrite(diod4, 0);
  digitalWrite(diod5, 0);
}

void miganieAll() {
  digitalWrite(diod1, 1);
  digitalWrite(diod2, 1);
  digitalWrite(diod3, 1);
  digitalWrite(diod4, 1);
  digitalWrite(diod5, 1);
  delay(20);
  }




void loop() {
  if (digitalRead(clicker) == 1) {
  activateBul = true;
}
if (activateBul) {
    steakX = analogRead(A0);
    steakY = analogRead(A1);
    if (firstDiodBul) {
      migDiod = random(diod2, diod5 + 1);
      firstDiodBul = false;
    }
    miganie();

    if (steakX < 400) {
      valueDiods += 3;
    }
    else if (steakX > 550) {
      valueDiods += 5;
    }

    if (steakY < 400) {
      valueDiods += 10;
    }
    else if (steakY > 550) {
      valueDiods += 1;
    }

    if ( valueDiods > 255 * (migDiod - 1) ) {
      activateBul = false;
    }
    if ( valueDiods > 255 * (migDiod - 2) + 125 )
      activateBul = false;
      victoryBul = true;
    }

  else {
    offAllDiods();
    if (victoryBul) {
      miganieAll();
      }
  }
}
