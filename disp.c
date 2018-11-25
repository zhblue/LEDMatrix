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
				{1,1,0,1,1,1,0,7},
				{0,1,0,1,0,1,0,7},
				{1,1,0,1,1,1,0,7},
				{1,0,0,1,0,1,0,7},
				{1,1,0,1,1,1,0,7},
				{0,0,0,0,0,0,0,7},
				{7,7,7,7,7,7,7,7},
				{6,0,0,0,0,0,0,7}

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
  int count=0;
  wiringPiSetup();
  wiringPiSPISetup(0,500000);
  //print();
  int go=0xff;
  while(go--){
	  
	 for(int i=0;i<8;i++){
	 	for(int j=0;j<8;j++){
			if((i==4||i==3) && (j==4||j==3)) {
				screen[i][j]=0;		
				continue;
			}
			if((i==1||i==6) && j!=0&&j!=7) {
				screen[i][j]=0;		
				continue;
			}
			if((j==1||j==6) && i!=0&&i!=7) {
				screen[i][j]=0;		
				continue;
			}
			screen[i][j]=(count)%4+3;
			count+=rand()%7;
		}
	 }
  	// print();
	 display();
  }
  return 0;
}
