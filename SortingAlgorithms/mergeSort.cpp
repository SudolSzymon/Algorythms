#include <iostream>


using namespace std;

int tab[1000000];
int t[100000];



void merge(int start, int sr, int ending)
{
    int i,j,q;
    for (i=start; i<=ending; i++) t[i]=tab[i];
    i=start; j=sr+1; q=start;
    while (i<=sr && j<=ending) {
        if (t[i]<t[j])
            tab[q++]=t[i++];
        else
            tab[q++]=t[j++];
    }
    while (i<=sr) tab[q++]=t[i++];
}


void divide(int start, int ending)
{
    int sr;
    if (start<ending) {
        sr=(start+ending)/2;
        divide(start, sr);
        divide(sr+1, ending);
        merge(start, sr, ending);
    }
}


int main() {
    int n;
    cin>>n;


    for (int i=0; i<n; i++)
    {
        cin>>tab[i];
    }

    divide(0,n-1);


    for (int i=0; i<n; i++)
        cout<<tab[i]<<"\n";
}