#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>

using namespace std;
pair<int,int> p;
bool vis [10001];
vector<pair<int,int> >  v[10001];
int a,b,c,d=1,n,m;
long long wynik=0;
priority_queue <pair<int,int> > q;

int main()
{
    int n,m;
    int a,b,c;
    cin>>n;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>a;
        cin>>b;
        cin>>c;
        v[a].push_back(make_pair(c, b));
        v[b].push_back(make_pair(c, a));
    }

    vis[1]=true;
    for(int i=0;i<v[1].size();i++)
    {
        p.first=-1*v[1][i].first;
        p.second=v[1][i].second;
        q.push(p);
    }
    pair<int,int> pair;
    while(n>1)
    {
        pair=q.top();
        q.pop();
        if(vis[pair.second]==false)
        {

            vis[pair.second]=true;

            for(int j=0;j<v[pair.second].size();j++)
            {
                p.first=-1*v[pair.second][j].first;
                p.second=v[pair.second][j].second;
                q.push(p);
            }
            n--;
            wynik=wynik-pair.first;
        }


    }
    cout<<wynik<<"\n";
    return 0;
}