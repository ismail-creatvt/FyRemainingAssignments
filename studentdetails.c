#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	int roll_no;
	char name[30];
	int marks[3];
	float percentage;
} Student;

void main(){
	Student *students;
	int n, i = 0, j = 0;
	printf("Enter the number of students : ");
	scanf("%d", &n);
	students = (Student*) malloc(sizeof(Student) * n);
	printf("Enter student Details...\n");
	while(i < n){
		printf("Student %d : \n", (i+1));
		printf("   Roll no : ");
		scanf("%d",&students[i].roll_no);
		printf("   Name : ");
		scanf("%s",students[i].name);
		printf("   Marks : \n");
		j = 0;
		while(j < 3){
			printf("      Subject %d : ", (j+1));
			scanf("%d",&students[i].marks[j]);
			j++;
		}
		printf("   Percentage : ");
		scanf("%f",&students[i].percentage);
		i++;
	}
	while(1){
		
	}
}