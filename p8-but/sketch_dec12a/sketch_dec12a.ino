int diod1 = 3, diod2 = 5, diod3 = 9, diod4 = 10, diod5 = 11;
void setup() {
  pinMode(diod1, OUTPUT);
  pinMode(diod2, OUTPUT);
  pinMode(diod3, OUTPUT);
  pinMode(diod4, OUTPUT);
  pinMode(diod5, OUTPUT);

}

void loop() {
  digitalWrite(diod1,1);
  digitalWrite(diod2, 1);
  digitalWrite(diod3, 1);
  digitalWrite(diod4, 1);
  digitalWrite(diod5, 1);
  
}
