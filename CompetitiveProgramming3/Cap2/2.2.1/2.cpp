#include <bits/stdc++.h>
using namespace std;

int n;
set<int> S;

int main(){

	int v;

	cin >> n >> v;
	
	int val;
	for(int i = 0; i < n; i++){
		cin >> val;

		if(!S.empty()){
			 if(S.find(v - val) != S.end()){
				cout << "Os elementos são: " << v-val << " + " << val << " = " << v << endl;
				return 0;
			}
		}
		S.insert(val);
	}

	cout << "Not found such pair" << endl;

	return 0;
}

