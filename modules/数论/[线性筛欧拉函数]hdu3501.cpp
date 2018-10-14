#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e6;
int prime[maxn/10];
int vis[maxn+5];
int phi[maxn+5];
int tot;
void primetable(){
    for(int i=2;i<=maxn;i++){
        if(!vis[i]){
            prime[tot++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<tot;j++){
            if(i*prime[j]>maxn)break;
            vis[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            else
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
}
int main(){
    int a,b;
    primetable();
    while(scanf("%d%d",&a,&b)!=EOF){
        ll ans=0;
        for(int i=a;i<=b;i++){
            ans+=phi[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
