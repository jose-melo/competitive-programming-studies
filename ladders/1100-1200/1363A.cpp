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

int t, n, x;

int main(){

	cin >> t;

	while(t--){

		cin >> n >> x;

		int odd = 0, even = 0;

		int aux;
		FI(n){
			cin >> aux;
			if(aux%2)
				odd++;
			else
				even++;
		}


		if(odd == 0){
			cout << "No\n";
			continue;
		}
	
		if(odd%2==0)odd--;

//		cout << x << " " << odd << " " << even << endl;

		if(odd >= x){
			if(x%2)
				x = 0;
			else
				x = 1;
		}else{
			x -= odd;
		}

//		cout << "x: " << x << endl;

		if(x == 0 || even >= x)
			cout << "Yes\n";
		else
			cout << "No\n";

		



	}



}

