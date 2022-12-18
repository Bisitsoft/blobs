/*
Console Progress Bar Example
Author: Orange233 (https://github.com/Orange23333)
*/

#include <stdio.h>
#include <stdbool.h>

#include <unistd.h>

#include "ConsoleProgressBar.h"

int main(){
	float i,n=100.0f,step=1.11111111f;
	int prcCache;
	int r;
	
	printf("Progress: ");
	prcCache=0;
	for(i=0;i<=n;i+=step){
		r=PrintProgress(20, 2, i/n, false);
		PrintRollingChars(&prcCache, true);
		PrintSameChar('\b', r);
		
		usleep(100*1000);
	}
	PrintProgress(20, 2, 1.0f, false);
	printf("Finished!\n");
	
	return 0;
}
