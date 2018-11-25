#include<stdio.h>
#include<wiringPi.h>
#include<wiringPiSPI.h>
#include<stdint.h>
#define RED 0
#define GREEN 1
#define BLUE 2
#define LINE 3
int main(){
  
  static uint8_t data[4]={0,0,0,0};
  static uint8_t heart[8]={0x00,0x66,0xFF,0xFF,0xFF,0x7e,0x3c,0x18};
  static uint8_t red=0;
  static uint8_t green=0;
  static uint8_t blue=0;
  wiringPiSetup();
  wiringPiSPISetup(0,500000);
  int time=4;
  while(time--){
	for(blue=0;blue<0xff;blue+=0xf){
		for(green=0;green<0xff;green+=0xf){
			for(int j=0;j<8;j++){
				data[RED]=~heart[j];
				data[GREEN]=~green;
				data[BLUE]=~blue;
				data[LINE]=0x01<<j;
				wiringPiSPIDataRW(0,data,sizeof(data));
				delay(2);
			}
		}
	}
  }
  return 0;
}
