#include <stdio.h>

#define N 4

int queue[100];
int front =-1,rear =-1;


void enqueue(int a){
	if(front==-1){
		front++;
		rear++;
	}else{
		rear++;
	}
	queue[rear]= a;

}

int dequeue(){
	if(front==-1 || front>rear){
		return -1;
	}
	int ret = queue[front];
	front++;
	return ret;
}

int inqueue(int a){
	int i;
	for(i=front;i<=rear;i++){
		if(queue[i]==a){
			return 1;
		}
	}
	return 0;
}


int cycle(int a[N][N],int n){
	int size = n;
	int parent[n];
	
	int i,j;
	int now;
	int visited[n];
	//visited willgive information about the node i weather is visited or not
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	front=-1;
	rear=-1;
	//queue initialisation
	
	int visit=0; 
	//visit will give you the number of nodes visited till now


	while(visit != n){

		for(i=0;i<n;i++){
			//This is to get the next unvisited node
			if(visited[i]==0){
				now = i;
				parent[now] = -1;
				enqueue(i);
				visit++;
				visited[i]=1;
				break;
			}
		}

		//this is dfs

		while(front<=rear){
			now = dequeue();
			for(i=0;i<n;i++){
				if(a[now][i]>=0 && parent[now]!=i && visited[i]==1){
					//If these three conditions satisfy then there is
					//a cycle in the graph
					return 1;
				}
				if(a[now][i] >=0 && parent[now]!=i){
					enqueue(i);
					parent[i]=now;
					visited[i]=1;
					visit++;
				}
			}
		}
	}
	
	return 0;

}


void kruskals(int a[N][N],int b[N][N],int n){
	int start =0;

	int from,to;
	int i,j,k;

	int min;
	int edge =0;

	while(edge != n-1){

		min = 9999;
		//THIS IS TO FIND THE MINIMUM EDGE
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(a[i][j]<min && a[i][j]!=-1){
					from = i;
					to = j;
					min = a[i][j];
				}
			}
		}

		b[from][to]=a[from][to];
		b[to][from]=a[to][from];
		edge++;
		if(cycle(b,n)==1){
			printf("Removing edge from %d,%d\n",from,to);
			b[from][to]=-1;
			b[to][from]=-1;
			edge--;
		}
		a[from][to]=-1;
		a[to][from]=-1;
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",b[i][j]);
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
	int s=0;

	kruskals(a,b,n);

}