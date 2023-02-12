#include<stdio.h>
struct student
{
    char name[100];
    int reg;
    int m1,m2,m3,sum;
};

int total(int a,int b,int c)
{
    int abc;
    abc=a+b+c;
    return abc;
}

int main()
{
    int i,j,n;
    struct student s[100];
    struct student temp;
    printf("Enter total number of students : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Student %d :\n",i+1);
        printf("Enter name : ");
        scanf("%s",&s[i].name);
        printf("Enter Reg. No. : ");
        scanf("%d",&s[i].reg);
        printf("Enter Maths marks : ");
        scanf("%d",&s[i].m1);
        printf("Enter Physics marks : ");
        scanf("%d",&s[i].m2);
        printf("Enter Chemistry marks : ");
        scanf("%d",&s[i].m3);
        s[i].sum=total(s[i].m1,s[i].m2,s[i].m3);
        printf("%s : Sum of marks = %d\n",s[i].name,s[i].sum);
    }
    printf("Rank List : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(s[i].sum>s[j].sum)
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
        
    }
    for(i=0;i<n;i++)
    {
        printf("%d.%s = %d\n",i+1,s[i].name,s[i].sum);
    }

    return 0;
}
