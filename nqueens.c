#include <stdio.h>

#define N 5

int attack[N][N];

void place_queen(int a,int b){
	int i,j;
	attack[a][b]++;
	for(i=0;i<b;i++){
		attack[a][i]++;
	}
	for(i=b+1;i<N;i++){
		attack[a][i]++;
	}

	for(i=0;i<a;i++){
		attack[i][b]++;
	}
	for(i=a+1;i<N;i++){
		attack[i][b]++;
	}

	i=a-1;
	j=b-1;
	while(i>=0&& j>=0){
		attack[i][j]++;
		i--;j--;
	}
	i=a+1;
	j=b+1;
	while(i<N&& j<N){
		attack[i][j]++;
		i++;j++;
	}

	i=a-1;
	j=b+1;
	while(i>=0&& j<N){
		attack[i][j]++;
		i--;j++;
	}
	i=a+1;
	j=b-1;
	while(i<N&& j>=0){
		attack[i][j]++;
		i++;j--;
	}
}
void remove_queen(int a,int b){
	int i,j;
	attack[a][b]--;
	for(i=0;i<b;i++){
		attack[a][i]--;
	}
	for(i=b+1;i<N;i++){
		attack[a][i]--;
	}

	for(i=0;i<a;i++){
		attack[i][b]--;
	}
	for(i=a+1;i<N;i++){
		attack[i][b]--;
	}

	i=a-1;
	j=b-1;
	while(i>=0&& j>=0){
		attack[i][j]--;
		i--;j--;
	}
	i=a+1;
	j=b+1;
	while(i<N&& j<N){
		attack[i][j]--;
		i++;j++;
	}

	i=a-1;
	j=b+1;
	while(i>=0&& j<N){
		attack[i][j]--;
		i--;j++;
	}
	i=a+1;
	j=b-1;
	while(i<N&& j>=0){
		attack[i][j]--;
		i++;j--;
	}
}


void queen(int curr)
{
	int i,j,k;

	for(i=0;i<N;i++){
		if(attack[curr][i]==0){
			place_queen(curr,i);
			if(curr<N-1){
				queen(curr+1);
			}else{
				for(j=0;j<N;j++){
					for(k=0;k<N;k++){
						if(attack[j][k]==1){
							printf("Q ");
						}else{
							printf("- ");
						}
					}
					printf("\n");
				}
				printf("\n\n");
			}
			remove_queen(curr,i);
		}
	}
}

void main(){
	int i;
	queen(0);

}