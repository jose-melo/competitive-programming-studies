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


int main(){

	int n, k;
	string num;

	cin >> n >> k;

	cin >> num;

	int dig;
	stack<char> p;
	for(int i = 0; i < n; i++){
		p.push(num.back());
		num.pop_back();
	}


	if(p.top() == '1'){
		if(k == 1 && n == 1)
			cout << "0";
		else if(k != 0)
			cout << "1";
		else
			cout << p.top();
		
		p.pop();
		
		
		for(int i = 0; i < k && !p.empty(); i++){
			if(p.top() == '0'){
				cout << "0";
				i--;
				p.pop();
			}else{
				cout << "0";
				p.pop();
			}
		}
	}else{
		
		if(k == 1 && n == 1)
			cout << "0";
		else if(k != 0)
			cout << "1";
		else
			cout << p.top();
		p.pop();

		for(int i = 1; i < k && !p.empty(); i++){
			if(p.top() == '0'){
				cout << "0";
				i--;
				p.pop();
			}else{
				cout << "0";
				p.pop();
			}
		}
	}
					
	while(!p.empty()){
		cout << p.top();
		p.pop();
	}

	cout << endl;

	return 0;
}



