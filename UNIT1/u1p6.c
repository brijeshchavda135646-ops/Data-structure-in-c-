//delete the element from the array of size 10
#include<stdio.h>
#include<conio.h>
void main()
{
    int i,arr[10],d,n=10;
    printf("\n Enter the value in array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        printf("\n%d",arr[i]);
    }
    printf("\n Enter the value you want to delete:");
    scanf("%d",&d);
    if(d<1||d>n)
    {
        printf("invalid position");
    }
    else
    {
    for(i=d-1 ; i<n-1 ; i++)
    {
            arr[i]=arr[i+1];
    }
    n--;
    }
    for(i=0;i<n;i++)
    {
        printf("\t %d",arr[i]);
    }
    getch();
}
