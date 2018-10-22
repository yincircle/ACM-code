#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=5e6;

vector<int>p;
int vis[maxn+10];
int mu[maxn+10];
unordered_map<ll,ll>map;
ll qmu(ll n){
    if(n<maxn)return mu[n];
    auto it=map.find(n);
    if(it!=map.end())
        return it->second;
    ll res=1;
    for(ll i=2,last;i<=n;i=last+1){
        last=n/(n/i);
        res-=(ll)(last-i+1)*qmu(n/i);
    }
    map.emplace(n,res);
    return res;
}
void init(){
    mu[1]=1;
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            p.push_back(i);
            mu[i]=-1;
        }
        for(int j=0;j<(int)p.size()&&i*p[j]<maxn;j++){
            vis[i*p[j]]=1;
            if(i%p[j])
                mu[i*p[j]]=-mu[i];
            else
                break;
        }
    }
    for(int i=2;i<maxn;i++)
        mu[i]+=mu[i-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init();
    long long a,b;
    cin>>a>>b;
    cout<<qmu(b)-qmu(a-1)<<endl;
    return 0;
}
