//
//  main.cpp
//  inheritence
//
//  Created by raghav babbar on 27/02/17.
//  Copyright © 2017 raghav babbar. All rights reserved.
//in this type of then
// tehn  class four has 2 copy of two variable one from class 2 and another from class 3
//by using virtual keyword
// if the base clas then the drive class may noit have  may or maynit hav cinstructor
// the dash method of object addd or remove
// display n elert box when user cli

#include<iostream>
#include <stack>
using namespace std;
typedef struct tree
{
    tree *right;
    tree *left;
    int data;
}tree;
tree *create(int d)
{
    tree *ptr=new tree;
    ptr->data=d;
    ptr->left=ptr->right=NULL;
    return ptr;
}
void insert(tree *&root,int data)
{
if(root==NULL)
root=create(data);
else if(data > root->data)
insert(root->right, data);
else if(data <root->data)
    insert(root->left, data);
}

void spiralOrder(tree *root)
{
    stack<tree*> s1;
    stack<tree*> s2;
    s1.push(root);
 while(!s1.empty()||!s2.empty())
 {
  if(s2.empty())
  {   while(!s1.empty())
  {
      tree *pop=s1.top();
      cout<<" "<<pop->data;
      s1.pop();
      if(pop->left)
          s2.push(pop->left);
      if(pop->right)
          s2.push(pop->right);
  }
      
      
  }
 else if(s1.empty())
 {
 while(!s2.empty())
 {
     tree *pop=s2.top();
     cout<<" "<<pop->data;
     s2.pop();
     if(pop->right)
         s1.push(pop->right);
     if(pop->left)
         s1.push(pop->left);
 
 }
 }
 }
}
int main()
{
    tree *root=NULL;
    while(1)
    {int d;
    cin>>d;
        if(d==-1) break;
        insert(root,d);
        
    }
    spiralOrder(root);


}
