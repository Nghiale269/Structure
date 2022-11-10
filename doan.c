#include <UART_ARDUINO.h>

UART Gui;
#include <Wire.h> 
#include<EEPROM.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#include<TimerOne.h>
#include <SimpleKalmanFilter.h> // Thu vien bo loc Kalman
SimpleKalmanFilter simpleKalmanFilter(2, 2, 0.015);
#define TRIAC_PIN 4 //chan 1 moc


unsigned long  currentTime2 =0;
unsigned long  currentTime3 =0;
unsigned long  previoustime =0;


// Define constants
#define ButtonUp 8
#define ButtonDown 9
#define ButtonSelect 10
#define ButtonSave 11
#define ButtonExit 12

#define debounceTimeout 50
long int lastDebounceTime;
int ButtonUpPreviousState = LOW;
int ButtonDownPreviousState = LOW;
int ButtonSelectPreviousState = LOW;
int ButtonSavePreviousState = LOW;
int ButtonExitPreviousState = LOW;

#define phunsuong 6
#include "DHT.h"
#define DHTPIN 5
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
float thoigiandao=0 ;
float nhietdodat=37.5;
float doamdat=50;
float nhietdo;

double E,E1,E2,alpha,gamma,beta;
double Kp,Ki,Kd;
double T;
double Output=0;
double LastOutput=0;
double thoigian;
int flag=0;
float doam;
float t;


void PID()
{
 
        nhietdo=dht.readTemperature();
         doam = dht.readHumidity();
        
   // }
   
   if(isnan(nhietdo)|| isnan(doam) )
   {// kiem tra//
    }
 else {
 // nhietdo= simpleKalmanFilter.updateEstimate(nhietdo);
  E=EEPROM.read(1)-nhietdo;
  alpha = 2*T*Kp + Ki*T*T + 2*Kd;
  beta = T*T*Ki - 4*Kd -2*T*Kp;
  gamma = 2*Kd;
  Output = (alpha*E + beta*E1 + gamma*E2 + 2*T*LastOutput)/(2*T);
 
  LastOutput=Output;
  E2=E1;
  E1=E;
  if (Output>9)
    Output=9;
    else if (Output<=1)
      Output=1;
  thoigian = 10-Output; 
  
  
 } 
}


void TriacControl()
{
  
   delayMicroseconds(thoigian*1000); 
   digitalWrite(TRIAC_PIN,HIGH);
  
  delay(1);
   digitalWrite(TRIAC_PIN,LOW);
}
/*Hàm điều khiển độ ẩm*/
void Doam2()
{
 
 if (doam<EEPROM.read(3)){
 digitalWrite(phunsuong,LOW);
 }
 else 
 digitalWrite(phunsuong,HIGH);
  }
////////////////
//int keypad_pin = A0;
int keypad_value = 0;
int keypad_value_old = 0;


char btn_push;




int selection1 = 0;

int mainMenuPage = 1;
int mainMenuPageOld = 1;
int mainMenuTotal = 4;



void setup()
{

   Gui.begin(9600);
   dht.begin();
    delay(10);
lcd.clear();
  lcd.begin();       
  lcd.backlight();
  delay(1000);
pinMode(TRIAC_PIN, OUTPUT);
     digitalWrite(phunsuong,LOW);
    
      pinMode(phunsuong,OUTPUT);
     digitalWrite(phunsuong,HIGH);
       pinMode(ButtonUp, INPUT);
  pinMode(ButtonDown, INPUT);
  pinMode(ButtonSelect, INPUT);
   pinMode(ButtonSave, INPUT);
  pinMode(ButtonExit, INPUT);
      //xác định thông số PID
      Kp=15 ; Ki=0.02 ; Kd=12;
      E=0 ;E1=0; E2=0;
    
      T=1.5;
      attachInterrupt(0,TriacControl, RISING);
      Timer1.initialize(1500000);
      Timer1.attachInterrupt(PID);
MainMenuDisplay();

}
void loop()
{
 
MainmenuBtn();

if(btn_push == 'S')//enter selected menu
{
  
  
    WaitBtnRelease();
    switch (mainMenuPage)
    {
        case 1:
          MenuA();
          break;
           Doam();
        case 2:
         
          break;
        case 3:
         
           MenuB();
          break;
        case 4:
          Run();
          break;
       
    }

      MainMenuDisplay();
      WaitBtnRelease();
  }
  delay(10);

 

}

