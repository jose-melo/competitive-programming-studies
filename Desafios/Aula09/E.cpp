#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> freq;


int main(){

	cin >> n;
	int aux;
	for(int i = 0; i < n; i++){
		
		cin >> aux;
		if(freq.find(aux) != freq.end())
			freq[aux]++;
		else
			freq.insert(make_pair(aux, 1));
	}

	int max = -1;

	for(auto x : freq)
		if(x.second > max)
			max = x.second;

	cout << max << "\n";
return 0;
}





