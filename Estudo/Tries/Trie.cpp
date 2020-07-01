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

struct Trie{

	int cont, word;
	map<char, Trie> m;

	Trie(){
		word = 0;
		cont = 0;
	}


	void add(string s, int i){

		cont++;
		if(i == s.size()){
			word++;
			return;
		}

		if(!m.count(s[i]))
			m[s[i]] = Trie();

		m[s[i]].add(s, i + 1);
	}

	bool find(string s, int i){
	
		if(i == s.size()){
			if(word == 0)
				return false;
			return true;
		}

		if(cont < 0 || !m.count(s[i]))
			return false;

		return m[s[i]].find(s, i + 1);
	}	
		
	void del(string s, int i){

		if(cont < 0 || !m.count(s[i]))
			return;

		cont--;
		if(i == s.size()){
			word--;
			return;
		}
		m[s[i]].del(s, i + 1);
		return;
	}	
};

int main(){

	string s;
	int n;

	cin >> n;
	Trie T =  Trie();
	while(n--){
		cin >> s;
		T.add(s, 0);
	}

	cout << T.find("banana", 0) << endl;
	cout << T.find("casa",  0) << endl;
	




}