void MainmenuBtn()
{
  btn_push = ReadKeypad();
WaitBtnRelease();
if(btn_push == 'U')
{
    mainMenuPage++;
    if(mainMenuPage > mainMenuTotal)
      mainMenuPage = 1;
      delay(200);
     // Serial.println(mainMenuPage);
}
else if(btn_push == 'D')
{
    mainMenuPage--;
    //Serial.print(mainMenuPage);
    if(mainMenuPage == 0)
      mainMenuPage = mainMenuTotal; 
      delay(200);
      //Serial.println(mainMenuPage);   
}

if(mainMenuPage != mainMenuPageOld) //only update display when page change
{
    MainMenuDisplay();
    mainMenuPageOld = mainMenuPage;
    delay(200);
}
}

void MainMenuDisplay()
{
lcd.clear();
lcd.setCursor(0,0);
switch (mainMenuPage)
{
    case 1:
      lcd.print(" Chon Nhiet Do");
    
       
      break;
    case 2:
      lcd.print("Chon Do Am");
      
       break;
     case 3:
    lcd.print("Thoi Gian Dao ");
   
       break;
    case 4:
     lcd.print("Bat Dau");
     
       break;
     
    
}
}

void MenuA()
{  
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Chon Nhiet Do");
lcd.setCursor(0,1);
    lcd.print("         ");
  lcd.setCursor(0,1);
     lcd.print(nhietdodat);
      lcd.setCursor(7,1);
     lcd.print("Do C");
     
 
while(ReadKeypad()!= 'N')
{
  if(ReadKeypad()=='U')
  {
    nhietdodat= nhietdodat+0.2;
    lcd.setCursor(0,1);
    lcd.print("          ");
    lcd.setCursor(0,1);
     lcd.print(nhietdodat);
     lcd.setCursor(7,1);
     lcd.print("Do C");
    
     delay(300);
          
   }
   if(ReadKeypad()=='D')
  {
    nhietdodat= nhietdodat-0.2;
   lcd.setCursor(0,1);
    lcd.print("        ");
    lcd.setCursor(0,1);
     lcd.print(nhietdodat);
     lcd.setCursor(7,1);
     lcd.print("Do C");
     
      delay(300);
   
   }
     if(ReadKeypad()=='L')
  
      {
      lcd.setCursor(0,1);
    lcd.print("            ");
     lcd.setCursor(0,1);
     lcd.print("Da Luu");
  EEPROM.write(1,nhietdodat);
  
  delay(10);
           }
  
    //Insert Task for Menu A here
 selection1=1;
// Serial.print("Selection1=");
 //Serial.println(selection1);  
}
}


