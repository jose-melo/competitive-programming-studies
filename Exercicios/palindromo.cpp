#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX_N 1010
#define INF 1000000000

string a;

int f[MAX_N][MAX_N];

int eh_palindromo(int i, int j){

	while(i < j){

		//printf("a[%i] = %c a[%d] = %c\n",i, a[i-1], j, a[j-1]);

		if(a[i-1] != a[j-1])
			return 0;
		i++;
		j--;
	}
return 1;
}

void pd(int n){

	f[0][0] = 0;

	for(int i = 1; i <= n; i++){
		f[i][i] = 1;
	}

	for(int l = 2; l <= n; l++){

		for(int i = 1; i <= n - l + 1; i++){
			int j = i + l - 1;
			int min = INF;	

			int aux = eh_palindromo(i, j);

			printf("i = %d j = %d aux = %d ", i, j, aux);

			if(aux)
				min = 1;
			else{
				for(int k = i; k < j; k++){

					if(f[i][k] + f[k+1][j] < min)
						min = f[i][k] + f[k+1][j];

				}
			}
			f[i][j] = min;
			printf("f[%d][%d] = %d\n", i, j, f[i][j]);
		}
	}
}

int main(){

	int n;
	cin >> n;
	getline(cin, a);
	getline(cin, a);

	pd(n);

	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			printf("f[%d][%d] = %d \n",i, j, f[i][j]);



	printf("%d\n", f[1][n]);
return 0;
}

















