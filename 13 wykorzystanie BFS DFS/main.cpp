#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> *tab;
queue <int> kolejka;
int *color;
int *pi;
int *time;
int t;

void dfs(int s)
{
    color[s]=1;
    t++;
    time[s]=t;
    //cout<<s<<"<- ";

    for(int i=0;i<tab[s].size();i++)
    {
        if(color[tab[s][i]]==0)
        {
            time[tab[s][i]]=t;
            pi[tab[s][i]]=s;
            dfs(tab[s][i]);
        }
    }

    color[s]=2;

}

void bfs(int s)
{
    kolejka.push(s);
    int u=s;
    color[u]=1;
    time[u]=0;

    while(kolejka.size()!=0)
    {

        u=kolejka.front();
        for(int i=0;i<tab[u].size();i++)
        {
            if(color[tab[u][i]]==0)
            {
                color[tab[u][i]]=1;
                time[tab[u][i]]=time[u]+1;
                pi[tab[u][i]]=u;
                kolejka.push(tab[u][i]);
            }
        }
        color[u]=2;
        kolejka.pop();

    }

}

int main()
{
    int v1,v2,m,n;

    cout<<"Podaj ilosc wierzcholkow i ilosc krawedzi:";
    cin>>n>>m;

    tab = new vector<int> [n+1];
    color = new int[n+1];
    pi = new int [n+1];
    time = new int [n+1];

    //! 0-kolor bialy(nieodwiedzony) 1- kolor szary(przetwarzony) 2-kolor czarny(przetworzony)
    //!Pierwszy node ma wartosc 0 !!

    for(int i=0;i<n;i++)
    {
        color[i]=0;
        pi[i]=-1;
        time[i]=0;
    }

    for(int i=0;i<m;i++)
    {
        cin>>v1>>v2;

        tab[v1].push_back(v2);


        if(v1!=v2)
        {
            tab[v2].push_back(v1);
        }

    }

    cout<<"Najkrotsza droga z do:"<<endl;

    cout<<"Wybierz poczatkowy node:";
    cin>>v1;


    cout<<"Wybierz koncowy node:";
    cin>>v2;


    t=0;

    bfs(v1);
/*
    for(int i=0;i<n;i++)
    {
        cout<<pi[i]<<endl;
    }
    */
    int d=v2;
    cout<<v2;
    while(pi[d]!=-1)
    {
        cout<<"<- "<<pi[d];
        d=pi[d];
    }

   // cout<<v1<<endl;


    return 0;
}
