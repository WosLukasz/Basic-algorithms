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

    //!sortowanie przez wstawianie


    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j<n-1;j++)
        {
            if(tab[j]>tab[j+1])
            {
                swap(tab[j],tab[j+1]);
            }
            else
            {
                break;
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
