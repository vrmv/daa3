#include <stdio.h>
#include <stdlib.h>
#define N 6

int queue[100];
int front=-1;
int rear=-1;

void enqueue(int a)
{
	rear++;
	if(front==-1)
	{
		front++;
	}
	queue[rear]=a;
	
}

int dequeue()
{
	if(rear==-1 || front>rear)
	{
	printf("cannot dequeue\n");
	return -1;
	}
	int ret;
	ret=queue[front];
	front++;
	return ret;
	}
	
	
	void bfs(int a[N][N],int start,int n)
	{
		int node,i;
		int visited[n];
		
		enqueue(start);
		
		for(i=0;i<n;i++)
		{
		visited[i]=0;
		}
		printf("%d\t",start);
		visited[start]=1;
		
		
		
		while(front<=rear)
		{
			node=dequeue();
			
			for(i=0;i<n;i++)
			{
				while(a[node][i]==1 && visited[i]==0)
				{
					enqueue(i);
					printf("%d\t",i);
					visited[i]=1;
				}
				}
				}
				}
				
				int main()
				{
					int a[N][N],i,j;
	
	for(i=0;i<N;i++){
	for(j=0;j<N;j++){
		scanf("%d",&a[i][j]);
		}
		}
		

	
	bfs(a,0,N);
}
		
		

	
