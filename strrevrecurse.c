#include<stdio.h>
#include<string.h>
void display_rev(char *str){
	if(strlen(str) == 0) return;
	printf("%c",str[strlen(str)-1]);
	str[strlen(str)-1] = '\0';
	display_rev(str);
}

void main(){
	char str[50];
	int i=0;
	printf("Enter a string : ");
	fgets(str, 50, stdin);
	str[strlen(str)-1] = '\0';
	display_rev(str);
	printf("\n");
}