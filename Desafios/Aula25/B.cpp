#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f3f3f3f3f
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

int n, q;
ll seg[4*212345];
ll lazy[4*212345];
ll input[212345];

void build(int node, int l, int r){

	if(l == r){
		seg[node] = input[l];
		return;
	}

	int mid = (l + r) / 2;

	build(2*node, l, mid);
	build(2*node + 1, mid+1, r);
	
	seg[node] = min(seg[2*node], seg[2*node + 1]);
return;
}

void arrumaLazy(int node){
	
	if(lazy[node] == 0)return;

	lazy[2*node] += lazy[node];
	seg[2*node] += lazy[node];

	lazy[2*node + 1] += lazy[node];
	seg[2*node + 1] += lazy[node];

	lazy[node] = 0;
}

void update(int node, int a, int b, int l, int r, ll val){

	if(b < l || a > r)return;//a----b l----r ou l-----r a----b 

	if(l <= a && b <= r){//Noh inteiramente contido ;D
		seg[node] += val;
		lazy[node] += val;
		return;
	}

	arrumaLazy(node);

	int mid = (a + b) / 2;

	update(2*node, a, mid, l, r, val);
	update(2*node + 1, mid+1, b, l, r, val);

	seg[node] = min(seg[2*node], seg[2*node + 1]);
}

ll query(int node, int a, int b, int l, int r){

	if(b < l || a > r)return INF; // Deu merda		

	if(l <= a && b <= r)//Noh inteiramente contido
		return seg[node];		

	arrumaLazy(node);

	int mid = (a + b) / 2;	
	
	ll resp = min(query(2*node, a, mid, l, r), query(2*node + 1, mid+1, b, l, r));
return resp;
}

int main(){

	fastio;

	cin >> n;

	FI(n)
		cin >> input[i+1];

	build(1, 1, n);

	cin >> q;

	int a, b;
	ll c;
	char ch;
	FI(q){

		cin >> a >> b;
		a++;
		b++;
		cin.get(ch);

		if(ch == '\n'){	
			if(a > b)
				cout << min(query(1, 1, n, a, n), query(1, 1, n, 1, b)) << "\n";
			else
				cout << query(1, 1, n, a, b) << "\n";
		}else{
			cin >> c;

			if(a > b){
				update(1, 1, n, a, n, c);	
				update(1, 1, n, 1, b, c);
			}else{
				update(1, 1, n, a, b, c);
			}

		}
		

	}
return 0;
}


