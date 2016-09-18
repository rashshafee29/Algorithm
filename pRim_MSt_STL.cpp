#include<bits/stdc++.h>
#define Pair pair<int,int>
#define INF 9999999
#define NIL -1
using namespace std;
int V,E,key[100],pa[100],c=0;
struct cmp
{
    bool operator()(const Pair __x,Pair __y) const
    {
        return __x.second > __y.second;
    }
};
priority_queue< Pair, vector <Pair> ,cmp > pq;
vector<Pair> qq[100];
int Mst_Prim()
{
    int v,u,i,w,j;
    for(j=1;j<=V;j++)
    {
        key[j]=INF;
        pa[j]=NIL;
    }
    key[1]=0;///source=r=1
    for(v=0;v<V;v++)
    {
        pq.push(Pair(qq[0][v].first,qq[0][v].second));
    }
    while(!pq.empty())
    {
        u=pq.top().first;
        pq.pop();
        int V_size=qq[u].size();
        cout<<"1<-\n";
        for(v=0;v<V_size;v++)
        {
            w=qq[u][v].second;
            cout<<"2<-\n";
            if(w<key[v])
            {
                pa[v]=u;
                key[v]=w;
                cout<<"3<-\n";
                c++;
            }
        }
    }
}
int main()
{
    int i,u,v,w,z;
    cout<<"How many vertex:";
    cin>>V;
    cout<<"How many edges:";
    cin>>E;
    for(i=0;i<E;i++)
    {
        cin>>u>>v>>w;
        qq[u].push_back(Pair(v,w));
        qq[v].push_back(Pair(u,w));
    }
    Mst_Prim();
    for(z=0;z<V;z++)
    {
        cout<<z<<"\t"<<key[z]<<"\t"<<pa[z]<<"\n";
    }
    return 0;
}
