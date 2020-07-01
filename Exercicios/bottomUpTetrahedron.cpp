#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10010000
#define INF 1000000000
#define mod 1000000007

#define A 0
#define B 1
#define C 2
#define D 3

long int f[4][MAX_N];

long int passos; 

/*void imp(int orig, int dest, int n){


	switch(orig){
		case 0:
			printf("orig = %c ", 'A');
			break;
		case 1:
			printf("orig = %c ", 'B');
			break;
		case 2:
			printf("orig = %c ", 'C');
			break;
		case 3:
			printf("orig = %c ", 'D');
			break;
	}

	switch(dest){
		case 0:
			printf("dest = %c ", 'A');
			break;
		case 1:
			printf("dest = %c ", 'B');
			break;
		case 2:
			printf("dest = %c ", 'C');
			break;
		case 3:
			printf("dest = %c ", 'd');
			break;
	}


	printf("n = %d\n", n);


}*/


void bottomUp(int orig, int dest, long int n){

	for(long int i = 0; i <= n; i++){
		for(int j = 0; j <= 3; j++){
		
			if(i == 0){
				f[j][i] = 0;
			}else{
				if(i == 1){
					if(j != dest){
						f[j][i] = 1;
					}
					else{
						f[j][i] = 0;
					}
				}else{

					for(int k = 0; k <= 3; k++){
						if(k != j){
							f[j][i] = (((f[j][i] % mod) + (f[k][i - 1] % mod) % mod) % mod);
						}
					}
				}
			}
		} 
	}
}

int main(){

	scanf("%li", &passos);

	long int i, j;

	for(i = 0; i <= passos; i++)
		for(j = 0; j <= 3; j++)
				f[j][i] = 0;

	bottomUp(D, D, passos);
	printf("%li\n", f[D][passos]);
return 0;
}










