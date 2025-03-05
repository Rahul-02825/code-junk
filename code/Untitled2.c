#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    int fine_pay,fine_day;
    int q;
    l1:printf("\t------------------------------------------------------------\n");
    printf("\t\t\tPASSWORD ENCRYPTED\n");
    printf("ENTER THE PASSWORD\n");
    char a[100]={"psgtech"};
    char default_password[100];
    scanf("%s",default_password);
    char crt[100];
    char new_password[100];
    if(strcmp(default_password,a)==0)
    {
        printf("CORRECT PASSWORD\n");
        printf("----------------------------------------------------------------\n");
        printf("\tDETAILS OF THE CANDIDATE\n");
        printf("name:");
        scanf("%s",s1.name);
        printf("roll number:");
        scanf("%s",s1.roll_number);
        printf("------------------------------------------------------------------\n");
        printf("MENU FOR THE LIBRARY FUNCTIONALITY\n");
        printf("1.return book entry\n2.add book\n3.field of searching books\n4.exit\n");
        printf("GIVE THE CORRESPONDING NUMBER TO SELECT THE ABOVE OPTIONS\n");
        int a;
        scanf("%d",&a);
        switch(a){
        case(1):
        printf("---------------------------------------------------------------------------\n");
        printf("\t\tRETURN BOOK ENTRY FORM\n");
        printf("NAME OF THE BOOK:");
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
        else{
            printf("NO FINE TO BE PAYED\n");
            printf("YOUR RETURN ENTRY FORM IS BEEN SUBMITTED\nSUBMIT IT WITHIN 2 DAY OF ENTRY OFFLINE");
        }
        break;
        }
    }
    else{
        printf("INCORRECT PASSWORD\nGIVE THE CORRECT PASSWORD\n");
        goto l1;
    }

}
