#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX_N 1100

ll f[MAX_N];
ll a[MAX_N];
ll b[MAX_N];

vector<pair<ll, ll>> v;

ll ponte;
ll maxi;
void pd(ll n){

	ponte = 1;
	maxi  = 0;
	//prllf("pd: \n");

	f[0] = 1;
	for(ll i = 0; i < n; i++){
		f[i] = 1;
		for(ll j = 0; j < i; j++){

			//prllf("i = %lli j = %lli  v[j].first = %lli v[i].first = %lli v[j].second = %lli v[i].second = %lli \n ", i, j, v[j].first, v[i].first, v[j].second, v[i].second);

			if(/*v[j].first <= v[i].first && */v[j].second <= v[i].second && f[i]<f[j]+1){
				f[i] = max(f[i], f[j] + 1);
			}
		}
	}
	/*for(ll i=0;i<MAX_N;i++)
      {
        f[i]=1;
        for(ll j=0;j<i;j++)
        {
           if(v[i].second>=v[j].second && f[i]<f[j]+1)
           {f[i]=f[j]+1;}
        }
        maxi=max(f[i],maxi);
	}*/
}

void clean(ll n){

	for(ll i = 0; i < MAX_N; i++){
		f[i] = 0;
	}
	v.clear();
return;
}

int main(){

	ll n, t;

	scanf("%lli", &t);

	while(t--){

		scanf("%lli", &n);

		for(ll i = 0; i < n; i++)
			scanf("%lli", &a[i]);
		for(ll i = 0; i < n; i++)
			scanf("%lli", &b[i]);

		v.clear();
		for(ll i = 0; i < n; i++)
			v.push_back(make_pair(a[i], b[i]));

		/*prllf("v: ");
		for(auto x = v.begin(); x < v.end(); x++)
			prllf("(%lli %lli) ", x->first, x->second);
		prllf("\n");*/

		ponte = 0;

		for(ll i = 0; i < n; i++)
			f[i] = 1;

		sort(v.begin(), v.end());

		pd(n);

		/*prllf("ponte: ");
		for(ll i = 0; i < ponte; i++)
			prllf("%lli ", f[i]);
		prllf("\n");*/

		sort(f, f + n + 1, greater<ll>());

		/*prllf("f: ");
		for(ll i = 0; i < n; i++)
			prllf("%lli ", f[i]);
		prllf("\n");*/

		printf("%lli\n", f[0]);
		clean(n);
	}
return 0;
}


