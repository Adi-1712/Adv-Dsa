#include <iostream>
using namespace std;
struct node {
    int key, bf;
    node *left, *right, *parent; 
    node(int k) {  
        key = k;
        bf = 0;
        left = right = parent = NULL;
    }
};

class avl {
    node *root;
    void LLrotation(node *i){
    	node *j, *ip;
    	j = i->left;
    	ip = i->parent;
    	ip->left = j;
    	j->parent = ip;
    	j->right = i;
    	i->parent = j;
    	i->left = NULL;
    	i->bf = height(i->left) - height(i->right);
    	j->bf = height(j->left) - height(j->right);
    	while(ip){
    		ip->bf = height(ip->left) - height(ip->right);
    		ip = ip->parent;
    	}
    	return;
    }
    void LRrotation(node *i)
    {
    	node *j, *ip;
        i=i->left;
    	i=j->parent;
    	j=i->right;
    	ip=i->parent;
    	j->parent=ip;
        ip->left=j;
        i->parent=j;
        i->right=NULL;
        i=i->parent;
        LLrotation(i);
        return;
        
    }
public:
    avl() { root = NULL; } 
    int height(node *root) {
        if (!root) return -1;
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh, rh) + 1;
    }
    void inorder(node *root) {
        if (!root) return;
        inorder(root->left);
        cout << root->key << " "<<root->bf<<endl;
        inorder(root->right);
    }
    void insert(int k) {
        node *nn = new node(k);
        if (!root) {
            root = nn;
            return;
        }
        node *p = root, *q = NULL;
        while (p) {
            q = p;
            if (p->key == k) return;
            p = (p->key < k) ? p->right : p->left;
        }
        nn->parent = q;
        if (q->key < k)
            q->right = nn;
        else
            q->left = nn;
        node *r = nn->parent;
        node *i = NULL;
        while(r){
        	r->bf = height(r->left) - height(r->right);
        	if(r->bf == 2 || r->bf == -2){
        		if(!i)
        			i = r;
        	}
        	r = r->parent;
        }
        if(!i) return;
        //type of imbalance
        if(i->bf == 2){
        	if(i->left->key > k)
        		LLrotation(i);
        	else
        		LRrotation(i);
	}
    }
    void display() 
    {
        inorder(root);
        cout << endl;
    }
};
int main() 
{
    avl t1;
    /*t1.insert(100);
    t1.insert(75);
    t1.insert(200);
    t1.insert(50);
    t1.insert(150);
    t1.insert(300);
    t1.insert(100);
    t1.display();
    */
    t1.insert(400);
    t1.insert(300);
    //t1.insert(200);
    t1.insert(500);
    t1.insert(100);
    t1.insert(250);
    t1.display();
    
   return 0;
}