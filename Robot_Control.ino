#define BLYNK_TEMPLATE_ID "TMPL0D2T-hLH"
#define BLYNK_DEVICE_NAME "Robot Control"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_NODE_MCU_BOARD
#include "BlynkEdgent.h"
int EN1 = D0;
int L1 = D1;
int L2 = D2;
int R1 = D3;
int R2 = D4;
int EN2 = D5;
int x;
int y;
BLYNK_WRITE(V1)
{
  x=param.asInt();
}
BLYNK_WRITE(V0)
{
  y=param.asInt();
}
BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);  
}

void moveForward(){
  digitalWrite(L1, HIGH);
  digitalWrite(R1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R2, LOW);
  Serial.println("Forward");
}

void moveBackward(){
  digitalWrite(L2, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(R1, LOW);
  Serial.println("Backward");
}

void moveRight(){
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  Serial.println("Right");
}

void moveLeft(){
  digitalWrite(R2, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(L1, LOW);
  Serial.println("Left");
}

void noMove(){
  digitalWrite(R2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L1, LOW);
}


void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
  pinMode(EN1,OUTPUT);
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(EN2,OUTPUT);
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, HIGH);
}

void loop() {
  BlynkEdgent.run();
  if(y>=80 && x<=75 && x>=25){
    moveForward();
  }
  
  if(y<=25 && x<=75 && x>=25){
    moveBackward();
  }
  
  if(y<=80 && y>=25 && x<=25){
    moveRight();
  }
  
  if(y<=75 && y>=25 && x>=75){
    moveBackward();
  }
  
  if(y<=75 && y>=25 && x<=75 && x>=25){
    noMove();
  }
}
