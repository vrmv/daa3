#include <stdio.h>
#include <stdlib.h>
#define N 4


void assignment(int a[N][N],int *job_assign){

	int i,j,j_id;
	int min;
	for(i=0;i<N;i++)      //i is for person and j is for job
	{
		min=999;
		j_id=-1;
		for(j=0;j<N;j++)
		{
			if(a[i][j]<min && job_assign[j]==-1)
			{
				min=a[i][j];
				j_id=j;   //as we have to the jpob number (minimum)
			}
		}

		job_assign[j_id]=i;
	}

	for(i=0;i<N;i++){
		printf("J0b %d is assigned to person%d\n",i+1,job_assign[i]+1);
	}

}

void main(){
	int n=N,i,j;
	int a[N][N];
	int job_assign[N];
	for(i=0;i<N;i++){
		job_assign[i]=-1;
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&a[i][j]);
		}
	}
	assignment(a,job_assign);

}
