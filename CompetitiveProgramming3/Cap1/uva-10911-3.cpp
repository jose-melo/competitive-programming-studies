#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;

int N, x, y;
double resp;
string s;
vector<pii> house;
double memo[(1<<16)+123];

double dist(pii a, pii b){
	return sqrt((a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se));
}

double pd(int bitmask){

	if(bitmask == (1<<(2*N))-1)
		return 0;

	if(memo[bitmask] != 0)
		return memo[bitmask];
	

	int bit1, bit2;
	double cost = 2e9;

	for(bit1 = 0; bit1 < 2*N; bit1++)
		if((bitmask & (1<<bit1)) == 0)
			break;
	
	
	for(bit2 = bit1 + 1; bit2 < 2*N; bit2++){
		if((bitmask & (1<<bit2)) != 0)
			continue;
	
		cost = min(cost, dist(house[bit1], house[bit2]) + pd(bitmask | 1<<bit1 | 1<<bit2));


	}


	return memo[bitmask] = cost;
}


int main(){

	int cont = 1;
	cin >> N;
	while(N != 0){

		for(int i = 0; i < 2*N; i++){
			cin >> s >> x >> y;
			house.pb(mp(x, y));
		}


		resp = pd(0);

		printf("Case %d: %.2lf\n",cont, resp);		
		house.clear();
		for(int i = 0; i < 2*N; i++)
			memo[i] = 0;
		
		cin >> N;
		cont++;	
	}

	return 0;
}






