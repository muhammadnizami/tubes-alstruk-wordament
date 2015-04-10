#include "mainmenu.h"
#include "statusboard.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
// Define the function to be called when ctrl-c (SIGINT) signal is sent to process
void signal_callback_handler(int signum)
{
	//supaya semua tersimpan, user harus mengikuti flow yang sudah ditentukan
	//jadi SIGINT tidak boleh memberhentikan program
}

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int _doesFileExist(const char *filename) {
    struct stat st;
    int result = stat(filename, &st);
    return result == 0;
}

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void createDirIfNotExist(char * path){


	struct stat st = {0};
	if (stat(path, &st) == -1) {
	    mkdir(path, 0700);
	}
}
int main(){
	int i;
//periksa berkas dependency
	if (!_doesFileExist("data/Dictionary.txt")){
		printf("ERROR: dictionary tidak ada\n");
		return;
	}
	for (i=0;i<10;i++)
		if (!_doesFileExist(boardfilename(i))){
			printf("ERROR: berkas board tidak ada\n");
			return;
		}



//periksa folder
	createDirIfNotExist("data");
	createDirIfNotExist("data/allhighscore");
	createDirIfNotExist("data/suggestion");


	

// Register signal and signal handler
	signal(SIGINT, signal_callback_handler);

//mulai
	mainmenu();
	return 0;
}
