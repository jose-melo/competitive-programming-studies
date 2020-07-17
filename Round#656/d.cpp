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


int t, n;
ll cont;

void solve(string s, char ch){

//	cout << s << " " << ch << " " << cont << endl;

	if(s.size() == 1){
		if(s[0] != ch)cont++;

		return;
	}
	int cont1 = 0, cont2 = 0;
	int n = s.size();

	for(int i = 0; i < n/2; i ++)
		if(s[i] != ch)cont1++;

	for(int i = n/2; i < n; i++)
		if(s[i] != ch)cont2++;

	cont += min(cont1, cont2);

	if(cont1 > cont2)
		solve(s.substr(0, n/2), ch+1);
	else
		solve(s.substr(n/2, n/2), ch+1);
}



int main(){

	cin >> t;

	while(t--){
	
		cin >> n;
		string s;
		
		cin >> s;

		cont = 0;
		solve(s, 'a');	
	
		
		cout << cont << endl;

	}


}

