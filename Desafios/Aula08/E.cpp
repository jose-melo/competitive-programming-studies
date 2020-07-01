#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll n;
ll v[512345];
ll accSum[512345];


int main(){

	cin >> n;
	vector<ll> podeP;
	vector<ll> podeQ;
	

	int control = 1;
	ll totalSum = 0;
	accSum[0] = 0;
	for(ll i = 1; i <= n; i++){
		cin >> v[i];
		totalSum += v[i];
		accSum[i] = accSum[i-1] + v[i];
	}

	if(totalSum%3){
		cout << "0\n";
		return 0; 
	}

	ll cont1 = 0, cont2 = 0;

	for(int i = 1; i < n; i++){
		
		if(accSum[i] == (totalSum/3)*2)
			cont1 += cont2;
		
		if(accSum[i] == totalSum/3)
			cont2++;
	}

	cout << cont1 << endl;


}
