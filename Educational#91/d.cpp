#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back

int n, m;
ll x, y, k;

int main(){

	cin >> n >> m;

	cin >> x >> k >> y;

	vector<int> a, b, resto, atual;
	int aux;
	int mark[n+10];

	memset(mark, 0, sizeof(mark));

	FI(n){
		cin >> aux;
		a.pb(aux);
	}

	FI(m){
		cin >> aux;
		b.pb(aux);
		mark[aux] = 1;
	}

	int j = 0;
	for(int i = 0; i < n; i++){
		if(j == m || a[i] != b[j]){
			resto.pb(a[i]);
		}else{
			atual.pb(a[i]);
			j++;
		}
	}

	if(j != m){
		cout << "-1\n";
		return 0;
	}

	if(resto.empty()){
		cout << "0\n";
		return 0;
	}

	sort(resto.begin(), resto.end());
	sort(atual.begin(), atual.end());

	ll resp = 0;
	while(resto.size() >= k && atual.back() < resto.back()){
		for(int i = 0; i < k; i++){
			mark[resto.back()] = 2;
			resto.pop_back();
		}
		resp += x;
	}

	if(atual[atual.size()-1] < resto[resto.size()-1]){
		cout << "-1\n";
		return 0;
	}

	if(x/k < y){

		while(resto.size() >= k){
			for(int i = 0; i < k; i++){
				resto.pop_back();
				mark[reto.back()] = 2;
			}
			resp += x;
		}
		
		int idx2 = 0, mx = -1;
		for(int i = 0; i < n; i++){

			if(mark[a[i]] == 1){
				idx2 = i;
				mx = a[i];
			}else{
				if(mark[a[i]] == 2){
					mx = max(mx, a[i]);
				}else{
					if(a[i] < mx){
						mark[a[i]] = 3;
					}else{
						mx = max(a[i], mx);
					}
				}
			}
		}
		
		idx2 = 0;
		mx = -1;
		for(int i = n-1; i >= 0; i--){

			if(mark[a[i]] == 1){
				idx2 = i;
				mx = a[i];
			}else{
				if(mark[a[i]] == 2 || mark[a[i]] == 3){
					mx = max(mx, a[i]);
				}else{
					if(a[i] < mx){
						mark[a[i]] = 3;
					}else{
						cout << "-1\n";
						return 0;
					}
				}
			}
		}


	
	}else{

		int idx2 = 0, mx = -1;
		for(int i = 0; i < n; i++){

			if(mark[a[i]] == 1){
				idx2 = i;
				mx = a[i];
			}else{
				if(mark[a[i]] == 2){
					mx = max(mx, a[i]);
				}else{
					if(a[i] < mx){
						resp += y;
						mark[a[i]] = 3;
					}else{
						mx = max(a[i], mx);
					}
				}
			}
		}
		
		idx2 = 0;
		mx = -1;
		for(int i = n-1; i >= 0; i--){

			if(mark[a[i]] == 1){
				idx2 = i;
				mx = a[i];
			}else{
				if(mark[a[i]] == 2 || mark[a[i]] == 3){
					mx = max(mx, a[i]);
				}else{
					if(a[i] < mx){
						resp += y;
						mark[a[i]] = 3;
					}else{
						cout << "-1\n";
						return 0;
					}
				}
			}
		}

	}


	cout << resp << endl;



	



}

