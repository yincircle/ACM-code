#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
const int maxn=2000050;
const int mod=51123987;
char s[maxn];
ll L[maxn];

struct Palindromic_AutoMaton{
    //basic
    int s[maxn],now;
    int nxt[maxn][26],fail[maxn],l[maxn],last,tot;
    //extension
    int num[maxn];
    void clear(){
        //1节点：奇数长度root 0节点：偶数长度root
        s[0]=l[1]=-1;
        fail[0]=tot=now=1;
        last=l[0]=0;
        memset(nxt[0],0,sizeof(nxt[0]));
        memset(nxt[1],0,sizeof(nxt[1]));
    }
    Palindromic_AutoMaton(){clear();}
    int newnode(int x){
        tot++;
        memset(nxt[tot],0,sizeof(nxt[tot]));
        fail[tot]=num[tot]=0;
        l[tot]=x;
        return tot;
    }
    int get_fail(int x){
        while(s[now-l[x]-2]!=s[now-1])x=fail[x];
        return x;
    }
    int add(int ch){
        s[now++]=ch;
        int cur=get_fail(last);
        if(!nxt[cur][ch]){
            int tt=newnode(l[cur]+2);
            fail[tt]=nxt[get_fail(fail[cur])][ch];
            nxt[cur][ch]=tt;
            num[tt]=num[fail[tt]]+1;
        }
        last=nxt[cur][ch];//num[last]++;
        return num[last];
    }
    void build(){
        for(int i=tot;i>=2;i--){
            num[fail[i]]+=num[i];
        }
        num[0]=num[1]=0;
    }
    void init(char* ss){
        while(*ss){
            add(*ss-'a');ss++;
        }
    }
    void init(string str){
        for(int i=0;i<(int)str.size();i++){
            add(str[i]-'a');
        }
    }
}pam;


int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    pam.clear();
    for(int i=0;i<n;i++){
        L[i]=pam.add(s[i]-'a');
    }
    for(int i=0;i<n;i++){
        if(i){
            L[i]+=L[i-1];   
        }
        //cout<<i<<" l="<<l[i]<<" r="<<r[i]<<endl;
    }
    ll ans=L[n-1]*(L[n-1]-1)/2;
    reverse(s,s+n);
    pam.clear();
    for(int i=0;i<n;i++){
        ll x=pam.add(s[i]-'a');
        if(i<n-1){
            ans=ans-L[n-2-i]*x;
        }
    }
    /*for(int i=0;i<n;i++){
        ans=ans-L[i]*R[n-2-i];
    }*/
    ans%=mod;
    printf("%lld",ans);
    return 0;
}