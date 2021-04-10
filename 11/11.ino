#include <dht.h>
#define dht_apin A0 
dht DHT;
char phone_no[]="01742104183";
int sound =A4;
int sensorValue = 0; //for variable to store the value coming from the sound sensor
int buzzer = 7;
int smokeA0 = A5;
int vibr_Pin =3;
int LED_Pin = 8;

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

  
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {

  


Serial.println("AT+CMGF=1");    
delay(2000);
Serial.print("AT+CMGS=\"");
Serial.print(phone_no); 
Serial.write(0x22);
Serial.write(0x0D);  // hex equivalent of Carraige return    
Serial.write(0x0A);  // hex equivalent of newline
delay(2000);
Serial.print("Gas level is high!");
Serial.print("GAS = ");
  Serial.println(analogSensor);
delay(500);
Serial.println (char(26));//the ASCII code of the ctrl+z is 26


    
    tone(buzzer, 1000, 200);
   // digitalWrite(LED_G,LOW);
  }
  else
  {
    //noTone(buzzer);
  //digitalWrite(LED_G,HIGH);
  }



long measurement =vib_init();
 //delay(50);
  
  if (measurement > 100){
    
     tone(buzzer, 1000, 200);



Serial.println("AT+CMGF=1");    
delay(2000);
Serial.print("AT+CMGS=\"");
Serial.print(phone_no); 
Serial.write(0x22);
Serial.write(0x0D);  // hex equivalent of Carraige return    
Serial.write(0x0A);  // hex equivalent of newline
delay(2000);
Serial.print("Vibration is high!");
Serial.println("VIB = ");
Serial.println(measurement);
delay(500);
Serial.println (char(26));//the ASCII code of the ctrl+z is 26



  
  }
  else{ 
    noTone(buzzer);
  }
  

//Soumd

sensorValue = analogRead (sound);

    if (sensorValue > 148){

  


Serial.println("AT+CMGF=1");    
delay(2000);
Serial.print("AT+CMGS=\"");
Serial.print(phone_no); 
Serial.write(0x22);
Serial.write(0x0D);  // hex equivalent of Carraige return    
Serial.write(0x0A);  // hex equivalent of newline
delay(2000);
Serial.print("Noise level is high!!");
Serial.println("Sound = ");
  Serial.print (sensorValue, DEC);
  Serial.println(" DB ");

delay(500);
Serial.println (char(26));//the ASCII code of the ctrl+z is 26




    tone(buzzer, 1000, 200);
  
   } 
    else{
    noTone(buzzer);
  }









//temperature_digital

  DHT.read11(dht_apin);
    
    if (DHT.humidity > 80){
    



Serial.println("AT+CMGF=1");    
delay(2000);
Serial.print("AT+CMGS=\"");
Serial.print(phone_no); 
Serial.write(0x22);
Serial.write(0x0D);  // hex equivalent of Carraige return    
Serial.write(0x0A);  // hex equivalent of newline
delay(2000);
Serial.print("High Humidity!");
Serial.println("Current humidity = ");
Serial.println(DHT.humidity);
delay(500);
Serial.println (char(26));//the ASCII code of the ctrl+z is 26

    tone(buzzer, 1000, 200);

   } 
    else{
    noTone(buzzer);
  }
   if (DHT.temperature > 30){

    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    tone(buzzer, 1000, 200);


Serial.println("AT+CMGF=1");    
delay(2000);
Serial.print("AT+CMGS=\"");
Serial.print(phone_no); 
Serial.write(0x22);
Serial.write(0x0D);  // hex equivalent of Carraige return    
Serial.write(0x0A);  // hex equivalent of newline
delay(2000);
Serial.print("Temperature is high!");
delay(500);
Serial.println (char(26));//the ASCII code of the ctrl+z is 26


   } 
    else{
    noTone(buzzer);
  }



//temperature
//
//int val = analogRead(tempPin);
//float mv = ( val/1024.0)*5000; 
//float cel = mv/10;
//float farh = (cel*9)/5 + 32;
//if (cel > 30){
//
//
//Serial.println("AT+CMGF=1");    
//delay(2000);
//Serial.print("AT+CMGS=\"");
//Serial.print(phone_no); 
//Serial.write(0x22);
//Serial.write(0x0D);  // hex equivalent of Carraige return    
//Serial.write(0x0A);  // hex equivalent of newline
//delay(2000);
//Serial.print("Another Temp is high!");
//Serial.println("TEMPERATURE = ");
//Serial.print(cel);
//Serial.print("*C");
//delay(500);
//Serial.println (char(26));//the ASCII code of the ctrl+z is 26
//
//}





  
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

