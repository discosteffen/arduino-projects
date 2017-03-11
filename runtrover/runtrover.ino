#include <Servo.h>

// ultrasonic stuff
#define trigPin 13
#define echoPin 12

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo myservo2;  // create servo object to control a servo


int pos = 0;    // variable to store the servo position
int pos1 = 70; // servo 2 position (tilt) 

int E1 = 6;  
int M1 = 4; 
int E2 = 5;                      
int M2 = 7;     
                   

void setup() 
{ 
// ultrasonic
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

      pinMode(M1, OUTPUT);   //dc
      pinMode(M2, OUTPUT); //dc
     myservo.attach(9);  // attaches the servo on pin 9 to the servo object
     myservo2.attach(10);  // attaches the servo on pin 9 to the servo object
  
} 
 
void loop() 
{ 
     long duration, distance;
      digitalWrite(trigPin, LOW);  // Added this line
      delayMicroseconds(2); // Added this line
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10); // Added this line
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = (duration/2) / 29.1;


//servo();
  forward();

//  Move distance to motor forward function? Or just in the run function. 

  if (distance <= 40){
    turn();
    Serial.println("Turn");
  }
  else {
    forward();
    Serial.print(distance);
    Serial.println(" cm");
  }




  
    
    }

void forward(){

  digitalWrite(M1,HIGH);   
  digitalWrite(M2,HIGH);  
  analogWrite(E1, 1);
  analogWrite(E2, 1);
  }

void turn(){

  digitalWrite(M1,LOW);   
  digitalWrite(M2,HIGH);  
  analogWrite(E1, 255);
  analogWrite(E2, 1);
 delay(500);
  }

void servo(){
  for (pos = 0; pos <= 180; pos += 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);
    myservo2.write(pos);
    delay(10);                       // waits 15ms for the servo to reach the position10
  }
  for (pos = 180; pos >= 0; pos -= 5) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);
    myservo2.write(pos);
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  }
