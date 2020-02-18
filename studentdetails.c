#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
	int roll_no;
	char name[30];
	int marks[3];
	float percentage;
} Student;

void printMenu(){
	printf("\n------------------------\n");
	printf("1. Search\n");
	printf("2. Modify\n");
	printf("3. Display all Students\n");
	printf("4. Display all student having percentage > _____\n");
	printf("0. Exit\n");
	printf("\n------------------------\n");
	printf("Enter your option : ");
}

Student *students;
int n;

void calculatePercentage(Student *student){
	int sum = 0, i=0;
	while(i < 3){
		sum += student->marks[i];
		i++;
	}
	student->percentage = sum/3.0;
}

void modifyStudent(Student *student){
	int option, j;
	printf("1. Roll no\n");
	printf("2. Name\n");
	printf("3. Marks\n");
	printf("Select field to modify : ");
	scanf("%d", &option);
	switch(option){
		case 1:
			printf("Enter Roll no : ");
			scanf("%d",&student->roll_no);
			break;
		case 2:
			printf("Enter name : ");
			fgets(student->name, 30, stdin);
			break;
		case 3:
			printf("Enter Marks :\n");
			j = 0;
			while(j < 3){
				printf("  Subject %d (Old Marks : %d) : ", (j+1), student->marks[j]);
				scanf("%d",&student->marks[j]);
				j++;
			}
			calculatePercentage(student);
			break;
	}

}

void printStudent(Student student){
	int j;
	printf("Student found : \n");
	printf("   Roll no : %d\n", student.roll_no);
	printf("   Name : %s\n", student.name);
	printf("   Marks : \n");
	j = 0;
	while(j < 3){
		printf("      Subject %d : %d\n", (j+1), student.marks[j]);
		j++;
	}
	printf("   Percentage : %.3f", student.percentage);
}

void displayAll(float min_percentage){
	int i=0;
	while(i < n){
		if(students[i].percentage > min_percentage){
			printStudent(students[i]);
			printf("\n-------------------\n");
		}
		i++;
	}
}

void searchStudent(int modify){
	int roll_no, i, j;
	printf("Enter Roll no : ");
	scanf("%d", &roll_no);
	for(i = 0; i < n; i++){
		if(students[i].roll_no == roll_no){
			if(modify){
				modifyStudent(&students[i]);
			} else{
				printStudent(students[i]);
				break;
			}
		}
	}
}

void main(){
	int i = 0, j = 0;
	float min_percentage;
	int option;
	printf("Enter the number of students : ");
	scanf("%d", &n);
	students = (Student*) malloc(sizeof(Student) * n);
	printf("Enter student Details...\n");
	while(i < n){
		printf("Student %d : \n", (i+1));
		printf("   Roll no : ");
		scanf("%d",&students[i].roll_no);
		fgetc(stdin);
		printf("   Name : ");
		fgets(students[i].name, 30, stdin);
		students[i].name[strlen(students[i].name)-1]='\0';
		printf("   Marks : \n");
		j = 0;
		while(j < 3){
			printf("      Subject %d : ", (j+1));
			scanf("%d",&students[i].marks[j]);
			j++;
		}
		calculatePercentage(&students[i]);
		i++;
	}
	while(1){
		printMenu();
		scanf("%d",&option);
		switch(option){
			case 0:
				break;
			case 1:
				searchStudent(0);
				break;
			case 2:
				searchStudent(1);
				break;
			case 3:
				displayAll(0);
				break;
			case 4:
				printf("Enter min percentage : ");
				scanf("%f",&min_percentage);
				displayAll(min_percentage);
				break;
		}
	}
}