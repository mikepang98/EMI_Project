#include <Servo.h>
#include <CheapStepper.h>
CheapStepper stepper;
Servo myservo;

boolean moveClockwise = true; 
int pos = 0;  
String str = "o";
int i = 0;
boolean boo = true;


const int echoPin = 4; // Echo Pin of Ultrasonic Sensor
const int pingPin = 5; // Trigger Pin of Ultrasonic Sensor

void setup() {
 
  Serial.begin(9600);   //serial communication 
  myservo.attach(3);    //servo motor pin
  
  pinMode(pingPin, OUTPUT); // pin 5 as output
  pinMode(echoPin, INPUT);  // pin 4 as input

}
void loop() {
  while(Serial.available()>0) 
    { 
  
  str = Serial.readString(); //read the str value send from bluetooth (app)
  }
  
  if (str == "o") { 

  delay(1000);
  Serial.println("string received");
  
  delay(1000);
  Serial.println("start cleaning now");
  
  delay(1000);
  Serial.println("cleaning in process");

  boo=true;
  
  for (pos = 0; pos <= 180; pos += 1) {     //turn 180 degree (open floor tile)
    // in steps of 1 degree
    myservo.write(pos);              
    delay(50);                       
  }
  delay(700);
  
  for (pos = 180; pos >= 0; pos -= 1) {     //turn back 180 degree (close floor tile)
    myservo.write(pos);             
    delay(50);

  }
  delay(1000);
  
   if (moveClockwise == true){        // step motor run 3 rounds
   for (int s=0; s<12288; s++){

    stepper.step(moveClockwise);
    
    int nStep = stepper.getStep();
      
   }                                 
   }
     Serial.println("cleaning done");
     
 while(boo){

  delay(1000);
  Serial.println("Scanning for remaining trash...");    
    
  digitalWrite(echoPin, LOW);     // to detect any remaining trash in the conveyor 
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(pingPin, LOW);

  long distance, duration, cm;          
  duration = pulseIn(echoPin, HIGH);    //method to convert values from ultrasonic sensor to distance (cm)
  distance = (duration/2)/29.1;

  delay(1000);
  
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();

  delay(1000);

    if (distance <= 200) {
      Serial.println("trash detected...now cleaning");
      delay(500);

    if (moveClockwise == true){
     for (int s=0; s<12288; s++){

    stepper.step(moveClockwise);
   
    int nStep = stepper.getStep();
  }

  delay(1000);
}
     delay(500);
      Serial.println("trash cleaned");
    
    }
    else{                                     // no trash is found, so operation end. 
      delay(1000);
      Serial.println("no trash found");
      
      delay(1000);
      Serial.println("cleaning done");
      
      boo=false; 
          }
        }
      } str = "";                           // jump out of the loop. end the operation
        delay (1000);
       }

  long microsecondsToCentimeters(long microseconds) // method to covert microsec to centimeters
  {
   return microseconds;
}
    

  


