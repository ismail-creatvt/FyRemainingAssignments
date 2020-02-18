#include<stdio.h>
#include<string.h>
#define UPPERCASE(c) (c >= 'A' && c <= 'Z')
#define LOWERCASE(c) (c >= 'a' && c <= 'z')

void main(){
	char str[50];
	int i=0;
	printf("Enter a string : ");
	fgets(str, 50, stdin);
	str[strlen(str)-1] = '\0';
	for(i=0;i<strlen(str);i++){
		if(UPPERCASE(str[i])){
			str[i] += 32;
		} 
		else if(LOWERCASE(str[i])){
			str[i] -= 32;
		}
	}
	printf("String is : %s\n", str);
	printf("\n");
}