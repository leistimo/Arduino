/*
  Library for the MMA8452Q
  By: Jim Lindblom and Andrea DeVore
  SparkFun Electronics

  Do you like this library? Help support SparkFun. Buy a board!
  https://www.sparkfun.com/products/14587

  This sketch uses the SparkFun_MMA8452Q library to initialize
  the accelerometer and stream its orientation.

  Hardware hookup:
  Arduino --------------- MMA8452Q Breakout
    3.3V  ---------------     3.3V
    GND   ---------------     GND
  SDA (A4) --\/330 Ohm\/--    SDA
  SCL (A5) --\/330 Ohm\/--    SCL

  The MMA8452Q is a 3.3V max sensor, so you'll need to do some
  level-shifting between the Arduino and the breakout. Series
  resistors on the SDA and SCL lines should do the trick.

  License: This code is public domain, but if you see me
  (or any other SparkFun employee) at the local, and you've
  found our code helpful, please buy us a round (Beerware
  license).

  Distributed as is; no warrenty given.
*/

#include <Wire.h>                 // Must include Wire library for I2C
#include "SparkFun_MMA8452Q.h"    // Click here to get the library: http://librarymanager/All#SparkFun_MMA8452Q

#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

#ifndef _BV
#define _BV(bit) (1<<(bit))
#endif

Adafruit_LEDBackpack matrix = Adafruit_LEDBackpack();

MMA8452Q accel;                   // create instance of the MMA8452 class

void setup() {

  matrix.begin(0x70);  // pass in the address

  Serial.begin(9600);
  Serial.println("MMA8452Q Orientation Test Code!");
  Wire.begin();
  

  if (accel.begin() == false) {
    Serial.println("Not Connected. Please check connections and read the hookup guide.");
    while (1);
  }
}

void loop() {
  if (accel.available()) {      // Wait for new data from accelerometer
    // Orientation of board (Right, Left, Down, Up);
    if (accel.isRight() == true) {
      Serial.println("Right");
      right(); //Added Function to create LED arrow on the 8x8 Dot Matrix - TLeishman
    }
    else if (accel.isLeft() == true) {
      Serial.println("Left");
      left(); //Added Function to create LED arrow on the 8x8 Dot Matrix - TLeishman
    }
    else if (accel.isUp() == true) {
      Serial.println("Up"); 
      up();//Added Function to create LED arrow on the 8x8 Dot Matrix - TLeishman
    }
    else if (accel.isDown() == true) {
      Serial.println("Down");
      down(); //Added Function to create LED arrow on the 8x8 Dot Matrix - TLeishman
    }
    else if (accel.isFlat() == true) {
      Serial.println("Flat");
    }
  }
}

void clear_all(){
   matrix.clear();
    matrix.writeDisplay();
    
  }

void right(){
matrix.displaybuffer[2]=_BV(5);
matrix.displaybuffer[3]= _BV(6);
matrix.displaybuffer[4]=_BV(0) |_BV(1) |_BV(2) |_BV(3) |_BV(4) |_BV(5) |_BV(6) |_BV(7);
matrix.displaybuffer[5]=_BV(6);
matrix.displaybuffer[6]=_BV(5);
 matrix.writeDisplay();
  delay(100); 
  clear_all(); 
}

void left(){
matrix.displaybuffer[2]=_BV(2);
matrix.displaybuffer[3]= _BV(1);
matrix.displaybuffer[4]=_BV(0) |_BV(1) |_BV(2) |_BV(3) |_BV(4) |_BV(5) |_BV(6) |_BV(7);
matrix.displaybuffer[5]=_BV(1);
matrix.displaybuffer[6]=_BV(2);
 matrix.writeDisplay();
  delay(100); 
  clear_all(); 
}

void up(){
matrix.displaybuffer[0]=_BV(4);
matrix.displaybuffer[1]=_BV(4);
matrix.displaybuffer[2]=_BV(4);
matrix.displaybuffer[3]= _BV(4);
matrix.displaybuffer[4]=_BV(4);
matrix.displaybuffer[5]=_BV(4) | _BV(2) | _BV(6);
matrix.displaybuffer[6]=_BV(4) | _BV(3) | _BV(5);
matrix.displaybuffer[7]=_BV(4);
 matrix.writeDisplay();
  delay(100); 
  clear_all(); 
}

void down(){
matrix.displaybuffer[0]=_BV(4);
matrix.displaybuffer[1]=_BV(4) | _BV(3) | _BV(5);
matrix.displaybuffer[2]=_BV(4) | _BV(2) | _BV(6);
matrix.displaybuffer[3]= _BV(4);
matrix.displaybuffer[4]=_BV(4);
matrix.displaybuffer[5]=_BV(4);
matrix.displaybuffer[6]=_BV(4);
matrix.displaybuffer[7]=_BV(4);
 matrix.writeDisplay();
  delay(100); 
  clear_all(); 
}


