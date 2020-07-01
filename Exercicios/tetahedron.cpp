#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10000001
#define mod 1000000007

#define A 0
#define B 1
#define C 2
#define D 3

long int f[4][MAX_N];

long int passos; 

/*void imp(int orig, int dest,long long int n){


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


	printf("n = %lli\n", n);


}*/


long int memoization(int orig, int dest, long int n){

	long int cont = 0;

	//imp(orig, dest, n);

	if(n == 0){
		//printf("RETURNED 0\n");
		f[orig][n] = 0;
		return 0;
	}

	if(n == 1){
		if(orig != dest){
			//printf("RETURNED 1\n");
			f[orig][n] = 1;
			return 1;
		}else{
			//printf("RETURNED 0\n");
			f[orig][n] = 0;
			return 0;
		}		
	}

	
	if(f[orig][n] != -1){
		//printf("RETURNED %lli\n", f[orig][n]);
		return f[orig][n];
	}


	for(int i = A; i <= D; i++){
		if(i != orig){

			if(f[i][n - 1] == -1){
				long int aux = memoization(i, dest, n -1);
				f[i][n - 1] = aux;
			}


			//printf("passos anteriores: ");
			//imp(i, dest, n-1);
			cont = ((cont % mod) + (f[i][n - 1] % mod)) % mod;

			//printf("cont = %d\n", cont);
		}
	}

	f[orig][n] = cont;

//printf("RETURNED %lli\n", f[orig][n]);
return f[orig][n];
}

int main(){

	scanf("%li", &passos);

	long int i, j;

	for(i = 0; i <= passos; i++)
		for(j = 0; j <= 3; j++)
				f[j][i] = -1;


	printf("%li\n", memoization(D, D, passos));
return 0;
}






