#include <iostream>

using namespace std;


//!ulepszenie
void med3(int tab[],int p, int k)
{


     if(tab[p]<tab[(p+k)/2])
     {
         if(tab[(p+k)/2]<tab[k])
         {
             swap(tab[p],tab[(p+k)/2]);
         }else
         {
             if(tab[p]<tab[k])
             {
                 swap(tab[p],tab[k]);
             }else
             {
                //zamien(tab[],p,(p+k)/2);
             }
         }
     }else
     {
         if(tab[p]<tab[k])
         {
         }else
         {
             if(tab[(p+k)/2]<tab[k])
             {
                 swap(tab[p],tab[k]);
             }
             else
             {
                 swap(tab[p],tab[(p+k)/2]);
             }
         }
     }
}



void quick(int p, int k , int tab[])
{

    if(p<k)
    {
        //ulepszenie

        //med3(tab,p,k);

        int d=p;
        int x=tab[d];


        for(int i=p+1;i<k;i++)
        {
            if(tab[i]<x)
            {
                d++;
                swap(tab[d],tab[i]);
            }
        }

        swap(tab[d],tab[p]);

        quick(p,d-1,tab);
        quick(d+1,k,tab);
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

    //!sortowanie szybkie

    quick(0,n,tab);

    //!koniec sortowania

    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;







    return 0;
}
