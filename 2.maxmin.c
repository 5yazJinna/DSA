#include<stdio.h>
void main()
{
    int i,n,num[20],max,min;
    printf("Enter the number of elements :");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i=0;i<n;i++)
    scanf("%d",&num[i]);
    max=num[0];
    for(i=1;i<n;i++)
    {
        if(num[i]>max)
        max=num[0];
    }
    printf("Maximum = %d\n",max);
    min=num[0];
    for(i=1;i<n;i++)
    {
        if(num[i]<min)
        min=num[i];
    }
    printf("Minimum = %d,min");
}