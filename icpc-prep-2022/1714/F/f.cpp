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

int main(){

	int t, n, d12, d23, d31;

	cin >> t;
	while(t--){
		cin >> n >> d12 >> d23 >> d31;

		int tmp;
		if(d12 < d31){
			tmp = d31;
			d31 = d12;
			d12 = tmp;
		}

		int level = -1;
		int mini = abs(d12 - d31);
		if(mini == 0)mini = 2;
		for(int i = mini; i <= d12+d31; i+=2){
			if(d23 == i){
				level=(i-mini)/2;
			}
		}
		if(level == -1){
			cout << "NO\n";
			continue;
		}

		int x,y,z, w;
		x = mini;
		y = d23 - x;
		z = y/2;
		w = d12-x-z;
		int node;

		cout << "level: " << level << endl;	

				

	}


}

