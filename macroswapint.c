#include<stdio.h>
#include<string.h>

#define SWAP(x, y) (x ^= y ^= x ^= y)

void display(int *array, int n){
	int i;
	for(i = 0; i< n; i++){
		printf("%d  ", array[i]);
	}
	printf("\n");
}

void main(int argc, char **argv){
	int i=0, j, n = 10;
	int array[] = {1, 4, 2, 51, 3, 21, 24, 11, 5, 11};
	printf("Before sorting ... \n");
	display(array, n);
	for(i=0; i < n; i++){
		for(j = 0; j < n - i -1; j++){
			if(array[j] > array[j+1]){
				SWAP(array[j], array[j+1]);
			}
		}
	}
	printf("After sorting ... \n");
	display(array, n);
} 

