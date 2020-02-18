#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
	char *str;
	int i, n, vowels = 0;
	printf("Enter string length : ");
	scanf("%d",&n);
	str = (char*) calloc(sizeof(char), n);
	printf("Enter a string : ");
	getc(stdin);
	fgets(str, n, stdin);
	for(i=0;i<n;i++){
		switch(str[i]){
			case 'a': case 'A': vowels++; break;
			case 'e': case 'E': vowels++; break;
			case 'i': case 'I': vowels++; break;
			case 'o': case 'O': vowels++; break;
			case 'u': case 'U': vowels++; break;
		}
	}
	printf("Consonants : %ld, Vowels : %d\n",(strlen(str)-vowels),vowels);
	free(str);
}