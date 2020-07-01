#include <bits/stdc++.h>
using namespace std;


int main(){

	int n, k, i, cont = 0, j, index;

	scanf("%d %d", &n, &k);


	vector<int> v(n);

	for(i = 0; i < n; i++){	
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());


    vector <int> aux(n, false);

	for(i = 0; i < n; i++){

		if(!aux[i]){

			cont++;
			if(binary_search(v.begin(), v.end(), k * v[i])){
				
				index = lower_bound(v.begin(), v.end(), k*1LL*v[i]) - v.begin();
                aux[index] = true;
			}
		}
	}

printf("%d\n", cont);
return 0;
}