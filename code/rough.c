#include <stdio.h>
#include <stdlib.h>
int main()
{
    /*int n,i,j;
    int *ptr;
    printf("Give the number of array elements:\n");
    scanf("%d",&n);
    printf("Give the array elements:");
    (int*)malloc(n*sizeof(int));
    if(ptr==NULL)
    {
        printf("memory not allocated");

    }
    else
    {
        //printf("memory allocated");
        //get input for array
        for(i=0;i<n;i++)
        {
            //ptr[i]=i+1;
            scanf("%d",&ptr[i]);
        }
        //print the array elements
        printf("The array elements are:\n");
        for(i=0;i<n;i++)
        {
            printf("%d",ptr[i]);
        }

    }

    return 0;*/
    int i,j,k,n,a[100],b[100],c[100];
    printf("Give the number of array elements:\n");
    scanf("%d",&n);
    printf("Give the array1 elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Give the array2 elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
    {
        c[i]=a[i];
    }
    k=i;
    for(i=0;i<n;i++)
    {
        c[k]=b[i];
        k++;
    }
    int m=2*n;
    /*printf("The merged array is:\n");
    for(i=0;i<k;i++)
    {
        printf("%d",c[i]);
    }*/
    int temp;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(c[i]<c[j])
            {
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }
        }
    }
    //printf("THe sortedarray is:\n");
    /*for(i=0;i<m;i++)
    {
        printf("%d",c[i]);
    }*/
    int x;
    for(i=0;i<m;i++)
    {
        x=c[n-1]+c[n];
    }
    printf("THe addition of middle number is:%d",x);

}
