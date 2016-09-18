#include<bits/stdc++.h>
#define INF 9999999
#define NIL -1
using namespace std;
int V,w[100][100],key[100],pa[100];
bool sts[100];
int Extract_Min()
{
    int v,min_=INF,minLoc;
    for(v=0;v<V;v++)
    {
        if(sts[v]==false && key[v]<min_)
        {
            min_=key[v];
            minLoc=v;
        }
    }
    return minLoc;
}
int Prim_MSt_NOrm()
{
    int v,u,x;
    for(u=0;u<V;u++)
    {
        key[u]=INF;
        pa[u]=NIL;
        sts[u]=false;
    }
    key[0]=0;///source=r=0
    pa[0]=NIL;
    for(x=0;x<V;x++)
    {
        u=Extract_Min();
        sts[u]=true;
        for(v=0;v<V;v++)
        {
            if(w[u][v] && sts[v]==false && w[u][v]<key[v])
            {
                pa[v]=u;
                key[v]=w[u][v];
            }
        }
    }
}
int main()
{
    //cout<<"How many vertex:";
    freopen("Prim_MSt_Norm.txt","r+",stdin);
    cin>>V;
    int p,i,j;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            cin>>w[i][j];
        }
    }
    Prim_MSt_NOrm();
    cout<<"Edge weight:\n";
    for(p=1;p<V;p++)
    {
        cout<<pa[p]<<"\t"<<p<<"\t"<<w[p][pa[p]]<<"\n";
    }
}
