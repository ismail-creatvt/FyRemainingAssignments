#include<stdio.h>
#include<string.h>

void main(){
	char str[50];
	int i=0;
	printf("Enter a string : ");
	fgets(str, 50, stdin);
	while(i<strlen(str)){
		if(str[i] == ' '){
			str[i] = '*';
		} else if(str[i] >= 'A' && str[i]<='Z'){
			str[i] += 32;
		} else if(str[i] >= 'a' && str[i]<='z'){
			str[i] -= 32;
		} else if(str[i] >= '0' && str[i] <= '9'){
			str[i] = '?';
		}
		i++;
	}
	printf("String is : %s\n", str);
}