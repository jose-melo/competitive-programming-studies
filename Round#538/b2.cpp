/*https://codeforces.com/contest/1114/problem/B*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define INF 0x3f3f3f3f
#define ll long long int
#define pii pair<ll, int>
#define mp make_pair


int n, m, k, num_subarrays;
ll num[MAX];
vector<pii> num_aux;
ll soma;

int main(){

	cin >> n >> m >> k;

	int index[MAX];

	for(int i = 1; i <= n; i++){
		scanf("%lld", &num[i]);
		num_aux.push_back(mp(num[i], i));
	}

	sort(num_aux.begin(), num_aux.end());
	
	vector<int> idx_pegar;
	for(int i = num_aux.size(), i >= m*k; i--)
		idx_pegar.push_back(num_aux[i].second);

	vector<int> cortes;
	for(int i = 0; i < k-1; i++)
		cortes.push_back(());

	printf("%lld\n", soma);
	for(int i = 0; i < cortes_idx; i++)
		printf("%d ", index[i]);
	printf("\n");
return 0;
}






