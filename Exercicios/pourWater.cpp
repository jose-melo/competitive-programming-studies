#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b, int* x, int *y){

	int div;
	if(a % b == 0){
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1;
	div = gcd(b % a, a, &x1, &y1);

	*x = y1 - (b/a)*x1;
	*y = x1;

	return div;
}

void solve(int a, int b, int c){


	if(c )

}











int main(){

	int t, a, b, c, i, j;


	scanf("%d", &t);

	for(j = 0; j < t; j++){
		scanf("%d %d %d", &a, &b, &c);
		
		if(a > b)
			solve(a, b, c);
		else
			solve(b, a, c);
	}

return 0;
}