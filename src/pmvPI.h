/*
 * pmvBBB.h
 *
 *  Created on: 15-Dec-2017
 *      Author: ccare
 */

#ifndef PMVPI_H_
#define PMVPI_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define MAX 64
int gpio[80]={0,1,2,3,4,5,6,7,8,9,10,30,60,31,50,48,51,5,4,13,12,3,2,49,15,117,14,115,
		      113,111,112,110,32,33,34,35,36,37,38,39,40,20,116,7,114,43,44};


int pinMODE(int x,char *q)				//pinMODE(GPIO pin,Direction)
{
	int FP;
	char GPIOpin[4],GPIOdirection[MAX];
	if((FP=open("/sys/class/gpio/export",O_WRONLY))==-1)
	{
		perror("pinMODE export");
		return 0;
	}
	perror("pinMODE export");
	sprintf(GPIOpin,"%d",gpio[x]);
	write(FP,GPIOpin,4);
    close(FP);

	sprintf(GPIOdirection,"/sys/class/gpio/gpio%d/direction",gpio[x]);
	if((FP=open(GPIOdirection,O_WRONLY))==-1)
		{
			perror("pinMODE direction");
			return 0;
		}
	perror("pinMODE direction");
	if(strcmp(q,"INPUT")==0)
		write(FP,"in",3);
	else if(strcmp(q,"OUTPUT")==0)
		write(FP,"out",4);
	close(FP);
	return 1;
}
int unexport(int x)
{
	int FP;
	char GPIOpin[4];
	if((FP=open("/sys/class/gpio/unexport",O_WRONLY))==-1)
	{
		perror("unexport");
		return 0;
	}
	perror("unexport");
	sprintf(GPIOpin,"%d",gpio[x]);
	write(FP,GPIOpin,4);
	close(FP);
	return 1;
}

int digitalWrite(int pin,int value)
{
	int FP;
	char GPIOvalue[MAX];
	sprintf(GPIOvalue,"/sys/class/gpio/gpio%d/value",gpio[pin]);
	if((FP=open(GPIOvalue,O_WRONLY))==-1)
	{
		perror("digitalWrite");
		return 0;
	}
	if(value==1)
		write(FP,"1",2);
	else
		write(FP,"0",2);
	close(FP);
	return 1;
}

int digitalRead(int pin)
{
	int FP;
	char ch;
	char GPIOvalue[MAX];
	sprintf(GPIOvalue,"/sys/class/gpio/gpio%d/value",gpio[pin]);
	if((FP=open(GPIOvalue,O_RDONLY))==-1)
	{
		perror("digitalRead");
		return 0;
	}
	read(FP,&ch,1);
	close(FP);
	if(ch=='0')
		return 0;
	else
		return 1;
}

void analog_init()
{
	int FP;
	if((FP=open("/sys/devices/bone_capemgr.8/slots",O_WRONLY))==-1)
	{
		perror("analog_init");
		return;
	}
	write(FP,"BB-ADC",6);
	close(FP);
	printf("ANALOG PIN ENABLES\n");
}

int analogRead(int pin)
{
	int FP;
	char PATH[MAX],a[3];
	sprintf(PATH,"/sys/bus/iio/devices/iio:device0/in_voltage%d_raw",pin);
	if((FP=open(PATH,O_RDONLY))==-1)
	{
		perror("analogRead\n");
		return 0;
	}
	read(FP,a,4);
	close(FP);
	return atoi(a);
}

int pwm_init(char *pin)
{
	int FP;
	char s[MAX];
	if((FP=open("/sys/devices/bone_capemgr.8/slots",O_WRONLY))==-1)
	{
		perror("PWM_init");
		return 0;
	}
	sprintf(s,"bone_pwm_%s",pin);
	write(FP,s,strlen(s));
	write(FP,"am33xx_pwm",10);
	close(FP);

	sprintf(s,"/sys/devices/ocp.2/pwm_test_%s.14/polarity",pin);
	if((FP=open(s,O_WRONLY))==-1)
	{
		perror("polarity");
		return 0;
	}
	write(FP,0,1);
	close(FP);
	return 1;
}

int pwm_write(char *pin,int value)
{
	int FP;
	char data[5];
		char PWM_PATH[MAX];
		sprintf(PWM_PATH,"/sys/devices/ocp.2/pwm_test_%s.14/duty",pin);
		if((FP=open(PWM_PATH,O_WRONLY))==-1)
		{
			perror("pwm_write");
			return 0;
		}
		sprintf(data,"%d",value);
		write(FP,data,strlen(data));
		close(FP);
		return 1;
}
void delay(int x)
{
	usleep(x*1000);
}

#endif /* PMVPI_H_ */
