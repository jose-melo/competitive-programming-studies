#include <bits/stdc++.h>
#define ll long long
using namespace std;
int pre[300005];
typedef pair<int,int> p;
 
int main()
{
  int n;
	cin>>n;
	ll ans = 0;
	int xx = 0;
	map<pair<int,int> ,int> ma;
	ma[p(0, 0)] = 1;
	for(int i=1;i<=n;i++){
		cin>>pre[i];
		pre[i] ^= pre[i-1];
		ans += ma[p(pre[i], i % 2)] ++;
	}
	cout<<ans<<endl;
  return 0;
}