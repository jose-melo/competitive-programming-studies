/*https://codeforces.com/problemset/problem/253/B*/
#include <bits/stdc++.h>
using namespace std;


vector<int> v;

int main(){


	ifstream pfin("input.txt");
	ofstream pfout("output.txt");

	int n, aux;
	
	pfin >> n;
	
	for(int i = 0; i < n; i++){
		pfin >> aux;
		v.push_back(aux);
	}

	sort(v.begin(), v.end());

	int min = 112345, res;
	for(int i = 0; i < n; i++){
		
		int l = i+1, r = n, mid;
		while(l < r){
			mid = (l + r)/2;

			if(v[mid] > 2*v[i])
				r = mid;
			
			if(v[mid] <= 2*v[i])
				l = mid+1;
		}
		res = n - (l-i);
		if(res < min)
			min = res;
	}

	pfout << min << endl;
	
return 0;
}



