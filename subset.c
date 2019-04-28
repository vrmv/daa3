#include <stdio.h>
#include <stdlib.h>

int n;
//n is the total number of elements in the set
int set[1000],subset[1000];

//Set will contain the elements
// subset[i] will be add(1) or dontadd(0)

void subset_sum(int curr,int sum,int target){
	int i,j;

	if(curr>n || sum+set[curr]>target){
		return;
	}
	
	if(sum+set[curr]==target){
		subset[curr]=1;

		for(i=0;i<n;i++){
			if(subset[i]==1)
				printf("%d,",set[i]);
		}
		printf("\n");
		
		subset[curr]=0;
		return;
	}
	subset[curr]=1;
	sum =sum+set[curr];
	subset_sum(curr+1,sum,target);
	//The above function is including the element curr
	subset[curr]=0;
	sum = sum-set[curr];
	subset_sum(curr+1,sum,target);
	//The above function is without the element curr

}


int main()
{
	
	int i;
	int target;
	//Target will be the sum that i have to reach
	printf("enter number of elements in set\n");
	scanf("%d",&n);  

	printf("enter the elements of the set\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&set[i]);
		subset[i]=0;
	}

	printf("enter the sum to reach\n");
	scanf("%d",&target);
	
	subset_sum(0,0,target);
}