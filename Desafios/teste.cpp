#include<bits/stdc++.h>

using namespace std;

/// Typedef
typedef long long int ll;


//Int data type
#define sc1(a)              scanf("%d", &a)
#define sc2(a, b)           scanf("%d %d", &a, &b)
#define sc3(a, b, c)        scanf("%d %d %d", &a, &b, &c)
#define sc4(a, b, c, d)     scanf("%d %d %d %d", &a, &b, &c, &d)

//Long Data type
#define scl1(a)             scanf("%lld", &a)
#define scl2(a, b)          scanf("%lld %lld", &a, &b)
#define scl3(a, b, c)       scanf("%lld %lld %lld", &a, &b, &c)
#define scl4(a, b, c, d)    scanf("%lld %lld %lld %lld", &a, &b, &c, &d)

#define mx 1000005
#define pf(a) cout<<a<<endl

/************ Star Library ************/
// Square number count in 2 number range (3 - 10)--> 2

#define Square_number_count_in_2_rang(n) for(ll i=0; i<n; i++){ scl2(a,b); ck = sqrt(a-1); dk = sqrt(b); cout<<dk-ck<<endl; }



// *********  Start in main method code  ************//

ll max(ll a, ll b){  return (a>b) ? a : b; }


int main()
{
    ll a,n,m,b=0,i=0,j,dk,ck=0;

    string arr, brr = "", crr = "";
    cin>>arr;

    n = arr.size();

    for(i=0; i<n; i++){
        if(arr[i]=='2'){
            for(j=i; j<n; j++){
                if(arr[j]!='1')
                    brr+=arr[j];
                else
                    crr+=arr[j];
            }break;
        }
        else{
            crr+=arr[i];
        }
    }
    sort(crr.begin(), crr.end());

    cout<<crr+brr<<endl;

}