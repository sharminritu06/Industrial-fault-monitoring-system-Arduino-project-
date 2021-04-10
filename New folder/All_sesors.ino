
#include <dht.h>
#define dht_apin A0 
dht DHT;

int sound =A4;
int sensorValue = 0; //for variable to store the value coming from the sound sensor
int buzzer = 7;
int smokeA0 = A5;
int vibr_Pin =3;
int LED_Pin = 8;
int LED_R = 13;
int LED_G = 12;
int LED_B = 11;
int tempPin = 1;
// Your threshold value. You might need to change it.
int sensorThres = 400;//gas

void setup() {
  pinMode(vibr_Pin, INPUT); //set vibr_Pin input for measurment
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode (sound, INPUT) ; 
    
  Serial.begin(9600);
}

void loop() {

//smoke

  int analogSensor = analogRead(smokeA0);

  Serial.print("GAS = ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    tone(buzzer, 1000, 200);
    digitalWrite(LED_R,HIGH);
   // digitalWrite(LED_G,LOW);
  }
  else
  {
    //noTone(buzzer);
    digitalWrite(LED_R, LOW);
  //digitalWrite(LED_G,HIGH);
  }
  
//vibration

long measurement =vib_init();
 //delay(50);
  Serial.print("VIB = ");
Serial.println(measurement);
  if (measurement > 100){
    digitalWrite(LED_R, HIGH);
     tone(buzzer, 1000, 200);

  }
  else{
    digitalWrite(LED_R, LOW); 
    noTone(buzzer);
  }
  
//temperature_digital

  DHT.read11(dht_apin);
    Serial.print("Current humidity = ");
    Serial.println(DHT.humidity);
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
 
    if (DHT.humidity > 80){
    digitalWrite(LED_R, HIGH);
    tone(buzzer, 1000, 200);

   } 
    else{
    digitalWrite(LED_R, LOW); 
    noTone(buzzer);
  }
   if (DHT.temperature > 30){
    digitalWrite(LED_B, HIGH);
    tone(buzzer, 1000, 200);
    
   } 
    else{
    digitalWrite(LED_B, LOW); 
    noTone(buzzer);
  }

  
//temperature

int val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

Serial.print("TEMPERATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();

//Soumd

sensorValue = analogRead (sound);
Serial.print("Sound = ");
  Serial.print (sensorValue, DEC);
  Serial.println(" DB ");
  Serial.println('\n');
     delay(1000);
    if (sensorValue > 48){
    digitalWrite (LED_R, HIGH);
    tone(buzzer, 1000, 200);
  
   } 
    else{
  digitalWrite (LED_R, LOW);
    noTone(buzzer);
  }
//long soundB=digitalRead (sound) ;
//if(soundB==0){
//  Serial.println("NO Sound!!");
//  digitalWrite(LED_R, LOW);
//  digitalWrite(LED_G,HIGH);
//  //noTone(buzzer);
//  
//}else{
//  Serial.println("Sound!!!!");
//  tone(buzzer, 1000, 200);
//  digitalWrite(LED_R,HIGH);
//  digitalWrite(LED_G,LOW);
//  delay(1000);
//  }

  
  
}

//vibration
long vib_init(){
  delay(10);
  long measurement=pulseIn (vibr_Pin, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}

//temperature
float getVoltage(int pin)
{
 return (analogRead(pin) * 0.004882814);
}

