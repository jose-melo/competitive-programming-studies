#include <bits/stdc++.h>
using namespace std;

#define ll long long int

string pessoas[6] = {"", "Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
vector<ll> inicios;
ll n;

int main(){

	cin >> n;

	if(n == 1){
		cout << pessoas[1] << "\n";
		return 0;
	}

	ll pot2;
	ll add = 5, ant = 1;
	inicios.push_back(1);

	for(ll i = 0; i <= log2(n)+10; i++){
		inicios.push_back(ant + add);
		ant += add;
		add *= 2;
	}

/*	for(auto x : inicios)
		cout << x << endl;
*/

	if(find(inicios.begin(), inicios.end(), n) != inicios.end())
		n++;

	vector<ll>::iterator it = lower_bound(inicios.begin(), inicios.end(), n);		
	it--;
	ll idx = it - inicios.begin();
	

	pot2 = 1;
	for(ll i = 0; i < idx; i++)pot2*=2;
	
//	cout << ((int)ceil((n - (*it) + 1)/((double)pot2)) % 6) << endl;
	
	cout << pessoas[((ll)ceil((n - (*it) + 1)/((double)pot2)) % 6)] << endl;
return 0;
}






