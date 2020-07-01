/*https://codeforces.com/problemset/problem/1166/C*/
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

vector<int> input;
int n;

bool ok(int a, int b){
	
	if(abs(b - a) >= abs(b) && abs(a + b) <= abs(b))
		return true;
return false;
}

bool ok2(int x, int y){

	if(abs(x - y) <= abs(y) && abs(x + y) >= abs(x))
		return true;
return false;
}

int bb(int ini){

	int l, r, mid;
	l = ini;
	r = input.size();

	while(l < r){
		mid = (l + r) / 2;
		if(ok(input[0], input[mid]))
			l = mid + 1;
		else
			r = mid;	
	}
return l;
}

int bb2(int ini){

	int l, r, mid;
	l = ini;
	r = input.size() - 1;

	while(l < r){
		mid = (l + r) / 2;


		if(ok2(input[input.size()-1], input[mid]))
			l = mid + 1;
		else
			r = mid;	
	}
return l;
}


int main(){

	fastio;

	cin >> n;

	int aux;
	FI(n){
		cin >> aux;
		input.pb(aux);
	}
		
	sort(input.begin(), input.end());

	int ind;
	for(int i = 0; i < input.size(); i++)
		if(input[i] > 0){
			ind = i;
			break;
		}
	
	int cont = 0;
	int idx = bb(ind);
	int tam = input.size();


	cont += ind * ((idx - ind));

	idx = bb2(ind);
	idx--;


	if(idx != ind-1)
		cont += ((tam - idx) * (tam - idx - 1)) / 2;
	
	cout << cont << "\n";
return 0;
}





