//https://codeforces.com/problemset/problem/580/A

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX_N 100100

int n, cont, ant, resp;
ll num;


int main(){

	cin >> n;

	ant = INT_MAX;
	cont = resp = 1;
	for(int i = 0; i < n; i++){
		cin >> num;

		if(ant > num)
			cont = 1;
		else
			cont++;
		ant = num;
		resp = max(resp, cont);
	}

	cout << resp << endl;

return 0;
}



