#include <bits/stdc++.h>
using namespace std;

int n, ultimo;
int input[212345];
int LIS[212345];
map<int, int> resp;
vector<int> res;



int main(){

	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> input[i];
		resp[input[i]] = max(resp[input[i]], resp[input[i] - 1]+1);
	}

	int maxx = -1;
	for(int i = n; i >= 1; i--)
		if(resp[input[i]] > maxx){
			maxx = resp[input[i]];
			ultimo = input[i];
		}	
		
	for(int i = n; i >= 1; i--)
		if(input[i] == ultimo){
			res.push_back(i);
			ultimo--;
		}

	cout << res.size() << endl;

	for(vector<int>::iterator it = res.end()-1; it >= res.begin(); it--)
		cout << *it << " ";

	cout << "\n";

return 0;
}




