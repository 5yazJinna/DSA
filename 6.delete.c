#include <stdio.h>
    void main()
    {
 
        int i,n,num[20];
        printf("Enter the number of elements :");
        scanf("%d",&n);
        printf("Enter the elements :\n");
        for(i=0;i<n;i++)
        scanf("%d",&num[i]);
        for(i=1;i<n;i++)
        {
            num[i]=num[i+1];
        }
        printf("After deleting the second element : \n");
        for(i=0;i<n-1;i++)
        printf("%d\t",num[i]);
    }