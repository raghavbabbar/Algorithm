//
//  main.cpp
//  tree_tranversal_without_recursion
//
//  Created by raghav babbar on 26/01/17.
//  Copyright © 2017 raghav babbar. All rights reserved.
//
#include <stack>
#include <iostream>
using namespace std;
typedef struct node
{int data;
    node *right;
    node *left;
}node;
void postOrder(node *rootnode);
void inOrder(node *rootnode);
void preOrder(node *rootNode);
node * makeNode(int d);
void createTree(node *root,int d);
node * makeNode(int d)
{
node *ptr=(node*)malloc(sizeof(node));
ptr->data=d;
ptr->left=ptr->right=NULL;
return ptr;
}
void createTree(node *root,int d)
{
if(d>root->data)
{
if(root->right)
    createTree(root->right,d);
else {root->right=makeNode(d);
}
}
else
{
if(root->left)
    createTree(root->left, d);
else
    root->left=makeNode(d);
}
}
void preOrder(node *rootNode)
{stack<node*> stk;
    stk.push(rootNode);
    while(!stk.empty())
    {node *ptr=stk.top();
     stk.pop();
        cout<<" "<<ptr->data;
     if(ptr->right)
         stk.push(ptr->right);
     if(ptr->left)
         stk.push(ptr->left);
    }
}
void inOrder(node *rootnode)
{stack<node*> stk;
    node*ptr=rootnode;
abc:
    stk.push(ptr);
    while(true)
    {if(!ptr->left) break;
     stk.push(ptr->left);
     ptr=ptr->left;
    }
    while(!stk.empty())
    {node *p= stk.top();
     stk.pop();
     cout<<" "<<p->data;
     if(p->right)
     {ptr=p->right;
     goto abc;
     }
    }
}
void postOrder(node *rootnode)
{stack<node* > stk;
    node * lastpop=NULL;
    node *ptr=rootnode;
abc:
    while(true)
    {stk.push(ptr);
     if(!ptr->left)
         break;
        ptr=ptr->left;
    }
    while(!stk.empty())
    {
    if(stk.top()->right&&stk.top()->right!=lastpop)
    {ptr=stk.top()->right;
        goto abc;
    }
        else
        {cout<<" "<<stk.top()->data;
            lastpop=stk.top();
            stk.pop();
        }
    
    
    }

    
    
}
int main()
{
cout<<"\nenter the data into the node and 0 to discontinue\n";
    int dd;
    cin>>dd;
    node * rootnode=makeNode(dd);
    while(true)
    {cin>>dd;
        if (dd==0) break;
        createTree(rootnode,dd);}
    
    cout<<"[";preOrder(rootnode);   cout<<"]";cout<<"\n";
    cout<<"[" ; inOrder(rootnode);cout<<"]";cout<<"\n";
      cout<<"["; postOrder(rootnode);cout<<"]";cout<<"\n";
return 0;
}
