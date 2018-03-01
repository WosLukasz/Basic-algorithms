#include <iostream>
#include <map>
#include <vector>

using namespace std;
/*
struct node
{
    int id;
    char color;
    node *parent;
    int odl;
    vector <node> neigh;

};
*/






int main()
{
    int n,m,e,v1,v2;

    bool **tab;

    //!LISTA SASIEDZTWA

    cout<<"ile bedzie wierzcholkow:";
    cin>>n;
    cout<<"Podaj liczbe krawedzi:";
    cin>>m;

    //Podajemy informacje o sasiedztwie krawedzi


    map< int, vector<int> >tabb;

    for(int i=0;i<m;i++)
    {
        cin>>v1>>v2;

        tabb[v1].push_back(v2);
        tabb[v2].push_back(v1);
    }

    map< int, vector<int> >::iterator it=tabb.begin();

    for(it;it!=tabb.end();it++)
    {
        cout<<it->first<<": ";
        for(int j=0;j<tabb[it->first].size();j++)
        {
            cout<<tabb[it->first][j]<<" ";
        }
        cout<<endl;
    }


    //!czy jest drzewem ?
/*
    if(m==n-1)
    {
        if(bfs()==1)
        {
            cout<<"Jest drzewem!";
            return 0;
        }
    }

    cout<<"Nie jest drzewem";
*/
    for(int i=0;i<n;i++)
    {
        delete [] tab[i];
    }

    delete [] tab;


    return 0;
}


  /*
    //!MACIERZ SASIEDZTWA





    cout<<"ile bedzie wierzcholkow:";
    cin>>n;

    tab=new bool *[n];

    for(int i=0;i<n;i++)
    {
        tab[i] = new bool [n];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            tab[i][j]=0;
        }
    }

    //Podajemy informacje o sasiedztwie krawedzi
    cout<<"Podaj liczbe krawedzi:";
    cin>>m;


    for(int i=0;i<m;i++)
    {
        cin>>v1>>v2;

        tab[v1][v2]=1;
    }

    for(int i=0;i<n;i++)
    {
        delete [] tab[i];
    }

    delete [] tab;

    //!MACIERZ incydencji


    cout<<"ile bedzie wierzcholkow:";
    cin>>n;
    cout<<"Podaj liczbe krawedzi:";
    cin>>m;

    tab=new bool *[n];

    for(int i=0;i<n;i++)
    {
        tab[i] = new bool [m];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            tab[i][j]=0;
        }
    }

    //Podajemy informacje o sasiedztwie krawedzi


    for(int i=0;i<m;i++)
    {
        cin>>v1>>v2>>e;

        tab[v1][e]=1;
        tab[v2][e]=1;
    }

    for(int i=0;i<n;i++)
    {
        delete [] tab[i];
    }

    delete [] tab;

*/
