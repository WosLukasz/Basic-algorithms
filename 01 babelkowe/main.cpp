#include <iostream>

using namespace std;

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

    //!sortowanie babelkowe


    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(tab[j]>tab[j+1])
            {
                swap(tab[j],tab[j+1]);
            }
        }
    }


    //!koniec sortowania

    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;







    return 0;
}
