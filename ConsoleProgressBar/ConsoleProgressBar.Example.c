/*
Console Progress Bar Example
Author: Orange233 (https://github.com/Orange23333)
*/

#include <stdio.h>
#include <stdbool.h>

#if defined(__linux__) || defined(__gnu_linux__)
	#include <unistd.h.h>
#elif defined(__WINDOWS__) || defined(_WIN64) || defined(_WIN32) || defined(__WIN32__)
	#include <windows.h>
#else
	#error No or Non-supported predef.
#endif


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
		
#if defined(__linux__) || defined(__gnu_linux__)
		usleep(100*1000);
#elif defined(__WINDOWS__) || defined(_WIN64) || defined(_WIN32) || defined(__WIN32__)
		Sleep(100);
#endif
	}
	PrintProgress(20, 2, 1.0f, false);
	printf("Finished!\n");
	
	return 0;
}
