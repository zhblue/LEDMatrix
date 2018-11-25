#include<stdio.h>
#include<stdlib.h>
#include<wiringPi.h>
#include<wiringPiSPI.h>
#include<stdint.h>
#define RED 0
#define GREEN 1
#define BLUE 2
#define LINE 3
static int screen[8][8]={
				{0,0,5,5,5,5,0,0},
				{0,5,0,0,0,0,5,0},
				{5,0,0,0,0,0,0,5},
				{5,0,1,0,0,1,0,5},
				{5,0,0,0,0,0,0,5},
				{5,0,3,0,0,3,0,5},
				{0,5,0,3,3,0,5,0},
				{0,0,5,5,5,5,0,0}

				}; 
int print(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			printf("%6x ",screen[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
int display(){

  static uint8_t data[4]={0,0,0,0};
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			for(int k=0;k<3;k++){
				if(screen[i][j] & (0x1<< k)){
					data[k]&=~(0x1<<j);
				}else{
					data[k]|=(0x01<<j);
				}
			}
			//data[GREEN]&=(screen[i][j]&&0x02)<<i;
			//data[BLUE]&=(screen[i][j]&&0x04)<<i;
		}
		data[LINE]=0x01<<i;
		wiringPiSPIDataRW(0,data,sizeof(data));
		delay(1);
	}
	return 0;
}
int main(){
  static uint8_t heart[8]={0x00,0x66,0xFF,0xFF,0xFF,0x7e,0x3c,0x18};
  static uint8_t red=0;
  static uint8_t green=0;
  static uint8_t blue=0;
  int count=0x2ff;
  wiringPiSetup();
  wiringPiSPISetup(0,500000);
  //print();
  while(count--){
  	// print();
	 display();
  }
  return 0;
}
