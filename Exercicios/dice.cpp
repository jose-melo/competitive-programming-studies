#include <bits/stdc++.h>
using namespace std;


#define MAX_N 11000
#define INF 0x3f3f3f3f

int memo[7][MAX_N];

int pd(int cima, int soma){

	if(soma == 0)return 0;
	if(soma < 0)return INF;
	
	if(memo[cima][soma] != INF)
		return memo[cima][soma];
		
	for(int i = 1; i <= 6; i++)
		if(i != cima && i + cima != 7)
			memo[cima][soma] = min(memo[cima][soma], pd(i, soma - i) + 1);
	
	return memo[cima][soma];
}

int main(){

	int T;
	int n;
	
	cin >> T;
	
	while(T > 0){
	
		cin >> n;
	
		for(int i = 0; i < 7; i++)
			for(int j = 0; j <= n; j++)
				memo[i][j] = INF;
		
		int aux = pd(1, n);
					
		if(aux < INF)
			printf("%d\n", pd(1, n));
		else
			printf("-1\n");
		
		T--;
	}


}

