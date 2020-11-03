#include <Servo.h>
double n = 45;
double x = 5;
double m = -1;
Servo servo1;
 #define inputCLK1 9
 #define inputDT1 10
 int B = 8;
 int BS = 0;

 int currentStateCLK1;
 int previousStateCLK1;

void setup()
{
  pinMode (inputCLK1,INPUT);
  pinMode (inputDT1,INPUT);
  pinMode (B,INPUT);
  servo1.attach(11);

  previousStateCLK1 = digitalRead(inputCLK1);
//  previousStateCLK1 = n;
   servo1.write(n);
}
 
void loop()
{
  BS = digitalRead(B);
  currentStateCLK1 = digitalRead(inputCLK1);
  if (BS == LOW) {
    m *= -1;
    delay(500);  
  }
  if (currentStateCLK1 != previousStateCLK1)
  { 
     if (digitalRead(inputDT1) != currentStateCLK1) { 
       n -= x;
       if (n<0){
        n=0;
       }
      
     } else {
       n += x;
       if (n>180){
        n=180;
       }
       
     }
     servo1.write(n);
     previousStateCLK1 = currentStateCLK1;
  }
  if(m == 1){
      n = 45;
      n += 45;
      servo1.write(n);
      delay(500);
      n -= 45;
      servo1.write(n);
      delay(500);
      n = 90;
      sad(servo1, n);
      n = 45;

   }
}

void sad(Servo servo1,double n){
  servo1.write(n);
  delay(1000);
  n-=5;
  delay(100);
  servo1.write(n);
  n-=5;
  delay(100);
  servo1.write(n);
  n-=5;
  delay(100);
  servo1.write(n);
  n-=5;
  delay(100);
  servo1.write(n);
  n-=5;
  delay(100);
  servo1.write(n);
  n-=5;
  delay(100);
  servo1.write(n);
  n-=5;
  delay(100);
  servo1.write(n);
  n-=5;
  delay(100);
  servo1.write(n);
  n-=5;
  delay(100);
  servo1.write(n);
  delay(100);
}

