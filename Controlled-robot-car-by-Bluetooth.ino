#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;

#define in1 4
#define in2 3
#define in3 6
#define in4 5
#define ena 2
#define enb 7 
char command;
int d=0;
int i;
void setup() {
servo1.attach(8);
servo2.attach(9);
servo3.attach(10);  
Serial.begin(9600);
Serial.println(" abc  ");

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(ena, OUTPUT);
pinMode(enb, OUTPUT);
}
void tien(int d){
  digitalWrite(in2,100);
  digitalWrite(in1,LOW);
  analogWrite(ena,d);
  digitalWrite(in3,100);
  digitalWrite(in4,LOW);
  analogWrite(enb,d);
  }
 void lui(int d){
  digitalWrite(in2,LOW);
  digitalWrite(in1,100);
  analogWrite(ena,d);
  digitalWrite(in3,LOW);
  digitalWrite(in4,100);
  analogWrite(enb,d);
  }
 void trai(int d){
  analogWrite(in2,(2*d)/3);
  analogWrite(in4,(2*d)/3);
  }
 void phai(int d){
  analogWrite(in1,(2*d)/3);
  analogWrite(in3,(2*d)/3);
  }
 void tientrai(int d) {
analogWrite(in3,d);
analogWrite(in4,(2*d)/3);
}

void tienphai(int d) {
analogWrite(in3,(2*d)/3);
analogWrite(in4,d);
}
void luiphai(int d) {
analogWrite(in4,(2*d)/3);
analogWrite(in1,d);
}
void luitrai(int d) {
analogWrite(in4,d);
analogWrite(in1,(2*d)/3);
}
void dunglai() {
analogWrite(in1,0);
analogWrite(in2,0);
analogWrite(in3,0);
analogWrite(in4,0);
}
void loop() {
  if (Serial.available() >0){
    command = Serial.read(); 
    Serial.print(command);
switch(command){
case 0:
    d = 0;
    break;
  case '1':
    d = 125;
    break;
  case '2':
    d = 138;
    break;
  case '3':
    d = 151;
    break;
  case '4':
    d = 164;
    break;
  case '5':
    d = 177;
    break;
  case '6':
    d = 190;
    break;
  case '7':
    d = 203;
    break;
  case '8':
    d = 216;
    break;
  case '9':
    d = 229;
    break;
  case 'q':
    d = 255;
    break;
  }
switch(command){
  case 'W':
    servo1.write(90);
    break;
  case 'w':
    servo1.write(0);
    break;
  case 'U':
    servo2.write(180);  
    servo3.write(0);   
    break;
  case 'u':
    servo2.write(90);
    servo3.write(90);
    break;
  case 'F':
  tien(d);
  break;
  case 'B':
  lui(d);
  break;
  case 'L':
  trai(d);
  break;
  case 'R':
  phai(d);
  break;
  case 'G':
  tientrai(d);
  break;
  case 'I':
  tienphai(d);
  break;
  case 'H':
  luitrai(d);
  break;
  case 'J':
  luiphai(d);
  break;
  case 'S':
  dunglai();
  break;
}
}
}
