#include <stdio.h>

#define N 4

void prims(int a[N][N],int b[N][N],int n,int s){
	int i,j,k;
	int set[n];

	for(i=0;i<n;i++){
		set[i]=1;
	}
	set[s]=0;

	int repeat=0;
	int from;
	int to;
	int min;
	for(repeat=0;repeat<n-1;repeat++){

		min = 999;

		for(i=0;i<n;i++){
			if(set[i]==0){
				for(j=0;j<n;j++){
					if(set[j]==1){
						if(a[i][j]<min && a[i][j]!=-1){
							min = a[i][j];
							from = i;
							to = j;
						}
					}
				}
			}
		}


		b[from][to]=a[from][to];
		b[to][from]=a[to][from];
		set[to]=0;
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

	prims(a,b,n,0);

}
