#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define mkp             make_pair<int,int>
#define umpii           unordered_map<int,int>
#define maxheap         priority_queue<int>
#define minheap         priority_queue<int, vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define in_arr(A,n)     loop(i,0,n) cin>>A[i];
#define p_arr(A,n)      loop(i,0,n) cout<<A[i]
;
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
  
const int mod= 1e9+7;
const int inf= 1e15;
 
 
void solve(){
    int n; cin>>n;
    int c[n+1],a[n+1],b[n+1];
    loop(i,0,n) cin>>c[i];
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];

    int dp[n+1][2];
    //dp(i,0) closed at i
    //dp(i,1) open at i
    dp[0][0]=0;
    dp[0][1]=abs(a[1]-b[1]);

    int ans =dp[0][1];

    for(int i=1; i<n; i++){
        if(i==n-1 || b[i+1]==a[i+1]){
           dp[i][1]=0;
        }

        else{
        dp[i][1]=max(abs(a[i]-b[i]), dp[i-1][1])+2+(min(a[i+1],b[i+1])-1) + (c[i]-max(a[i+1],b[i+1]));
        }
        dp[i][0]=max(abs(a[i]-b[i]) + 2+ c[i]-1, dp[i-1][1]+2+c[i]-1);

        ans=max(ans, dp[i][0]);
    }

    cout<<ans<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}