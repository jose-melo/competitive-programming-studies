#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX_N 1010
#define INF 1000000000


string a;
string b;
int res[MAX_N][MAX_N];
deque<char> prin;


int f[MAX_N][MAX_N];


/*void pd(int n, int m){

	for(int i = 0; i <= n; i++)
		f[i][0] = 0;

	for(int i = 0; i <= m; i++)
		f[0][i] = 0;
		
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i-1] == b[j-1])
				f[i][j] = f[i-1][j-1] + 1;
			else
				f[i][j] = max(f[i-1][j], f[i][j-1]);
		}
	}
}*/

int memoization(int i, int j){

	if(i == 0 || j == 0)return 0;

	if(f[i][j] != 0)
		return f[i][j];


	if(a[i-1] == b[j-1]){
		res[i][j] = 1;
		f[i][j] = memoization(i-1, j-1) + 1;
	}
	else{
		int aux1 = memoization(i, j-1), aux2 = memoization(i-1, j) ;
		f[i][j] = max(aux1, aux2);
		if(aux1 >= aux2){
			res[i][j] = 2;
		}else{
			res[i][j] = 3;
		}
	}

return f[i][j];
}

void imp(int n, int m){

	//printf("imp n = %d, m = %d\n",n, m);	

	if(n <= 0 || m <= 0)return;

	if(res[n][m] == 1){
		prin.push_front(a[n-1]);
		return imp(n-1, m-1);
	}

	if(res[n][m] == 2)
		return imp(n, m-1);
	else
		return imp(n-1, m);
	
return;
}

int main(){


	while(getline(cin, a)){
		getline(cin, b);

		//pd(a.size(), b.size());

		printf("%d\n", memoization(a.size(), b.size()));

		imp(a.size(), b.size());

		printf("res: ");
		for(auto x = prin.begin(); x < prin.end(); x++)
			printf("%c", *x);
		printf("\n");
		prin.clear();
	}	
return 0;
}







