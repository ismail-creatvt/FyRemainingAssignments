#include<stdio.h>
#include<stdlib.h>
int add_time(int *hour, int *min, int *sec, int add_sec){
	int add_min = 0, add_hour, days = 0;
	if(add_sec > 60){
		add_min = add_sec / 60;
		add_sec = add_sec - (add_min * 60);
		if(add_min > 60){
			add_hour = add_min/60;
			add_min = add_min - (add_hour * 60);
			if(add_hour > 23){
				days = add_hour/24;
				add_hour %= 24;
			}
			*hour = *hour + add_hour;
		}
		*min = *min + add_min;
	}
	*sec = *sec + add_sec;
	if(*sec >= 60){
		*sec = *sec - 60;
		(*min)++;
	}
	if(*min >= 60){
		*min = *min - 60;
		(*hour)++;
	}
	if(*hour >= 24){
		*hour = *hour - 24;
		days++;
	}
	return days;
}

void main(){
	int hour, min, sec, add_sec;
	printf("Enter hours : ");
	scanf("%d",&hour);
	if(hour < 0 || hour > 23){
		fprintf(stderr, "Hour should be between 0-23\n");
		exit(1);
	}
	printf("Enter minutes : ");
	scanf("%d",&min);
	if(min < 0 || min > 59){
		fprintf(stderr, "Minute should be between 0-59\n");
		exit(1);
	}
	printf("Enter seconds : ");
	scanf("%d",&sec);
	if(sec < 0 || sec > 59){
		fprintf(stderr, "Second should be between 0-59\n");
		exit(1);
	}
	printf("Enter seconds to add : ");
	scanf("%d",&add_sec);
	printf("Old Time : %d hr %d min %d sec\n",hour, min, sec);
	int days = add_time(&hour, &min, &sec, add_sec);
	if(days > 0){
		printf("New Time : %d days %d hr %d min %d sec\n",days, hour, min, sec);
	} else{
		printf("New Time : %d hr %d min %d sec\n",hour, min, sec);
	}
}