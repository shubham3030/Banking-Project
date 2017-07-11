#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
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

void admin();
void user();
void ufunc(time_t,long int,char []);
void adfunc(char []);

