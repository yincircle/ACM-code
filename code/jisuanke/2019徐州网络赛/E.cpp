#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 500050;
const int INF = 0x3f3f3f3f;

int A[maxn];

struct Seg_Tree{
    int val[maxn<<2];
    void init(){
        memset(val,0,sizeof(val));
    }
    inline void up(int rt){
        val[rt]=max(val[rt<<1],val[rt<<1|1]);
    }
    void build(int rt,int l,int r){
        if(l==r){
            val[rt]=A[l];
            return ;
        }
        int mid=l+r>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        up(rt);
    }
    /*void update(int rt,int l,int r,int L,int R,int del){
        if(l>R||r<L)return ;
        if(L<=l&&r<=R){
            val[rt]+=del*(r-l+1);
            lazy[rt]+=del;
            return ;
        }
        int mid=l+r>>1;
        down(rt,l,r);
        update(rt<<1,l,mid,L,R,del);
        update(rt<<1|1,mid+1,r,L,R,del);
        up(rt);
    }
    void add(int rt,int l,int r,int L,int del){
        if(l==r){
            val[rt]+=del;
            return ;
        }
        down(rt,l,r);
        int mid=l+r>>1;
        if(L<=mid)add(rt<<1,l,mid,L,del);
        else add(rt<<1|1,mid+1,r,L,del);
        up(rt);
    }
    int query_sum(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)return val[rt];
        int mid=l+r>>1;
        down(rt,l,r);
        int res=0;
        if(L<=mid)res+=query_sum(rt<<1,l,mid,L,R);
        if(R>mid)res+=query_sum(rt<<1|1,mid+1,r,L,R);
        return res;
    }*/
    int res;
    int query(int rt,int l,int r,int L,int R,int del){
        //cout<<rt<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<del<<" "<<res<<endl;
        if(L>l||r>R)return -1;
        if(l==r){
            return l;
        }
        int mid=l+r>>1;
        if(val[rt<<1|1]>=del){
            res=max(query(rt<<1|1,mid+1,r,L,R,del),res);
            //puts("R");cout<<res<<endl;
        }
        else if(val[rt<<1]>=del){
            res=max(query(rt<<1,l,mid,L,R,del),res);
            //puts("L");cout<<res<<endl;
        }
        return res;
    }
}seg;

int ans[maxn];

int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    seg.init();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    seg.build(1,1,n);
    for(int i=1;i<=n;i++){
        seg.res=-1;
        ans[i]=seg.query(1,1,n,1,n,A[i]+m);
        if(ans[i]<=i)ans[i]=-1;
    }
    for(int i=1;i<=n;i++){
        if(ans[i]!=-1)
            printf("%d%s",ans[i]-i-1,i!=n?" ":"\n");
        else
            printf("%d%s",-1,i!=n?" ":"\n");
    }
    return 0;
}