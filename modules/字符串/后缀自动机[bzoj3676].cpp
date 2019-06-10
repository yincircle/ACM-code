//bzoj 3676
//len[t]回文t的长度 num[t]回文t的出现次数


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e6 + 50;

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
    void add(int ch){
        s[now++]=ch;
        int cur=get_fail(last);
        if(!nxt[cur][ch]){
            int tt=newnode(l[cur]+2);
            fail[tt]=nxt[get_fail(fail[cur])][ch];
            nxt[cur][ch]=tt;
        }
        last=nxt[cur][ch];num[last]++;
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
    ll query();
}pam;

ll Palindromic_AutoMaton::query(){
    ll ret=1;
    for(int i=2;i<=tot;i++){
        ret=max(ret,1ll*l[i]*num[i]);
    }
    return ret;
}

char s[maxn];
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    scanf("%s",s);
    pam.init(s);
    pam.build();
    printf("%lld\n",pam.query());
    return 0;
}