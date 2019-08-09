#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
 
struct AC_Automaton
{
	static const int K=26;//may need change
	int next[maxn][K],fail[maxn],cnt[maxn],last[maxn];
	int len[maxn];
    int root,tot;
	inline int getid(char c)//may need change
	{
		return c-'a';
	}
	int newnode()
	{
		memset(next[tot],0,sizeof(next[tot]));
		fail[tot]=0;
		cnt[tot]=0;
        len[tot]=0;
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	void insert(char *s)
	{
		int n,now,i;
		n=strlen(s);
		now=root;
		for(i=0;i<n;i++)
		{
			int t=getid(s[i]);
			if(!next[now][t]) {
                next[now][t]=newnode();
                len[next[now][t]]=i+1;
            }
			now=next[now][t];
		}
		cnt[now]++;
	}
	void setfail()
	{
		int i,now;
		queue<int>q;
		for(i=0;i<K;i++)
		{
			if(next[root][i]) q.push(next[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			//suffix link
			if(cnt[fail[now]]) last[now]=fail[now];
			else last[now]=last[fail[now]];
			/*
			may need add something here:
			cnt[now]+=cnt[fail[now]];
			*/
			for(i=0;i<K;i++)
			{
				if(next[now][i])
				{
					fail[next[now][i]]=next[fail[now]][i];
					q.push(next[now][i]);
				}
				else next[now][i]=next[fail[now]][i];
			}
		}
	}
	//build fail tree 
	vector<int> mp[maxn];
	void build_tree()
	{
		for(int i=0;i<=tot;i++) mp[i].clear();
		for(int i=1;i<tot;i++) mp[fail[i]].push_back(i);
	}
    //extra
    ll l[maxn],sz[maxn];
    void solve(char *s){
        ll ans=0;
        int n=strlen(s);
        int now=root;
        memset(l,0,sizeof(l));
        memset(sz,0,sizeof(sz));
        for(int i=0;i<n;i++){
            int tmp=0;
            tmp=now=next[now][getid(s[i])];
            while(tmp){
                l[i]+=cnt[tmp];
                if(i-len[tmp]+1>=0){
                    sz[i-len[tmp]+1]+=cnt[tmp];
				}
                tmp=last[tmp];
            }
        }
        for(int i=0;i<n-1;i++){
            ans+=l[i]*sz[i+1];
        }
        printf("%lld\n",ans);
    }
}ac;
 
char s[maxn],ss[maxn];
 
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    while(scanf("%s",s)!=EOF){
        ac.init();
        int q;
        scanf("%d",&q);
        while(q--){
            scanf("%s",ss);
            ac.insert(ss);
        }
        ac.setfail();
        ac.solve(s);
    }    
    return 0;
}