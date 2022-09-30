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

	int t, n, tmp;

	cin >> t;
	while(t--){
		cin >> n;
		priority_queue<int> p1, p2;

		FI(n){
			cin >> tmp;
			p1.push(tmp);
		}

		FI(n){
			cin >> tmp;
			p2.push(tmp);
		}
	
		int res = 0;
		int val;
		while(!p1.empty()){
			int val1 = p1.top();
			int val2 = p2.top();
			if(val1 == val2){
				p1.pop();
				p2.pop();
			}else{
				
				if(val1 > val2){
					val = ceil(log10(val1));
					if(val1 == 1 || (int)ceil(log10(val1)) == (int)floor(log10(val1)))val++;
					res++;
					p1.pop();
					p1.push(val);
				}else{
					val = ceil(log10(val2));
					if(val2 == 1 || (int)ceil(log10(val2)) == (int)floor(log10(val2)))val++;
					res++;
					p2.pop();
					p2.push(val);
				}	
			}
		}
		cout << res << endl;	
	}
}

