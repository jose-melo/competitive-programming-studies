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

int T;
int n;
ll sumA, sumB;


int main(){


	cin >> T;

	while(T--){

		cin >> n;

		sumA = 0;
		
		for(int i = n-1; i >= n/2; i--)
			sumA += (1<<i);

		sumB = (1<<n);
		for(int i = 1; i < n/2; i++)
			sumB += (1<<i);

		cout << sumB-sumA << endl;


	}


}
