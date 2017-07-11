#include"header.h"
/*
struct user
{
        char name[20];                                                                //USER MEMBERS
        char pass[20];
        long int acno;
        long int acbal;
        time_t utime;
}u;

struct admin                                                                                       //ADMIN MEMBERS
{
    char username[20];
    char password[20];
}ad;
*/
char username[20];
char ch,ch1,ch2;
time_t newtime;
long int accno,accn,l=0,secs;
int count=0,flag=0,flg,i;
int roi=10;
char pass[20];
char name[20];

void admin()                                                                                           //ADMIN LOGIN
{
    printf("\n\n\n\tEnter the Adminname: ");
    scanf("%s",name);
    FILE *fp;
    fp=fopen("Admin.txt","r");
    if(fp==NULL)
    {
                puts("\n\nAdmin file cannot be opened!!!");
                exit(1);
    }
        fscanf(fp,"%s%s",ad.username,ad.password);

        do                                                                                                                                               /*Check for Admin username and password*/
         {
                if(strcmp(ad.username,name)==0)
                {
                        printf("\n\tEnter the password: ");
                        while(1)
                        {
                                ch=getch();
                                if(ch==13)
                                        break;
                                pass[i++]=ch;
                                printf("*");
                        }
                        pass[i]='\0';
                        if(strcmp(ad.password,pass)==0)
                                {       printf("\n\n\tPassword match");
                                        printf("\n\n\n\n\n\n\n\n\n\nPress Enter to proceed");
                                        ch=getche();
                                        adfunc(ad.username);
                                }
                        else
                                        printf("\n\n\tYou have entered a wrong password");
                }
                else
                {
                        printf("\n\n\tWrong Username!!!");
                }
                printf("\n\nDo you wish to login again: (y/n)?? ");
                ch=getche();
                if(ch=='y')
                {
                        system("cls");
                        printf("\n\t\t\t---------------------");
                        printf("\n\t\t\t Welcome to Gringotts");
                        printf("\n\t\t\t---------------------");
                        printf("\n\n\n\t\t\tLogin as Admin");
                        printf("\n\n\n\tEnter the Adminname: ");
                        scanf("%s",name);
                }

        }while(ch=='y');
}
void adfunc(char name[])                                                                                                                //ADMIN FUNCTIONS
{
                do
                {
                        system("cls");
                        printf("\n\t\t\t---------------------");
                        printf("\n\t\t\t Welcome to Gringotts");
                        printf("\n\t\t\t---------------------");
                        printf("\n\n\n\t\t\tWelcome %s",name);
                        printf("\n\n\n\t\t\tAdmin Page");
                        printf("\n\n\t1. Signup ");
                        printf("\n\n\t2. Delete an account ");
                        printf("\n\n\t3. Logout");
                        printf("\n\n\tEnter your choice: ");
                        ch1=getche();
                        switch(ch1)
                        {
                                case '1': system("cls");
                                                FILE *fp;
                                                fp=fopen("User.txt","a+");
                                                u.acno=12320;
                                                do
                                                {       system("cls");
                                                        printf("\n\t\t\t---------------------");
                                                        printf("\n\t\t\t Welcome to Gringotts");
                                                        printf("\n\t\t\t---------------------");
                                                        printf("\n\n\n\t\t\tWelcome %s",name);
                                                        printf("\n\n\t\t\tSignup ");
                                                        A:
                                                        printf("\n\n\tEnter the Username : ");
                                                        scanf("%s",username);
                                                        rewind(fp);
                                                        while(fscanf(fp,"%s%s%d%d%d",u.name,u.pass,&u.acno,&u.acbal,&u.utime)!=EOF)                     /*Check for username of user*/
                                                        {
                                                                if(strcmp(u.name,username)==0)
                                                                {
                                                                        printf("\nUsername Already Exists!!");
                                                                        printf("\nDo you wish to try again (y/n)??");
                                                                        ch2=getche();
                                                                        if(ch2=='y')
                                                                                goto A;
                                                                        else
                                                                                goto B;
                                                                }

                                                        }
                                                        printf("\n\tEnter the Password : ");
                                                        i=0;
                                                        while(1)
                                                        {
                                                                        ch=getch();
                                                                        if(ch==13)
                                                                                break;
                                                                        u.pass[i++]=ch;
                                                                        printf("*");
                                                        }
                                                        u.pass[i]='\0';
                                                        u.acno++;
                                                        printf("\n\n\tEnter the Account balance : ");
                                                        scanf("%d",&u.acbal);
                                                        printf("\n\tThe Account no. : %d",u.acno);
                                                        u.utime=time(NULL);
                                                        printf("\n\n\tCreation time: %s",ctime(&u.utime));
                                                        fprintf(fp,"%s %s %d %d %d                 \n",username,u.pass,u.acno,u.acbal,u.utime);
                                                        printf("\n\nAdd another account (y/n)");
                                                        fflush(stdin);
                                                        ch2=getche();
                                                }while(ch2=='y');
                                                B:
                                                fclose(fp);
                                                break;
                                case '2': system("cls");
                                                printf("\n\t\t\t---------------------");
                                                printf("\n\t\t\t Welcome to Gringotts");
                                                printf("\n\t\t\t---------------------");
                                                printf("\n\n\n\t\t\t\t Welcome %s",name);
                                                printf("\n\n\t\t Delete an account ");
                                                FILE *ft;
                                                fp=fopen("User.txt","r+");
                                                ft=fopen("Temp.txt","a+");
                                                printf("\n\n\n\tEnter the account no. : ");
                                                scanf("%d",&accno);
                                                while(fscanf(fp,"%s%s%d%d%d",u.name,u.pass,&u.acno,&u.acbal,&u.utime)!=EOF)
                                                {
                                                        flag=0;
                                                        if(u.acno==accno)
                                                        {
                                                                flag=1;
                                                                rewind(fp);
                                                                while(fscanf(fp,"%s%s%d%d%d",u.name,u.pass,&u.acno,&u.acbal,&u.utime)!=EOF)
                                                                {
                                                                        if(u.acno!=accno)
                                                                                fprintf(ft,"%s %s %d %d %d                 \n",u.name,u.pass,u.acno,u.acbal,u.utime);                                    /*Transfering Data to Temporary File*/
                                                                }
                                                        }
                                                }
                                                fclose(fp);
                                                fclose(ft);
                                                if(flag==1)
                                                {
                                                        printf("\nAccount no. %d Deleted ",accno);
                                                        remove("User.txt");
                                                        rename("Temp.txt","User.txt");
                                                }
                                                else
                                                        printf("\nAccount not found!!!");
                                                break;
                                case '3': main();
                                                break;

                        }
                        printf("\n\nDo you wish to visit Admin page(y/n)??");
                        ch2=getche();
                }while(ch2=='y');
}
void user()                                                                                                         //USER LOGIN
{
        printf("\n\n\n\tEnter the Username. : ");
        scanf("%s",name);
        FILE *fp;
        fp=fopen("User.txt","r");
        if(fp==NULL)
        {
                        puts("\n\nUser file cannot be opened!!!");
                        exit(1);
        }

do                                                                                                                                                                                     /*Check for username and password for user*/
{
        rewind(fp);
        while(fscanf(fp,"%s%s%d%d%d",u.name,u.pass,&u.acno,&u.acbal,&u.utime)!=EOF)
        {
                if(strcmp(u.name,name)==0)
                {
                        flg=1;i=0;
                        printf("\n\tEnter the password: ");
                        while(1)
                        {
                                ch=getch();
                                if(ch==13)
                                        break;
                                pass[i++]=ch;
                                printf("*");
                        }
                        pass[i]='\0';
                        if(strcmp(u.pass,pass)==0)
                                {       printf("\n\n\tPassword match !!");
                                        printf("\n\n\n\n\n\n\n\n\n\nPress Enter to proceed");
                                        ch=getche();
                                        newtime=time(NULL);
                                        ufunc(newtime,u.acno,u.name);
                                }
                        else
                                        printf("\n\n\tYou have entered a wrong password");
                }
        }
        if(flg!=1)
                printf("\n\n\tUsername does not exist!!!");
        printf("\n\nDo you wish to login again: (y/n)?? ");
        ch=getche();
        if(ch=='y')
        {
                system("cls");
                printf("\n\t\t\t---------------------");
                printf("\n\t\t\t Welcome to Gringotts");
                printf("\n\t\t\t---------------------");
                printf("\n\n\n\t\t\tLogin as User");
                printf("\n\n\n\tEnter the Username: ");
                scanf("%s",name);
        }
}while(ch=='y');
}
void ufunc(time_t nwtime,long int accno,char name[])                                                                              //USER FUNCTIONS
{
        FILE *fp;
        fp=fopen("User.txt","r+");
        int count=0;
        while(fscanf(fp,"%s%s%d%d%d",u.name,u.pass,&u.acno,&u.acbal,&u.utime)!=EOF)                             /*Account balance update using rate of interest*/
        {
                count++;
                if(u.acno==accno)
                {
                        secs=difftime(nwtime,u.utime);
                        u.acbal*=(secs*roi)/100;                                                                                                                        /*roi=Rate of Interest initialised with integer value 10*/
                        fseek(fp,l,SEEK_SET);
                        if(count==1)
                                fprintf(fp,"%s %s %d %d %d                 ",u.name,u.pass,u.acno,u.acbal,u.utime);
                        else
                                fprintf(fp,"\n%s %s %d %d %d                 ",u.name,u.pass,u.acno,u.acbal,u.utime);
                        break;
                }
                l=ftell(fp);
        }
        fclose(fp);
        do
        {
                system("cls");
                printf("\n\t\t\t---------------------");
                printf("\n\t\t\t Welcome to Gringotts");
                printf("\n\t\t\t---------------------");
                printf("\n\n\t\t\t\t Hi %s",name);
                printf("\n\n\t1. Display Account Details");
                printf("\n\n\t2. Modify the Details");
                printf("\n\n\t3. Logout ");
                printf("\n\n\tEnter your choice : ");
                ch1=getche();
                switch(ch1)
                {
                        case '1': system("cls");
                                        printf("\n\t\t\t---------------------");
                                        printf("\n\t\t\t Welcome to Gringotts");
                                        printf("\n\t\t\t---------------------");
                                        printf("\n\n\t\t\t\t Hi %s",name);
                                        printf("\n\n\t\t\t Display Account Details ");
                                        FILE *fp;
                                        fp=fopen("User.txt","r");
                                        while(fscanf(fp,"%s%s%d%d%d",u.name,u.pass,&u.acno,&u.acbal,&u.utime)!=EOF)
                                                {
                                                        flag=0;
                                                        if(u.acno==accno)
                                                        {
                                                                printf("\n\n\tUsername => %s",u.name);
                                                                printf("\n\tAccount no. => %d",u.acno);
                                                                printf("\n\tPassword => ");
                                                                for(i=0;u.pass[i]!='\0';i++)
                                                                        printf("*");
                                                                printf("\n\tAccount balance => %d",u.acbal);
                                                                printf("\n\tYour Account Creation Time => %s",ctime(&u.utime));
                                                                flag=3;
                                                                break;
                                                        }
                                                }
                                        if(flag==0)
                                                printf("\n\n\tAccount not Found!!!");
                                        fclose(fp);
                                        break;
                        case '2': system("cls");
                                        printf("\n\t\t\t---------------------");
                                        printf("\n\t\t\t Welcome to Gringotts");
                                        printf("\n\t\t\t---------------------");
                                        printf("\n\n\t\t\t\t Hi %s",name);
                                        printf("\n\n\t\t\t Modify The Details");
                                        fp=fopen("User.txt","r+");
                                        l=0;int cnt=0;
                                        while(fscanf(fp,"%s%s%d%d%d",u.name,u.pass,&u.acno,&u.acbal,&u.utime)!=EOF)
                                                {       flag=0;cnt++;
                                                        if(u.acno==accno)
                                                               {
                                                                        printf("\n\n\tEnter the new name : ");
                                                                        scanf("%s",u.name);
                                                                        printf("\n\tEnter the new Account balance : ");
                                                                        scanf("%d",&u.acbal);
                                                                        printf("\n\tEnter the new Password : ");
                                                                        i=0;
                                                                        while(1)
                                                                        {
                                                                                ch=getch();
                                                                                if(ch==13)
                                                                                        break;
                                                                                u.pass[i++]=ch;
                                                                                printf("*");
                                                                        }
                                                                        u.pass[i]='\0';
                                                                        fseek(fp,l,SEEK_SET);
                                                                        if(cnt==1)
                                                                                fprintf(fp,"%s %s %d %d %d                 \n",u.name,u.pass,u.acno,u.acbal,u.utime);
                                                                        else
                                                                                fprintf(fp,"\n%s %s %d %d %d                 \n",u.name,u.pass,u.acno,u.acbal,u.utime);
                                                                        flag=2;
                                                                        break;
                                                               }
                                                        l=ftell(fp);
                                                }
                                        if(flag==2)
                                                printf("\n\n\tAccount Modified");
                                        else
                                                printf("\n\n\tAccount not found!!!");
                                        fclose(fp);
                                        break;
                        case '3': main();
                                        break;
                }
                printf("\n\nDo you wish to visit User page(y/n)??? ");
                ch2=getche();
        }while(ch2=='y');
}
