#include <bits/stdc++.h>

#define range(x) begin(x),end(x)

using namespace std;
typedef long long ll;
const int maxn = 2000050;
const int INF = 0x3f3f3f3f;

int fa[maxn];
bool vis[maxn];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void uni(int u,int v){
    u=find(u),v=find(v);
    if(u==v)return ;
    if(u<v)swap(u,v) ;
    fa[v]=u;
}

vector<int>tmp;

int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int n,q;
    scanf("%d%d",&n,&q);
    vector<pair<int,int> >op;
    for(int i=0;i<q;i++){
        int z,x;
        scanf("%d%d",&z,&x);
        op.emplace_back(z,x);
        tmp.push_back(x);
        tmp.push_back(x+1);        
    }
    sort(range(tmp));
    tmp.erase(unique(range(tmp)),tmp.end());
    iota(range(fa),0);
    for(auto p:op){
        int z,x;tie(z,x)=p;
        x=lower_bound(tmp.begin(),tmp.end(),x)-tmp.begin();
        if(z==1){
            if(vis[x])continue;
            vis[x]=1;
            uni(x,x+1);
        }
        else{
            int ans=tmp[find(x)];
            if(ans>n)ans=-1;
            printf("%d\n",ans);
        }
    }
    return 0;
}