//https://www.spoj.com/problems/PHONELST/

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

class Trie(){

	map<char, Trie> m;
	int cont;
	int word;

	Trie(){
		cont = 0;
		word = 0;		
	}

	void add(string s, int i){
		
		cont++;
		
		if(i == s.size()){
			word++;
			return;
		}
	
		if(m[s[i]].count() == 0)
			m[s[i]] = Trie();

		m[s[i]].add(s, i+1);
		return;
	}

	bool find(string s, int i){
	
		if(s.size() == i){
			if(word == 1)
				return true;
			return false;
		}
		return m[s[i]].find(s, i+1);
	}
}

int main(){}







