#include<bits/stdc++.h>
using namespace std;
const int maxN=10000;
const int INF=0x3f3f3f3f;
typedef pair<int,int>P;
int n,m,s,t,k;
int dist[maxN],tdist[maxN],cnt[maxN];
bool f[maxN];
vector<P>Adj[maxN];
vector<P>Rev[maxN];
struct edge{
    int to,len;
    edge(){}
    edge(int t,int l):to(t),len(l){}
};
priority_queue<edge> q;
bool operator<(const edge &a,const edge &b){
    return (a.len+dist[a.to])>(b.len+dist[b.to]);
}
void dijkstra(){
    memset(dist,0,sizeof(dist));
    fill(tdist,tdist+maxN,INF);
    tdist[t]=0;
    while(!q.empty())q.pop();
    q.push(edge(t,0));
    while(!q.empty()){
        int x=q.top().to;
        int d=q.top().len;
        q.pop();
        if(tdist[x]<d)continue;
        for(int i=0;i<(int)Rev[x].size();i++){
            int y=Rev[x][i].first;
            int len=Rev[x][i].second;
            if(d+len<tdist[y]){
                tdist[y]=d+len;
                q.push(edge(y,tdist[y]));
            }
        }
    }
    for(int i=1;i<=n;i++){
        dist[i]=tdist[i];
    }
}
int aStar(){
    if(dist[s]==INF)return -1;
    while(!q.empty())q.pop();
    q.push(edge(s,0));
    memset(cnt,0,sizeof(cnt));
    while(!q.empty()){
        int x=q.top().to;
        int d=q.top().len;
        q.pop();
        cnt[x]++;
        if(cnt[t]==k)return d;
        if(cnt[x]>k)continue;
        for(int i=0;i<(int)Adj[x].size();i++){
            int y=Adj[x][i].first;
            int len=Adj[x][i].second;
            q.push(edge(y,d+len));
        }
    }
    return -1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int st,ed,l;
        scanf("%d%d%d",&st,&ed,&l);
        Adj[st].push_back(make_pair(ed,l));
        Rev[ed].push_back(make_pair(st,l));
    }
    scanf("%d%d%d",&s,&t,&k);
    if(s==t)k++;
    dijkstra();
    printf("%d\n",aStar());
    return 0;
}


