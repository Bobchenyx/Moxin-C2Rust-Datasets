#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char findTheDifference(char * s, char * t)
{
	int sumS = 0;
	int sumT = 0;
	char result;		

	while (*s) {
		sumS += (*s++) - 'a';
	}
	while (*t) {
		sumT += (*t++) - 'a';
	}
	
	result = sumT - sumS + 'a';
	return result;
}