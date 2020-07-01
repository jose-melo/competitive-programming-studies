#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define x first
#define mp make_pair
#define y second
#define FI(n) for(int i = 0; i < n; i++)
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;



long double dist(pii a, pii b){

	long double resp = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));

	return resp;
	
}


int main(){

	int T, n;

	long double teta, r;
	cin >> T;

	int cont = 1;
	vector<pii> v;
	while(T--){


		cin >> n;
		
		cout << "Case #"<<cont<<": ";
		int a, b;
		FI(n){
			cin >> a >> b;
			v.pb(mp(a, b));
		}
		cin >> a >> b;


		long double resp = 0;
		FOR(i, 1, n){
		
			r = dist(mp(a, b), v[1]);
		
			if(v[i+1].x - v[i].x == 0)
				teta = 3.1415
			teta = tan(v[i+1].y / (v[i+1].x - v[i].x));
			
			resp += r * teta;

		}
		
		printf("%.3Lf\n", resp);
		cont++;	
	}




}



