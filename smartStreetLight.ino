
// avg value of ldr is around 430
//if it goes above 750 then we will open the led
// 13 echo
//12 trig
//11 trig
//10 echo

#define echoPin1 13
#define trigPin1 12
#define echoPin2 10
#define trigPin2 11
#define firstLED 5
#define secondLED 7
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(firstLED,OUTPUT);
  pinMode(secondLED,OUTPUT);
  pinMode(trigPin1,OUTPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(echoPin2,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue=analogRead(A0);
  Serial.println(sensorValue);
  delay(20);
  if(sensorValue>750){
    long duration1,distance1,duration2,distance2;
    // for first ultra sonic
    digitalWrite(trigPin1,LOW);
    delay(2);
    digitalWrite(trigPin1,HIGH);
    delay(10);
    digitalWrite(trigPin1,LOW);
    duration1=pulseIn(echoPin1,HIGH);
    distance1=(duration1/2)/29.1;
    
    // for second ultrasonic
    digitalWrite(trigPin2,LOW);
    delay(2);
    digitalWrite(trigPin2,HIGH);
    delay(10);
    digitalWrite(trigPin2,LOW);
    duration2=pulseIn(echoPin2,HIGH);
    distance2=(duration2/2)/29.1;
    //set distance to 5cm in our case
    Serial.println(distance2);
    if(distance1>0 && distance1<=5){
      digitalWrite(firstLED, HIGH);
      Serial.println(distance1);
    }
    else{
      digitalWrite(firstLED, LOW);
      Serial.println("Out of range");
      }
    if(distance2>0 && distance2<25){
      digitalWrite(secondLED,HIGH);
      Serial.println(distance2);
    }
    else{
      digitalWrite(secondLED,LOW);
      Serial.println("Out of range");
      }
    delay(20);   
  }
  else{
      digitalWrite(firstLED, LOW);
      digitalWrite(secondLED,LOW);
    }
}
