#include<iostream>
using namespace std;


void quicksort(int T[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = T[(left + right) / 2];


      while (i <= j) {
            while (T[i] < pivot)
                  i++;
            while (T[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = T[i];
                  T[i] = T[j];
                  T[j] = tmp;
                  i++;
                  j--;
            }
      };


      if (left < j)
            quicksort(T, left, j);
      if (i < right)
            quicksort(T, i, right);
}
int main()
{
int  a;

cin >> a;
int T[a+1];

for (int i = 0; i < a; i++) // wczytywanie liczb do tablicy
{
cin >> T[i];
}

quicksort(T,0,a-1); // wywolanie funkcji sortujacej

for (int i = 0; i < a; i++) // wypisanie posortowanej tablicy
cout << T[i] << "\n";



return 0;
}