#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int n;
int memo[212345];
vector<pii> input;
vector<int> resp;
set<int> repetidos;

struct comparator{
	
	bool operator()(const pii& lhs, const pii& rhs){
		pii a = lhs;
		pii b = rhs;

		if(a.first < b.first)
			return true;

		if(a.first == b.first)
			if(a.second > b.second)
				return true;

		return false;

	}
	
}objeto;


int main(){
	
	cin >> n;
	int aux;
	for(int i = 0; i < n; i++){
		cin >> aux;	
		input.push_back(make_pair(aux, i));
	}
	
	sort(input.begin(), input.end(), objeto);
	
	int idx = 0, start = 0, cont = 1, max = -1;
	for(int i = 0; i < input.size()-1; i++){
		
		if(input[i+1].first == input[i].first)continue;	
		if(input[i+1].second > input[i].second){
			cont++;
		}else{
			if(cont > max){
				max = cont;
				start = idx;
			}
			cont = 1;
			idx = i+1;
		}
	}
	if(cont > max){
		max = cont;
		start = idx;
	}
		

	resp.push_back(input[start].second+1);
	repetidos.insert(input[start].first);

	for(int i = start; i < input.size()-1; i++){
		if(input[i+1].second < input[i].second)break;
		if(repetidos.find(input[i+1].first) == repetidos.end())
			resp.push_back(input[i+1].second+1);
		repetidos.insert(input[i+1].first);
	}

	cout << resp.size() << endl;

	for(auto x : resp)
		cout << x << " ";

	cout << "\n";


return 0;
}


