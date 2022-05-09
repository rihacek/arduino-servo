#include <Servo.h> 

int servoPin = 5;
int servoPos = 30; // set the limit of servo position 
 
Servo servo; 

int angle = 0;

void setup() {
  servo.attach(servoPin);
  pinMode(LED_BUILTIN, OUTPUT);
}

void servoMove()
{ 
  // scan from 0 to servoPos degrees
  for(angle = 0; angle < servoPos; angle++)  
  {                                  
    servo.write(angle);               
    delay(15);                   
  } 
  // now scan back from servoPos to 0 degrees
  for(angle = servoPos; angle > 0; angle--)    
  {                                
    servo.write(angle);           
    delay(15);
  }       
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  
  servoMove();

  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
}