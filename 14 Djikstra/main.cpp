#include <iostream>
#include <map>
#include <vector>
#include <set>

#define INFINITY 2147483647

/*
Testing data:

6
9
A B
3
A E
3
E F
2
F A
6
B C
1
C F
1
C D
3
D B
3
F D
1
A
*/

using namespace std;

map < char , map<char,int> > Adj;
map < char , map<char,int> >::iterator it;
map <char, char> pi;
map <char, int> d;
set <char> Q;
set <char> S;
int n,m,w;
char v1,v2;

char extract_min()
{
    char u=v1;
    int mi=INFINITY;

    set <char>::iterator iti;

    for(iti=Q.begin();iti!=Q.end();iti++)
    {
        if(d[*iti]<mi)
        {
            mi=d[*iti];
            u=*iti;
        }
    }

    return u;
}

void djikstra(char v1)
{
    d[v1]=0;
    char u;

    while(!Q.empty())
    {

        u=extract_min();


        Q.erase(u);
        S.insert(u);

         map<char,map<char,int> >::const_iterator ptr;

        for(ptr=Adj.begin();ptr!=Adj.end(); ptr++)
        {
            if(ptr->first==u)
            {
                break;
            }
        }


        for( map<char,int>::const_iterator eptr=ptr->second.begin();eptr!=ptr->second.end(); eptr++)
        {

            if(S.find(eptr->first)==S.end())
            {
                //cout<<"relax("<<u<<","<<eptr->first<<")"<<endl;

               if(d[eptr->first]>d[u]+eptr->second)
                {
                    d[eptr->first]=d[u]+eptr->second;
                    pi[eptr->first]=u;
                }


            }

        }

    }

}

int main()
{
    cout<<"Podaj ilosc wezlow:";
    cin>>n;
    cout<<"Podaj ilosc krawedzi:";
    cin>>m;

    for(int i=0;i<m;i++)
    {
        cin>>v1>>v2;
        cin>>w;

        Adj[v1].insert(map<char, int>::value_type(v2, w));
        Q.insert(v1);
        Q.insert(v2);

    }

    for(it=Adj.begin();it!= Adj.end();it++)
    {
        d[(it->first)]= INFINITY;
        pi[(it->first)]= NULL;

    }


    cout<<"Podaj wierzcholek od ktorego zaczniesz:";
    cin>>v1;

    djikstra(v1);

    map <char, int>::iterator iti;
    for(iti= d.begin();iti!=d.end();iti++)
    {
        cout<<iti->first<<": "<<pi[iti->first]<<" | "<<iti->second<<endl;

    }

    return 0;
}
