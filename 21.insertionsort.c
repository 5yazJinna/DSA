#include <math.h>
#include <stdio.h>
void display(int arr[], int n)
{
	int i;
	for (i=0;i<n;i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void sort(int arr[], int n)
{
	int i,temp,j;
	for (i=1;i<n;i++)
	{
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
	}
}
int main()
{
	int arr[100],n,i;
    printf("Enter number of elements to be sorted : ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
	sort(arr, n);
    printf("Sorted elements : \n");
	display(arr, n);
	return 0;
}
