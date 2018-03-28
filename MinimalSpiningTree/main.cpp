//
// Created by Szymon on 28/03/2018.
//


#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int tab[100000];
int n;
int m;
int result;
int x, y, z;
vector <pair <int, pair<int, int> > > q;
pair <int, pair<int, int> > d;
int find(int c)
{
    if(tab[c]!=c)
        tab[c]=find(tab[c]);
    return tab[c];
}
void Union(int a, int b)
{
    a = find(a);

    b = find(b);
    tab[a]=b;
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
        tab[i]=i;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d", &d.second.first, &d.second.second, &d.first);
        q.push_back(d);
    }
    sort(q.begin(), q.end());
    for(int i=0; i<q.size(); i++)
    {
        if(find(q[i].second.first)!=find(q[i].second.second))
        {
            result+=q[i].first;

            Union(q[i].second.first , q[i].second.second);

        }
    }
    printf("%d", result);
    return 0;
}