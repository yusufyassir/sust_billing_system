#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct dat {
/**
 * struct dat - Stores date
 * @mm: month
 * @dd: day
 */
    int mm;
    int dd;
};
struct student{
    /**
 * struct student - store student info
 * @name: students name
 * @class: students class
 * @dat: payment date
 * @fee: paid fee
 */
    struct dat dt;
    char name[30];
    int Class;
    int fee;
}st1;
struct teacher{
      /**
 * struct teacher - store student info
 * @name: teacher name
 * @class: teachers class
 * @dat: payment date
 * @fee: paid salary
 */
    struct dat dt;
    char name[30];
    int Class;
    int sal;
}tc1;
int j, i; // for account type and opp selection
FILE *st, *th;//file handlers
void addrec();// for adding records
void main(){
    printf("**********wellcome to SUST billing system**********\n\n\n");
    printf("            please enter acount type        \n");
    printf("            1:: students acount     \n");
    printf("            2:: teachers acount     \n");
    printf("            3:: Exit     \n");
    scanf("%d", &i);
    if (i == 3){
        printf("\n***thank you for using our program***\n");//prints messagge before closing program
        exit(0);
    }
    system("cls");
    printf("                please enter your choice\n");
    printf("                1:: to add recored\n");
    printf("                2:: to exit\n");
    scanf("%d", &j);
    system("cls");
     if (j == 2){
        printf("\n***thank you for using our program***\n");//prints messagge before closing program
        exit(0);
    }
    addrec();

}

void addrec(){
/**
 * addrec - adds enteries
 * no argements passed
 * Description - takes information from user and stores it in a file
 * Return - void
 */
    if(i == 1){
        char state = 'y';
        printf("**********adding records**********\n");
        st = fopen("student.bin", "wb+");
        while (state == 'y' || state == 'Y' ){
            printf("enter students name: ");
            scanf("%s", st1.name);
            printf("enter students class: ");
            scanf("%d", &st1.Class);
            printf("enter date mm dd ");
            scanf("%d %d", &st1.dt.mm, &st1.dt.dd);
            printf("enter fees: ");
            scanf("%d", &st1.fee);
            fwrite(&st1,sizeof(st1),1,st);
            printf("enter ( y / Y ) to continue and (q) to exit: ");
            fflush(stdin);
            state = getc(stdin);
        }
        fclose(st);
    }
    if(i == 2){
        char state = 'y';
        printf("**********adding records**********\n");
        th = fopen("teacher.bin", "wb+");
        while (state == 'y' || state == 'Y' ){
            printf("enter teachers name: ");
            scanf("%s", tc1.name);
            printf("enter students class: ");
            scanf("%d", &tc1.Class);
            printf("enter date in m\\d format: ");
            scanf("%d %d", &tc1.dt.mm, &tc1.dt.dd);
            printf("enter salary: ");
            scanf("%d", &tc1.sal);
            fwrite(&tc1,sizeof(tc1),1,th);
            printf("enter ( y / Y ) to continue and (q) to exit: ");
            fflush(stdin);
            state = getc(stdin);
        }
        fclose(th);
    }
}
