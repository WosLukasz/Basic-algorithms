#include <iostream>

using namespace std;

void przywroc(int *tab, int r, int n)
{

     int min = r;
     if (2*r+1 < n && tab[min]>tab[ 2*r+1]) min=2*r+1;
     if (2*r+2 < n && tab[min]>tab[ 2*r+2]) min=2*r+2;

     if (min != r)
     {
         swap(tab[ r], tab[ min]);
         przywroc(tab, min, n);
     }

}

void sortuj (int *tab, int n){

     if (n>0)
     {
         swap(tab[ 0], tab[ n-1]);
         przywroc(tab, 0, n-1);
         sortuj (tab, n-1);
     }
}

int main()
{
    int n;
    int *tab;

    cin>>n;

    tab = new int [n];

    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
    }


    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;

    //!sortowanie przez kopcowanie


        for(int i=n/2; i>=0; --i)
        {
            przywroc(tab, i, n);
        }

        sortuj (tab, n);

    //!koniec sortowania

    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;







    return 0;
}
