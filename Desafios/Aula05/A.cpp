 #include <bits/stdc++.h>
 using namespace std;
 
 int n, a, b, sumTotal;
 int dist[110];
 
 int main(){

	int sum1 = 0, sum2, sumTotal;

        cin >> n;
	sumTotal = 0; 
        for(int i = 1; i <= n; i++){
        	scanf("%d", &dist[i]);
        	sumTotal += dist[i]; 
	}
	cin >> a >> b;
	
	if(a > b)swap(a, b);
	for(int i = a; i < b; i++)
		sum1 += dist[i];
	
	sum2 = sumTotal - sum1;	
	int res = min(sum1, sum2);

	printf("%d\n", res);

return 0;
}
