#include<stdio.h>
#include<stdlib.h>

void main(){
	float *numbers = (float*) malloc(sizeof(float) * 5);
	float total = 0;
	int i=0;
	printf("Enter five decimal numbers : \n");
	while(i<5){
		scanf("%f",&numbers[i]);
		i++;
	}
	numbers = (float*) realloc(numbers, sizeof(float) * 8);
	printf("Enter 3 more decimal numbers : \n");
	while(i<8){
		scanf("%f",&numbers[i]);
		i++;
	}
	i=0;
	while(i<8){
		total += numbers[i];
		i++;
	}
	printf("Sum : %.3f, Average : %.3f\n", total, total/8);
}