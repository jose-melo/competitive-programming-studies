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

double dist(pii a, pii b){
	return sqrt((a.fi - b.fi)*(a.fi - b.fi) + (a.se - b.se)*(a.se - b.se));
}


int main(){

	int  N, x, y, idx;
	string s;
	vector<pii> house;
	int javi[20];
	double cost = 0, min;
	cin >> N;
	
	while(N != 0){
		for(int i = 0; i < 2*N; i++){
			cin >> s >> x >> y;
			house.pb(mp(x,y));
		}

		for(int i = 0; i < 20; i++)
			javi[i] = 0;

		for(int i = 0; i < 2*N; i++){
			if(javi[i] == 1)continue;
			min = 10000000;
			
			for(int j = 0; j < 2*N; j++){
				if(javi[j] == 1 || j == i)continue;
				if(dist(house[i], house[j]) < min){
					min = dist(house[i], house[j]);
					idx = j;
				}
			}
			cout << i << " " << idx << " " << cost << " "  << min << endl;
			javi[i] = 1;
			javi[idx] = 1;
			cost += min;
		}

		cout << cost << endl;
		cout << printf("%.02f", cost);
		cin >> N;
		house.clear();	
	}	
	return 0;	
}
