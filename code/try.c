#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp;
    fopen("text.txt","w");
    char ch[44];
    strcpy(ch,"ggggg");
    fprintf(fp,"%s",ch);
    fclose(fp);
}
