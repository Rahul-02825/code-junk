#include <stdio.h>
#include <string.h>
int main()
{
    /*int s,min,remd,remh,rems,sec,hours,days;
    printf("Give the seconds:");
    scanf("%d",&s);
    if(s>=60)
    {
        min=s/60;
        rems=s%60;
        printf("The seconds in minutes is:%d and %d seconds",min,rems);
    }
    if(s>=3600)
    {
        hours=s/3600;
        remh=s%3600;
        min=remh/60;
        sec=remh%60;
        printf("The seconds in minutes is:%d and %d seconds and %d seconds",hours,min,sec);
    }
    if(s>=86400)
    {
        days=s/86400;
        remd=s%86400;
        if(remd>60)
        {
            hours=remd/3600;
            min=remd/60;
            sec=remd%60;
            printf("The seconds in days is:%d and %d hours and %d minutes and %d seconds",days,hours,min,sec);
        }
        else
        {
            printf("The seconds in days and seconds is %d and %d:",days,remd);
        }


    }*/
    int i,j,n;
    int array[100];
    char x[10],y[10];
    printf("Give the number of elements in the array:");
    scanf("%d",&n);
    printf("Give the element to be removed:");
    getc(x);
    printf("Give the element to be replaced:");
    //scanf("%c",&y);
    getc(y);
    printf("Give the array elements:\n");
    //for(i=0;i<n;i++)
    //{
        scanf("%s",array[i]);
    //}

    //int flag=0;
    for(i=0;i<n;i++)
    {
        if(array[i]==x)
        {
            array[i]=y;
        }

    }
    //for(i=0;i<n;i++)
    //{
        printf("%s",array[i]);
    //}



}
