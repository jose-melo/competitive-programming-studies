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

int T, n, idx1, idx2;
string s, resp;


int main(){

	cin >> T;
	
	while(T--){
		cin >> n;
		cin >> s;

		resp.clear();

		idx1 = idx2 = -1;	
		for(int i = 0; i < n; i++){
			if(s[i] == '1'){
				idx1 = i;
				break;
			}
		}
		
		if(idx1 != -1){
			for(int i = 0; i < n; i++){
				if(s[i] == '1'){
					idx1 = i;
					break;
				}
				resp.pb('0');
			}
		}

	
		for(int i = n-1; i >= 0; i--){
			if(s[i] == '0'){
				idx2 = i;
				break;
			}
		}
		
		if(idx1 == -1 || idx2 == -1 || idx1 > idx2){
			cout << s << endl;
			continue;
		}

		for(int i = idx2; i < n; i++){
			resp.pb(s[i]);
		}
		cout << resp << endl;	

	}



}
