#include <Servo.h>

#define trigPin 3
#define echoPin 2
Servo myservo;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(5);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin, HIGH); //에코핀이 high가 될 때까지 시간 측정
  if(duration == 0){
    distance = 0;
  }else{
    distance = duration / 58.2;
  }

  Serial.print(distance);
  Serial.println("cm"); //손소독제 아래에 손을 댔을 때 초음파 센서가 확인하는 거리가 어느 정도 되는지 확인하기 위해 시리얼 모니터로 확인
  delay(300);

  if(distance < 15){
    myservo.write(320);
    delay(4000);
  }else{
    myservo.write(30);
    delay(1000);
  }
  
}
