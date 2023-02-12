#include <stdio.h>
    void main()
    {
        int i,n,a=0,b=1,fib=0;
        printf("Enter the number of elements to be printed :");
        scanf("%d",&n);
        printf("%d\t%d\t",a,b);
        for(i=0;i<n-2;i++)
        {
            fib=a+b;
            a=b;
            b=fib;
            printf("%d\t",fib);
        }
    }