#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
struct pri
{
    int operator() (const pair<int,int>&p1,const pair<int,int>&p2)
    {
        return p1.second<p2.second;
    }
} p;
int main()
{
    priority_queue<pp,vector<pp>,pri> q;
    int n;
    //cin>>n;
    vector<pp> g[100+1];
    int e,u,v,w,i;
    cin>>e;
    for(i=0; i<e; i++)
    {
        cin>>u>>v>>w;
        g[u].push_back(pp(v,w));
        g[v].push_back(pp(u,w));
    }
    int s=0;
    //cin>>s;
    int d[n+1];
    for(i=1; i<=n; i++)
        d[i]=999;
    d[s]=0;
    q.push(pp(s,d[s]));
    while(!q.empty())
    {
        u=q.top().first;
        q.pop();
        int size=g[u].size();
        for(int i=0; i<size; i++)
        {
            v=g[u][i].first;
            w=g[u][i].second;
            cout<<u<<" "<<" "<<w<<endl;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                q.push(pp(v,d[v]));
            }
        }
    }
    for(i=1; i<=10; i++)
        printf("node %d,min weight=%d\n",i,d[i]);
    return 0;
}
