#include"header.h"
int main()
{

    char ch,ch1;
    char name[20];
    do
    {
        system("cls");
        printf("\n\t\t\t---------------------");
        printf("\n\t\t\t Welcome to Gringotts");
        printf("\n\t\t\t---------------------");
        printf("\n\n\n\t\t\t  -----------------");
        printf("\n\t\t\t      LOGIN PAGE");
        printf("\n\t\t\t  -----------------");
        printf("\n\n\n\n\n\t\t\t  1. Login as Admin");
        printf("\n\n\t\t\t  2. Login as User");
        printf("\n\n\t\t\t  3. Exit the Portal");
        printf("\n\n\n\n\nEnter your choice : ");
        ch=getche();
        switch(ch)
        {
            case '1': system("cls");
                            printf("\n\t\t\t---------------------");
                            printf("\n\t\t\t Welcome to Gringotts");
                            printf("\n\t\t\t---------------------");
                            printf("\n\n\n\t\t\tLogin as Admin");
                            admin();
                            break;
            case '2': system("cls");
                            printf("\n\t\t\t---------------------");
                            printf("\n\t\t\t Welcome to Gringotts");
                            printf("\n\t\t\t---------------------");
                            printf("\n\n\n\t\t\tLogin as User");
                            user();
                            break;
            case '3': exit(0);

        }
        printf("\n\n\nDo you wish to visit Home page (y/n)?? ");
        ch1=getche();
        if(ch1=='n')
                exit(1);
    }while(ch1=='y');
return(0);
}


