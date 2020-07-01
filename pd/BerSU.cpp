//https://codeforces.com/problemset/problem/489/B
#include <bits/stdc++.h>
using namespace std;


int memo[101][101], boys[101], girls[101];
int num_boys,  num_girls;

int pd(int i, int j){

	if(i == num_boys || j == num_girls)
		return 0;

	if(i > num_boys || j > num_girls)
		return -(1<<30);

	if(memo[i][j] != -1)
		return memo[i][j];

	if(abs(boys[i] - girls[j]) <= 1)
		memo[i][j] = pd(i+1, j+1) + 1;
	else
		memo[i][j] = max(pd(i, j+1), pd(i+1, j));
return memo[i][j];
}



int main(){

	cin >> num_boys;
	for(int i = 0; i < num_boys; i++)
		cin >> boys[i];


	cin >> num_girls;
	for(int i = 0; i < num_girls; i++)
		cin >> girls[i];

	sort(boys, boys + num_boys);
	sort(girls, girls + num_girls);

	for(int i = 0; i < num_boys; i++)
		for(int j = 0; j < num_girls; j++)
			memo[i][j] = -1;

	cout << pd(0, 0) << endl;


}





