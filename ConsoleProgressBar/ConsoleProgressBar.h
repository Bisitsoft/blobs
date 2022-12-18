/*
Console Progress Bar
Author: Orange233 (https://github.com/Orange23333)
*/

#ifndef _ConsoleProgressBar_h
	#define _ConsoleProgressBar_h
	
	#if defined(__cplusplus)
extern "C"{
	#else
		#include <stdbool.h>
	#endif

void PrintSameChar(const char _ch, const int n);
void PrintRollingChars(int *lastStatus, const bool printBackspace);
//param `length`: The length of progress-bar's bar. It must equals or larger than 1.
//param `point`: `point` E [0,6].
int PrintProgress(int length, int point, float value, const bool printBackspace);
	
	#if defined(__cplusplus)
}
	#endif
#endif
