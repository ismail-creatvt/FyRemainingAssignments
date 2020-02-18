#include<stdio.h>
#include<string.h>
int search(char *str, char c){
	int pos = -1, i = 0;
	while(i<strlen(str)){
		if(str[i] == c){
			pos = i;
			break;
		}
		i++;
	}
}

void main(){
	char str[50], c;
	printf("Enter a string : ");
	scanf("%s", str);
	getc(stdin);
	printf("Enter character to search : ");
	scanf("%c", &c);
	printf("'%c' found at position %d\n",c, search(str, c));
}