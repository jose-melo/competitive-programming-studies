#include <bits/stdc++.h>
using namespace std;

long long int n;
vector<int> resp;

int main(){

	cin >> n;

			long long int somaTotal = ((1+n)*n)/2;
	
	if(somaTotal % 2)
		cout << "1\n";
	else
		cout << "0\n";

	long long int atual = n;
	long long int cont = 0;
	long long int somaGrupo = somaTotal / 2;
	while(somaGrupo > atual){
		resp.push_back(atual);
		somaGrupo -= atual;
		atual--;
		cont++;
	}
	
	resp.push_back(somaGrupo);
	cont++;
	cout << cont << " ";
	for(auto x : resp)
		cout << x << " ";
	cout << "\n";

return 0;
}




