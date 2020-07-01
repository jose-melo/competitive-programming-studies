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

int pais[112345];
int ordem[112345];
set<int> especiais;
int qtdEspeciais[112345];
int n, m, k;
bool acabou;
vector<pair<int, pair<int, int>>> listAdj;

void build(){

	for(int i = 1; i <= n; i++){
		pais[i] = i;
		ordem[i] = 1;
		if(especiais.find(i) != especiais.end())
			qtdEspeciais[i] = 1;
	}

}

int find(int noh){

	if(pais[noh] == noh)
		return noh;

	pais[noh] = find(pais[noh]);
return pais[noh];
}

bool isSameSet(int x, int y){
	return find(x) == find(y);
}

void UNION(int a, int b){

	if(!isSameSet(a, b)){
		int x = find(a);
		int y = find(b);

		if(ordem[x] < ordem[y]){
			pais[x] = y;
			qtdEspeciais[y] += qtdEspeciais[x];			
			if(qtdEspeciais[y] == especiais.size())
				acabou = true;			

		}else{
			pais[y] = x;
			qtdEspeciais[x] += qtdEspeciais[y];			
			if(ordem[x] == ordem[y])
				ordem[x]++;
			if(qtdEspeciais[x] == especiais.size())
				acabou = true;
		}
	}
return;
}

int main(){

	fastio;

	cin >> n >> m >> k;


	int a, b, c;
	FI(k){
		cin >> a;	
		especiais.insert(a);
	}

	build();	

	FI(m){
		cin >> a >> b >> c;
		listAdj.pb(mp(c, mp(a, b)));
	}

	sort(listAdj.begin(), listAdj.end());
	
	acabou = false;
	vector<pair<int, pair<int, int>>>::iterator it = listAdj.begin();
	int res = -1;
	while(!acabou){
		auto val = *it;
		UNION(val.se.fi, val.se.se);
		res = val.fi;	
		it++;
	}
	
	FI(k)
		cout << res << " ";
	cout << "\n";
return 0;
}


