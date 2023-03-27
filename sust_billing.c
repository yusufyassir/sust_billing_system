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
    struct dat dt;
    char name[30];
    int Class;
    int sal;
}tc1;
int j, i;
FILE *st, *th;
void addrec();
void main(){
    printf("**********wellcome to SUST billing system**********\n\n\n");
    printf("            please enter acount type        \n");
    printf("            1:: students acount     \n");
    printf("            2:: teachers acount     \n");
    printf("            3:: Exit     \n");
    scanf("%d", &i);
    if (i == 3){
        printf("\n***thank you for using our program***\n\n");//prints messagge before closing program
        exit(0);
    }
    system("cls");
    addrec();

}

void addrec(){
    if(i == 1){
        char state = 'y';
        printf("**********adding records**********\n");
        st = fopen("student.txt", "w+");
        fprintf(st, "Name   Class   Date    Paid fees\n");
        while (state == 'y' || state == 'Y' ){
            printf("enter students name: ");
            scanf("%s", st1.name);
            printf("enter students class: ");
            scanf("%d", &st1.Class);
            printf("enter date in m\\d format: ");
            scanf("%d %d", &st1.dt.mm, &st1.dt.dd);
            printf("enter fees: ");
            scanf("%d", &st1.fee);
            fprintf(st, "%s    %d     %d/%d     $%d\n", st1.name, st1.Class, st1.dt.mm, st1.dt.dd, st1.fee);
            printf("enter ( y / Y ) to continue and (q) to exit: ");
            fflush(stdin);
            state = getc(stdin);
        }
        fclose(st);
    }
    if(i == 2){
        char state = 'y';
        printf("**********adding records**********\n");
        st = fopen("teacher.txt", "w+");
        fprintf(st, "Name   Class   Date    Paid fees\n");
        while (state == 'y' || state == 'Y' ){
            printf("enter teachers name: ");
            scanf("%s", tc1.name);
            printf("enter students class: ");
            scanf("%d", &tc1.Class);
            printf("enter date in m\\d format: ");
            scanf("%d %d", &tc1.dt.mm, &tc1.dt.dd);
            printf("enter salary: ");
            scanf("%d", &tc1.sal);
            fprintf(st, "%s    %d     %d/%d     $%d\n", tc1.name, tc1.Class, tc1.dt.mm, tc1.dt.dd, tc1.sal);
            printf("enter ( y / Y ) to continue and (q) to exit: ");
            fflush(stdin);
            state = getc(stdin);
        }
        fclose(st);
    }
}
