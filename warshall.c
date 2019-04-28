#include <stdio.h>
#include <stdlib.h>
#define N 4


void warshall(int dist[N][N],int n)
{
	int iter,i,j;

	//Printing graph before applying graph
	printf("Before warshall\n");
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
				if(dist[i][j]>dist[i][iter]+dist[iter][j] && i!=j)
				{
					dist[i][j]=dist[i][iter]+dist[iter][j];
				
				

				}
			}
		}
	}

	//Printing graph after applying graph
	printf("After warshall\n");
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
	

	warshall(a,n);

}
