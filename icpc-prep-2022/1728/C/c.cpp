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
		vector<int> a, b;
		unordered_map<int, int> m1, m2;
		set<int> s1, s2, trash;	
		cin >> n;
		FI(n){
			cin >> tmp;
			a.pb(tmp);
			s1.insert(tmp);
			trash.insert(tmp);
			m1[tmp] += 1;
		}
		FI(n){
			cin >> tmp;
			b.pb(tmp);
			s2.insert(tmp);
			m2[tmp] += 1;
		}

	
		for(auto x : trash){
			if(s2.find(x) != s2.end()){
				if(m2[x] > m1[x]){
					s1.erase(x);
					m2[x] -= m1[x];
					m1[x] = 0;
				}else if(m1[x] > m2[x]){
					s2.erase(x);
					m1[x] -= m2[x];
					m2[x] = 0;
				}else{
					m1[x] = 0;
					m2[x] = 0;
					s1.erase(x);
					s2.erase(x);
				}	
			}
		}

		//cout << "s1: " << endl;
		//for(auto x: s1){
			//cout << x << " ";
		//}
		//cout << endl;
		
		//cout << "s2: " << endl;
		//for(auto x: s2){
			//cout << x << " ";
		//}
		//cout << endl;


		int res = 0;
		while(!s1.empty()){
			int val_1 = *s1.rbegin();
			int val_2 = *s2.rbegin();
			int val;

			//cout << "s1: " << " ";
			//for(auto x: s1){
				//cout << x << " ";
			//}
			//cout << endl;
			
			//cout << "s2: " << " ";
			//for(auto x: s2){
				//cout << x << " ";
			//}
			//cout << endl;

			if(val_1 >= val_2){
				val = ceil(log10(val_1));
				if(val_1 == 1 || ceil(log10(val_1)) == floor(log10(val_1)))val++;
				//cout << "val_1 " << val_1 <<  " val " << val << endl;
				if(m1[val_1] == 1)s1.erase(val_1);
				m1[val_1]--;
				res++;
				if(s2.find(val) != s2.end()){
					if(m2[val] == 1){
						s2.erase(val);
					}
					m2[val]--;
				}else{
					s1.insert(val);
					m1[val]++;
				}
			}else{
				val = ceil(log10(val_2));
				if(val_2 == 1 || ceil(log10(val_2)) == floor(log10(val_2)))val++;
				//cout << "val_2 " << val_2 << " val " << val << endl;
				if(m2[val_2] == 1)s2.erase(val_2);
				m2[val_2]--;
				res++;
				if(s1.find(val) != s1.end()){
					if(m1[val] == 1){
						s1.erase(val);
					}
					m1[val]--;
				}else{
					s2.insert(val);
					m2[val]++;
				}
			}
		}

		cout << res << endl;

		a.clear();
		b.clear();
		m1.clear();
		m2.clear();
		s1.clear();
		s2.clear();
	}
}

