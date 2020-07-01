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

int  N, x, y, idx, bitmask;
string s;
vector<pii> house;
int javi[20];
double cost = 0, min;
	

double dist(pii a, pii b){
	return sqrt((a.fi - b.fi)*(a.fi - b.fi) + (a.se - b.se)*(a.se - b.se));
}

double pd(N){

	if(N == 1)
		return dist(house[0], house[1]);
	

	double custo = pd(N-1);	
	double min = INF;	
	int a, b;

	for(int bit1 = 0; bit1 < 2*N; bit++){
		if(bitmask<<bit1 & 1)continue;		
		for(int bit2 = 0; bit2 < 2*N; bit2++){
			if(bitmask<<bit2 & 1 || bit1 == bit2)continue;
			if(dist(house[bit1], house[bit2]) < min){
				min = dist(house[bit1], house[bit2]);
				a = bit1;
				b = bit2;
			}
		}
	}
	
	custo += min;
	bitmask += 1<<bit1;
	bitmask += 1<<bit2;	
	return custo;
}

void solve(){

	


}


int main(){

	cin >> N;
	
	while(N != 0){
		for(int i = 0; i < 2*N; i++){
			cin >> s >> x >> y;
			house.pb(mp(x,y));
		}


		solve();

		cout << cost << endl;
		cout << printf("%.02f", cost);
		cin >> N;
		house.clear();	
	}	
	return 0;	
}
