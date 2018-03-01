#include <iostream>

using namespace std;

int *tab1;


void merge_sort(int tab[],int p,int k)
{


   int s=(p+k+1)/2;


   if(p<s-1)
   {
       merge_sort(tab,p,s-1);
   }
   if(s<k)
   {
       merge_sort(tab,s,k);
   }

   int i1 = p;
   int i2 = s;

   for(int i=p;i<=k;i++)
   {
       if((i1 == s) || ((i2 <= k) && (tab[i1] > tab[i2])))
       {
           tab1[i]=tab[i2];
            i2++;
       }else
       {
           tab1[i]=tab[i1];
            i1++;
       }

   }

    for(int i=p;i<=k;i++)
   {
      tab[i]=tab1[i];
   }


}



int main()
{
    int n;
    int *tab;

    cin>>n;

    tab = new int [n];
    tab1 = new int [n];

    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
    }


    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;

    //!sortowanie przez scalanie


    merge_sort(tab,0,n-1);


    //!koniec sortowania

    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;


    cout<<tab[n-1]<<" ";




    return 0;
}
