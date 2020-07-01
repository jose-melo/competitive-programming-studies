#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX_N 1000


typedef struct {
	
	ll x;
	ll y;
	ll max;

} point;

point f[MAX_N];

bool comparator1(point a, point b){
	return a.y < b.y;
}

bool comparator2(point a, point b){
	return a.max > b.max;
}


double sinal(point p1, point p2, point p3){
	//printf("p1 = (%lli %lli) p2 = (%lli %lli) p3 = (%lli %lli)\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
	double res1 = ((p2.x - p1.x) * (p3.y - p2.y)), res2 = ((p3.x - p2.x)*(p2.y - p1.y));

	//printf("res1 = %lf, res2 = %lf\n", res1, res2);

	double res = res1 - res2;
return res;
}

bool esta_dentro(point a, point p, point b, point x){
	
	double aux = sinal(a, p, x), aux2 = sinal(b, p, x);

	//printf("esta dentro:p = (%lli %lli) x = (%lli %lli)  aux = %lf, aux2 = %lf\n",p.x, p.y, x.x, x.y, aux, aux2);

	if(aux < 0 && aux2 > 0)
		return true;
return false;
}

void pd(ll n, point a, point b){

	//printf("pd:\n");


	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j < i; j++){

			//printf("i = %lli j = %lli\n", i, j);

			if(esta_dentro(a, f[i], b, f[j])){
				f[i].max = max(f[i].max, f[j].max + 1);
				//printf("f[i].max = %lli\n", f[i].max);
			}
		}
	}
}

int main(){

	ll n;
	point a, b;

	scanf("%lli %lli %lli", &n, &a.x, &b.x);
	a.y = 0;
	b.y = 0;


	for(ll i = 1; i <= n; i++)
		f[i].max = 1;

	for(ll i = 1; i <= n; i++)
		scanf("%lli %lli", &f[i].x, &f[i].y);

	/*printf("f: ");
	for(ll i = 1; i <= n; i++)
		printf("(%lli, %lli, %lli)", f[i].x, f[i].y, f[i].max);
	printf("\n");*/

	sort(f + 1, f + n + 1, comparator1);

	/*printf("f: ");
	for(int i = 1; i <= n; i++)
		printf("(%lli, %lli, %lli)", f[i].x, f[i].y, f[i].max);
	printf("\n");*/

	pd(n, a, b);

	sort(f + 1, f + n + 1, comparator2);

	printf("%lli\n", f[1].max);
return 0;
}










