#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
    int i=0,x,y,age[100],j,k,c1,l,flag=0,arr[100][100],no;
    long int number[100];
    char name[100][100],address[100][100],blood[100][100];
    l3:printf("\tEnter your location\n\t1 for Aruppukkottai\n\t2 for Virudhunagar\n\t3 for Sattur\n\t4 for Sivakasi\n\t5 for Srivilliputhur\n\t6 for Rajapalayam\n\t7 for Kariapatti\n\t8 for Thiruchuli\n");
    scanf("%d",&l);
    FILE *out;
    arr[1][3]=1;
    arr[0][2]=2;
    arr[1][2]=3;
    arr[1][1]=4;
    arr[0][1]=5;
    arr[1][0]=6;
    arr[0][3]=7;
    arr[0][4]=8;
    if(l==1)
    {
        out = fopen("Aruppukkottai.htm","a+");
        x=1;
        y=3;
    }
    else if(l==2)
    {
        out = fopen("Virudhunagar.htm","a+");
        x=0;
        y=2;
    }
    else if(l==3){
        out = fopen("Sattur.htm","a+");
        x=1;
        y=2;
    }
    else if(l==4){
        out = fopen("Sivakasi.htm","a+");
        x=1;
        y=1;
    }
    else if(l==5){
        out = fopen("Srivilliputhur.htm","a+");
        x=0;
        y=1;
    }
    else if(l==6){
        out =fopen("Rajapalayam.htm","a+");
        x=1;
        y=0;
    }
    else if(l==7){
        out = fopen("Kariapatti.htm","a+");
        x=0;
        y=3;
    }
    else if(l==8){
        out = fopen("Thiruchuli.htm","a+");
        x=0;
        y=4;
    }
    else
    {
        printf("Invalid input\nTry again");
        goto l3;
    }
    l4:l2:l1:printf("Enter 1 to volunteer for the program (or) \nEnter 2 to look for blood donors (or)\nEnter 3 to exit\n");
    scanf("%d",&c1);
    if(c1!=1&&c1!=2&&c1!=3)
    {
        printf("Invalid input\nTry again\n");
        goto l1;
    }
    switch(c1)
    {
        case 1:
                fseek(out,0,SEEK_END);
                printf("Enter name\n");
                scanf("%s",name[i]);
                printf("Enter age\n");
                scanf("%d",&age[i]);
                if(age[i]<18||age[i]>65)
                {
                    printf("You are too young to donate blood\n");
                    goto l4;
                }
                printf("Enter address\n");
                scanf("%s",address[i]);
                printf("Enter contact number\n");
                scanf("%ld",&number[i]);
                printf("Enter blood type\n");
                scanf("%s",blood[i]);
                fprintf(out,"%-30s%-15d%-70s%-30s%-10ld\n",name[i],age[i],address[i],blood[i],number[i]);
                i++;
                goto l2;
    case 2:
                printf("Enter Blood type\n");
                char b;
                scanf("%*c%c",&b);
                flag=0;
                i=0;
                printf("Donors available in your locality\n");
                fseek(out,1,SEEK_SET);
                while(!feof(out))
                {

                    if(blood[i]==b)
                    printf("%-30s%-15d%-70s%-30s%-10ld\n\n\n\n",name[i],age[i],address[i],blood[i],number[i]);
                    i++;
                }
                for(j=0;j<3;j++)
                {
                    for(k=0;k<5;k++)
                    {
                        if((x==j-1&&y==k-1)||(x==j-1||y==k)||(x==j-1&&y==k+1)||(x==j&&y==k-1)||(x==j&&y==k+1)||(x==j+1&&y==k-1)||(x==j+1&&y==k+1))
                        {
                            no = arr[j][k];
                        }
                    }
                }
                if(no==1)
                {
                    out = fopen("Aruppukkottai.htm","a+");
                    i=0;
                    while(!feof(out))
                    {
                        if(blood[i]==b)
                        printf("%-30s%-15d%-70s%-30s%-15ld\n\n\n\n",name[i],age[i],address[i],blood[i],number[i]);
                        i++;
                    }
                }
                else if(no==2)
                {
                    out = fopen("Virudhunagar.htm","a+");
                    i=0;
                    while(!feof(out))
                    {
                        if(blood[i]==b)
                        printf("%-30s%-15d%-70s%-30s%-15ld\n\n\n\n",name[i],age[i],address[i],blood[i],number[i]);
                        i++;
                    }
                }
                else if(no==3){
                    out = fopen("Sattur.htm","a+");
                    i=0;
                    while(!feof(out))
                    {
                        if(blood[i]==b)
                        printf("%-30s%-15d%-70s%-30s%-15ld\n\n\n\n",name[i],age[i],address[i],blood[i],number[i]);
                        i++;
                    }
                }
                else if(no==4){
                    out = fopen("Sivakasi.htm","a+");
                    i=0;
                    while(!feof(out))
                    {
                        if(blood[i]==b)
                        printf("%-30s%-15d%-70s%-30s%-15ld\n\n\n\n",name[i],age[i],address[i],blood[i],number[i]);
                        i++;
                    }
                }
                else if(no==5){
                    out = fopen("Srivilliputhur.htm","a+");
                    i=0;
                    while(!feof(out))
                    {
                        if(blood[i]==b)
                        printf("%-30s%-15d%-70s%-30s%-15ld\n\n\n\n",name[i],age[i],address[i],blood[i],number[i]);
                        i++;
                    }
                }
                else if(no==6){
                    out =fopen("Rajapalayam.htm","a+");
                    i=0;
                    while(!feof(out))
                    {
                        if(blood[i]==b)
                        printf("%-30s%-15d%-70s%-30s%-15ld\n\n\n\n",name[i],age[i],address[i],blood[i],number[i]);
                        i++;
                    }
                }
                else if(no==7){
                    out = fopen("Kariapatti.htm","a+");
                    i=0;
                    while(!feof(out))
                    {
                        if(blood[i]==b)
                        printf("%-30s%-15d%-70s%-30s%-15ld\n\n\n\n",name[i],age[i],address[i],blood[i],number[i]);
                        i++;
                    }
                }
                else {
                    out = fopen("Thiruchuli.htm","a+");
                    i=0;
                    while(!feof(out))
                    {
                        if(blood[i]==b)
                        printf("%-30s%-15d%-70s%-30s%-15ld\n\n\n\n",name[i],age[i],address[i],blood[i],number[i]);
                        i++;
                    }
                }

        case 3:
                fclose(out);
                exit(0);
    }
    return 0;
}
