
// ultrasonic stuff
#define trigPin 13
#define echoPin 12

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
    Serial.print(distance);
    Serial.println(" cm");
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

  digitalWrite(M1,HIGH);   
  digitalWrite(M2,LOW);  
  analogWrite(E1, 255);
  analogWrite(E2, 50);
 delay(500);
  }

