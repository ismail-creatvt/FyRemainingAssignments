#include<stdio.h>
#include<string.h>

#define EQUALSTR(str1, str2) (strcmp(str1, str2) == 0 ? 1 : 0)

void main(int argc, char **argv){
	if(EQUALSTR(argv[1], argv[2])){
		printf("Strings are equal\n");
	} else{		
		printf("Strings are not equal\n");
	}
} 