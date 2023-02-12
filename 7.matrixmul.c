#include<stdio.h>
int main()
{
    int r1,c1,r2,c2,i,j,k,a[10][10],b[10][10],mul[10][10];
    printf("No. of rows of first matrix : ");
    scanf("%d",&r1);
    printf("No. of columns of first matrix : ");
    scanf("%d",&c1);
    printf("Enter the elements of first matrix :\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("No. of rows of second matrix : ");
    scanf("%d",&r2);
    printf("No. of columns of second matrix : ");
    scanf("%d",&c2);
    printf("Enter the elements of second matrix :\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    if (c1==r2)
    {
        printf("Multiply of the matrix :\n");
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                mul[i][j]=0;
                for(k=0;k<c1;k++)
                {
                    mul[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                printf("%d\t",mul[i][j]);
            }
            printf("\n");
        }
    }
    else
    printf("Matrix muliplication not possible");
}