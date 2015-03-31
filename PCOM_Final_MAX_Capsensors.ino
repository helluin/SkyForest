#include <CapacitiveSensor.h>

const int transistorPin1 = 9;
const int transistorPin2 = 10;
const int transistorPin3 = 11;

const int thresh1 = 1000;
const int thresh2 = 1000;
const int thresh3 = 2000;

CapacitiveSensor   cs_1 = CapacitiveSensor(3,4);   //cloud should be plugged into pin 4 (receive pin)
CapacitiveSensor   cs_2 = CapacitiveSensor(5,6);        // 10 megohm resistor between pins 4 & 6, pin 6 is sensor pin, add wire, foil
CapacitiveSensor   cs_3 = CapacitiveSensor(12,13);        // 10 megohm resistor between pins 4 & 8, pin 8 is sensor pin, add wire, foil

int led1onoroff;
int led2onoroff; 
int led3onoroff; 

int sensVal;           // for raw sensor values 
float filterVal;       // this determines smoothness  - .0001 is max  1 is off (no smoothing)
float smoothedVal;     // this holds the last loop value just use a unique variable for every different sensor that needs smoothing
float smoothedVal2;    // this would be the buffer value for another sensor if you needed to smooth two different sensors - not used in this sketch
int i, j;              // loop counters or demo

void setup() {
  
  pinMode(transistorPin1, OUTPUT);
  pinMode(transistorPin2, OUTPUT);
  pinMode(transistorPin3, OUTPUT); 

//cs_1.set_CS_AutocaL_Millis(0xFFFFFFFF);
//cs_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
  
  Serial.begin(9600);
//  Serial.println("start");
  
//  cs_1.set_CS_AutocaL_Millis(10);
//  cs_2.set_CS_AutocaL_Millis(10);
//  cs_3.set_CS_AutocaL_Millis(10);

  led1onoroff=255;
  led2onoroff=255;
  led3onoroff=255;

}

void loop() {
  //initializing
  long start = millis();
  long total1 =  cs_1.capacitiveSensor(10);
  long total2 =  cs_2.capacitiveSensor(10);
  long total3 =  cs_3.capacitiveSensor(10); 

  Serial.print(led1onoroff); 
  Serial.print("\t");
  Serial.print(total1);
//  //Serial.print(" "); 
  Serial.print("\t");
//  Serial.print(" ");  
  Serial.print(led2onoroff); 
  Serial.print(" ");
  Serial.print("\t");
  Serial.print(total2);
  Serial.print("\t");
////  Serial.println(led2onoroff);
  Serial.print(led3onoroff); 
  Serial.print("\t");
  Serial.println(total3);


// filter with a counter
// ++ then set it back to zero?
// what did Andy say?
// averaging and filtering

  //LED1
  if(total1 > thresh1) {
    led1onoroff = 0;
    analogWrite(transistorPin1, led1onoroff); 
  } 
  else {
    led1onoroff=255; 
    analogWrite(transistorPin1, led1onoroff);
  }


  //LED2
  if(total2 > thresh2) {
    led2onoroff = 0;
    analogWrite(transistorPin2, led2onoroff); 
  } 
  else {
    led2onoroff=255; 
    analogWrite(transistorPin2, led2onoroff);
  }

//  //LED3
  if(total3 > thresh3) {
    led3onoroff = 0;
    analogWrite(transistorPin3, led3onoroff); 
  } 
  else {
    led3onoroff=255; 
    analogWrite(transistorPin3, led3onoroff);
  }


}
