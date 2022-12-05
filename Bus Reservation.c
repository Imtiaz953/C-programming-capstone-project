#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct details {

      char first_name[30];
      char last_name[30];
      char user_name[30];
      char password[20];
      int traveller_age[32];

};
char ch[10][30]={"Green Lines","Hanif Paribahan","Shamoly Paribahan","Shohagh Paribahan","Ena Express","Eagle Paribahan"};
char name[32][100]={'\0'};
char number[32][100]={'\0'};
int num1[32]={0};
int bsno;
void registration();
void login();
void homepage();
void bus();  //for list of bus
void name_number(int booking, char numstr[100]);
void booking();    //for booking the tickets
int read_number();   //for reading the number from the file
void read_name();  //for reading the name from the file
void status();  //for printing the status by user input
void status_1(); //for printing the status while booking ticket
void cancel();   // ticket cancel

int main(){
    // for using registration or login

    int option;
    printf("                                  Welcome to bus reservation system\n\n\n\n");
    printf("                Press 1 to Registration\n                Press 2 to Login\n");
    scanf("%d",&option);


    if(option == 1){
        system("CLS");
        registration();
    }
    else if(option == 2){
        system("CLS");
       login();
        homepage();
    }

    return 0;
}
void homepage(){
    int num;
    do{
    system("cls");
    printf("\n\n\n");
    printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
    printf("\t\t\t\t\t[1]=> View Bus List\n");
    printf("\n");
    printf("\t\t\t\t\t[2]=> Book Tickets\n");
    printf("\n");
    printf("\t\t\t\t\t[3]=> Cancle Booking\n");
    printf("\n");
    printf("\t\t\t\t\t[4]=> Bus Status Board\n");
    printf("\n");
    printf("\t\t\t\t\t[5]=> Exit\n\n");
    printf("===============================================================================================================\n\n");
    printf("\t\t\tEnter Your Choice: ");
    scanf("%d",&num);
    switch(num)
    {
      case 1:
        bus();//for list of bus
        break;
      case 2:
        booking();//for booking the tickets
        break;
      case 3:
        cancel();
        break;
      case 4:
        status();
        break;
    }
     getch();

    }while(num != 5);
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");

    getch();
    login();
    registration();
    return 0;
}
void registration(){
    char first_name[30];
    FILE*log;

    log = fopen("login.text","w");

    struct details l;

    printf("\nWelcome to our Site. For Bus Reservation we need some details about yours.\n\n");
    fflush(stdin);
    printf("\nEnter your First Name:\n");
    scanf("%c",l.first_name);

    fflush(stdin);
    printf("\nEnter your Last Name:\n");
    scanf("%s",l.last_name);

    printf("\nEnter your Age:\n");
    scanf("%d",l.traveller_age);

    printf("\nThank You.\nNow please choose a username and password for login system.\nAnd ensur that the username is no more than 30 characters long.");

    printf("\nEnter Username:\n");
    scanf("%s",l.user_name);

    printf("\nEnsure that your password is at least 8 characters long and contains ( charcter, symbol and numbers)\n");
    printf("\nEnter your password:\n");
    scanf("%s",l.password);

    fwrite(&l,sizeof(l),1,log);
    fclose(log);

    printf("\nWelcome to our site\n");
    printf("\nNow login with Username and Password.\n");
    printf("Press any key to Continue....");

    getch();
    system("CLS");
    login();
    homepage();
}
void login(){
     char user_name[30],password[30];
     FILE*log;

     log = fopen("login.text","r");

     struct details l;

     printf("\nPlease Enter your login credentials below\n\n");

     fflush(stdin);
     printf("Username:");
     scanf("%s",&user_name);

     printf("\nPassword:\n");
     scanf("%s",&password);

      while(fread(&l,sizeof(l),1,log))
        {
        if(strcmp(user_name,l.user_name)==0 && strcmp(password,l.password)==0)

            {
                printf("\nSuccessful Login\n");
            }
        else
            {
                printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
            }
        }

    fclose(log);

    return;
}
void bus()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n",ch[1]);
    printf("\n");
	printf("\t\t\t\t\t[3]  =>  %s\n",ch[2]);
    printf("\n");
	printf("\t\t\t\t\t[4]  =>  %s\n",ch[3]);
    printf("\n");
	printf("\t\t\t\t\t[5]  =>  %s\n",ch[4]);
	printf("\n");
	printf("\t\t\t\t\t[6]  =>  %s\n",ch[5]);
    printf("\n");
	printf("\t\t\t\t\t[7]  =>  %s\n",ch[6]);
}
void booking(){
    int i=0;
    char numstr[100];

    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for entering bus number
    bus();//for seeing bus least

    printf("Enter the Bus number: ");
    scanf("%d",&bsno);

    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for selecting coach
    printf("Your Bus Number is %d ********** %s",bsno,ch[bsno-1]);
    status_1(bsno);
    FILE *f1, *fopen();//for reading the seats from the user.

    char str1[80]="32";
    int seat1,seat2,booking=0;

    if(bsno == 1){

       f1 = fopen("bus1.text","r+");
       fgets(str1,80,f1);
       fclose(f1);
    }
    else if(bsno == 2){

       f1 = fopen("bus2.text","r+");
       fgets(str1,80,f1);
       fclose(f1);
    }
    else if(bsno == 3){

       f1 = fopen("bus3.text","r+");
       fgets(str1,80,f1);
       fclose(f1);
    }
    else if(bsno == 4){

       f1 = fopen("bus4.text","r+");
       fgets(str1,80,f1);
       fclose(f1);
    }
    else if(bsno == 5){

       f1 = fopen("bus5.text","r+");
       fgets(str1,80,f1);
       fclose(f1);
    }
    else if(bsno == 6){

       f1 = fopen("bus6.text","r+");
       fgets(str1,80,f1);
       fclose(f1);
    }
    else if(bsno == 7){

       f1 = fopen("bus7.text","r+");
       fgets(str1,80,f1);
       fclose(f1);
    }

   seat1=atoi(str1);//covert the string into number
   if(seat1 <= 0){

      printf("There is no blank seat in this bus ");
      }

    else
    {
      printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n",seat1);
      printf("\n\t\t\t\tNumber of Tickets:----->");
      scanf("%d",&booking);
      printf("\n");

      seat1=seat1-booking;
      itoa(bsno,numstr,10);
      name_number(booking,numstr);
      printf("\n\t\t\t\tThe Total booking amount is %d",200*booking);
      itoa(seat1, str1, 10);

    }
}

