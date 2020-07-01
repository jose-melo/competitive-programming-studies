#include <bits/stdc++.h>
using namespace std;


int n;
int memo[212345];
int input[21235];
vector<int> resp;


int pd(int idx, int ultimo){

	cout << idx << " " << ultimo << endl;

	if(idx > n)return 0;

	if(memo[idx] != -1)
		return memo[idx];

	
	int a = -1, b = -1;

	if(ultimo < 0 || input[idx] == ultimo+1)
		a = pd(idx+1, input[idx]) + 1;

	b = pd(idx+1, ultimo);
	
	memo[idx] = max(a, b);
	
	if(a > b)
		resp.push_back(idx);

return memo[idx];
}


int main(){

	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> input[i];	

	for(int i = 0; i <= n; i++)
		memo[i] = -1;
	
	cout << pd(1, -1) << endl;
	
	for(vector<int>::iterator it = resp.end()-1; it >= resp.begin(); it--)
		cout << *it << " ";
	cout << "\n";


return 0;
}


