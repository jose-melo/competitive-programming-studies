#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int n, m;
vector<ll> choc, cup;

int main(){

	cin >> n;
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	ll a;
	for(int i = 0; i < n; i++){
		cin >> a;
		choc.push_back(a);	
	}
	cin >> m;

	for(int i = 0; i < m; i++){
		cin >> a;
		cup.push_back(a); 
	}
	
	sort(choc.begin(), choc.end());

	ll totalSum = 0;
	for(int i = 0; i < n; i++)
		totalSum += choc[i];
	
	for(int i = 0; i < m; i++)	
		cout << totalSum - choc[n - cup[i]] << "\n";

return 0;
}






