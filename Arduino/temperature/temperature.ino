int Ptemp=0;
void setup() {
  
Serial.begin(9600);
}

void loop() {
int reading=analogRead(Ptemp);
float voltage=reading*5/1024;

Serial.println(voltage);

float temp=(voltage-0.5)*100;

Serial.println(temp);
delay(1000);
}
