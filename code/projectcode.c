#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define y 75
void drawline()
{
    int i;
    for(i=0;i<y;i++)
    {
        printf("-");
    }
}
int main()
{

    struct details{
        char name[100];
        char roll_number[100];
    };
    struct book_detail{
        char bookname[100];
    };
    struct date{
        int day1,month1,year1;
    };
    struct date1{
        int day2,month2,year2;
    };
    struct date d1;
    struct date1 d2;
    struct book_detail b1;
    struct details s1;
    char np[100],anp[100];
    int fine_pay,fine_day,main_menu,p;
    int q,z=0,i,o;
    l1:system("cls");
    drawline();
    printf("\n\t\t\tPASSWORD ENCRYPTED\n");
    drawline();
    printf("\nENTER THE PASSWORD\n");
    char a[100]={"psgtech"};
    char default_password[100];
    scanf("%s",default_password);
    char crt[100];
    char new_password[100];
    if(strcmp(default_password,a)==0)
    {
        printf("CORRECT PASSWORD\n");
        system("pause");
        system("cls");
        drawline();
        printf("\n\t\t\tCHOOSE ONE\n");
        drawline();
        printf("\n1.CHANGE PASSWORD\n2.CONTINUE\n");
        printf("GIVE THE NUMBER FOR THE OPTIONS\n");
        scanf("%d",&o);
        system("cls");
        if(o==1)
        {
            l2:system("cls");
            drawline();
            printf("\n\t\t\tCHANGING PASSCODE\n");
            drawline();
            printf("\nGIVE THE DEFAULT PASSCODE:");
            scanf("%s",default_password);
            if(strcmp(default_password,a)==0)
            {
                printf("GIVE THE NEW PASSWORD:");
                scanf("%s",np);
                printf("GIVE THE NEW PASSWORD AGAIN");
                scanf("%s",anp);
                if(strcmp(np,anp)==0)
                {
                    char infile[50];
                    FILE *fp;
                    fp=fopen("passcode.htm","a+");
                    while(fgets(infile,50,fp));
                    {
                        if(strcmp(infile,anp)==0);
                    }
                    printf("password already exist\n");
                    printf("password is updated\n");
                    fprintf(fp,"%s",np);
                    goto l1;

                    system("pause");
                }
                else
                {
                    printf("PASSWORD DOES NOT MATCH\nGIVE IT AGAIN\n");
                    system("pause");
                    goto l2;
                }
            }
            else
            {
                printf("DEFAULT PASSWORD IS WRONG\n");
                goto l2;
            }
        }
        system("cls");
        drawline();
        printf("\n\t\t\tDETAILS OF THE CANDIDATE\n");
        drawline();
        FILE *pointer;
        pointer=fopen("details.htm","a+");
        printf("\nNAME:");
        scanf("%s",s1.name);
        printf("ROLL NUMBER:");
        scanf("%s",s1.roll_number);
        fprintf(pointer,"%s\t\t\t\t%s\n",s1.name,s1.roll_number);
        fprintf(pointer,"\n");
        system("cls");
        l3:drawline();
        printf("\n\t\t\tMENU FOR THE LIBRARY FUNCTIONALITY\n");
        drawline();
        printf("\n1.GET BOOK ENTRY\n2.RETURN BOOK ENTRY\n3.FIELD OF SEARCHING BOOKS\n4.EXIT\n");
        printf("GIVE THE CORRESPONDING NUMBER TO SELECT THE ABOVE OPTIONS\n");
        int a;
        scanf("%d",&a);
        system("cls");
        switch(a){
        case(2):
        drawline();
        printf("\n\t\t\tRETURN BOOK ENTRY FORM\n");
        drawline();
        printf("\nNAME OF THE BOOK:");
        scanf("%s",b1.bookname);
        printf("GIVE THE BOOK BOUGHT DATE:");
        scanf("%d/%d/%d",&d1.day1,&d1.month1,&d1.year1);
        printf("GIVE THE BOOK RETURN DATE");
        scanf("%d/%d/%d",&d2.day2,&d2.month2,&d2.year2);
        if(d1.month1<d2.month2)
        {
            {
                if(d2.day2>d1.day1)
                {
                    printf("FINE HAS TO BE PAYED\n");
                    fine_day=d2.day2-d1.day1;
                    fine_pay=fine_day*10;
                    printf("YOUR FINE IS:%d\n",fine_pay);
                }
            }
        }
        else if(d1.month1==d2.month2)
        {
            printf("NO FINE TO BE PAYED\n");
            printf("YOUR RETURN ENTRY FORM IS BEEN SUBMITTED\nSUBMIT IT WITHIN 2 DAY OF ENTRY OFFLINE");
        }
        printf("PRESS 1 TO RETURN TO THE MAIN MENU");
        scanf("%d",&main_menu);
        if(main_menu==1)
        {
            goto l3;
        }
        break;
        system("cls");
        case(1):
        drawline();
        printf("\n\t\t\tGET BOOK ENTRY\n");
        drawline();
        printf("\nGIVE THE BOOK NAME THAT HAS TO BE TAKEN:");
        scanf("%s",b1.bookname);
        printf("DATE WHEN BOOK TAKEN:");
        scanf("%d/%d/%d",&d1.day1,&d1.month1,&d1.year1);
        if(d1.month1==1){


        if(d1.day1==29)
        {
            printf("YOUR BOOK HAS BEEN REGISTERED\n");
            printf("THE BOOK HAS TO BE RETURNED WITHIN 1/3/%d\n",d1.year1);
            printf("OR FINE HAS TO BE PAYED\n\nFINE WILL BE BASED ON THE LATE SUBMISSION DATE\n");
        }
        if(d1.day1==30)
        {
            printf("YOUR BOOK HAS BEEN REGISTERED\n");
            printf("THE BOOK HAS TO BE RETURNED WITHIN 2/3/%d\n",d1.year1);
            printf("OR FINE HAS TO BE PAYED\n\nFINE WILL BE BASED ON THE LATE SUBMISSION DATE\n");
        }
        if(d1.day1==31)
        {
            printf("YOUR BOOK HAS BEEN REGISTERED\n");
            printf("THE BOOK HAS TO BE RETURNED WITHIN 3/3/%d\n",d1.year1);
            printf("OR FINE HAS TO BE PAYED\n\nFINE WILL BE BASED ON THE LATE SUBMISSION DATE\n");

        }
        }
        else
        {
            printf("YOUR BOOK HAS BEEN REGISTERED\n");
            printf("THE BOOK HAS TO BE WRITTEN WITHIN %d/%d/%d\nOR FINE HAS TO BE PAYED\n\nFINE WILL BE BASED ON THE LATE SUBMISSION DAYS\n",d1.day1,d1.month1+1,d1.year1);
        }
        break;
        case(4):
        goto l4;
        l4:printf("THankyou for using our system");
        break;
    }
}
    else{
        printf("INCORRECT PASSWORD\nGIVE THE CORRECT PASSWORD\n");
        system("pause");
        goto l1;
    }

}


