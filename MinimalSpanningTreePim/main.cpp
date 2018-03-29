#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>

using namespace std;
pair<int,int> p;
bool vis [10001];
vector<pair<int,int> >  v[10001];
int a,b,c,d=1,n,m;
long long result=0;
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
        v[a].emplace_back(c, b);
        v[b].emplace_back(c, a);
    }

    vis[1]=true;
    for (auto &i : v[1]) {
        p.first=-1* i.first;
        p.second= i.second;
        q.push(p);
    }
    pair<int,int> pair;
    while(n>1)
    {
        pair=q.top();
        q.pop();
        if(!vis[pair.second])
        {

            vis[pair.second]=true;

            for(int j=0;j<v[pair.second].size();j++)
            {
                p.first=-1*v[pair.second][j].first;
                p.second=v[pair.second][j].second;
                q.push(p);
            }
            n--;
            result =result-pair.first;
        }


    }
    cout<<result<<"\n";
    return 0;
}