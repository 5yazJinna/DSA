#include<stdio.h>
void main()
{
    int i,j,a,n,num[20];
    printf("Enter the number of elements :");
    scanf("%d",&n);
    printf("Enter %d elements :\n",n);
    for(i=0;i<n;++i)
    scanf("%d",&num[i]);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(num[i]>num[j])
            {
                a=num[i];
                num[i]=num[j];
                num[j]=a;

            }
        }
    }
    printf("Elements in ascending order :\n");
    for(i=0;i<n;++i)
    printf("%d\t",num[i]);
}