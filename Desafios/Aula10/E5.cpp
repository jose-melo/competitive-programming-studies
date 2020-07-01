    #include <iostream>
     
    using namespace std;
     string s;
     int n,k;
     bool ok(int m)
     {
         int a=0,b=0;
         for(int i=0;i<m;i++)
         {
             if(s[i]=='a')
             {
                 a++;
             }
             else b++;
         }
         if(a<=k||b<=k)
            return 1;
            int idx=0;
         for(int i=m;i<n;i++)
         {
             if(s[idx++]=='a')
             {
                 a--;
             }
             else b--;
     
             if(s[i]=='a') a++;
             else b++;
     
             if(a<=k||b<=k)
            return 1;
     
     
     }
     return 0;
     }
     int bs(int st,int e)
     {
         while(st<e)
         {
             int mid=st+(e-st+1)/2;
             if(ok(mid))
             {
                 st=mid;
             }
             else
             {
                 e=mid-1;
             }
         }
         return st;
     }
    int main()
    {
     
        cin>>n>>k;
     
        cin>>s;
        cout<<bs(0,n);
        return 0;
    }


