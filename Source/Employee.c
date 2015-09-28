/*

 * Name: Ranjan Mishra
 * Roll No: MTech-CS1519
 * Program Description: Reading and writing to a binary file.
 * Acknowledgement: 

 */




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 100

typedef struct record{
	int empNo;
	char name[MAX_LENGTH];
	double salary;
	char address[MAX_LENGTH];
	}Employee;

void addNewEmployee(char *fileName){
	FILE *fp;
	Employee *emp;
	emp=(Employee*)malloc(sizeof(Employee));
	emp->empNo=rand()%13123;
	printf("\nPlease enter below asked details");
	printf("\nName\t:");
	scanf("%s", emp->name);
	printf("Salary\t:");
	scanf("%lf", &emp->salary);
	printf("Address :");
	scanf("%s", emp->address);
	fp=fopen(fileName, "ab+");
	if(fp==NULL){
		perror("\Error opening file");
		exit(0);
	}

	fprintf(fp, "\n%d %s %lf %s", emp->empNo, emp->name, emp->salary, emp->address); 	
	fclose(fp);
	printf("\nEmployee deatails have been added to the file");
}

void display(Employee emp){
	
	printf("\nEmp No\t\t: %d", emp.empNo);
	printf("\nEmp Name\t: %s", emp.name);
	printf("\nEmp Salary\t: %f", emp.salary);
	printf("\nEmp Address\t: %s", emp.address);
	printf("\n");


}

void displayAll(char *fileName){
	FILE *fp;
	Employee emp;
	
	fp=fopen(fileName, "rb");
	printf("\nPrinting the details of Employees one by one");
	if(fp==NULL){
		perror("\nError opening file");
		exit(0);
	}
	while(!feof(fp)){
		fscanf(fp, "%d %s %lf %s", &emp.empNo, emp.name, &emp.salary, emp.address);
		display(emp);
	} 
	fclose(fp);
}
	

void search(int empNo, char *fileName){
	FILE *fp;
	Employee emp;
	int result=0;

	fp=fopen(fileName, "rb");
	if(fp==NULL){
		perror("\nError opening file");
		exit(0);
	}
	while(!feof(fp)){
		fscanf(fp, "%d %s %lf %s", &emp.empNo, emp.name, &emp.salary, emp.address);
		if(emp.empNo==empNo){	
			printf("\nEmployee details found are:");	
			display(emp);
			result=1;
			break;
		}
	} 
	fclose(fp);
	
	if(result==0)
		printf("\nNo employee with Employee No:%d is present", empNo);
	
}



int main(){
	int i, ch;
	FILE *fp;
	char *fileName;
	int empNo;
	
	do{
		printf("\n\n# # # # # # # # # # # # # -- MENU -- # # # # # # # # # # # # #");
		printf("\n#                                                            #");
		printf("\n# 1: Add new Employee Record                                 #");
		printf("\n# 2: Search for an Employee Record                           #");
		printf("\n# 3: Display all the records                                 #");		
		printf("\n#                                                            #"); 				  
		printf("\n# # # # # # # # # # # # # # ## # # # # # # # # # # # # # # # #"); 
		printf("\n\nPlease enter your choice(-1 to exit):");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				addNewEmployee("employee");
				break;
			case 2: 
				printf("\nPlease enter the Employee No:");
				scanf("%d", &empNo);
				search(empNo, "employee");
				break;
			case 3:
				displayAll("employee");	
				break;		
			default:

				break;
		}
	}while(ch!=-1);

	return 0;
}
