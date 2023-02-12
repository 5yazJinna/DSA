#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[],int low,int high)
{
    int pivot=arr[high],i=low-1,j;
    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int p=partition(arr,low,high);
        sort(arr,low,p-1);
        sort(arr,p+1,high);
    }
}
void display(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
	int arr[100],n,i;
    printf("Enter number of elements to be sorted : ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
	sort(arr,0,n-1);
    printf("Sorted elements : \n");
	display(arr, n);
}