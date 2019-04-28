#include <stdio.h>
#include <stdlib.h>



 void quicksort(int *arr,int start,int end)
 {
 	int pivot,i,j,temp;
 	if(start<=end)
 	{
 		pivot=arr[end];
 		i=end-1;
 		while(i>=start)
 		{
 			if(arr[i]>pivot)
 			{
 				temp=arr[i];
 				j=i;
 				while(j<end)
 				{
 					arr[j]=arr[j+1];
 					j++;
 				}
 				arr[end]=temp;
 			}
 			i--;
 		}

 		int pos;
 		for(i=start;i<=end;i++)
 		{
 			if(arr[i]==pivot)
 				{
 					pos=i;
 				}
 		}

	quicksort(arr,start,pos-1);
	quicksort(arr,pos+1,end);
 	}
 }


 int main()
{
    int i;
	int a[]={9,8,4,0,9,2,1,4,6,8};
	int n = sizeof(a)/sizeof(int);
	printf("Before sorting\t");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	quicksort(a,0,9);
	printf("After sorting \t");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}

