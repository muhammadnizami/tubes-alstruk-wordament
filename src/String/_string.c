#ifndef _string_h
#define _string_h

#include "../ADT Boolean/boolean.h"

boolean _strcmp(char * a, char * b){
	int i=0;
	while (a[i]==b[i]&&a[i]!='\0'&&b[i]!='\0')
		i++;
	return a[i]!=b[i];
}

char * _strcpy(char * dest, char * src){
	int i=0;
	while (src[i]!='\0'){
		dest[i]=src[i];
		i++;
	}
	dest[i]='\0';
	return dest;
}

char * _strcat(char * dest, char * src){
	int i=0;
	int j;
	while (dest[i]!='\0')i++;
	j=0;
	while (src[j]!='\0'){
		dest[i]=src[j];
		j++;
		i++;
	}
	return dest;
}

#endif
