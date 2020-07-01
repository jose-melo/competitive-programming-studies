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

string s[10][10];

void analisa(int dig, char val){

	switch(val){

		case 0:
			s[dig][0] = '1';
			s[dig][1] = '0';
			s[dig][2] = '0'; 
			s[dig][3] = '1';
			s[dig][4] = '1';
			s[dig][5] = '1';
			s[dig][6] = '1';
			break;
		case 1: 
			s[dig][0] = '1';
			s[dig][1] = '0';
			s[dig][2] = '1'; 
			s[dig][3] = '0';
			s[dig][4] = '1';
			s[dig][5] = '1';
			s[dig][6] = '1';
			break;
		case 2:	
			s[dig][0] = '1';
			s[dig][1] = '0';
			s[dig][2] = '1'; 
			s[dig][3] = '1';
			s[dig][4] = '0';
			s[dig][5] = '1';
			s[dig][6] = '1';
			break;
		case 3: 
			s[dig][0] = '1';
			s[dig][1] = '0';
			s[dig][2] = '1'; 
			s[dig][3] = '1';
			s[dig][4] = '1';
			s[dig][5] = '0';
			s[dig][6] = '1';
			break;
		case 4: 
			s[dig][0] = '1';
			s[dig][1] = '0';
			s[dig][2] = '1'; 
			s[dig][3] = '1';
			s[dig][4] = '1';
			s[dig][5] = '1';
			s[dig][6] = '0';
			break;
		case 5: 
			s[dig][0] = '0';
			s[dig][1] = '1';
			s[dig][2] = '0'; 
			s[dig][3] = '1';
			s[dig][4] = '1';
			s[dig][5] = '1';
			s[dig][6] = '1';
			break;
		case 6: 
			s[dig][0] = '0';
			s[dig][1] = '1';
			s[dig][2] = '1'; 
			s[dig][3] = '0';
			s[dig][4] = '1';
			s[dig][5] = '1';
			s[dig][6] = '1';
			break;
		case 7: 
			s[dig][0] = '0';
			s[dig][1] = '1';
			s[dig][2] = '1'; 
			s[dig][3] = '1';
			s[dig][4] = '0';
			s[dig][5] = '1';
			s[dig][6] = '1';
			break;
		case 8: 
			s[dig][0] = '0';
			s[dig][1] = '1';
			s[dig][2] = '1'; 
			s[dig][3] = '1';
			s[dig][4] = '1';
			s[dig][5] = '0';
			s[dig][6] = '1';
			break;
		case 9: 
			s[dig][0] = '0';
			s[dig][1] = '1';
			s[dig][2] = '1'; 
			s[dig][3] = '1';
			s[dig][4] = '1';
			s[dig][5] = '1';
			s[dig][6] = '0';
			break;
	}

}

int main(){

	fastio;

	int T;
	int n, idx = 1;
	cin >> T;

	while(T--){
		idx = 0;
		cin >> n;
			
		while(n > 0){
			analisa(idx, n % 10);
			n /= 10;
			idx++;
		}		
	
		while(idx < 9){
			analisa(idx, 0);
			idx++;
		}
		
		for(int i = 0; i < 2; i++){
			for(int j = 8; j >= 0; j--)
				cout << s[j][i];
			cout << "\n";
		}
		cout << "---------\n";

		for(int i = 2; i <= 7; i++){
			for(int j = 8; j >= 0; j--)
				cout << s[j][i];
			cout << "\n";
		} 

	}
return 0;
}


