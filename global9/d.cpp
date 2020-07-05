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

int main(){

	cin >> t;

	while(t--){
		
		cin >> n;
		vector<int> v;
		int aux;
		set<int> s1, s2;
		int freq[1002];

		memset(freq ,0, sizeof(freq));

		FI(n){
			cin >> aux;
			v.pb(aux);
			s1.insert(aux);
		}

		for(int i = 0; i < n; i++)
			freq[v[i]]++;
				
		

		for(int i= 0; i <= n; i++)
			if(s1.find(i) == s1.end())
				s2.insert(i);

		int val;
		vector<int> resp;
		for(int i = 1; i <= 2*n; i++){
					
			val = *(s2.begin());
			if(val == n)val--;
			resp.pb(val+1);


			if(freq[v[val]] == 1)
				s2.insert(v[val]);

			freq[v[val]]--;
			v[val] = val;
			s2.erase(val);
		}

		
		cout << resp.size() << endl;
		for(auto x: resp)
			cout << x << " ";
		cout << endl;


	}



}

