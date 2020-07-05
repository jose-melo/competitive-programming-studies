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

int t, a, b, c, d, x, y, x1, x2;
int y_1, y_2;

int main(){

	cin >> t;

	while(t--){

		cin >> a >> b >> c >> d;

		cin >> x >> y >> x1 >> y_1 >> x2 >> y_2;

		if(x1 == x2 && (a != 0 || b != 0)){
			cout << "NO\n";
			continue;
		}

		if(y_1 == y_2 && (c != 0 || d != 0)){
			cout << "NO\n";
			continue;
		}
				 
		if(x == x1 && a != 0 && b == 0){
			cout << "NO\n";
			continue;
		}
		
		if(x == x2 && b != 0 && a == 0){
			cout << "NO\n";
			continue;
		}

		if(y == y_1 && c != 0 && d == 0){
			cout << "NO\n";
			continue;
		}

		if(y == y_2 && d != 0 && c == 0){
			cout << "NO\n";
			continue;
		}

		if(a >= b)
			x -= (a-b);
		else
			x += (b-a);		

		if(c >= d)
			y -= (c-d);
		else
			y += (d-c);

		if(x < x1 || x > x2 || y < y_1 || y > y_2){
			cout << "NO\n";
			continue;
		}		

		cout << "YES\n";
		
	}



}

