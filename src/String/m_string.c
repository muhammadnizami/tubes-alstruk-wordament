#include "_string.h"
#include <stdio.h>

int main(){
	printf("strcmp: %x, seharusnya: 1", _strcmp("asdf","asd"));
	printf("strcmp: %x, seharusnya: 0", _strcmp("asdf","asdf"));
	char a[4072];
	_strcpy(a,"jika strcpy berhasil akan tampil pesan ini hingga titik lalu newline.\n");
	printf("test strcpy:\n%s",a);


	char b[4072];
	_strcpy(b,"mulai test strcat,");
	_strcat(b,"test test test berhasil\n");
	printf("test strcat:\n%s",b);
}
