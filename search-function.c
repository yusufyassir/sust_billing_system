void search_rec(){

    /**
    * Takes number or class from the user and search it in the file
    * @cs:for class
    * @name:for the user naem
    */
int cs,search_class,choice;
char state='y',name[20];
system("cls");
printf("\t\t********** Searching for record \t\t**********\n");
while((state=='y')||(state=='Y')){
    printf("\t\t1:: Search using class\n");
    printf("\t\t2:: Search using name\n");
    printf("\t\t3:: Exit\n");
    printf("\t\t Enter your choice\n");
    fflush(stdin);
    scanf("%d", &choice);
    if(i==1){

            switch(choice) {
                case 3:
                    exit(0);
                    break;
                case 1:
                    printf("Enter student class \n");
                    scanf("%d",&search_class);
                    st = fopen("student.bin","rb+");
                    if(st==NULL){
                        printf("Error opening the file");
                        break;
                    }
                    fseek(st,0,SEEK_SET);
                    while(fread(&cs,sizeof(int),1,st)){
                        if(cs == search_class){
                            printf("Record found!\n");
                            break;
                        }
                        printf("Not found!\n");
                        fclose(st);
                        break;
                    }
                     printf("enter ( y / Y ) to continue and (q) to exit: ");
                    fflush(stdin);
                    state = getc(stdin);
                    break;
                case 3:
                     printf("Enter student name \n");
                 fflush(stdin);
                 scanf("%s", name);
                 st = fopen("student.bin", "rb+");
                 while (fread(&st1, sizeof(st1), 1, st) == 0)
                 {
                     if (strcmpi(name, st1.name) == 0)
                     {
                         printf("Record found \n");
                         return (0);
                     }
                     printf("Record not found \n");
                     return (0);                 }
                 fflush(stdin);
                fclose(st);
                break;


            }
    }
    if(i==2){
        switch(choice) {
                case 3:
                    exit(0);
                    break;
                case 1:
                    printf("Enter teacher class \n");
                    scanf("%d",&search_class);
                    th = fopen("teacher.bin","rb+");
                    if(st==NULL){
                        printf("Error opening the file");
                        break;
                    }
                    fseek(st,0,SEEK_SET);
                    while(fread(&cs,sizeof(int),1,st)){
                        if(cs == search_class){
                            printf("Record found!\n");
                            break;
                        }
                        printf("Not found!\n");
                        fclose(th);
                        break;
                                            }
                case 3:
                    printf("Enter teacher name \n");
                 fflush(stdin);
                scanf("%s", name);
                 th = fopen("teacher.bin", "rb+");
                 while (fread(&tc1, sizeof(tc1), 1, th) == 0)
                 {
                     if (strcmpi(name, tc1.name) == 0)
                     {
                         printf("Record found \n");
                         break;
                     }
                     printf("Record not found \n");
                     break;
                 }
                 fflush(stdin);
                 fclose(th);
                 break;
                     printf("enter ( y / Y ) to continue and (q) to exit: ");
                    fflush(stdin);
                    state = getc(stdin);


            }
    }

}




