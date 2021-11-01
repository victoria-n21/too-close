#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7; // LCD pins 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int trigPin =9, echoPin = 10; // ultrasonic sensor pins 
long duration; //the time it takes for echoPin to receive signal output from trigPin.
int distance; //the distance that will be calculated later. 

const int buzzerPin = 13; //buzzer pin


void setup() {
  Serial.begin(9600); // set up serial monitor 
  lcd.begin(16, 2); // set up LCD columns and rows 
  pinMode(trigPin, OUTPUT); //set trigPin as output, sends a signal out to an object. This signal travels at the speed of sound, 343m/s or 0.034cm/us 
  pinMode(echoPin, INPUT); //set echoPin as input, receives the signal, outputs time traveled.
  pinMode(buzzerPin,OUTPUT); //set buzzerPin as output 
  }


void loop() {
  //ultrasonic sensor 
  digitalWrite(trigPin, LOW); //clear trigPin
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH); //send out signal for 10us 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); //stop signal 

  duration = pulseIn(echoPin, HIGH); //read value from the echoPin 

  // Distance = Time * Speed. Time = Duration, Speed = 0.034cm/us. Divide by 2 b/c the signal travels out and then back, and we only want half this value (distance out)
  distance = duration*(0.034/2)*0.393701; //0.393701 is the cm to inch conversation. Change as needed. 
 
  lcd.setCursor(0,0); //Set the cursor at column 0, row 0 (top left) 

  //display the distance value
  lcd.print("Distance:"); 
  lcd.print(distance);

  lcd.setCursor(0,1); //Set the cursor at column 0, row 1 (bottom left)

  //Monitor the distance relative to 6inch
  if (distance < 6) { 
    lcd.print("TOO CLOSE");
    tone(buzzerPin, 300, 50); //300 is the frequency in hertz (to change the tone), 50 is the delay in milliseconds 
   }
  if (distance >= 6) {
    lcd.print(":)");
    noTone(buzzerPin); //play no tone
    delay(100);
  }

  delay(1000);
  lcd.clear(); //clear the LCD screen for the next distance value 

return 0; 
}
