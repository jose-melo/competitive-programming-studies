#include <bits/stdc++.h>
using namespace std;

int m, s;
int res_menor[200];


int main(){

	int idx = 0;
	cin >> m >> s;
	int aux_m = m;
	int aux_s = s;
	int dig = s%9;
	if(dig == 0)
		dig = 1;
	aux_s -= dig;
	res_menor[idx] = dig;
	idx++;
	aux_m--;
	while(aux_m	> 1){
		dig = aux_s%9;
		if(aux_s == 9)dig = 9;

		res_menor[idx] = dig;
		idx++;
		aux_m--;
		aux_s -= dig;
	}
	
	if(aux_s > 9 || s == 0){
		cout << "-1 -1\n";
		return 0;
	}

	res_menor[idx] = aux_s;
	idx++;

	for(int i = 0; i < idx; i++)
		cout << res_menor[i];
	cout << " ";
	for(int i = 0; i < idx; i++)
		cout << s - res_menor[i];
	cout << "\n";
return 0;
}


