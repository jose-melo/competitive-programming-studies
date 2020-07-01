#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int n, m;
ll choc[312345], cup[312345];

int main(){

	cin >> n;
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	ll a;
	for(int i = 0; i < n; i++){
		cin >> choc[i];	
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> cup[i]; 
	}
	
	sort(choc, choc + n);

	ll totalSum = 0;
	for(int i = 0; i < n; i++)
		totalSum += choc[i];
	
	for(int i = 0; i < m; i++)	
		printf("%ld\n", totalSum - choc[n - cup[i]]);

return 0;
}






