//
//  main.cpp
//  level-Order_transversal
//
//  Created by raghav babbar on 01/02/17.
//  Copyright © 2017 raghav babbar. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
 typedef struct node
{node *right;
    node *left;
    int data;
}node;
node* create(int d)
{node *ptr=new node;
    ptr->data=d;
    ptr->left=ptr->right=NULL;
    return ptr;
    
}
void insertnode(int d,node *r)
{if(d>r->data)
{if(r->right)
    insertnode(d,r->right);
else {r->right=create(d);
    }
}
else
{
    if(r->left)
        insertnode(d, r->left);
    else{ r->left=create(d);
        }
}
}
void printLevelOrder(node *r)
{
    queue<node*> q;
    q.push(r);
    while(!q.empty())
    {node *ptr=q.front();
        
        cout<<" "<<ptr->data;
        q.pop();
        if(ptr->left)
            q.push(ptr->left);
        if(ptr->right)
            q.push(ptr->right);
            
    
    }
}
int main()
{
    int d;
    cout<<"\n enter the element in the tree press 0 to discontinue";
    cin>>d;
    node *root=create(d);
    while(true)
    {cin>>d;
        if(d==0) break;
        insertnode(d, root);
    }
    
  cout<<"LEVEL Order transversal ";  printLevelOrder(root);
    return 0;
}
