//
//  main.cpp
//  Swap_nodes
//
//  Created by raghav babbar on 03/02/17.
//  Copyright © 2017 raghav babbar. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct node
{
    int data;
    node *left;
    node *right;
}node;
void levelbylevel(node *r,int l);
void rotate(node *r);
void  height(node *root);
node *create(int n);

void inorder(node *root);
int  h=1;
int maxx=1;
int main()
{
    int n,a,b;
    cin>>n;
    node *root=NULL;
    root=create(1);
    queue<node*> q;
    q.push(root);
    node *ptr=NULL;
    for(int i=1;i<=n;i++)
    {cin>>a>>b;
        if(!q.empty()){
            ptr=q.front();
            q.pop(); }
        if(a!=-1)
        {ptr->left=create(a);
            q.push(ptr->left);
        }
        if(b!=-1)
        {
            ptr->right=create(b);
            q.push(ptr->right);
        }
        
    }
    height(root);
    
    
    int t,k;
    cin>>t;
    
    
    for(int i=0;i<t;i++)
    {
        cin>>k;
        
        int w=1;
        while((k*w)<maxx)
        {int f=k*w;
            levelbylevel(root,f);
            w++;
        }
        inorder(root);
        cout<<"\n";
        
    }
    
    
}
void inorder(node *root)
{if(root)
{inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
}

void  height(node *root)
{
    if(root->left)
    {h++;
        height(root->left);
    } if(root->right)
    {
        h++;
        height(root->right);
    }
    if(h>maxx)
        maxx=h;
    h--;
    
}

void rotate(node *r)
{node *t;
    
    t=r->left;
    r->left=r->right;
    r->right=t;
}
void levelbylevel(node *r,int l)
{if(r)
{
    if(l==1)
    rotate(r);
    levelbylevel(r->left,l-1);
    levelbylevel(r->right,l-1);
}
}

node *create(int n)
{
    node *ptr=new node;
    ptr->data=n;
    ptr->left=ptr->right=NULL;
    return ptr;
}