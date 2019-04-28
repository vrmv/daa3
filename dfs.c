#include <stdio.h>
#include <stdlib.h>
#define N 6
int stack[100];
int top=-1;
int max=100;

void push(int elem)
{
if(top==(max-1))
{
printf("stack is full\n");

}
else
{
top++;
stack[top]=elem;
}
}

int pop()
{
if(top==-1)
{
printf("stack is empty\n");

}
else
{
int ret;
ret=stack[top];
top--;
return ret;
}
}

void dfs(int a[N][N],int start,int n)
{
int node,i;


int visited[n];
push(start);
for(i=0;i<n;i++)
{
visited[i]=0;
}

printf("%d\t",start);


visited[start]=1;

while(top!=-1)
{
node=pop();

for(i=0;i<n;i++)
{

if(a[node][i]==1 && visited[i]==0)
{
push(node);
push(i);
printf("%d\t",i);
visited[i]=1;
break;
}
}
}
}

int main(){
	int a[N][N],i,j;
	
	for(i=0;i<N;i++){
	for(j=0;j<N;j++){
		scanf("%d",&a[i][j]);
		}
		}
		

	
	dfs(a,0,N);
}
