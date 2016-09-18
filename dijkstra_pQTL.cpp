//uva usable :)

#include<bits/stdc++.h>
#define pair pair<int,int>
#define INF 99999
#define NIL -1
using namespace std;
int n,V,d[100],pa[100];
struct comp
{
    bool operator()(const pair __x, pair __y) const
    {
        return __x.second > __y.second;
    }
};
priority_queue< pair, vector < pair >, comp > p;
vector< pair > g[100];
int Initialize_Single_Source_Stl()
{
    int v;
    for(v=0;v<=n;v++)
    {
        d[v]=INF;
        pa[v]=NIL;
    }
    ///source=1;
    d[1]=0;
}
int Dijkstra_STL()
{
    int u,v,w,i,V_size;
    Initialize_Single_Source_Stl();
    p.push(pair(1,d[1]));///source=1;
    while(!p.empty())
    {
        u=p.top().first;
        p.pop();
        V_size=g[u].size();
        for(i=0;i<V_size;i++)
        {
            v=g[u][i].first;
            w=g[u][i].second;
            if(d[v]>d[u]+w)///Relazzzzzzz
            {
                d[v]=d[u]+w;
                pa[v]=u;
                p.push(pair(v,d[v]));
            }
        }
    }
}
int print_soln()
{
    int v;
    for(v=1;v<=n;v++)
    {
        cout<<v<<"\t\t"<<d[v]<<"\t\t"<<pa[v]<<"\n";
    }
}
int main()
{
    freopen("dijkstra_pqin.txt","r",stdin);
    int i,w,u,v;
    //cout<<"how many nodes:";
    cin>>n;
    //cout<<"How many Edges:";
    cin>>V;
    cout<<"Nodes\t\t"<<"Distance\t"<<"Parents\n";
    for(i=1;i<=V;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back(pair(v,w));
        g[v].push_back(pair(u,w));
    }
    Dijkstra_STL();
    print_soln();
    return 0;
}
