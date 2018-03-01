#include <iostream>
#include <windows.h>

using namespace std;



class BST{

private:

struct wezel{

    int dane;
    wezel *lewy;
    wezel *prawy;
    wezel *ojciec;

}*korzen;

public:

    BST()
    {
        korzen=NULL;
    }

    void tree_insert(int k)
    {
        wezel *y=korzen;
        wezel *x=korzen;

        while(x!=NULL)
        {
           y=x;
           if(k<=(x->dane))
           {
               x=x->lewy;
           }
           else
           {
               x=x->prawy;
           }
        }

        wezel *el = new wezel;

        el->dane=k;
        el->ojciec=y;
        el->lewy = NULL;
        el->prawy = NULL;

        if(y==NULL)
        {
            korzen=el;
        }
        else
        {
            if(k<=(y->dane))
            {
                y->lewy=el;
            }else
            {
                y->prawy=el;
            }
        }

    }

    void tree_del(int k)
    {
        wezel *y=korzen;
        wezel *x=korzen;

        while(k!=(x->dane))
        {
           y=x;
           if(k<=(x->dane))
           {
               x=x->lewy;
           }
           else
           {
               x=x->prawy;
           }
        }

        if(x->lewy==NULL && x->prawy==NULL)
        {
            delete x;
            if(k<=(y->dane))
            {
                y->lewy=NULL;
            }else
            {
                y->prawy=NULL;
            }
        }else if((x->lewy==NULL && x->prawy!=NULL) || (x->lewy!=NULL && x->prawy==NULL))
        {

            if(k<=(y->dane))
            {
                y->lewy=x->lewy;
            }else
            {
                y->prawy=x->prawy;
            }

            delete x;
        }else
        {
           // cout<<"jeszcze nie dziala! "<<endl;

            wezel *z=x->prawy;
            wezel *oj=x->prawy;

            while(z->lewy!=NULL)
            {
                oj=z;
                z=z->lewy;
            }

            if(z->prawy!=NULL)
            {
               // wezel *pom=z->prawy;

                oj->lewy = z->prawy;
                z->prawy->ojciec=oj;

            }


            if(k<=(y->dane))
            {
                y->lewy=z;

            }else
            {
                y->prawy=z;
            }

            z->ojciec=y;
            z->lewy = x->lewy;


            if(z!=(x->prawy))
            {
                z->prawy = x->prawy;
            }

            delete x;


        }



    }



    void tree_max()
    {
        wezel *x=korzen;

        while((x->prawy)!=NULL)
        {
            x=x->prawy;
        }

        cout<<"Wynik: "<<(x->dane)<<endl;
    }

    void tree_min()
    {
        wezel *x=korzen;

        while((x->lewy)!=NULL)
        {
            x=x->lewy;
        }

        cout<<"Wynik: "<<(x->dane)<<endl;
    }

    void in()
    {
        inorder(korzen);
    }

    void inorder(wezel *x)
    {
        if((x->lewy)!=NULL)
        inorder(x->lewy);

        cout<<(x->dane)<<" ";

        if((x->prawy)!=NULL)
        inorder(x->prawy);
    }

    void pre()
    {
        preorder(korzen);
    }

    void preorder(wezel *x)
    {

        cout<<(x->dane)<<" ";

        if((x->lewy)!=NULL)
        preorder(x->lewy);

        if((x->prawy)!=NULL)
        preorder(x->prawy);
    }

    void post()
    {
        postorder(korzen);
    }

    void postorder(wezel *x)
    {

        if((x->lewy)!=NULL)
        postorder(x->lewy);

        if((x->prawy)!=NULL)
        postorder(x->prawy);

        cout<<(x->dane)<<" ";
    }

    ~BST()
    {
        delete korzen;
    }

};

int main()
{

   BST b;

   int x;
   int d;

   while(x!=8)
   {
       cout<<"Dodaj do BST (1) \n USUN Z BST (2) \n MAX (3) \n MIN (4) \n inorder(5) \n preorder(6) \n postorder(7)"<<endl;
        cout<<"========================================"<<endl;

       cin>>x;
        //system("CLS");
       switch( x )
        {
        case 1:
            cin>>d;
            b.tree_insert(d);
            break;

        case 2:
            cin>>d;
            b.tree_del(d);
            break;

        case 3:
            b.tree_max();
            break;

        case 4:
            b.tree_min();
            break;
        case 5:
            b.in();
            cout<<endl;
            break;
        case 6:
            b.pre();
            cout<<endl;
            break;
        case 7:
            b.post();
            cout<<endl;
            break;
        case 8:

            break;

        default:
            cout<<"Podaj poprawny numer";
            break;
        }




   }



    return 0;
}
