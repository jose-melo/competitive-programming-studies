#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int, int>

ll totaSum;

struct comparator{

	bool operator()(const pii& lhs, const pii& rhs){
		
		pii a, b;
		
		a = lhs;
		b = rhs;

		if(a.first < b.first)
			return true;
		
		if(a.first == b.first)
			if(a.second > b.second)
				return true;

		return false;
	}
	
};




int main(){

	int n, pos, macas;
	cin >> n;

	
	set<pii, comparator> esq, dir;

	while(n--){
	
		cin >> pos >> macas;
		
		if(pos < 0)
			esq.insert(make_pair(abs(pos), macas));
		else
			dir.insert(make_pair(pos, macas));
	}
	ll contEsq, contDir;	

	if(esq.size() < dir.size()){
		contEsq = 0;
		for(auto x : esq)
			contEsq += x.second;
	
		contDir = 0;
		int cont = 0;
		
		for(set<pii>::iterator it = dir.begin(); it != dir.end() && cont < esq.size()+1; it++){
			contDir += it->second;
			cont++;
		}	

	}
/*
	cout << "esq: " << endl;	
	for(auto x : esq)
		cout << x.first << " " << x.second << endl;

	for(auto x : dir)
		cout << x.first << " " << x.second << endl;



	cout << "dir: " << endl;*/	
	if(dir.size() < esq.size()){
		contDir = 0;
		for(auto x : dir)
			contDir += x.second;
	
		contEsq = 0;
		int cont = 0;
		
		for(set<pii>::iterator it = esq.begin(); it != esq.end() && cont < dir.size()+1; it++){
			contEsq += it->second;
			cont++;
		}
	}

	if(esq.size() == dir.size()){
		contDir = 0;
		for(auto x : dir)
			contDir += x.second;
		
		contEsq = 0;
		for(auto x : esq)
			contEsq += x.second;
	


	}

	cout << contEsq+contDir << "\n";

return 0;
}

	
