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
		bool ok = false;
		vector<int> resp;
		for(int i = 1; i <= 2*n && !ok; i++){
		
			ok = true;
			for(int i = 1; i < n; i++)
				if(v[i-1] > v[i])
					ok = false;					
	
			val = *(s2.begin());
		
			int ehn = 0;
			if(val == n){
				for(int i = 0; i < n; i++)
					if(v[i] != i)
						val = i;
			}

			resp.pb(val+1);

			if(freq[v[val]] == 1)
				s2.insert(v[val]);

			freq[val]++;
			freq[v[val]]--;
			
			if(ehn == 0)
				v[val] = val;
			else
				v[val] = n;
			s2.erase(val);
		}

		cout << resp.size() << endl;
		for(auto x: resp)
			cout << x << " ";
		cout << endl;
	}



}

