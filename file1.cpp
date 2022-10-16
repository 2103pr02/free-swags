/* ____                       _  __                     _       _       _       
  |  _ \ _ __ ___ _ __ ___   | |/ /__ _ _ __ ___   __ _| |     | | __ _(_)_ __  
  | |_) | '__/ _ \ '_ ` _ \  | ' // _` | '_ ` _ \ / _` | |  _  | |/ _` | | '_ \ 
  |  __/| | |  __/ | | | | | | . \ (_| | | | | | | (_| | | | |_| | (_| | | | | |
  |_|   |_|  \___|_| |_| |_| |_|\_\__,_|_| |_| |_|\__,_|_|  \___/ \__,_|_|_| |_|
*/                                                                            

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define debug(x); cout<<#x<<" "<<x<<endl;
ll hell=1e9+7;

int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<ll>> dp(n+1,vector<ll>(3,0));
    // dp[i][0]-> rest
    // dp[i][1]-> contest
    // dp[i][2]-> gym

    for(ll i=1;i<=n;i++){
        dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
        if(arr[i-1]==1 || arr[i-1]==3){
            dp[i][1]=1+max(dp[i-1][0],dp[i-1][2]);
        }
        if(arr[i-1]==2 || arr[i-1]==3){
            dp[i][2]=1+max(dp[i-1][0],dp[i-1][1]);
        }
    }

    cout<<n-max({dp[n][0],dp[n][1],dp[n][2]});
    cout<<endl;
    return 0;
}
