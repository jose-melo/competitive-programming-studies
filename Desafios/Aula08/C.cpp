#include <bits/stdc++.h>
using namespace std;

#define ll long long int


int main(){

	ll n, k, pot2, pot5, aux, pot2Res, pot5Res;

	cin >> n >> k;
	aux = n;

	pot2 = 0;
	while(aux % 2 == 0){
		pot2++;
		aux /= 2;
	}
	
	aux = n;
	pot5 = 0;
	while(aux % 5 == 0){
		pot5++;
		aux /= 5;
	}
	
	if(pot2 > k)pot2 = k;
	if(pot5 > k)pot5 = k;

	pot2Res =  k - pot2;
	pot5Res = k - pot5;

	ll calc1 = 1;
	for(ll i = 0; i < pot2Res; i++)
		calc1 *= 2;

	ll calc2 = 1;
	for(ll i = 0; i < pot5Res; i++)
		calc2 *= 5;

	ll res = n * calc1 * calc2;	
	
	cout << res << "\n";

return 0;
}






