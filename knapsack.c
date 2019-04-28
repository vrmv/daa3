#include <stdio.h>
#include <stdlib.h>
#define N 3


void knapsack(int *val,int *wt,int n,int maxwt){

	int profit[n+1][maxwt+1];
	int i,w;
	for(i=0;i<n+1;i++)
	{
		for(w=0;w<maxwt+1;w++)         //w is like j for traversing matrix
		{
			if(i==0||w==0)
			{
				profit[i][w]=0;
				continue;
			}
			if(wt[i-1]<=w)
			{

				if(profit[i-1][w]>profit[i-1][w-wt[i-1]]+val[i-1]){
					profit[i][w]=profit[i-1][w];
				}else{
					profit[i][w]=profit[i-1][w-wt[i-1]]+val[i-1];
				}
				
			}
			else
			{
				profit[i][w]=profit[i-1][w];
			}
		}
	}


	printf("maximum profit is %d",profit[n][maxwt]);

}

int main()
{
	int n=N;
	int val[N],wt[N],max;
	int i;

	printf("enter max weight of knapsack\n");
	scanf("%d",&max);

	printf("enter the weights and values of %d elements\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&wt[i],&val[i]);
	}
	
	knapsack(val,wt,n,max);
}
