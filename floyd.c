#include <stdio.h>
#include <stdlib.h>
# define N 4

void floyd(int dist[N][N],int n)
{
	int i,j,iter;

	//Printing graph before applying graph
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",dist[i][j]);
		}
		printf("\n");
	}

	for(iter=0;iter<n;iter++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dist[i][j]==0)
				{
					if(dist[i][iter]==1 && dist[iter][j]==1 && i!=j)
						dist[i][j]=1;
				}
			}
		}
	}

	//Printing graph after applying graph
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",dist[i][j]);
		}
		printf("\n");
	}


}


int main(){

	int n=N,i,j;

	int a[n][n];
	int b[n][n];

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			b[i][j]=-1;
		}
	}
	

	floyd(a,n);

}
