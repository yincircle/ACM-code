#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100000;
bool check[maxn+10];
int prime[maxn+10];
int mu[maxn+10];
void Moblus(){
    memset(check,false,sizeof(check));
    mu[1]=1;
    int tot=0;
    for(int i=2;i<=maxn;i++){
        if(!check[i]){
            prime[tot++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<tot;j++){
            if(i*prime[j]>maxn)break;
            check[i*prime[j]]=true;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }
            else{
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
}
int sum[maxn+10];
ll solve(int n,int m){
    ll ans=0;
    if(n>m)swap(n,m);
    for(int i=1,la=0;i<=n;i=la+1){
        la=min(n/(n/i),m/(m/i));
        ans+=(ll)(sum[la]-sum[i-1])*(n/i)*(m/i);
    }
    return ans;
}

int main(){
    Moblus();
    sum[0]=0;
    for(int i=1;i<=maxn;i++)
        sum[i]=sum[i-1]+mu[i];
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d,k;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        printf("%lld\n",solve(b/k,d/k)-solve((a-1)/k,d/k)-solve(b/k,(c-1)/k)+solve((a-1)/k,(c-1)/k));
    }
    return 0;
}

