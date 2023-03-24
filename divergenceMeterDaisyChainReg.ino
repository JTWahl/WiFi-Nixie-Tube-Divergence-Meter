/**********Code By - RR (RoboRomantic)**********/

//import libraries
#include <Wire.h>
#include <Eeprom24C04_16.h>

//set up eeprom
#define EEPROM_ADDRESS 0x50
static Eeprom24C04_16 eeprom(EEPROM_ADDRESS);

//assign pin numbers for communication with the shift registers
const int latchPin = 3; //RCK
const int clockPin = 4; //SCK
const int dataPin = 5; //SER

//assign pin number to real time clock trigger system
const int rtcTrigger = A1;

//initialize global binary nixie variables to later be concatenated for registers
byte nixie1Binary = B0000;
byte nixie2Binary = B0000;
byte nixie3Binary = B0000;
byte nixie4Binary = B0000;
byte nixie5Binary = B0000;
byte nixie6Binary = B0000;
byte nixie7Binary = B0000;
byte nixie8Binary = B0000;

void setup(){
  Serial.begin(115200);
  eeprom.initialize();

  //set up pins
  pinMode(latchPin, OUTPUT);  
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  //set up eepromm data
  const word address = 0;
  const byte mem = 500;

  //create array for received memory bytes and read into it
  byte outputBytes[mem] = { 0 };

  //read data from eeprom
  eeprom.readBytes(address, mem, outputBytes);

  //***uncomment to print eeprom data over serial***
  //printEEPROM(mem, outputBytes);
}

void loop(){   
//TODO: generate divergence number based on matrix values in the serial stream and eepromm mem matrix
/*  searchSerial();
  
  if (digitalRead(rtcTrigger) == HIGH) {
    slotMachine(); //antipoisoning effect
  }
//TODO: build a clockwork RTC that activates every couple of hours
*/

  //concatenate nixie nibble binary values into bytes
  byte register1Input = (nixie1Binary << 4) + nixie2Binary;
  byte register2Input = (nixie3Binary << 4) + nixie4Binary;
  byte register3Input = (nixie5Binary << 4) + nixie6Binary;
  byte register4Input = (nixie7Binary << 4) + nixie8Binary;

  //send output bytes to registers
  updateShiftRegisters(register1Input, register2Input, register3Input, register4Input);

  delay(100);
}

void searchSerial() {
  String serialData = "";
//TODO: implement divergence number linear interpolation equation
// d = a [(F1 || ... || Fn) / (2^n)] + [i(Pc - Pk)]

  const int preconvConst;
  int divNum = 0;
  int attrVal = 0;
  bool fluct1 = 0;
  bool fluct2 = 0;
  bool fluct3 = 0;
  bool fluct4 = 0;
  bool fluct5 = 0;
  bool fluct6 = 0;
  bool fluct7 = 0;
  bool fluct8 = 0;

}


//function to send out binary data to the tubes' registers
void updateShiftRegisters(byte data1, byte data2, byte data3, byte data4) {
  digitalWrite(latchPin, LOW); //set latch pin low to prepare for data entry
  shiftOut(dataPin, clockPin, MSBFIRST, data4);
  shiftOut(dataPin, clockPin, MSBFIRST, data3);
  shiftOut(dataPin, clockPin, MSBFIRST, data2);
  shiftOut(dataPin, clockPin, MSBFIRST, data1);
  digitalWrite(latchPin, HIGH); //set latch pin high to make registers write out data
}

//antipoisoning function to prevent sputtering from destroying tubes over time
void slotMachine() {
  for (int digitSelect; digitSelect++; digitSelect <= 9) {    
    switch (digitSelect) {
      
      case 0:
        nixie1Binary = B0000;
        nixie2Binary = B0000;
        nixie3Binary = B0000;
        nixie4Binary = B0000;
        nixie5Binary = B0000;
        nixie6Binary = B0000;
        nixie7Binary = B0000;
        nixie8Binary = B0000;      
      break;
  
      case 1:
         nixie1Binary = B0001;
         nixie2Binary = B0001;
         nixie3Binary = B0001;
         nixie4Binary = B0001;
         nixie5Binary = B0001;
         nixie6Binary = B0001;
         nixie7Binary = B0001;
         nixie8Binary = B0001;      
      break;
      
      case 2:
          nixie1Binary = B0010;
          nixie2Binary = B0010;
          nixie3Binary = B0010;
          nixie4Binary = B0010;
          nixie5Binary = B0010;
          nixie6Binary = B0010;
          nixie7Binary = B0010;
          nixie8Binary = B0010;      
      break;
      
      case 3:
        //doesnt work on any tubes for some reason???
         nixie1Binary = B0011;
         nixie2Binary = B0011;
         nixie3Binary = B0011;
         nixie4Binary = B0011;
         nixie5Binary = B0011;
         nixie6Binary = B0011;
         nixie7Binary = B0011;
         nixie8Binary = B0011;      
      break;
      
      case 4:
        nixie1Binary = B0100;
        nixie2Binary = B0100;
        nixie3Binary = B0100;
        nixie4Binary = B0100;
        nixie5Binary = B0100;
        nixie6Binary = B0100;
        nixie7Binary = B0100;
        nixie8Binary = B0100;      
      break;
      
      case 5:
      //doesnt work on any tubes for some reason???
        nixie1Binary = B0101;
        nixie2Binary = B0101;
        nixie3Binary = B0101;
        nixie4Binary = B0101;
        nixie5Binary = B0101;
        nixie6Binary = B0101;
        nixie7Binary = B0101;
        nixie8Binary = B0101;      
      break;
      
      case 6:
        nixie1Binary = B0110;
        nixie2Binary = B0110;
        nixie3Binary = B0110;
        nixie4Binary = B0110;
        nixie5Binary = B0110;
        nixie6Binary = B0110;
        nixie7Binary = B0110;
        nixie8Binary = B0110;      
      break;
      
      case 7:
      //doesnt work on any tubes for some reason???
        nixie1Binary = B0111;
        nixie2Binary = B0111;
        nixie3Binary = B0111;
        nixie4Binary = B0111;
        nixie5Binary = B0111;
        nixie6Binary = B0111;
        nixie7Binary = B0111;
        nixie8Binary = B0111;      
      break;
      
      case 8:
        nixie1Binary = B1000;
        nixie2Binary = B1000;
        nixie3Binary = B1000;
        nixie4Binary = B1000;
        nixie5Binary = B1000;
        nixie6Binary = B1000;
        nixie7Binary = B1000;
        nixie8Binary = B1000;      
      break;
      
      case 9:
        nixie1Binary = B1001;
        nixie2Binary = B1001;
        nixie3Binary = B1001;
        nixie4Binary = B1001;
        nixie5Binary = B1001;
        nixie6Binary = B1001;
        nixie7Binary = B1001;
        nixie8Binary = B1001;      
      break;
    } 

    delay(500);
  } 
}

void printEEPROM(byte mem, byte outputBytes[]) {
  //print memory data from array
  for (byte i = 0; i < mem; i++) 
  {
    Serial.write(outputBytes[i]);
  }
  Serial.println("");
}

