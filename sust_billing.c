#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct dat {
    int mm;
    int dd;
};
struct student{
    struct dat dt;
    char name[30];
    int Class;
    int fee;
}st1;
struct teacher{
    struct dat;
    char name[30];
    int Class;
    int sal;
}tc1;
int j, i;
FILE *st, *th;
void addrec();
void main(){
    printf("**********wellcome to SUST billing system**********\n");
    printf("        please enter acount type        \n");
    printf("        1:: students acount     \n");
    printf("        2:: teachers acount     \n");
    scanf("%d", &i);
    system("cls");
addrec();

//if(i == 1){
//    printf("enter students name: ");
//    scanf("%s", st1.name);
//    printf("enter students class: ");
//    scanf("%d", &st1.Class);
//    printf("enter date in m\\d format: ");
//    scanf("%d %d", &st1.dt.mm, &st1.dt.dd);
//    printf("enter fees: ");
//    scanf("%d", &st1.fee);
//    st = fopen("student.txt", "w");
//    fprintf(st, "Name   Class   Date    Paid fees\n");
//    fprintf(st, "%s    %d     %d/%d     $%d", st1.name, st1.Class, st1.dt.mm, st1.dt.dd, st1.fee);
 //   fclose(st);
//}
}
void addrec(){
    if(i == 1){
    printf("enter students name: ");
    scanf("%s", st1.name);
    printf("enter students class: ");
    scanf("%d", &st1.Class);
    printf("enter date in m\\d format: ");
    scanf("%d %d", &st1.dt.mm, &st1.dt.dd);
    printf("enter fees: ");
    scanf("%d", &st1.fee);
    st = fopen("student.txt", "w");
    fprintf(st, "Name   Class   Date    Paid fees\n");
    fprintf(st, "%s    %d     %d/%d     $%d", st1.name, st1.Class, st1.dt.mm, st1.dt.dd, st1.fee);
    fclose(st);
}
}
