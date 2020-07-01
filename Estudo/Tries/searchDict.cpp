//https://www.spoj.com/problems/DICT/
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

string pal;
bool achei;
string molde;

class Trie{

	public:
	int word, cont;		
	map<char, Trie> m;

	Trie(){
		word = 0;
	}

	void add(string s, int i){

		if (i == s.size()){
			word += 1;
			return;	
		}	

		if (!m.count(s[i])){
			m[s[i]] = Trie();
		}
		
		return m[s[i]].add(s, i+1);

	}


	bool fodase(string a, string b){
		
		if(a.size() != b.size())
			return false;

		for(int i = 0; i < b.size(); i++)
			if(a[i] != b[i])
				return false; 
		return true;
	}

	void dfs(Trie t){
		
		if(t.word > 0){

			if(molde.compare(pal) != 0){ 
				cout << pal << endl;
				achei = true;
			}
		}

		FOR(i, 0, 27){
			if(t.m.count(i+'a')){
				pal.push_back('a'+i);
				dfs(t.m[i + 'a']);
				pal.pop_back();
			}
		}
	return;
	}
	bool search(string s, int i){

		if (i ==  s.size()){
			
			dfs(*this);
			return false;
		}

		if(!m.count(s[i]))
			return false;


		return m[s[i]].search(s, i+1);
	}
};

int main(){

	fastio;

	int n, k;
	string s;

	cin >> n;
	
	Trie T = Trie();

	map<int, string> mapa;

	FI(n){
		cin >> s;
		T.add(s, 0);
	}	

	cin >> k;
		
	FI(k){
	
		cin >> s;
		achei = false;
		cout << "Case #" << i+1 << ":\n";
	
		pal.clear();	
		pal = s;		

		molde = s;	
		T.search(s, 0);
	
		if(!achei)
			cout << "No match.\n";

	}
return 0;
}



