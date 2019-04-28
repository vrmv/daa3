#include <stdio.h>
#include <stdlib.h>

#define N 6

void dij(int a[N][N],int start,int n)
{
	int i,j,done;
	int prev_change[N];
	int next_change[N];
	int dist[N];
	
	for(i=0;i<n;i++)
	{
		dist[i]=99999;
		 prev_change[i]=0;
	         next_change[i]=0;
		
	}
	
	dist[start]=0;
	prev_change[start]=1;
	
	done=0;	
	while(done==0)
	{
		for(i=0;i<n;i++)
		{
			if(prev_change[i]==1)
			{
				for(j=0;j<n;j++)
				{
					if(a[i][j]>0 && dist[i]+a[i][j]<dist[j])
					{
						dist[j]=dist[i]+a[i][j];
						next_change[j]=1;
					}
				}
			}
		}
		
		done=1;
		for(i=0;i<n;i++)
		{
			if(next_change[i]==1)
			{
				done=0;
				break;
			}
		}
		
		for(i=0;i<n;i++)
		{
			prev_change[i]=next_change[i];
			next_change[i]=0;
	        }
			
	}
	
	printf("the distance from %d to all other nodes are\n",start);
	for(i=0;i<n;i++)
	{
		printf("%d\t",dist[i]);
	}
}


int main()
{
		int n=N;
		int i,j;
		int a[N][N];
		int b[N][N];
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
				b[i][j]=-1;
			}
	 }
	 
	 dij(a,0,n);
	 }
