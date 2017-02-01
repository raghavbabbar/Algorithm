//
//  main.cpp
//  Binary_search_tree
//
//  Created by raghav babbar on 26/01/17.
//  Copyright © 2017 raghav babbar. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
typedef struct node
{int data;
    node *right;
    node *left;
    node *parent;
}node;
class BinarySearchTree
{node *root;
    node *array[2];
public:
  BinarySearchTree()
    {
     root=NULL;
     array[0]=array[1]=NULL;
    }
    bool isEmpty()
    {return root==NULL;
    }
    
    void createRootNode(int d);
    void inOrder(){inOrdertrans(root);};
    void inOrdertrans(node *r);
    void postOrder(){postOrdertrans(root);};
    void postOrdertrans(node *r);
    void preOrder(){preOrdertrans(root);};
    void preOrdertrans(node *r);
    void insert(int d);
    void insertnode(int d,node *n);
    void remove(int);
    int  totalnode() ;
    int  num_internal_node(node *r);
    int  internalnode(){return num_internal_node(root);}
    int  leafNode(){ return num_leaf_node(root);};
    int  num_leaf_node(node *n);
    node* create(int d);
    node *find(int d,node *r);
    bool isLeaf(node* );
    bool hasOneChild(node *);
    bool hasTwoChild(node *);
    node *find_minimum(node *);
};
node * BinarySearchTree::find_minimum(node* rot )
{   node *r=rot;
    node *ptr;
    int min=rot->data;
    stack<node *> stk;
    stk.push(rot);
    while (!stk.empty())
    {if(stk.top()->data<min)
    {min=stk.top()->data;
        r=stk.top();
    }
        ptr=stk.top();
        stk.pop();
        if(ptr->right)
            stk.push(ptr->right);
        if(ptr->left)
            stk.push(ptr->left);
    }
  return r;
}
node * BinarySearchTree:: find(int d,node *r)
{if(r)
{
if(d>(r->data))
    return (find(d,r->right));
else if(d<(r->data))
    return (find(d,r->left));
else if(d==(r->data))
{  cout<<"\nreturning -- in find "<<r->data<<"\n";
   return  r;
    
}
}
return NULL;
}
bool BinarySearchTree::hasTwoChild(node * r)
{if(r->left&&r->right)
{   cout<<"true";
    return true;}
else {
    cout<<"false "; return false;}
}
bool BinarySearchTree::isLeaf( node *r)
{  cout<<"leaf";
if(r->right||r->left)
   
{ cout<<"false leaf";return false;}
else {cout<<"\n true leaf";
    return true;}
}
bool BinarySearchTree::hasOneChild(node *r)
{
if((r->left&&!r->right)||(!r->left&&r->right))
{ cout<<"one child true";
    return true;
}
else return  false;

}

void BinarySearchTree::remove(int d)
{node *m=find(d,root);
   node*ptr=NULL;
abc:
   if(m)
 {
   
     
   if(isLeaf(m))
  { cout<<"\n leaf running\n";
  ptr=m->parent;
  if(ptr->left==m)
  {ptr->left=NULL;
  }
  else
  {ptr->right=NULL;
  }
      
  }
else if (hasOneChild(m))
{cout<<"one chuild";
    ptr=m->parent;
    cout<<"\nleft val"<<ptr->left->data;
    cout<<"\n right value "<<ptr->right->data;
    cout<<"\n main value"<<m->data;
     if(ptr->left==m)
     {
       if(m->left)
       {  ptr->left=m->left;
           m->left->parent=m->parent;}
       else{ ptr->left=m->right;
           m->right->parent=m->parent;
           
                  }
         
     }
    else if (ptr->right==m)
    {if(m->left)
    {ptr->right=m->left;
        m->left->parent=m->parent;
    }else
    {
    
        ptr->right=m->right;
        m->right->parent=m->parent;
    
    
    }
        
    
    }
    

}
 else if (hasTwoChild(m))
 {
     node *right_small_node=find_minimum(m->right);
     m->data=right_small_node->data;
     m=find(right_small_node->data , m->right);
     goto abc;
 }
 }
 else cout<<"\nelemnt not found";
}
void BinarySearchTree::insert(int d)
{if(root)
    insertnode(d,root);
else
    createRootNode(d);
 }

void BinarySearchTree::insertnode(int d,node *r)
{if(d>r->data)
{if(r->right)
     insertnode(d,r->right);
else {r->right=create(d);
    r->right->parent=r;}
}
else
{
if(r->left)
    insertnode(d, r->left);
else{ r->left=create(d);
    r->left->parent=r;}
}
}
void BinarySearchTree::createRootNode(int d)
{
root=create(d);
    root->parent=NULL;
}
node*BinarySearchTree::create(int d)
{
    node  *ptr=(node*)malloc(sizeof(node));
    ptr->left=ptr->right=ptr->parent=NULL;
    ptr->data=d;
    return ptr;
}

int BinarySearchTree::totalnode()
{
    return (num_leaf_node(root)+num_internal_node(root));
}
int BinarySearchTree::num_internal_node(node *r)
{if(r)
{
   if(!r->left&&!r->right)
    return 0;
  else
    return (num_internal_node(r->right)+num_internal_node(r->left)+1);
}
else return 0;
}
int BinarySearchTree::num_leaf_node(node *r)
{if(r)
{
 if(!r->left&&!r->right)
    return (num_leaf_node(r->right)+num_leaf_node(r->left)+1);
else
    return (num_leaf_node(r->right)+num_leaf_node(r->left)+0);

}
else return 0;
}

void BinarySearchTree::inOrdertrans( node *r)
{if(r)
{
    inOrdertrans(r->left);
    cout<<" "<<r->data
    ;
    inOrdertrans(r->right);
    
}
}
void BinarySearchTree::preOrdertrans(node *r)
{
 if(r)
 {
     cout<<" "<<r->data;
     preOrdertrans(r->left);
     preOrdertrans(r->right);
 }
}
void BinarySearchTree::postOrdertrans(node *r)
{
    if(r)
    {postOrdertrans(r->left);
    postOrdertrans(r->right);
    cout<<" "<<r->data;
        
    
    }
}
int main()
{int t,elemt;
 cout<<"\n 0.insert a elemnet in a tree";
 cout<<"\n 1.Preorder transversal";
 cout<<"\n 2.Inorder transversal";
 cout<<"\n 3.Postorder transversal";
 cout<<"\n 4.number of leaft node";
 cout<<"\n 5.number of internal node";
 cout<<"\n 6.total node";
 cout<<"\n 7.delete the element";
 cout<<"\n 9.to exit";
    
    BinarySearchTree tree;
    
  
    tree.insert(2);
    tree.insert(1);
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    tree.insert(7);
    while (1) {
        cout<<"\n enter the choice";
        cin>>t;
        switch (t) {
            case 0:cout<<"\n enter the element";
                cin>>elemt;
              
                tree.insert(elemt);
                break;
            case 1:cout<<"\n[ ";tree.preOrder();cout<<" ]"; break;
            case 2:cout<<"\n[ ";tree.inOrder();cout<<" ]";break;
            case 3:cout<<"\n[ ";tree.postOrder();     cout<<" ]"; break;
            case 4:cout<<"\n leaf node="<<tree.leafNode(); break;
            case 5:cout<<"\n internal node="<<tree.internalnode();break;
            case 6:cout<<"\n total node="<<tree.totalnode();break;
            case 7:cout<<"\n enter the element to delete"; cin>>elemt;tree.remove(elemt);break;
            default: exit(0);
                break;
        }
    
    
    }
    
       return 0;
}
