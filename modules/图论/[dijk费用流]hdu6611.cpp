#include <bits/stdc++.h>
using namespace std;

const int NMAX = 5000;

struct mcmf {
 
    int n, m, s, t;
    vector <int> graph[NMAX];
 
    const int INF = 1e9 + 15;
    int potentials[NMAX];
    bool vis[NMAX];
    int dist[NMAX];
    int father[NMAX];
    priority_queue <pair <int, int> > _queue;
    
    struct Edge
    {
        int from, to;
        int flow, cap, cost;
 
        Edge(int _from = 0, int _to = 0, int _flow = 0, int _cap = 0, int _cost = 0):
            from(_from), to(_to), flow(_flow), cap(_cap), cost(_cost) {}
        inline int other(int node)
        {
            return from ^ to ^ node;
        }
    };
    
    vector<Edge>edges;
    void init(int _n,int _s,int _t) {
        m = 0;
        n = _n, s = _s, t = _t;
        edges.clear();
        for(int i=1;i<=n;i++) graph[i].clear();
    }
    //Edge edges[2 * MMAX];

    void add_edge(int from, int to, int cap, int cost)
    {
        //edges[m ++] = Edge(from, to, 0, cap, cost);
        edges.push_back({from,to,0,cap,cost});m++;
        //edges[m ++] = Edge(to, from, 0, 0, -cost);
        edges.push_back({to,from,0,0,-cost});m++;
        graph[from].push_back(m - 2);
        graph[to].push_back(m - 1);
    }

    int BellmanDP(int node)
    {
        if (vis[node])
            return potentials[node];
        if (node == s)
        {
            potentials[s] = 0;
            return 0;
        }
        vis[node] = true;
 
        potentials[node] = INF;
        for (auto edg: graph[node])
            if (edges[edg ^ 1].flow < edges[edg ^ 1].cap)
                potentials[node] = min(potentials[node], BellmanDP(edges[edg ^ 1].other(node)) + edges[edg ^ 1].cost);
        return potentials[node];
    }
 
 
 
    bool Dijkstra()
    {
        memset(vis, 0, (n + 1) * sizeof(bool));
        for (int i = 1; i <= n; ++ i)
            dist[i] = INF;
 
        dist[s] = 0;
        _queue.push(make_pair(0, s));
 
        int node;
        while (!_queue.empty())
        {
            node = _queue.top().second;
            _queue.pop();
 
            if (vis[node])
                continue;
            vis[node] = true;
 
            for (auto edge: graph[node])
            {
                int other = edges[edge].other(node);
                int cost = edges[edge].cost + potentials[node] - potentials[other];
 
                if (edges[edge].flow < edges[edge].cap && dist[node] + cost < dist[other])
                {
                    dist[other] = dist[node] + cost;
                    father[other] = edge;
                    _queue.push(make_pair(-dist[other], other));
                }
            }
        }
 
        for (int i = 1; i <= n; ++ i)
            dist[i] += (potentials[i] - potentials[s]);
 
        return vis[t];
    }
 
    pair <int, int> JohnsonDinic()
    {
        memset(potentials, 0, (n + 1) * sizeof(int));
        BellmanDP(t);
 
        int flow = 0, cost = 0;
        while (Dijkstra())
        {
            int node = t;
            int minimum = INF;
            int sum = 0;
 
            while (node != s)
            {
                minimum = min(minimum, edges[father[node]].cap - edges[father[node]].flow);
                sum += edges[father[node]].cost;
                node = edges[father[node]].other(node);
            }
 
            node = t;
            while (node != s)
            {
                edges[father[node]].flow += minimum;
                edges[father[node] ^ 1].flow -= minimum;
                node = edges[father[node]].other(node);
            }
 
            flow += minimum;
            cost += minimum * sum;
 
            memcpy(potentials, dist, (n + 1) * sizeof(int));
        }
 
        return make_pair(flow, cost);
    }
 
    inline pair <int, int> computeFlow() {
        return JohnsonDinic();
    }
}MM;

int A[2050],N,k;

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
    scanf("%d %d", &N, &k);
    MM.init(N*2+3,0,N*2+3);
    for(int i=1;i<=N;i++)
        scanf("%d",&A[i]);
    MM.add_edge(0,N*2+1,k,0);
    for(int i=1;i<=N;i++){
        MM.add_edge(N*2+1,i,1,0);
        MM.add_edge(i,N+i,1,-A[i]);
        MM.add_edge(N+i,N*2+2,1,0);
        for(int j=i+1;j<=N;j++){
            if(A[i]<=A[j])
                MM.add_edge(N+i,j,1,0);
        }
    }
    MM.add_edge(N*2+2,N*2+3,k,0);
    auto ans=MM.computeFlow();
    printf("%d\n",-ans.second);
    }
}
