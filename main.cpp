/*
 * @Author: your name
 * @Date: 2020-12-26 15:39:02
 * @LastEditTime: 2020-12-29 09:45:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /UART/main.cpp
 */
#include "serialPort.hpp"
#include <iostream>
#include <string>
uint8_t buff[8];
uint8_t buff1[8] = "123";
const char *dev  = "/dev/ttyUSB0";
int main()

{ 
  serialPort myserial;
  int i,nread,nwrite;
  cout<<"serialPort Test"<<endl;
  myserial.OpenPort(dev);
  myserial.setup(115200,0,8,1,'N'); 
  for (i=0;i<6;i++) buff[i]=0x30+i;buff[6]=0x0a;buff[7]=0x0d;
  while (true)
  {
	  
    //nwrite = myserial.writeBuffer( buff1, 8);
	  nread = myserial.readBuffer(buff, 8);
    //cout << int(buff[0]) << int(buff[1]) <<int(buff[2]) << endl;
    //cout << nread << endl;
    if(buff[0]=='k')
    {
      cout<<"get"<<buff<<endl;
      
    }
	  usleep(400);
  }
}