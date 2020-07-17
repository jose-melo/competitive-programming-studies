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
 
ll n, m, x, k, y, t;
 
int main(){
 
 
	
	cin >> n >> m;
 
	cin >> x >> k >> y;
 
	vector<int> a, b;
	int aux;
 
	FI(n){
		cin >> aux;
		a.pb(aux);
	}
 
	FI(m){
		cin >> aux;
		b.pb(aux);
	}
 
	ll idx1 = 0, idx2, num, idx3 = 0;
		
	ll resp = 0, p;
	while(idx1 < n){
		
		while(idx1 < n && idx3 < m && a[idx1] == b[idx3]){
				idx1++;
				idx3++;
		}
		
		idx2 = idx1;
		
		while(idx2 < n && idx3 < m && a[idx2] != b[idx3])idx2++;
 
		if(idx3 == m)idx2 = n;
 
		if(idx2 == n && idx3 != m){
			resp = -1;
			break;
		}
 
		p = -1;
		for(int u = idx1; u < idx2; u++)
			if(a[u] > p)
				p = a[u];
 
		num = idx2 - idx1;
		if(num % k){
			
			bool ok = false;
			if(idx1 > 0 && a[idx1-1] > p)ok = true;
			if(idx2 < n && a[idx2] > p)ok = true;		
			if(num < k && !ok){
				resp = -1;
				break;
			}
			resp += y*(num%k);
			num -= (num%k);
				
		}
		if(x < y*k){
			resp += (num/k)*x;
			idx1 = idx2;
		}else{
			if(idx1 > 0 && a[idx1-1] > p){
				resp += num*y;	
				idx1 = idx2;
				continue;
			}	
 
			if(idx2 < n && a[idx2] > p){
				resp += num*y;
				idx1 = idx2;
				continue;
			}
			resp += (num-k)*y;
			resp += x;
			idx1 = idx2;
		}	
	}
 
	cout << resp << endl;
 
}
