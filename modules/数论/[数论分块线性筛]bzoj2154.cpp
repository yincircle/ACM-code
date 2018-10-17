#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10000005;
const int mod=20101009;
bool check[maxn+10];
int prime[maxn+10];
int mu[maxn+10];
int sum[maxn+10];
int n,m;
vector<int>p;
void Moblus(){
    mu[1]=1;
    for(int i=2;i<=n;i++){
        if(!check[i]){
            p.push_back(i);
            mu[i]=-1;
        }
        for(int j=0;j<(int)p.size();j++){
            if(i*p[j]>maxn)break;
            check[i*p[j]]=true;
            mu[i*p[j]]=mu[i]*mu[p[j]];
            if(i%p[j]==0){
                mu[i*p[j]]=0;
                break;
            }
        }
    }
    sum[1]=mu[1];
    for(int i=2;i<=maxn;i++)
        sum[i]=(sum[i-1]+(1ll*i*i*mu[i]%mod))%mod;
}
ll su(ll x,ll y){
    x=x*(x+1)/2%mod;
    y=y*(y+1)/2%mod;
    return x*y%mod;
}
ll solve(int x,int y){
    ll ans=0;
    for(int i=1,pos=1;i<=x;i=pos+1){
        pos=min(x/(x/i),y/(y/i));
        ans=(ans+(sum[pos]-sum[i-1]+mod)%mod*su((ll)x/i,(ll)y/i)%mod)%mod;
    }
    return ans;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n>m)swap(n,m);
        ll ans=0;
        Moblus();
        for(int i=1,pos=0;i<=n;i=pos+1){
            pos=min(n/(n/i),m/(m/i));
            ans=(ans+(1ll*(i+pos)*(pos-i+1)/2)%mod*solve(n/i,m/i)%mod)%mod;
        }
        printf("%lld",ans);
    }
    return 0;
}
