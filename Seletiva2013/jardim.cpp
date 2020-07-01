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
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;
#define PI 3.14159265359
double v[1000];

int main(){

	int T;
	cin >> T;
	
	while (T--){
		int N, lp, dif;
		cin >> N >> lp >> dif;

		int ini = 0;
		for (int i = 0; i < N; i++){
			cin >> v[i];
			if (v[i] == 0) ini = i;
		}

		double dis = 0;
		double maxE = 0;
		for (int i = ini-1; i >= 0; i--){
			dis += lp + dif;
			double arc = atan(v[i]/dis) * 180 / PI;
			maxE = max (maxE, arc);
		}

		dis = 0;
		double maxD = 0;
		for (int i = ini+1; i < N; i++){
			dis += lp + dif;
			double arc = atan(v[i]/dis) * 180 / PI;
			maxD = max (maxD, arc);
		}

		double mult = 960.0/180.0;
		double resp = 180 - maxD - maxE;
		resp = resp*mult;
		printf("%.10lf\n", resp);

	}

	return 0;
}	
