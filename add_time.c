#include<stdio.h>
void add_time(int *hour, int *min, int *sec, int add_sec){
	int add_min = 0;
	if(add_sec > 60){
		add_min = add_sec / 60;
		add_sec = add_sec - (add_min * 60);
		*min = *min + add_min;
	}
	*sec = *sec + add_sec;
	if(*sec >= 60){
		*sec = *sec - 60;
		*min++;
	}
	if(*min >= 60){
		*min = *min - 60;
		*hour++;
	}
	if(*hour >= 24){
		*hour = *hour - 24;
	}
}

void main(){
	int hour, min, sec, add_sec;
	printf("Enter hours : ");
	scanf("%d",&hour);
	printf("Enter minutes : ");
	scanf("%d",&min);
	printf("Enter seconds : ");
	scanf("%d",&sec);
	printf("Enter seconds to add : ");
	scanf("%d",&add_sec);
	add_time(&hour, &min, &sec, add_sec);
	printf("Time : %d hr %d min %d sec\n",hour, min, sec);
}