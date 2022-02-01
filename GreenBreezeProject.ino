
      //LIBRARYS
//////////////////////////////////
                                //
#include <DHT.h>                //
#include <Adafruit_SSD1306.h>   //
#include <splash.h>             //
#include <SPI.h>                //
#include <Wire.h>               //
#include <Adafruit_GFX.h>       //
#include <U8glib.h>             //
#include <String.h>             //
//////////////////////////////////

          //INITIALIZING OLED SCREEN
////////////////////////////////////////////////////////////////////////////////
#define SCREEN_WIDTH 128 // OLED display width, in pixels                     //
#define SCREEN_HEIGHT 32 // OLED display height, in pixels                    //
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)        //
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)  //
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);     //
////////////////////////////////////////////////////////////////////////////////

    //SETUP FOR LOGO BITMAP
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const unsigned char  GreenBreezelogoBitMap[] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x1f, 0xc0, 0x03, 0xf8, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1f, 0xe0, 0x07, 0xf8, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x03, 0xff, 0xff, 0x80, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 
  0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 
  0xff, 0x80, 0x00, 0x00, 0x00, 0x03, 0xff, 0x80, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 
  0xe0, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x07, 
  0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //INITIALIZING TEMP SENSOR
        //AND SETTING GLOBAL TEMP VARIABLE
///////////////////////////
#define type DHT11       //
const int dhtPin = 3;    //
DHT dht(dhtPin, type);   //
float tempf;      
float humid;             //
///////////////////////////


        //DEFINING PINOUT FOR INFARED SENSOR
//////////////////////////////////////////////////////////////////
const int IRSensor = 2; // connect ir sensor to arduino pin 2   //
const int LED = 13; // conect Led to arduino pin 13             //
//////////////////////////////////////////////////////////////////

        //TIME VARIABLES
////////////////////////////
unsigned long timeStart;
unsigned long timeNow;
int displayScreen =1;
///////////////////////////////

        //FUNCTIONS FOR IR INTERFACE
//////////////////////////////
void displayIRsensor(int);
String readIRsensor(int);
//////////////////////////////

      //FUNCTIONS FOR DISPLAY SCREENS
/////////////////////////////////////////////////////
void sensorDisplayScreen(double , double , float );
void batteryDisplayScreen(double,double, double);
void drawLogo();
/////////////////////////////////////////////////////

      //VARIABLES FOR IR COUNTING
/////////////////////////////
int myRead[2] = {0,0};
int currentRead = 0;
int lastRead = 0;
int passes = 0;
int passCount = 0;
double rpm = 0;
double rpmAry[2] = {0,0};
/////////////////////////

    //VARIABLES FOR VOLTAGE AND CURRENT
//////////////////////////////////////
const int VoltagePin = 0;
const int CurrentPin = 1; 
double Voltage = 0;
double Current = 0; 
double Power = 0;
//double Light = 0;
//int count = 1;
//////////////////////////////////////

        //  SETUP FUNCTION
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
   pinMode (IRSensor, INPUT); // sensor pin INPUT
   pinMode (LED, OUTPUT); // Led pin OUTPUT
   
   Serial.begin(9600);
   
   // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();

  //starting first timestamp 
  timeStart = millis();
  //timeNow = millis();
  
 //begin temp sensor
 dht.begin();
  
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//end of setup


      //LOOP FUNCTION
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  
  tempf = dht.readTemperature(true); //setting vaariable for temperature in ferenhiegt
  humid = dht.readHumidity();

  timeNow = millis();   //timecheck for current time
  
  int statusSensor = digitalRead(IRSensor);   //getting int output from infared sensor

  //displayIRsensor(statusSensor);      //calling a function to check infared output in serial monitor
  String irSensor = readIRsensor(statusSensor);     //setting variable for current infared status

   Voltage = analogRead(VoltagePin) / 40.92;
   Current = (((analogRead(CurrentPin) * 5.0) / 1023.0) - 2.5) / 0.066;
   Power = Voltage*Current;

  //count how many times the infared sensor changes state
  myRead[0] = statusSensor;
  
  if(myRead[0] == !myRead[1]){
    passes = passes + 1;
    }
  else if(myRead[0] == myRead[1]){
    passes = passes;
    }
  passCount = passes/2;

  
  
  
  
  if(abs((timeNow-timeStart)) >= 5000){
   timeStart = millis(); 
   rpmAry[1] = rpmAry[0];
   passes = 0;
   passCount = 0;
   if(displayScreen==3){displayScreen = 1;}
   else{displayScreen++;   }

  
   }
  Serial.println("time start:" + String(timeStart));
  Serial.println("Time Now:" + String(timeNow));
  Serial.println("display screen: " + String(displayScreen));

  rpm = getRPM(passCount);
  rpmAry[0] = rpm;
  
  if(displayScreen == 1){
    display.clearDisplay();
    display.drawBitmap(0, 0, GreenBreezelogoBitMap, 128, 32, WHITE);
    display.display();
     
    }
   else if(displayScreen == 2){
   display.clearDisplay();
   sensorDisplayScreen(rpmAry[1], humid, tempf);      //sets screen to display sensor data
  
    }
   else if(displayScreen == 3){
    display.clearDisplay();
    batteryDisplayScreen(Voltage, Current, Power);
    
    }


  
  
 // sensorDisplayScreen(irSensor, passCount, tempf);      //sets screen to display sensor data
  

  
 myRead[1] = myRead[0]; 
 Voltage = 0;
 Current = 0;
 Power = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//end of loop

double getRPM(int passcount){
  double pass = passcount;
  double revs = pass/3;
  double rpm = revs*12;
  return rpm;
  }


  

       //DISPLAY BATTERY DATA TO LED SCREEN
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void batteryDisplayScreen(double Voltage, double Current, double Power){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("     Battey Data");      //print title to display
  display.println("Voltage: " +String(Voltage) + " V" );        //print battery voltage to display
  display.println("Current: "+ String(Current) + " A");    //print battery current to display
  display.println("Power: " + String(Power) + " W");      //print battery stauts to display
  display.display();    //set display
  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//end of Battery display


        //DISPLAY SENSOR DATA TO LED SCREEN
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sensorDisplayScreen(double rpm, double humid, float tempf){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("     Sensor Data");      //print title to display
  display.println("RPM: " + String(rpm));        //print rpm to display
  display.println("Humidity: " + String(humid) + "%");    //print how many times the infared state has changed to display
  display.println("Temperature: " + String(tempf) + (char)247+ "F");      //print temperature to display
  display.display();    //set display
  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//end of sensor display


      //SERIAL FEEDBACK FOR INFARED SENSOR
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void displayIRsensor(int state){
  if (state == 1){
    digitalWrite(LED, LOW); // LED LOW
    Serial.println("IR Sensor: 0");//print to seral monitor
  }
  else{
    digitalWrite(LED, HIGH); // LED High
    Serial.println("IR Sensor: 1");//print to seral monitor
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//end of infared serial print


        //LOOKS FOR INT OUTPUT FROM INFARED SENSOR AND RETURNS STRING EQUIVALENT
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
String readIRsensor(int state){
  String str ;      //define return variable
  if (state == 1){    //check for infared output
    str = "LOW";     //set return varaible
  }
  else{
    str = "HIGH";   //set return varaible
  }
  return str;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//end of reading infared sensor and returning string
