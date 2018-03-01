#include <iostream>

using namespace std;


class kolejka{

private:
    struct wezel
    {
        int dane;
        wezel *next;
        wezel *prev;

    }*head;

public:

        kolejka()
        {
            head=NULL;

        }

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
};

int main()
{
    int x=0;
    int d;

    kolejka a;

    while(x!=4)
    {
        cout<<"wstaw na stos(1) | zdejmij na stos (2) | sprawdz co jest na stosie (3) | wyjscie (4)"<<endl;
        cin>>x;

        if(x==1)
        {
            cout<<"Co chcesz dodac na stos:";
            cin>>d;

            a.push(d);
        }

        if(x==2)
        {
            a.pop();
        }

        if(x==3)
        {
            a.top();
        }



    }




    return 0;
}
