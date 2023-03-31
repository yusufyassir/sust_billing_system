void search_rec(){

    /**
    * Takes number or class from the user and search it in the file
    * @cs:for class
    * @name:for the user naem
    */
int cs,search_class,choice;
char state='y';
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
            }
    }

}




