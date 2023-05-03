//Functions - T Leishman
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#ifndef _BV
#define _BV(bit) (1<<(bit))
#endif
Adafruit_LEDBackpack matrix = Adafruit_LEDBackpack();

int custom = 250; //set the delay time
int custom2 = 15;

void setup() {
  matrix.begin(0x70);  // pass in the address
  }
  
void loop() {
    
    //Clockwise Corners
    light_led(0, 0); //call the function and pass row and column to light a single LED
    light_led(7, 0);
    light_led(7, 7);
    light_led(0, 7);

    clear_all(); //turn off all LEDs

    outside_in(); //custom routine

    flashy_x();

  for (int i = 0; i<=2; i++){
    tim();
    delay(1000);
  }

  for (int i = 0; i<=2; i++){
  outside_in();
}
  flashy_x();
  }

void light_led(int row, int column){
    matrix.displaybuffer[row] = _BV(column);
    matrix.writeDisplay();
    delay(custom);    
    matrix.clear();
    matrix.writeDisplay();
    delay(custom);
  }

void clear_all(){
   matrix.clear();
    matrix.writeDisplay();
    delay(custom);
  }

void outside_in(){
        
    for (int row = 0; row<=7; row++){
      matrix.displaybuffer[row]=_BV(0);
      matrix.writeDisplay();
      delay(custom2);
    }
    for (int column = 1; column<=7; column++){
      matrix.displaybuffer[7]=  _BV(column-7) |_BV(column-6) | _BV(column-5) |_BV(column-4) |_BV(column-3) |_BV(column-2) | _BV(column-1) | _BV(column);
      matrix.writeDisplay();
      delay(custom2);
    }
    for (int row = 6; row>=0; row--){
      matrix.displaybuffer[row]= _BV(0) | _BV(7);
      matrix.writeDisplay();
      delay(custom2);
    }
    for (int column = 6; column>=1; column--){
      matrix.displaybuffer[0]=  _BV(0) | _BV(7) | _BV(column) | _BV(column+1)| _BV(column+2)| _BV(column+3) | _BV(column+4)| _BV(column+5);
      matrix.writeDisplay();
      delay(custom2);
    }
    for (int row = 1; row<=6; row++){
      matrix.displaybuffer[row]=_BV(0) | _BV(1) | _BV(7);
      matrix.writeDisplay();
      delay(custom2);
    }
    for (int column = 2; column<=6; column++){
      matrix.displaybuffer[6]=  _BV(0)|_BV(1) | _BV(7) | _BV(column) | _BV(column-1) | _BV(column-2) | _BV(column-3) | _BV(column-4);
      matrix.writeDisplay();
      delay(custom2);
    }
    for (int row = 5; row>=1; row--){
      matrix.displaybuffer[row]= _BV(0) |_BV(1) | _BV(6) | _BV(7);
      matrix.writeDisplay();
      delay(custom2);
    }
    for (int column = 5; column>=2; column--){
      matrix.displaybuffer[1]=  _BV(0) |_BV(1) | _BV(column) | _BV(column+1)| _BV(column+2)| _BV(column+3)| _BV(6) | _BV(7);
      matrix.writeDisplay();
      delay(custom2);
    }
    for (int row = 2; row<=5; row++){
      matrix.displaybuffer[row]=_BV(0) | _BV(1) | _BV(2) | _BV(6) | _BV(7);
      matrix.writeDisplay();
      delay(custom2);
    }  
    for (int column = 3; column<=5; column++){
      ////matrix.displaybuffer[7]=  _BV(0) |_BV(1) | _BV(2) |_BV(3) |_BV(4) |_BV(5) | _BV(6) | _BV(7);
      matrix.displaybuffer[5]=  _BV(0)|_BV(1) |_BV(2) | _BV(6) |_BV(7) |_BV(column) |_BV(column-1) | _BV(column-2);
      matrix.writeDisplay();
      delay(custom2);
    } 
    for (int row = 4; row>=2; row--){
      matrix.displaybuffer[row]=_BV(7) |_BV(6) |_BV(5) | _BV(2) | _BV(1) | _BV(0);
      matrix.writeDisplay();
      delay(custom2); 
    }
    for (int column = 4; column>=3; column--){
      matrix.displaybuffer[2]=  _BV(0) |_BV(1) | _BV(2) | _BV(column) | _BV(column+1)| _BV(5)| _BV(6) | _BV(7);
      matrix.writeDisplay();
      delay(custom2);
    }
    for (int row = 3; row<=4; row++){
      matrix.displaybuffer[row]=_BV(0) | _BV(1) | _BV(2) | _BV(3) | _BV(5) | _BV(6) | _BV(7);
      matrix.writeDisplay();
      delay(custom2);
    } 

    for (int row = 4; row>=2; row--){
      matrix.displaybuffer[row]=_BV(7) |_BV(6) |_BV(5) | _BV(4)| _BV(3) | _BV(2) | _BV(1) | _BV(0);
      matrix.writeDisplay();
      delay(custom2); 
    }
   
      clear_all();
              
    }

