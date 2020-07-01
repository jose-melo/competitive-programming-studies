#include <bits/stdc++.h>
using namespace std;

#define MAX_N 4000
#define INF 1000000000
#define mod 1000000007

long long int f[MAX_N][MAX_N];

int k, n, d; 

long long int solve(int node, int control){

	//printf("node = %d control = %d n = %d\n", node, control, n);

	long long int resp = 0;

	if(node == n){
		if(control == 1)
			resp = (resp + 1) % mod;

	//printf("RETURNED %lli\n", resp);
	return resp;
	}

	if(node > n){

		//printf("RETURNED peido 0\n");
		f[node][control] = 0;
	return 0;
	}

	if(f[node][control] != -1){
		//printf("RETURNED %lli\n", f[node][control]);
		return f[node][control];
	}



	for(int i = 1; i <= k; i++){

		if(node + i <= n){
			if(control != 1){
				if(i >= d)
					control = 1;
				else
					control = 0;
			}

			//printf("node_prox = %d control = %d\n",i + node, control);
			if(f[node + i][control] != -1){
				resp = ((resp % mod) + (f[node + i][control] % mod)) % mod;
				//printf("resp = %lli\n", resp);
			}
			else{
				f[node + i][control] = solve(node + i, control) % mod;
				resp = ((resp % mod) + (f[node + i][control] % mod)) % mod;
				//printf("resp = %lli\n", resp);
			}
		}
	}

//printf("RETURNED %lli\n", resp);
return resp;
}


int main(){


	scanf("%d %d %d", &n, &k, &d);

	//printf("n = %d\n",n );

	for(int i = 0; i <= 10*n; i++){
		f[i][0] = f[i][1] = -1;
	}

	//printf("n = %d\n",n );

	printf("%lli\n", solve(0, 0));


}	