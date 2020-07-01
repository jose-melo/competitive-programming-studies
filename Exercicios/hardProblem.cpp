#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define INF 1000000000
#define mod 1000000007
#define ll long long int

ll f1[MAX_N];
ll f2[MAX_N];
ll cu[MAX_N];
string palavras[MAX_N];

int n;

int eh_possivel(int pal, int inversionA, int inversionB, int inversionC){

	string auxA, auxB, auxC;

	if(pal > 1)auxA = palavras[pal - 1];
	if(pal < n )auxC = palavras[pal + 1];
	auxB = palavras[pal];

	//printf("%s\n", palavras[pal].c_str());

//	printf("##1111testes (A, B) = %d (B, C) = %d\nA = %s B = %s C = %s\n",strcmp(auxA.c_str(), auxB.c_str()),strcmp(auxB.c_str(), auxC.c_str()),auxA.c_str(),auxB.c_str(),auxC.c_str());
		

	if(inversionA == 1)
		reverse(auxA.begin(), auxA.end());
	if(inversionB == 1)
		reverse(auxB.begin(), auxB.end());
	if(inversionC == 1)
		reverse(auxC.begin(), auxC.end());

	if(pal != 1 && pal != n){
		//printf("testes (A, B) = %d (B, C) = %d\nA = %s B = %s C = %s\n",strcmp(auxA.c_str(), auxB.c_str()),strcmp(auxB.c_str(), auxC.c_str()),auxA.c_str(),auxB.c_str(),auxC.c_str());
		if(strcmp(auxA.c_str(), auxB.c_str()) < 0 && strcmp(auxB.c_str(), auxC.c_str()) < 0)
			return 1;
		else
			return 0;		
	}

	if(pal == 1 && pal != n){
		if(strcmp(auxB.c_str(), auxC.c_str()) < 0)
			return 1;
		else
			return 0;
	}
	
	if(pal == n && pal != 1){
		if(strcmp(auxA.c_str(), auxB.c_str()) < 0)
			return 1;
		else
			return 0;
	}

return 0;
}




int memoization(int i, int j){

	//printf("i = %d j = %d\n",i, j);

	if(i == j){
		//printf("RETURNED 0\n");
		return 0;
	}

	if(f1[i] != -1 && f2[j] != -1){
		//printf("RETURNED %lli\n",f1[i]);
		return f1[i];
	}


	ll min = INF, min_real = INF, aux2;
	int o, p, q, oa, ob, oc, pal, pal_min;
	o = p = q = oa = ob = oc = -1;

	if(i + 1 == j){

		ll aux = 0, aux2 = 0; 

		if((f1[i] != -1 && f2[i] != -1) && (f1[i + 1] != -1 && f2[j] != -1))
			aux = f1[i] + f1[i - 1];
		else
			aux = memoization(i, i) + memoization(i + 1, j);

		aux2 = aux;
		if(eh_possivel(i, 0, 0, 0) == 0){
			for(int a = 0; a < 2; a++){	
				for(int b = 0; b < 2; b++){
					for(int c = 0; c < 2; c++){


						int posible = eh_possivel(i, a, b, c);
						//printf("a = %d b = %d c = %d posible = %d\n",a, b, c, posible);

						if(posible == 1){
							if(a == 1)aux += cu[i - 1];
							if(b == 1)aux += cu[i];
							if(c == 1)aux += cu[i + 1];

							if(aux < min && aux != 0){
								//printf("aux = %lli\n", aux);
								min = aux;
								o = a;
								p = b;
								q = c;
								pal = i;
							}
							aux = aux2;

						}
					}
				}	
			}
		}else{
			//printf("eh_possivel sem mudanca, aux = %lli\n", aux);
			if(min_real == INF)min_real = aux;
			oa = ob = oc = -1;
		}

		if(min < min_real){
			min_real = min;
			//printf("min_real = %lli\n", min_real);
			oa = o;
			ob = p;
			oc = q;
			pal_min = pal;
		}
	}


	for(int k = i + 1; k < j; k++){

		ll aux = 0, aux2 = 0; 

		if((f1[i] != -1 && f2[i] != -1) && (f1[i + 1] != -1 && f2[j] != -1))
			aux = f1[i] + f1[i - 1];
		else
			aux = memoization(i, i) + memoization(i + 1, j);

		aux2 = aux;
		//if(i == 1 && j == 4)
			//printf("############################AUX = %lli k = %d\n", aux, k);

		if(eh_possivel(k, 0, 0, 0) == 0){
			for(int a = 0; a < 2; a++){	
				for(int b = 0; b < 2; b++){
					for(int c = 0; c < 2; c++){

						int posible = eh_possivel(k, a, b, c);

						//printf("a = %d b = %d c = %d posible = %d\n",a, b, c, posible);

						if( posible == 1){
							if(a == 1){aux += cu[k - 1];}
							if(b == 1){aux += cu[k];}
							if(c == 1){aux += cu[k + 1];}

							if(aux < min && aux != 0){
								//printf("aux = %lli\n", aux);
								min = aux;
								o = a;
								p = b;
								q = c;
								pal = k;
							}
							aux = aux2;

						}
					}
				}	
			}
		}else{
			//printf("eh_possivel sem mudanca, aux = %lli\n", aux);
			if(min_real == INF)min_real = aux;
			oa  = ob = oc = -1;
		}

		if(min < min_real){
			min_real = min;
			//printf("min_real = %lli\n", min_real);
			oa = o;
			ob = p;
			oc = q;
			pal_min = pal;
		}
	}

	f1[i] = f2[j] = min_real;
	
	if(oa == 1){
		//printf("INVERSAO %s para", palavras[pal_min - 1].c_str());
		reverse(palavras[pal_min - 1].begin(), palavras[pal_min - 1].end());
		//printf("%s\n", palavras[pal_min - 1].c_str());
	}
	if(ob == 1){
		//printf("INVERSAO %s para", palavras[pal_min].c_str());
		reverse(palavras[pal_min].begin(), palavras[pal_min].end());
		//printf("%s\n", palavras[pal_min].c_str());
	}
	if(oc == 1){
		//printf("INVERSAO %s para", palavras[pal_min + 1].c_str());
		reverse(palavras[pal_min + 1].begin(), palavras[pal_min + 1].end());
		//printf("%s\n", palavras[pal_min + 1].c_str());
	}

//printf("RETURNED %lli\n", f1[i]);
return f1[i];
}


int main(){


	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		scanf("%lli", &cu[i]);


	for(int i = 0; i <= n; i++)
			f1[i] = -1;
	for(int j = 0; j <= n; j++)
			f2[j] = -1;

	for(int i = 1; i <= n; i++)
		cin >> palavras[i];

	ll res = memoization(1, n);

	if(res != INF)
		printf("%lli\n",res);
	else
		printf("-1\n");
return 0;
}


