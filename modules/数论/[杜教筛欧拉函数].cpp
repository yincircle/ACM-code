#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=5e6;
const int mod=1e9+7;
int Madd(int a,int b){
    return a+b<mod?a+b:a+b-mod;
}
int Msub(int a,int b){
    return a<b?mod+a-b:a-b;
}
int Mmul(int a,int b){
    return (ll)a*b%mod;
}
vector<int>p;
int vis[maxn+10];
int phi[maxn+10];
unordered_map<ll,ll>map;
ll qphi(ll n){
    if(n<maxn)return phi[n];
    auto it=map.find(n);
    if(it!=map.end())
        return it->second;
    ll res=n&1?Mmul((n+1)/2%mod,n%mod):Mmul(n/2%mod,(n+1)%mod);
    for(ll i=2,last;i<=n;i=last+1){
        last=n/(n/i);
        res=Msub(res,Mmul((last-i+1)%mod,qphi(n/i)));
    }
    map.emplace(n,res);
    return res;
}
void init(){
    phi[1]=1;
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            p.push_back(i);
            phi[i]=i-1;
        }
        for(int j=0;j<(int)p.size()&&i*p[j]<maxn;j++){
            vis[i*p[j]]=1;
            if(i%p[j])
                phi[i*p[j]]=phi[i]*(p[j]-1);
            else{
                phi[i*p[j]]=phi[i]*p[j];
                break;
            }
        }
    }
    for(int i=2;i<maxn;i++)
        phi[i]=(phi[i]+phi[i-1])%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init();
    long long a;
    cin>>a;
    cout<<qphi(a)<<endl;
    return 0;
}
