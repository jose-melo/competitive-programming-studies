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

int t, n, m, x, y;

char mat[112][1123];

int main(){

	cin >> t;

	while(t--){

		cin >> n >> m >> x >> y;

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> mat[i][j];

		int idx, cont1 = 0, cont2 = 0;
		for(int i = 0; i < n; i++){
			idx = 0;
			while(idx < m-1){
				if(mat[i][idx] == '.' && mat[i][idx+1] == '.'){
					cont1++;
					idx += 2;
				}else{
					if(mat[i][idx] == '.')cont2++;
					idx++;
				}
			}
//			cout << mat[i][idx] << " " << i << " " << idx << " "<<"\n";
			if(idx == m-1 && mat[i][idx] == '.')cont2++;
		}

		if(2*x <= y){
			cout << x*(cont2 + 2*cont1) << endl;
		}else{
			cout << x*cont2 + y*cont1 << endl;
		}
	}



}

