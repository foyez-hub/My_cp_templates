#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back
ll dp[1000][1000];
ll f(ll l,ll r,string s){
    if(dp[l][r]!=-1) return dp[l][r];

    if(l>=r) return 1;

    
    if(s[l]==s[r]){
       return dp[l][r]=f(l+1,r-1,s);
    }
    else{
        return dp[l][r]=0;
    }

}
int main()
{
    string s;
    cin>>s;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            dp[i][j]=-1;
        }
        
    }
    
     ll ans=-1;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            // cout<<i<<" "<<j<<" "<<f(i,j,s)<<endl;
            if(f(i,j,s)==1){
                ans=max(ans,ll(abs(i-j)+1));

            }
            
        }
        
    }
    cout<<ans<<endl;

}
