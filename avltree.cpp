//
//  main.cpp
//  avltree
//
//  Created by raghav babbar on 12/02/17.
//  Copyright © 2017 raghav babbar. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct AvlNode
{
    AvlNode *right;
    AvlNode *left;
    int height;
    int data;
    AvlNode(AvlNode *r=NULL,AvlNode *l=NULL,int h=0,int d=0):right{r},left{r},height{h},data{d}
    {}
}AvlNode;


class AvlTree
{
AvlNode *root;
int height;
    AvlNode* leftRotate(AvlNode  *&r);
    AvlNode* rightRotate(AvlNode *&r);
   AvlNode* create(int);
 void insertdata(AvlNode *&r,int d );
 void intraversal(AvlNode *);
 int maxx(int a,int b);
 int getHeight(AvlNode*);
 void lorder(AvlNode *root,int d);
    int getBalnce(AvlNode *root);
public:
    AvlTree()
    {   height=0;
        root=NULL;
    }
    
    void insert(int);
    void inorder();
    int getHeightOfTree();
    void levelOrderTraversal();
};
int AvlTree::getBalnce(AvlNode *roo)
{
    return getHeight(roo->left)-getHeight(roo->right);
}
void AvlTree::levelOrderTraversal()
{
    for(int i=0;i<=getHeightOfTree();i++)
    {    cout<<"\n";
        lorder(root, i);
    
    }
}
void AvlTree::lorder(AvlNode *root,int d)
{if(d==0)
cout<<root->data<<"("<<root->height<<")";
else
{   if(root->left)
    lorder(root->left, d-1);
    if(root->right)
    lorder(root->right, d-1);
}
    
}
int AvlTree::getHeightOfTree()
{
    height=root->height;
    return root->height;
}
int AvlTree::getHeight(AvlNode *r)
{if(r)
return r->height;
else return -1;
}
int AvlTree::maxx(int a, int b)
 {
 return a>b?a:b;
 }

void AvlTree::inorder()
{intraversal(root);
}
void AvlTree:: intraversal(AvlNode *r)
{if(r)
{
intraversal(r->left);
cout<<r->data<<"("<<r->height<<") ";
intraversal(r->right);
}
}

AvlNode* AvlTree ::create(int d)
{   AvlNode *ptr=new AvlNode();
    ptr->left=ptr->right=NULL;
    ptr->data=d;
    ptr->height=0;
    return ptr;
}
void AvlTree::insert(int d)
{   if(root)
    insertdata(root,d);
else root=create(d);
}
void AvlTree::insertdata(AvlNode *&r, int d)
{
if(d>r->data)
{    if(r->right)
    insertdata(r->right, d);
    else
    { r->right=create(d);
           }
}
 else if(d<r->data)
 {   if (r->left)
     insertdata(r->left, d);
 else{ r->left=create(d);
     }
    
 }
 r->height=maxx(getHeight(r->left), getHeight(r->right))+1;
 int balancefacor=getBalnce(r);
   
 //rr rotation
 if(balancefacor<-1&&d>r->right->data)
 {
     r=leftRotate(r);
 }//rl totation
 else if(balancefacor<-1&&d<r->right->data)
    {
        r->right = rightRotate(r->right);
        r=leftRotate(r);
    }
    //ll rotation
 else if (balancefacor>1&&d<r->left->data)
 {
   r = rightRotate(r);
   
 }
    //lr rotation
 else if (balancefacor>1&&d>r->left->data)
 { r->left = leftRotate(r->left);
   r=rightRotate(r);
 }

}
AvlNode* AvlTree::rightRotate(AvlNode *&r)
{  AvlNode *rleft=r->left;
   AvlNode  *rleft_right = rleft->right;
    rleft->right=r;
    r->left=rleft_right;
    r->height=maxx(getHeight(r->left), getHeight(r->right))+1;
    rleft->height=maxx(getHeight(rleft->left), getHeight(rleft->right))+1;
      return rleft;
}
AvlNode* AvlTree:: leftRotate(AvlNode *&r)
{AvlNode *rright=r->right;
AvlNode *rright_left=rright->left;
    rright->left=r;
    r->right=rright_left;
    r->height=maxx(getHeight(r->left), getHeight(r->right))+1;
    rright->height=maxx(getHeight(rright->left),getHeight(rright->right))+1;
    return rright;
}

int main()
{
    AvlTree tree1;
    tree1.insert(5);
    tree1.insert(9);
    tree1.insert(10);
     tree1.insert(11);
     tree1.insert(12);
     tree1.insert(13);
    tree1.inorder();
    tree1.levelOrderTraversal();
    
}
