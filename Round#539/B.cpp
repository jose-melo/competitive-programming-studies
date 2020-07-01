#include <bits/stdc++.h>
using namespace std;

#define MAX_N 50000
#define ll long long int
ll n;
int energias[MAX_N];

int main(){

	cin >> n;

	for(ll i = 0; i < n; i++)
		scanf("%d", &energias[i]);
	
	sort(energias, energias + n);

	ll b;
	ll sum = 0;
	for(ll i = 1; i < n-1; i++)
		sum += energias[i];


	ll sum_atual = sum + energias[0] + energias[n-1];

	for(ll i = 0; i < n; i++){
		b = energias[n-1 - i];


		for(ll j = 2; j*j <= b; j++){


			if(b % j == 0){
				if(sum + (energias[0]*j) + (energias[n-1]/j) < sum_atual){
					sum_atual = sum + (energias[0]*j) + (energias[n-1-i]/j);
				}
			}	
		}
		sum -= energias[n-1-i-1];
		sum += b;
	}

	cout << sum_atual << "\n";

return 0;
}
