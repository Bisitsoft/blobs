/*
Console Progress Bar
Author: Orange233 (https://github.com/Orange23333)
*/

#include "ConsoleProgressBar.h"

#include <stdio.h>

const char rollingChars[]={'|','/','-','\\'};

void PrintSameChar(const char _ch, const int n){
	int i;
	for(i=0;i<n;i++){
		putchar(_ch);
	}
}

void PrintRollingChars(int *lastStatus, const bool printBackspace){
	putchar(rollingChars[*lastStatus]);
	if(printBackspace){
		putchar('\b');
	}

	if(++(*lastStatus)>=4){
		*lastStatus=0;
	}
}

int PrintProgress(int length, int point, float value, const bool printBackspace){
	int i;
	int totalLength,numLength,temp;
	float num;
	char formatString[6];

	if(length<1){
		length=1;
	}
	if(point<0){
		point=0;
	}
	if(point>6){
		point=6;
	}
	if(value<0.0f){
		value=0.0f;
	}
	if(value>1.0f){
		value=1.0f;
	}
	num=value*100.0f;
	numLength=point==0?0:(point+1);
	temp=num;
	do{
		++numLength;
		temp/=10;
	}while(temp>0);
	totalLength=3+length+numLength;
	sprintf(formatString,"%%.%df",point);

	//[|||__ 79.9%]
	putchar('[');
	temp=length*value;
	for(i=0;i<temp;i++){
		putchar('>');
	}
	for(;i<length;i++){
		putchar('_');
	}
	//%9.6f
	printf(formatString,num);
	putchar('%');
	putchar(']');

	if(printBackspace){
		PrintSameChar('\b',totalLength);
	}

	return totalLength;
}
