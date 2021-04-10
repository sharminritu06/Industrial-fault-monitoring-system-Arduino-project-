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
long measurement =vib_init();

sensorValue = analogRead (sound);




  DHT.read11(dht_apin);




  
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {

  tone(buzzer, 1000, 200);


Serial.println("AT+CMGF=1");    
delay(2000);
Serial.print("AT+CMGS=\"");
Serial.print(phone_no); 
Serial.write(0x22);
Serial.write(0x0D);  // hex equivalent of Carraige return    
Serial.write(0x0A);  // hex equivalent of newline
delay(2000);
Serial.println("Gas level is high!");
Serial.print("GAS = ");
Serial.println(analogSensor);
Serial.println("Other Sensors measurments");
Serial.print("VIB = ");
Serial.println(measurement);

Serial.print("Sound = ");
Serial.print (sensorValue, DEC);
Serial.println(" DB ");

Serial.print("Current humidity = ");
Serial.println(DHT.humidity);

Serial.print("temperature = ");
Serial.print(DHT.temperature); 
Serial.println("C  ");
delay(500);
Serial.println (char(26));//the ASCII code of the ctrl+z is 26


    
    
   // digitalWrite(LED_G,LOW);
  }
  else
  {
    //noTone(buzzer);
  //digitalWrite(LED_G,HIGH);
  }




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
Serial.println("Vibration is high!");
Serial.print("VIB = ");
Serial.println(measurement);


Serial.println("Other Sensors measurments");
Serial.print("GAS = ");
Serial.println(analogSensor);

Serial.print("Sound = ");
Serial.print (sensorValue, DEC);
Serial.println(" DB ");

Serial.print("Current humidity = ");
Serial.println(DHT.humidity);

Serial.print("temperature = ");
Serial.print(DHT.temperature); 
Serial.println("C  ");
delay(500);
Serial.println (char(26));//the ASCII code of the ctrl+z is 26



  
  }
  else{ 
    noTone(buzzer);
  }
  

//Soumd


    if (sensorValue > 148){

tone(buzzer, 1000, 200);  


Serial.println("AT+CMGF=1");    
delay(2000);
Serial.print("AT+CMGS=\"");
Serial.print(phone_no); 
Serial.write(0x22);
Serial.write(0x0D);  // hex equivalent of Carraige return    
Serial.write(0x0A);  // hex equivalent of newline
delay(2000);
Serial.println("Noise level is high!!");
Serial.print("Sound = ");
  Serial.print (sensorValue, DEC);
  Serial.println(" DB ");

  Serial.println("Other Sensors measurments");
Serial.print("VIB = ");
Serial.println(measurement);

Serial.print("GAS = ");
Serial.println(analogSensor);

Serial.print("Current humidity = ");
Serial.println(DHT.humidity);

Serial.print("temperature = ");
Serial.print(DHT.temperature); 
Serial.println("C  ");

delay(500);
Serial.println (char(26));//the ASCII code of the ctrl+z is 26




   } 
    else{
    noTone(buzzer);
  }









//temperature_digital

    
    if (DHT.humidity > 80){
    
tone(buzzer, 1000, 200);


Serial.println("AT+CMGF=1");    
delay(2000);
Serial.print("AT+CMGS=\"");
Serial.print(phone_no); 
Serial.write(0x22);
Serial.write(0x0D);  // hex equivalent of Carraige return    
Serial.write(0x0A);  // hex equivalent of newline
delay(2000);
Serial.println("High Humidity!");
Serial.print("Current humidity = ");
Serial.println(DHT.humidity);

Serial.println("Other Sensors measurments");
Serial.print("VIB = ");
Serial.println(measurement);

Serial.print("Sound = ");
Serial.print (sensorValue, DEC);
Serial.println(" DB ");

Serial.print("GAS = ");
Serial.println(analogSensor);

Serial.print("temperature = ");
Serial.print(DHT.temperature); 
Serial.println("C  ");
delay(500);
Serial.println (char(26));//the ASCII code of the ctrl+z is 26

   } 
    else{
    noTone(buzzer);
  }
   if (DHT.temperature > 30){

    
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
Serial.print("temperature = ");
Serial.print(DHT.temperature); 
Serial.println("C  ");

Serial.println("Other Sensors measurments");
Serial.print("VIB = ");
Serial.println(measurement);

Serial.println("Sound = ");
Serial.print (sensorValue, DEC);
Serial.println(" DB ");

Serial.print("Current humidity = ");
Serial.println(DHT.humidity);

Serial.print("GAS = ");
Serial.println(analogSensor);
delay(500);
Serial.println (char(26));//the ASCII code of the ctrl+z is 26


   } 
    else{
    noTone(buzzer);
  }



////temperature
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

