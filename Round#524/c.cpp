#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<ll, ll>
#define x first
#define y second


bool checa_englobado(pii a, pii b){

	cout << "a = ("<<a.x<<", "<<a.y<< ")  b = ("<< b.x<<", "<< b.y << ") "<< endl;
	if(b.x <= a.x && b.y <= a.y)
		return true;
	
return false;
}


int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll T, n, m, eng1_w, eng1_b, eng2_b, eng2_w;
	pii p1White, p2White, p1Black, p2Black;

	cin >> T;

	while(T--){

		eng1_w = 0;
		eng2_w = 0;

		eng1_b = 0;
		eng2_b = 0;
		cin >> n >> m;
		cin >> p1White.x >> p1White.y >> p2White.x >> p2White.y;
		cin >> p1Black.x >> p1Black.y >> p2Black.x >> p2Black.y;

		ll tabWhite, tabBlack;
		tabWhite = tabBlack = (m*n)/2;

		if(checa_englobado(p1White, p1Black))eng1_w++;
		if(checa_englobado(p1White, p2Black))eng1_w++;
		if(checa_englobado(p2White, p1Black))eng2_w++;
		if(checa_englobado(p2White, p2Black))eng2_w++;

		if(checa_englobado(p1Black, p1White))eng1_b++;
		if(checa_englobado(p1Black, p2White))eng1_b++;
		if(checa_englobado(p2Black, p1White))eng2_b++;
		if(checa_englobado(p2Black, p2White))eng2_b++;

		cout << "eng1_w = " << eng1_w << " eng2_w = " << eng2_w << endl;
		cout << "eng1_b = " << eng1_b << " eng2_b = " << eng2_b << endl;
		//Caso 1:
		if(eng2_w == 2 && eng1_w == 1 && eng2_b == 1 && eng1_b == 0){
			ll res_x = p2Black.x - p1White.x+1; 
			ll res_y = p2Black.y - p1White.y+1;

			ll totalWhite = (p2White.x-p1White.x+1)*(p2White.y-p1White.y+1);
			totalWhite -= res_x*res_y;

			ll totalBlack = (p2Black.x-p1Black.x+1)*(p2Black.y-p1Black.y+1);

			cout << totalWhite << " " << totalBlack << endl;
			continue;
		}

		//Caso 2:
		if(eng2_w == 1 && eng1_w == 1 && eng2_b == 2 && eng1_b == 0){

			ll res_x = p2White.x - p1White.x+1;
			ll res_y = p2Black.y - p1White.y+1;

			ll totalWhite = (p2White.x-p1White.x+1)*(p2White.y-p1White.y+1);
			totalWhite -= res_x*res_y;

			ll totalBlack = (p2Black.x-p1Black.x+1)*(p2Black.y-p1Black.y+1);

			cout << totalWhite << " " << totalBlack << endl;
			continue;
		}



		//Caso 3:
		if(eng2_w == 2 && eng1_w == 0 && eng2_b == 1 && eng1_b == 1){

			ll totalWhite = (p2White.x-p1White.x+1)*(p2White.y-p1White.y+1);
			ll totalBlack = (p2Black.x-p1Black.x+1)*(p2Black.y-p1Black.y+1);

			totalWhite -= totalBlack;

			cout << totalWhite << " " << totalBlack << endl;
			continue;
		}		

		//Caso 4:
		if(eng2_w == 2 && eng1_w == 2 && eng2_b == 0 && eng1_b == 0){

			ll totalWhite = (p2White.x-p1White.x+1)*(p2White.y-p1White.y+1);
			ll totalBlack = (p2Black.x-p1Black.x+1)*(p2Black.y-p1Black.y+1);
			cout << totalWhite << " " << totalBlack << endl;
			continue;
		}


		//Caso 1.2:
		if(eng2_b == 2 && eng1_b == 1 && eng2_w == 1 && eng1_w == 0){

			ll res_x = p2White.x - p1Black.x+1;
			ll res_y = p2White.y - p1Black.y+1;

			ll totalBlack = (p2Black.x-p1Black.x+1)*(p2Black.y-p1Black.y+1);
			
			ll totalWhite = (p2White.x-p1White.x+1)*(p2White.y-p1White.y+1);
			totalWhite -= res_x*res_y;

			cout << totalBlack << " " << totalWhite << endl;
			continue;
		}

		//Caso 2.2:
		if(eng2_b == 1 && eng1_b == 1  && eng2_w == 2 && eng1_w == 0){

			ll res_x = p2Black.x - p1Black.x+1;
			ll res_y = p2White.y - p1Black.y+1;

			ll totalBlack = (p2Black.x-p1Black.x+1)*(p2Black.y-p1Black.y+1);
			

			ll totalWhite = (p2White.x-p1White.x+1)*(p2White.y-p1White.y+1);
			totalWhite -= res_x*res_y;

			cout << totalBlack << " " << totalWhite << endl;
			continue;
		}



		//Caso 3.2:
		if(eng2_b == 2 && eng1_b == 0 && eng2_w == 1 && eng1_w == 1){

			ll totalBlack = (p2Black.x-p1Black.x+1)*(p2Black.y-p1Black.y+1);
			ll totalWhite = (p2White.x-p1White.x+1)*(p2White.y-p1White.y+1);

			totalWhite = 0;

			cout << totalBlack << " " << totalWhite << endl;
			continue;
		}		

		//Caso 4.2:
		if(eng2_b == 2 && eng1_b == 2 && eng2_w == 0 && eng1_w == 0){

			ll totalBlack = (p2Black.x-p1Black.x+1)*(p2Black.y-p1Black.y+1);
			ll totalWhite = (p2White.x-p1White.x+1)*(p2White.y-p1White.y+1);
			cout << totalBlack << " " << totalWhite << endl;
			continue;
		}

		//Caso 5
		if(eng2_b == 2 && eng1_b == 1 && eng2_w == 0 && eng1_w == 0){

			ll totalBlack = (p2Black.x-p1Black.x+1)*(p2Black.y-p1Black.y+1);
			ll totalWhite = (p2White.x-p1White.x+1)*(p2White.y-p1White.y+1);
			cout << totalBlack << " " << totalWhite << endl;
			continue;
		}

		//Caso 5.1
		if(eng2_w == 2 && eng1_w == 1 && eng2_b == 0 && eng1_b == 0){

			ll totalBlack = (p2Black.x-p1Black.x+1)*(p2Black.y-p1Black.y+1);
			ll totalWhite = (p2White.x-p1White.x+1)*(p2White.y-p1White.y+1);
			cout << totalBlack << " " << totalWhite << endl;
			continue;
		}

		//Caso 6 e 6.1
		if(eng2_b == 0 && eng1_b == 0 && eng2_w == 0 && eng1_w == 0){

			ll totalBlack = (p2Black.x-p1Black.x+1)*(p2Black.y-p1Black.y+1);
			ll totalWhite = (p2White.x-p1White.x+1)*(p2White.y-p1White.y+1);
			cout << totalBlack << " " << totalWhite << endl;
			continue;
		}

		//Caso 7:
		if(eng2_w == 2 && eng1_w == 0 && eng2_b == 1 && eng1_b == 0){

			ll res_x = p2Black.x - p1White.x+1;
			ll res_y = p2Black.y - p1Black.y+1;

			ll totalWhite = (p2White.x-p1White.x+1)*(p2White.y-p1White.y+1);
			totalWhite -= res_x*res_y;

			ll totalBlack = (p2Black.x-p1Black.x+1)*(p2Black.y-p1Black.y+1);

			cout << totalWhite << " " << totalBlack << endl;
			continue;
		}


		//Caso 7.1:
		if(eng2_b == 2 && eng1_b == 0 && eng2_w == 1 && eng1_w == 0){

			ll res_x = p2White.x - p1Black.x+1;
			ll res_y = p2White.y - p1White.y+1;

			ll totalWhite = (p2White.x-p1White.x+1)*(p2White.y-p1White.y+1);
			totalWhite -= res_x*res_y;

			ll totalBlack = (p2Black.x-p1Black.x+1)*(p2Black.y-p1Black.y+1);

			cout << totalWhite << " " << totalBlack << endl;
			continue;
		}




	}
}

