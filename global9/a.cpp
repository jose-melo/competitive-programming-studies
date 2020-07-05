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

int t, n, p;

int main(){

	cin >> t;

	while(t--){

		cin >> n;

		vector<int> a(n+1), b(n+1);
		
		for(int i= 0; i < n; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		
		if(a[n-1] - a[n-2] >= 0)
			p = 1;
		else
			p = 0;

		for(int i = n-2; i > 0; i--){
			if(p){
				if(b[i-1] <= 0)
					b[i-1] *= -1;
			}else{
				if(b[i-1] >= 0)
					b[i-1] *= -1;
			}
			p ^= 1;
		}	
		
		for(int i = 0; i < n; i++)
			cout << b[i] << " ";
		cout << endl;


	}



}

