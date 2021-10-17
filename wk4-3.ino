#include <Stepper.h> //引入步進馬達函示庫

const int stepsPerRevolution = 2048;  //此馬達轉一圈為2048步
const int RPM = 5; //馬達旋轉速度
const int Button_Pin=25;
const int Button2_Pin=26;
int button1out=1;                        //設定整數
int button2out=1;

//宣告Stepper物件，的步數和引腳
//引角依序對應驅動版的1N1、1N3、1N2、1N4
Stepper myStepper(stepsPerRevolution, 13, 14, 12, 27);  

void setup() {  
  Serial.begin(115200);
  myStepper.setSpeed(RPM);  //設定馬達轉速
  pinMode (Button_Pin, INPUT);              //Arduino 從按鈕開關讀入
  pinMode (Button2_Pin, INPUT);
}

void loop() {
button1out = digitalRead (Button_Pin);   //讀取按鈕開關值
button2out = digitalRead (Button2_Pin);

  if (button1out ==1){                //當讀入值為零的時候，表示有按下按鈕開關，步進馬達正轉64步
  myStepper.step(64);
 }
 if (button2out ==1){                //當讀入值為零的時候，表示有按下另一按鈕開關，步進馬達反轉64步
  myStepper.step(-64);
 }
}
