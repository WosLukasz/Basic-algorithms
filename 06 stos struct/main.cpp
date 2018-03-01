#include <iostream>

using namespace std;


struct wezel
{
    int dane;
    wezel *next;
    wezel *prev;

}*head;

void push(int d)
{
    wezel *nowy = new wezel;

    nowy->dane=d;


    if(head==NULL)
    {
        nowy->next=NULL;
        nowy->prev=NULL;
    }else
    {
         nowy->next=NULL;
         head->next=nowy;
         nowy->prev=head;
    }

    head=nowy;

}

void pop()
{
    if(head==NULL)
    {
        cout<<"lista pusta"<<endl;
    }else if(head->prev==NULL)
    {
        delete head;

        head=NULL;
    }else
    {
        head=head->prev;
        delete head->next;
        head->next=NULL;
    }




}


void top()
{
    if(head!=NULL)
    cout<<(head->dane)<<endl;
    else
        cout<<"lista pusta"<<endl;

}



int main()
{
    int x=0;
    int d;

    head=NULL;

    while(x!=4)
    {
        cout<<"wstaw na stos(1) | zdejmij ze stosu(2) | sprawdz co jest na stosie (3) | wyjscie (4)"<<endl;
        cin>>x;

        if(x==1)
        {
            cout<<"Co chcesz wrzuciæ na stos:";
            cin>>d;

            push(d);
        }

        if(x==2)
        {
            pop();
        }

        if(x==3)
        {
            top();
        }



    }




    return 0;
}
