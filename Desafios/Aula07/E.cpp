#include <bits/stdc++.h>
using namespace std;

int a, b;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a >> b;
	
	if(a == b){
		cout << "infinity\n";
		return 0;
	}
	
	if(a-b < 0){
		cout << "0\n";
		return 0;
	}

	int diff  = a-b;
	vector<int> v;	
	
	int i;
	double raiz = sqrt(diff);

	for(i = 1; i <= raiz; i++)
		if(diff % i == 0)
			v.push_back(i);
	
	i--;

	if(b == raiz){
		cout << v.size() - 1 << endl;
		return 0;
	}

	if(b < raiz){
		int k;
	
		for( k = 0; k < v.size() && v[v.size()-1-k] > b; k++); 
		if(i != raiz)
			cout << k + v.size() << "\n";
		else
			cout << k + v.size() - 1<< "\n";
	
		return 0;
	}
	
	int k;
	for(k = 0; k < v.size() && diff/v[k] > b; k++);

	cout << k << "\n";

return 0;
}