void flashy_x(){
  
  for (int i = 0; i<=3; i++){

  matrix.displaybuffer[0]=_BV(0) |_BV(7);
  matrix.displaybuffer[1]=_BV(1) |_BV(6);
  matrix.displaybuffer[2]=_BV(2) |_BV(5);
  matrix.displaybuffer[3]=_BV(3) |_BV(4);
  matrix.displaybuffer[4]=_BV(3) |_BV(4);
  matrix.displaybuffer[5]=_BV(2) |_BV(5);
  matrix.displaybuffer[6]=_BV(1) |_BV(6);
  matrix.displaybuffer[7]=_BV(0) |_BV(7);

  matrix.writeDisplay();
  delay(100); 
  clear_all(); 

  matrix.displaybuffer[0]=_BV(1) |_BV(2)|_BV(3)|_BV(4)|_BV(5)|_BV(6);
  matrix.displaybuffer[1]=_BV(0) |_BV(2)|_BV(3)|_BV(4)|_BV(5)|_BV(7);
  matrix.displaybuffer[2]=_BV(0) |_BV(1)|_BV(3)|_BV(4)|_BV(6)|_BV(7);
  matrix.displaybuffer[3]=_BV(0) |_BV(1) |_BV(2)|_BV(5)|_BV(6)|_BV(7);
  matrix.displaybuffer[4]=_BV(0) |_BV(1) |_BV(2)|_BV(5)|_BV(6)|_BV(7);
  matrix.displaybuffer[5]=_BV(0) |_BV(1)|_BV(3)|_BV(4)|_BV(6)|_BV(7);
  matrix.displaybuffer[6]=_BV(0) |_BV(2)|_BV(3)|_BV(4)|_BV(5)|_BV(7);
  matrix.displaybuffer[7]=_BV(1) |_BV(2)|_BV(3)|_BV(4)|_BV(5)|_BV(6);

  matrix.writeDisplay();
  delay(100); 
  clear_all(); 
  }
}  

void tim(){


  matrix.displaybuffer[0]=_BV(3) |_BV(4);
  matrix.displaybuffer[1]=_BV(3) |_BV(4);
  matrix.displaybuffer[2]=_BV(3) |_BV(4);
  matrix.displaybuffer[3]=_BV(3) |_BV(4);
  matrix.displaybuffer[4]=_BV(3) |_BV(4);
  matrix.displaybuffer[5]=_BV(3) |_BV(4);
  matrix.displaybuffer[6]=_BV(0) |_BV(1) |_BV(2)|_BV(3)|_BV(4)|_BV(5)|_BV(6) | _BV(7);
  matrix.displaybuffer[7]=_BV(0) |_BV(1) |_BV(2)|_BV(3)|_BV(4)|_BV(5)|_BV(6) | _BV(7);

  matrix.writeDisplay();
  delay(500); 
  clear_all(); 

  matrix.displaybuffer[0]=_BV(3) |_BV(4);
  matrix.displaybuffer[1]=_BV(3) |_BV(4);
  matrix.displaybuffer[2]=_BV(3) |_BV(4);
  matrix.displaybuffer[3]=_BV(3) |_BV(4);
  matrix.displaybuffer[4]=_BV(3) |_BV(4);
  matrix.displaybuffer[5]=_BV(3) |_BV(4);
  matrix.displaybuffer[6]=_BV(3) |_BV(4);
  matrix.displaybuffer[7]=_BV(3) |_BV(4);

  matrix.writeDisplay();
  delay(500); 
  clear_all(); 

  matrix.displaybuffer[0]=_BV(0) |_BV(1) | _BV(6) |_BV(7);
  matrix.displaybuffer[1]=_BV(0) |_BV(1) | _BV(6) |_BV(7);
  matrix.displaybuffer[2]=_BV(0) |_BV(1) | _BV(6) |_BV(7);
  matrix.displaybuffer[3]=_BV(0) |_BV(1) | _BV(3) | _BV(4)| _BV(6) |_BV(7);
  matrix.displaybuffer[4]=_BV(0) |_BV(1) | _BV(3) | _BV(4) | _BV(6) |_BV(7);
  matrix.displaybuffer[5]=_BV(0) |_BV(1) | _BV(2) | _BV(3) | _BV(4) |_BV(5) |_BV(6) |_BV(7);
  matrix.displaybuffer[6]=_BV(0) |_BV(1) | _BV(2) |_BV(5) |_BV(6) |_BV(7);
  matrix.displaybuffer[7]=_BV(0) |_BV(1) | _BV(6) |_BV(7);

  matrix.writeDisplay();
  delay(500); 
  clear_all();

}



