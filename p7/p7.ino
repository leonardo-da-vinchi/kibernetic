#include <OneWire.h>
#include <DallasTemperature.h>
int ds = 4;
OneWire onewire(ds);
DallasTemperature dt(&onewire);

int button = 2;
int diod = 3;
int temperature = 0;
bool bulCels = true;
bool ThreeSekBul = true;
bool TenSekBul = true;
long time = 0;

void setup() {
  Serial.begin(9600);
  dt.begin();
  pinMode(button, INPUT);

}

bool check_butt() {
  if (!digitalRead(button)) {
    return 1;
  }
  else {
    return 0;
  }
}

void miganie() {
  digitalWrite(diod, 1);
  delay(100);
  digitalWrite(diod, 0);
  delay(100);
}

void loop() {
  dt.requestTemperatures();
  temperature = dt.getTempCByIndex(0);
  
  if (millis() - time >= 10000) {
    miganie();
    if (TenSekBul) {
      for (int i = 0; i <= 1400; i += 200) {
        miganie();
      }
      if (bulCels) {
        Serial.print(temperature);
        Serial.println(" C");
      }
      else {
        Serial.print((int)(temperature * 1.8 + 32));
        Serial.println(" F");
      }
      TenSekBul = false;
    }
  }


  if ( check_butt() ) {
    for (int i = 0; i <= 3000; i += 100) {
      delay(100);
      ThreeSekBul = true;
      if (!check_butt()) {
        Serial.print(temperature);
        Serial.println(" C");
        ThreeSekBul = false;
        TenSekBul = true;
        bulCels = true;
        time = millis();
        break;
      }
    }
    while (check_butt()) continue;
    if (ThreeSekBul) {
      Serial.print((int)(temperature * 1.8 + 32));
      Serial.println(" F");
      TenSekBul = true;
      bulCels = false;
      time = millis();
    }
  }
}
