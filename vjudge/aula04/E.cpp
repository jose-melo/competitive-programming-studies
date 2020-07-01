/*https://codeforces.com/problemset/problem/680/A*/
#include <bits/stdc++.h>
using namespace std;

int v[5];
int freq[101];
int val[5];
int soma;

int main(){

	for(int i = 0; i < 100; i++)
		freq[i] = 0;

	soma = 0;
	for(int i = 0; i < 5; i++){
		cin >> v[i];
		soma += v[i];
	}

	for(int i = 0; i < 5; i++)
		if(freq[v[i]] < 3)freq[v[i]]++;


	for(int i = 0; i < 5; i++){
		if(freq[v[i]] == 2 || freq[v[i]] == 3)val[i] = freq[v[i]]*v[i];
		freq[v[i]] = 0;
	}


	int res = -1;
	for(int i = 0; i < 5; i++)
		res = max(res, val[i]);

	cout << soma - res << endl;
return 0;
}



