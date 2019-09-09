#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int maxn = 1000050;
const int mod=1e9+7;

int qpow(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return res;
}

int n,dep[maxn],dist,dp[maxn];
vector<int>son[maxn];

void dfs(int u,int fa,int d){
    dep[u]=d;
    for(auto to:son[u]){
        if(to!=fa)dfs(to,u,d+1);
    }
}


//dp[u]=((sum 1-dp[v])/cnt)^cnt
void dfs2(int u,int fa){
    if(dep[u]==dist)dp[u]=1;
    else dp[u]=0;
    int cnt=0;
    int sum=0;
    for(auto to:son[u]){
        if(to!=fa){
            dfs2(to,u);
            sum=(sum+1)%mod;
            sum=(sum-dp[to])%mod;
            cnt++;
        }
    }
    if(dp[u])return ;
    dp[u]=1ll*sum*qpow(cnt,mod-2)%mod;
    dp[u]=qpow(dp[u],cnt)%mod;
    //cnt=qpow(cnt,cnt);
    //dp[u]=1ll*dp[u]*qpow(cnt,mod-2)%mod;
    dp[u]=1-dp[u];
    if(dp[u]<0)dp[u]+=mod;
}

int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        son[u].push_back(v);
        son[v].push_back(u);
    }
    dfs(1,0,1);
    dist=0;
    for(int i=1;i<=n;i++)dist=max(dist,dep[i]);
    dfs2(1,0);
    printf("%d\n",dp[1]);
    return 0;
}