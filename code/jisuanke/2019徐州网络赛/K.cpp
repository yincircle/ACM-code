#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int maxn = 1050;
const int INF = 0x3f3f3f3f;

int x[maxn],y[maxn];

unordered_map<ull,int>mp;

ull encode(int x,int y){
    union{
        struct{int xx,yy;};
        ll ret;
    }s;
    s.xx=x;s.yy=y;
    return s.ret;
}

int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",x+i,y+i);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            mp[encode(x[i]+x[j],y[i]+y[j])]+=2;
        }
        mp[encode(x[i]*2,y[i]*2)]++;
    }
    int ans=10000;
    for(auto p:mp){
        ans=min(ans,n-p.second);
        cout<<p.first<<endl;
    }
    cout<<ans;
    return 0;
}