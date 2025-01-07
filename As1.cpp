#include<iostream>
using namespace std;

struct node
{  
    string word,meaning;
    node *left,*right;
};

class BST
{
    node*root;

    void inorder_2(node*root)
    {
        if(!root)
           return;
        inorder_2(root->left);
        cout<<root->word<<"\t"<<root->meaning<<endl;
        inorder_2(root->right);
        return;
    }

    public:
    BST()
    {
        root=NULL;
    }

    void insert(string w,string m)
    {
        node *nn=new node;
        if(!nn) return;
        nn->left =nn->right=NULL;
        nn->word=w;
        nn->meaning=m;

        if(!root)
        {
            root=nn;
            return;
        }
        node *ptr=root;
        while(ptr)
        {
            if (ptr->word==w)
            {
               delete nn;
               return;
            }
            if(ptr->word<w)
            {
               if(!ptr->right)
               {
                ptr->right =nn;
                return;
               }
               else
               {
                ptr=ptr->right;
               }
            }
            else
            {
                if(!ptr->left)
                {
                    ptr->left=nn;
                    return;
                }
                else
                    ptr=ptr->left;
            }
        }
         return;
    }

    void inorder()
    {
        inorder_2(root);
        return;
    }

    void search(string target)
    {
        int key=0;
        node *ptr=root;
        while(ptr)
        {
            if (ptr->word==target)
            {
               cout<<"Found"<<endl;
               key++;
               return;
            }
            if(ptr->word<target)
            {
               if(ptr->word==target)
               {
                cout<<"Found"<<endl;
                key++;
                return;
               }
               else
               {
                ptr=ptr->right;
               }
            }
            else
            {
                if(ptr->word==target)
                {
                    cout<<"Found"<<endl;
                    key++;
                    return;
                }
                else
                    ptr=ptr->left;
            }
        }
        if(!key)
            {
                cout<<"Not found"<<endl;
            }
    }
};

int main()
{
    BST t1;
    t1.insert("Computer","Machine");
    t1.insert("Teacher","Faculty");
    t1.insert("Student","Learner");
    t1.insert("Parent","Guardian");
    t1.insert("Algo","Steps");
    t1.insert("Bag","Luggage");
    t1.inorder();
    t1.search("Parent");
    t1.search("Hi");
    return 0;
}