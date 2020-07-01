#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000000
#define ll long long int

ll add[MAX_N];
ll input[MAX_N];
ll topop[MAX_N];

pair<pair<ll, ll>, ll> op[MAX_N];

int main(){

	ll n, m, k, a, b, c;

	scanf("%lli %lli %lli", &n, &m, &k);

	for(ll i = 1; i <= n; i++)
		scanf("%lli", &input[i]);			
	
	for(ll i = 1; i <= m; i++){
		scanf("%lli %lli %lli", &a, &b, &c);
		op[i].first = make_pair(a, b);
		op[i].second = c;
	}

	/*printf("topop: ");
	for(ll i = 1; i <= k; i++)
		printf("%lli ", topop[i]);
	printf("\n");*/

	for(ll i = 1; i <= k; i++){
		scanf("%lli %lli", &a, &b);
		topop[a] += 1;
		topop[b + 1] -= 1;
	}

	/*printf("topop: ");
	for(ll i = 1; i <= k; i++)
		printf("%lli ", topop[i]);
	printf("\n");*/

	for(ll i = 1; i <= m; i++)
		topop[i+1] += topop[i];

	/*printf("topop: ");
	for(ll i = 1; i <= k; i++)
		printf("%lli ", topop[i]);
	printf("\n");*/

	/*printf("add: ");
	for(ll i = 1; i <= m; i++)
		printf("%lli ", add[i]);
	printf("\n");*/

	for(ll i = 1; i <= m; i++){
		add[op[i].first.first] += topop[i]*op[i].second;
		add[op[i].first.second + 1] -= topop[i]*op[i].second;
	}

	/*printf("add: ");
	for(ll i = 1; i <= m; i++)
		printf("%lli ", add[i]);
	printf("\n");*/

	for(ll i = 1; i <= n; i++)
		add[i+1] += add[i];


	/*printf("add: ");
	for(ll i = 1; i <= m; i++)
		printf("%lli ", add[i]);
	printf("\n");*/


	/*printf("input: ");
	for(ll i = 1; i <= n; i++)
		printf("%lli ", input[i]);
	printf("\n");*/

	for(ll i = 1; i <= n; i++)
		input[i] += add[i];


	for(ll i = 1; i <= n; i++)
		printf("%lli ", input[i]);
	printf("\n");


}








