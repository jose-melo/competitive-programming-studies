#include <bits/stdc++.h>
using namespace std;

int n;

int main(){

	cin >> n;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int p, q, cont = 0;
	bool control = true;
	vector<int> resp;

	p = 1;
	q = n;
	while(p < q-1){
		
		if(control){
			resp.push_back(p);
			resp.push_back(q);
		}
		cont++;
		control = !control;
		p++;
		q--;
	}


	if(p == q-1){
		if(cont % 2){
			cout << "0\n";
		}else{
			cout << "1\n";		
			resp.push_back(p);
		}
	}else if(p == q){
		cout << p << "\n"; 
	}
	
	cout << resp.size() << " ";
	for(auto x : resp)
		cout << x << " ";
	cout << "\n";


return 0;
}





