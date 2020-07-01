#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int t;
ll n;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	
	while(t--){

		cin >> n;
	
		ll totalSum = ((1+n)*n)/2;
		
		ll pot2 = 1;
		ll pot2Sum = 0;
		while(pot2 <= n){
			pot2Sum += pot2;
			pot2 *= 2;	
		}
		
		ll res = totalSum - (2*pot2Sum);
		
		cout << res << "\n";

	}	
return 0;
}