void name_number(int booking, char numstr[100]){

    char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";

    int number;
    FILE *a,*b;
    int i=0;
    strcat(numstr,".txt");
    strcat(tempstr1,numstr);
    strcat(tempstr2,numstr);
    a = fopen(tempstr1,"a");//for open the file to write the name in the file
    b = fopen(tempstr2,"a");//for open the file for writing the number in the file


    for(i=0; i<booking; i++)//for entering the person name and seat number in the file
    {

         printf("============================Enter the details for ticket no %d============================\n\n\n",i+1);
         fflush(stdin);
         printf("\t\t\t\tEnter the seat number:--->");
         scanf("%d",&number);

         fflush(stdin);
         printf("\t\t\t\tEnter the name of person:--->");
         scanf("%s",name[number-1]);
         printf("\n======================================================================================================\n\n");
         printf("\n");
         itoa(number, tempstr, 10);
         fprintf(a,"%s ",name[number-1]);
         fprintf(b,"%s ",tempstr);

     }

fclose(a);
fclose(b);

  homepage();

}

int read_number(int bsno) //for putting the numeric value in the array
{
    char tempstr[100],tempstr2[12]="number";
    FILE *a;

    char numstr[100];
    int i=0,j=0,k;

    itoa(bsno,numstr,10);
    strcat(numstr,".txt");
    strcat(tempstr2,numstr);

    a = fopen(tempstr2,"a+");//for open the file to write the name in the file

    while(!feof(a)){

            number[i][j] = fgetc(a);

           if(number[i][j] == ' '){

               j=0;
               i++;
           }
           else{

               j++;
            }
   }

   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}

void read_name(int bsno)// for putting the numerical value in the array
{
    char tempstr1[12]="status";
    FILE *b;

    char numstr[100];
    int i=0,j=0,k=0;
    itoa(bsno,numstr,10);
    strcat(numstr,".txt");
    strcat(tempstr1,numstr);

    b = fopen(tempstr1,"a+");//for open the file to write the name in the file

   while(!feof(b)){

        name[i][j] = fgetc(b);

        if(name[i][j] == ' '){

                j=0;
                i++;
        }
        else{
        j++;
        }
   }

   name[i][j]='\0';
   k=i;
   fclose(b);
}

void status(){
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,trno,index=0,j;
    printf("Enter the number of bus:---->");
    scanf("%d",&bsno);
    j=read_number(bsno);
    read_name(bsno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n",bsno,ch[bsno-1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
}
void status_1(int bsno){
    printf("Your Bus Number is %d ********** %s",bsno,ch[bsno-1]);
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");

    int i,index=0,j;
    j=read_number(bsno);
    read_name(bsno);
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}

}
void cancel(){
    int seat_no,i,j;
    char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
    printf("Enter the bus number:---->");
    scanf("%d",&bsno);

    itoa(bsno,numstr,10);
    strcat(numstr,".txt");
    strcat(tempstr1,numstr);
    strcat(tempstr2,numstr);
    read_number(bsno);
    read_name(bsno);
    status_1(bsno);

    printf("Enter the seat number:--->");
    scanf("%d",&seat_no);
    FILE *a,*b;

    a = fopen(tempstr1,"w+");
    b = fopen(tempstr2,"w+");

    for(i=0; i<32; i++){

     if(num1[i] == seat_no){

         for(j=0; j<32; j++){

             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
 }

fclose(a);
fclose(b);

printf("\n\n");
    printf("======================================================================================================\n");
 printf("\t\t\t\tYour Ticket cancel has been successful ;\t\t\t\n");
    printf("======================================================================================================\n");

}
