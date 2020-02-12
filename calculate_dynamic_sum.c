#include<stdio.h>
#include<malloc.h>
char* suffix(int i){
	switch(i){
		case 0:
			return "st";
		case 1:
			return "nd";
		case 2:
			return "rd";
		default:
			return "th";
	}	
}

void main(){
	int i, n, sum = 0;
	int *numbers;
	printf("Enter total numbers : ");
	scanf("%d",&n);
	numbers = malloc(sizeof(int) * n);
	for(i = 0; i < n; i++){		
		printf("Enter %d%s number : ", (i+1), suffix(i));
		scanf("%d",&numbers[i]);
		sum += numbers[i];
	}
	printf("Sum : %d\n", sum);
	free(numbers);
}