void MenuB()
{  
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Chon thoi Gian ");
lcd.setCursor(1,1);
     lcd.print( thoigiandao);
     lcd.setCursor(7,1);
     lcd.print( " Phut");
   
while(ReadKeypad()!= 'N')
{
    //Insert Task for Menu B here
    if(ReadKeypad()=='U')
  {
   thoigiandao++;
    delay(300);
     lcd.setCursor(0,1);
    lcd.print("          ");
    lcd.setCursor(0,1);
     lcd.print( thoigiandao);
      lcd.setCursor(7,1);
     lcd.print( " Phut");
    
   }
   if(ReadKeypad()=='D')
  {
  thoigiandao= thoigiandao-1;
    delay(300);
    lcd.setCursor(0,1);
    lcd.print("         ");
    lcd.setCursor(0,1);
     lcd.print( thoigiandao);
      lcd.setCursor(7,1);
     lcd.print( " Phut");
    
     
   
   }
  if(ReadKeypad()=='L')
  {
    
    delay(300);
    lcd.setCursor(0,1);
   lcd.print("            ");
     lcd.setCursor(0,1);
     lcd.print("Da Luu");    
    EEPROM.write(2,thoigiandao);
    //Gui.write_float(thoigiandao);
    
   }
   
 
  
 selection1=2;  
}
}
void Doam()
{  
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Chon Do Am ");
lcd.setCursor(0,1);
     lcd.print( doamdat);
      lcd.setCursor(7,1);
     lcd.print("%");
    
     
while(ReadKeypad()!= 'N')
{
    if(ReadKeypad()=='U')
  {
   doamdat++;
    delay(300);
    lcd.setCursor(0,1);
    lcd.print("          ");
    lcd.setCursor(0,1);
     lcd.print( doamdat);
     lcd.setCursor(7,1);
     lcd.print("%");
      
    
   }
   if(ReadKeypad()=='D')
  {
  doamdat= doamdat-1;
    delay(300);
    lcd.setCursor(0,1);
    lcd.print("         ");
    lcd.setCursor(0,1);
    lcd.print( doamdat);
    lcd.setCursor(7,1);
    lcd.print("%");      
   }
  if(ReadKeypad()=='L')
  {    
    delay(300);
    lcd.setCursor(0,1);
    lcd.print("            ");
     lcd.setCursor(0,1);
     lcd.print("Da Luu");   
    EEPROM.write(3,doamdat);
   }
 selection1=3;
}
}
void Run(){
 
  Gui.write_float(EEPROM.read(2));
 while(ReadKeypad()!= 'N')
  {  
 currentTime3 = millis();
 if (  (unsigned long)(currentTime3 - previoustime) >(1000))
    {    
 Serial.println(doam);
 previoustime=currentTime3 ;       
    }
   Doam2();
lcd.setCursor(0,0);
lcd.print("Nhiet : ");
lcd.print(nhietdo);
lcd.print(" oC");
lcd.setCursor(0,1);
lcd.print("Do am : ");
lcd.print(doam);
lcd.print(" %");
selection1=4;
}
}
char ReadKeypad()
{
 // Read the buttons
    int ButtonUpPressed = digitalRead(ButtonUp);
    int ButtonDownPressed = digitalRead(ButtonDown);
    int ButtonSelectPressed = digitalRead(ButtonSelect);
    int ButtonSavePressed = digitalRead(ButtonSave );
    int ButtonExitPressed = digitalRead( ButtonExit);
    
  // Get the current time
  long int currentTime = millis();
  
  if(ButtonUpPressed == LOW &&ButtonDownPressed == LOW && ButtonSelectPressed == LOW && ButtonSavePressed == LOW && ButtonExitPressed == LOW){
    //Reset the count time while button is not pressed
    lastDebounceTime = currentTime;
    ButtonUpPreviousState = LOW;
    ButtonDownPreviousState = LOW;
    ButtonSelectPreviousState = LOW;
    ButtonSavePreviousState = LOW;
    ButtonExitPreviousState = LOW;
  }
  if(((currentTime - lastDebounceTime) > debounceTimeout)){
   
    if((ButtonUpPressed == HIGH) && (ButtonUpPreviousState == LOW)){
     return 'U' ;
  ButtonUpPreviousState = ButtonUpPressed; // Would be HIGH
    }
    if((ButtonDownPressed == HIGH) && (ButtonDownPreviousState  == LOW)){
      return 'D' ;
      ButtonDownPreviousState = ButtonDownPressed;
    }
    if((ButtonSelectPressed == HIGH) && (ButtonSelectPreviousState  == LOW)){
      return 'S' ;
      ButtonSelectPreviousState = ButtonSelectPressed;
    }
    if((ButtonSavePressed== HIGH) && (ButtonSavePreviousState == LOW))
    {     
     return 'L' ;
      ButtonSavePreviousState = ButtonSavePressed;
      
      }
    if((ButtonExitPressed == HIGH) && (ButtonExitPreviousState  == LOW)){
      
      return 'N' ;
     
      // Toggle state to only toggle if released and pressed again
      ButtonExitPreviousState = ButtonExitPressed;
    }
    }
}

void WaitBtnRelease()
{
 // while( ButtonUpPressed == LOW ){}
}