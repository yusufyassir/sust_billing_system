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
void delrec(int j); //for deleting records
void fees(); //to see fees
void salary(int mm); //to see salary
int chkdat(int mnt,int dnt); //to check date
int check_class(); //to check class

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
void delrec(int j)
{
    system("cls");
    printf("\n\t******************************************************************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t*********************          DELETE RECORD     *******************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t******************************************************************");
    FILE *temp,*t1;
    FILE *fs;
    FILE *ft;
    int a=1;
    char name[50],c='y';
    if (j==1)
    {
        while(c=='y'||c=='Y')
        {
            int a=1;
            printf("\n\nenter name of student to delete: ");
            fflush(stdin);
            scanf("%[^\n]",name);
            fs=fopen("student","rb");
            temp=fopen("tempfile","wb");//opening of temporary file for deleting process
            while (fread(&st1,sizeof(st1),1,fs)==1)
            {
                if (strcmp(st1.name,name)==0)
                {
                    a=0;
                    continue;
                }
                else
                {
                    fwrite(&st1,sizeof(st1),1,temp);
                }
            }

            if (a==1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  DELETED");
            printf("\n\n");
            system("pause");
            fflush(stdin);

            fclose(fs);
            fclose(temp);
            system("del student");/*all data except the data to be
            deleted in student were 1st moved to temp and data in student
            was deleted*/
            system("ren tempfile, student");//renaming temp to student
            printf("\n\nDo you want to continue with the process(press y or Y");
            fflush(stdin);
            c=getch();
        }
        getch();
    }

    if (j==2)
    {
        a=1;
        char namet[50];
        while(c=='y'||c=='Y')
        {
            printf("\n\nEnter name of teacher to delete record: ");
            fflush(stdin);
            scanf("%[^\n]",namet);
            ft=fopen("teacher","rb");
            t1=fopen("tempfile1","wb");
            while (fread(&tc1,sizeof(tc1),1,ft)==1)
            {
                if (strcmp(tc1.name,namet)==0)
                {
                    a=0;
                    continue;
                }
                else
                {
                    fwrite(&tc1,sizeof(tc1),1,t1);
                }
            }

            if (a==1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  DELETED");
            printf("\n\n");
            system("pause");
            fflush(stdin);

            fclose(ft);
            fclose(t1);
            system("del teacher");
            system("ren tempfile1, teacher");
            printf("\n\nDo you want to continue with the process(press y or Y");
            fflush(stdin);
            c=getch();
        }
        getch();
    }
}
void fees()
{
    if(i == 1 && j == 2){
    int mm;
    system("cls");
    FILE *files,*temp_f;
    int p=0;
    char name_s[30],cs='y';
    int clss, Class_num,monthss,diffs;
    while(cs=='y'||cs=='Y')
    {
        int p=1,day=0;
        fflush(stdin);
        printf("\n\nEnter name:: ");
        scanf("%s",name_s);
        printf("\n\nEnter class:: ");
        fflush(stdin);
        clss=check_class();
        files=fopen("student.bin","rb+");
        temp_f=fopen("te","wb+");
        while(fread(&st1,sizeof(st1),1,files)==1)
        {
            if(strcmp(st1.name,name_s)==0 && clss==st1.Class)
            {
                p=0;
                printf("\n\nEnter the month till which fee to be paid:: ");
                fflush(stdin);
                scanf("%d",&monthss);
                diffs=mm-st1.dt.mm;
                st1.debt=(diffs*st1.fee)*0.01;
                st1.duedate=(diffs)*st1.fee;
                if (st1.debt<0) st1.debt=0;
                if (st1.duedate<0) st1.duedate=0;
                if (st1.total<0) st1.total=0;
                st1.total=st1.debt+st1.duedate+st1.advanced;
                printf("\nfine :: %.2f",st1.debt);
                printf("\ndue :: %.2f",st1.duedate);
                printf("\ntotal :: %.2f",st1.total);
                printf("\nadvance :: %.2f",st1.advanced);
                st1.dt.mm=monthss;
                st1.total=0;
                st1.debt=0;
                st1.duedate=0;
                fwrite(&st1,sizeof(st1),1,temp_f);
            }
        }
        if (p==1)
            printf("\n\nRECORD NOT FOUND");
        printf("\n\n");
        system("pause");
        fflush(stdin);

        fclose(files);
        fclose(temp_f);
        system("del student.bin");
        system("ren te, student.bin");
        printf("\n\nDo you want to continue with the process(press y or n");
        fflush(stdin);
        cs=getch();
    }
    getch();
}
;}
void salary(int mm)
{
    system("cls");
    FILE *f,*t;
    int a=1,day;
    char name[30],c='y';
    int month,dif,id;
    while(c=='y'||c=='Y')
    {
        int a=1;
        fflush(stdin);
        printf("\n\nEnter name:: ");
        scanf("%[^\n]",name);
        printf("\n\nEnter ID:: ");
        scanf("%d",&id);
        f=fopen("teacher.bin","rb+");
        t=fopen("te","wb+");
        while(fread(&tc1,sizeof(tc1),1,f)==1)//file opened
        {
            if(strcmp(tc1.name,name)==0 )//name entered is compared to the existing name in file
            {
                float lsal;
                a=0;
                printf("\n\nEnter the month till which salary is to be paid:: ");
                fflush(stdin);
                scanf("%d",&month);
                month=chkdat(month,day);
                tc1.adv=(month-mm-1)*tc1.sal;
                if (tc1.adv<0) tc1.adv=0;
                lsal=mm-tc1.dt.mm;//months of salary left to be paid
                if(lsal<0) lsal=0;
                tc1.tot=tc1.adv+tc1.sal*(1+lsal);
                if(month==tc1.dt.mm) tc1.tot=0;
                printf("\nmonthy salary left to be paid:: %.2f",lsal);
                printf("\ntotal :: %.2f",tc1.tot);
                printf("\nadvance :: %.2f",tc1.adv);
                tc1.dt.mm=month;
                fwrite(&tc1,sizeof(tc1),1,t);
                fclose(f);
                fclose(t);

                if (a==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                system("del teacher");
                system("ren te, teacher");
            }
        }
        printf("\n\nDo you want to continue with the process(press y or Y");
        fflush(stdin);
        c=getch();
    }
    getch();
}
int chkdat(int mnt,int dnt)
{
    int mon,day;
    if (mnt>12 || mnt<1 || dnt<1 || dnt>32)
    {
        MessageBox(0,"Invalid Date!\nEnter Again","Error!",0);

        fflush(stdin);
        scanf("%d%d",&mon,&day);
        mon=chkdat(mon,day);
    }
    else
        return (mnt);
}



int check_class()
{
    int mntttt,monsss;
    fflush(stdin);
    scanf("%d",&mntttt);
    if (mntttt>12 ||mntttt<1)
    {
        MessageBox(0,"Invalid Class!\nEnter Class","Error!!",0);
        fflush(stdin);
        monsss=check_class();
    }
    else
        return mntttt;
}
