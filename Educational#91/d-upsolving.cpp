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

ll n, m, x, k, y, t, resp;
vector<int> a,b;

bool calcula(int idx1, int idx2){

	int p, num;
	p = -1;
	for(int u = idx1; u < idx2; u++)
		if(a[u] > p)
			p = a[u];

	num = idx2 - idx1;
		
	bool ok = false;
	if(idx1 > 0 && a[idx1-1] > p)ok = true;
	if(idx2 < n && a[idx2] > p)ok = true;		
	if(num < k && !ok){
		resp = -1;
		return false;
	}

	if(num % k){
		resp += y*(num%k);
		num -= (num%k);
	}
	if(x <= y*k){
		resp += (num/k)*x;
	}else{
		if(ok){
			resp += num*y;	
		}	
		resp += (num-k)*y;
		resp += x;
	}
	return true;
}


int main(){


	cin >> n >> m;

	cin >> x >> k >> y;

	int aux;
	FI(n){
		cin >> aux;
		a.pb(aux);
	}

	FI(m){
		cin >> aux;
		b.pb(aux);
	}

	int idx1 = 0, idx2, idx3 = 0;

	while(idx1 < n){
		
		while(idx3 < m && a[idx1] == b[idx3]){
				idx1++;
				idx3++;
		}
	
		idx2 = idx1;
		while(idx2 < n && a[idx2] != b[idx3])idx2++;	

		idx3++;

		if((idx2 == n && idx3 < m-1)){
			cout << "-1\n";
			return 0;
		}	

		if(!calcula(idx1, idx2)){
			cout << "-1\n";
			return 0;
		}

		cout << resp << " " << idx1 << " " << idx2 << " " << idx3 << endl;
		idx1 = idx2+1;	
		idx2 = idx1;
	}

	if((idx2 == n && idx3 < m-1)){
		cout << "-1\n";
		return 0;
	}	


	cout << resp << endl;

}

