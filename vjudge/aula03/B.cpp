/*https://codeforces.com/problemset/problem/129/A*/
#include <bits/stdc++.h>
using namespace std;

int v[150];
int sumArray[150];
int n, cont;

int main(){

	cin >> n;

	sumArray[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		sumArray[i] = sumArray[i-1]+v[i];
	}

	cont = 0;
	for(int p = 1; p <= n; p++){
		if((sumArray[p-1] + (sumArray[n]-sumArray[p])) % 2 == 0){
			cont++;
		}
	}

	cout << cont << endl;
return 0;
}



