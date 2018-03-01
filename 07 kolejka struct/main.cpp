#include <iostream>

using namespace std;


struct wezel
{
    int dane;
    wezel *next;
    wezel *prev;

}*head,*head1;

void push(int d)
{
    wezel *nowy = new wezel;

    nowy->dane=d;

    if(head==NULL)
    {
        nowy->next=NULL;
        nowy->prev=NULL;
        head1=nowy;
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
    if(head1==NULL)
    {
        cout<<"lista pusta"<<endl;
    }else if(head1->next==NULL)
    {
        delete head;


        head=NULL;
        head1=NULL;
    }else
    {
        head1=head1->next;
        delete head1->prev;
        head1->prev=NULL;
    }

}

void top()
{
    if(head1!=NULL)
    cout<<(head1->dane)<<endl;
    else
        cout<<"lista pusta"<<endl;

}

int main()
{
    int x=0;
    int d;

    head=NULL;
    head1=NULL;

    while(x!=4)
    {
        cout<<"wstaw do kolejki(1) | zdejmij z kloejki(2) | sprawdz co jest w kolejce (3) | wyjscie (4)"<<endl;
        cin>>x;

        if(x==1)
        {
            cout<<"Co chcesz dodac do kolejki:";
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
