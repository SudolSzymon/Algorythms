#include<iostream>
using namespace std;
 
void Sortowanie( int tab[], int size )
{
    int temp, j;
    
    for( int i = 1; i < size; i++ )
    {
        temp = tab[ i ];
        
        for( j = i - 1; j >= 0 && tab[ j ] > temp; j-- )
             tab[ j + 1 ] = tab[ j ];
        
        tab[ j + 1 ] = temp;
    }
}

 
int main()
{
    int n;
    
    
    cin>>n;
 int tab[n];
 
    for(int i=0; i<n; i++)
    {
           
            cin>>tab[i];
    }
 
    
 
    Sortowanie(tab,n);
 
    
    for(int i=0; i<n; i++)
            cout<<tab[i]<<" ";
 
    
    return 0;    
}
 