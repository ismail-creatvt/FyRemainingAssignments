#include<stdio.h>
#include<string.h>

void main(){
	char str[50], c;
	int i=0, k=0, j=0;
	printf("Enter a string : ");
	fgets(str, 50, stdin);
	while(i<strlen(str)){
		j = i;
		k = i;
		while(str[j] != ' ' && str[j] != '\n'){
			j++;
		}
		i=j+1;
		j--;
		while(k<=j){
			c = str[k];
			str[k] = str[j];
			str[j] = c;
			k++;
			j--;
		}
	}
	printf("String is : %s\n", str);
}