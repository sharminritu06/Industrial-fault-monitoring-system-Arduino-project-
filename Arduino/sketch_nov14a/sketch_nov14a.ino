int red=9;
int green=10;
int blue=11;

void setup() {
pinMode(red,OUTPUT);

pinMode(green,OUTPUT);

pinMode(blue,OUTPUT);
  
}

void loop() {
  digitalWrite(red,HIGH);
  delay(1000);
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  digitalWrite(blue,HIGH);
  delay(1000);
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,HIGH);
  delay(1000);
  digitalWrite(blue,LOW);
  digitalWrite(green,HIGH);
  digitalWrite(red,LOW);
  delay(1000);
}
