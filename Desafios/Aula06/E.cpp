#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll n, k;
vector<int> resp;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	cin >> n >> k;	
	int i;
	
	double raiz = sqrt(n);
	
	for(i = 1; i <= raiz; i++)
		if(n % i == 0)
			resp.push_back(i);
	i--;
/*	cout << i << " " << raiz << endl;
	for(auto x: resp)
		cout << x << " ";
	cout << "\n";	
*/
	ll tam = 2*resp.size();
	if(i == raiz)tam--;	

//	cout << "tam = " << tam << " size = " << resp.size() << endl;
	if(k > tam){
		cout << "-1\n";
		return 0;
	}

	if(k <= resp.size()){
		cout << resp[k-1] << "\n";
		return 0;
	}

	if(i != raiz)
		cout << n / (resp[(resp.size() - (k % resp.size()))%(resp.size())]) << "\n";
	else
		cout << n / (resp[(resp.size() - (k % resp.size()) - 1)%(resp.size())]) << "\n";
return 0;
}
