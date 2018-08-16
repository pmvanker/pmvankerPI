/*
 * led.c
 *
 *  Created on: 16-Aug-2018
 *      Author: pmvanker
 */
#include "pmvPI.h"
int main()
{
	int i;
	pinMODE(2,"OUTPUT");
	for(i=0;i<5;i++)
	{
		digitalWrite(2,1);
		delay(500);
		digitalWrite(2,0);
		delay(500);
	}
	unexport(2);
}

