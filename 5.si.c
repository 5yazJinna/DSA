#include<stdio.h>
void main()
{
    int p,r,t;
    float si;
    printf("Enter principal :");
    scanf("%d",&p);
    printf("Enter rate of interest :");
    scanf("%d",&r);
    printf("Enter time :");
    scanf("%d",&t);
    si=(p*r*t)/100;
    printf("Simple interest = %f",si);
}