#include<stdio.h>
struct student{
int rollno;
char name[50];
float mark;
};
union contact{
char phone[15];
char email[50];
};
int main(){
struct student s;
union contact c;
FILE *fp;
printf("Enter student roll number:"); scanf("%d",&s.rollno);
printf("Enter student name:");scanf("%s",s.name);
printf("Enter student mark:");scanf("%f",&s.mark);
printf("Enter phone number:");scanf("%s",c.phone);
fp=fopen("student.txt","w");
if(fp==NULL){
printf("Unable to open file.");
return 0;
}
fprintf(fp,"Roll Number :%d\n",s.rollno);
fprintf(fp,"name     :%s\n",s.name);
fprintf(fp,"Mark    :%.2f\n",s.mark);
fprintf(fp,"Phone   :%s\n",c.phone);
fclose(fp);
printf("\nStudent details written to file successfully.\n");
fp = fopen("student.txt","r");
if(fp == NULL){
printf("Unable to open file.");
return 0;
}
printf("\n-----STUDENT DETAILS -----\n");
while(fscanf(fp,"[^\n]%*c",s.name)== 1){
printf("%s\n",s.name);
}
fclose(fp);
return 0;
}
