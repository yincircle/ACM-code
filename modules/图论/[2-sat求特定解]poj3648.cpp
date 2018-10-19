#include<queue>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1010;
const int maxm=100010;

struct edge{
    int to,nex;
}edge[maxm];
int head[maxn],tot;
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v){
    edge[tot].to=v;
    edge[tot].nex=head[u];
    head[u]=tot++;
}
int low[maxn],dfn[maxn],sta[maxn],belong[maxn];
int ind,top;
int scc;
bool instack[maxn];
int num[maxn];

void tarjan(int u){
    int v;
    low[u]=dfn[u]=++ind;
    sta[top++]=u;
    instack[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].nex){
        v=edge[i].to;
        if(!dfn[v]){
            tarjan(v);
            if(low[u]>low[v])low[u]=low[v];
        }
        else if(instack[v]&&low[u]>dfn[v])
            low[u]=dfn[v];
    }
    if(low[u]==dfn[u]){
        scc++;
        do{
            v=sta[--top];
            instack[v]=false;
            belong[v]=scc;
            num[scc]++;
        }
        while(v!=u);
    }
}
bool solvable(int n){
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
    memset(num,0,sizeof(num));
    ind=scc=top=0;
    for(int i=0;i<n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=0;i<n;i++)
        if(belong[i]==belong[i^1])
            return false;
    return true;
}
queue<int>q1,q2;
vector< vector<int> >dag;
char color[maxn];
int indeg[maxn];
int cf[maxn];
void solve(int n){
    dag.assign(scc+1,vector<int>());
    memset(indeg,0,sizeof(indeg));
    memset(color,0,sizeof(color));
    for(int u=0;u<n;u++){
        for(int i=head[u];i!=-1;i=edge[i].nex){
            int v=edge[i].to;
            if(belong[u]!=belong[v]){
                dag[belong[v]].push_back(belong[u]);
                indeg[belong[u]]++;
            }
        }
    }
    for(int i=0;i<n;i+=2){
        cf[belong[i]]=belong[i^1];
        cf[belong[i^1]]=belong[i];
    }
    while(!q1.empty())q1.pop();
    while(!q2.empty())q2.pop();
    for(int i=1;i<=scc;i++)
        if(indeg[i]==0)
            q1.push(i);
    while(!q1.empty()){
        int u=q1.front();q1.pop();
        if(color[u]==0){
            color[u]='R';
            color[cf[u]]='B';
        }
        int sz=dag[u].size();
        for(int i=0;i<sz;i++){
            indeg[dag[u][i]]--;
            if(indeg[dag[u][i]]==0)
                q1.push(dag[u][i]);
        }
    }
}
int change(char s[]){
    int ret=0;
    int i=0;
    while(s[i]>='0'&&s[i]<='9'){
        ret*=10;
        ret+=s[i]-'0';
        i++;
    }
    if(s[i]=='w')return 2*ret;
    else return 2*ret+1;
}
int main(){
    int n,m;
    char s1[10],s2[10];
    while(scanf("%d%d",&n,&m)==2&&(n+m)){
        init();
        while(m--){
            scanf("%s%s",s1,s2);
            int u=change(s1);
            int v=change(s2);
            addedge(u^1,v);
            addedge(v^1,u);
        }
        addedge(1,0);
        if(solvable(2*n)){
            solve(2*n);
            for(int i=1;i<n;i++){
                if(color[belong[2*i]]=='R')printf("%dw",i);
                else printf("%dh",i);
                if(i<n-1)printf(" ");
                else printf("\n");
            }
        }
        else printf("bad lucn\n");
    }
    return 0;
}
