//
//  main.cpp
//  breadth_first_search
//
//  Created by raghav babbar on 28/02/17.
//  Copyright © 2017 raghav babbar. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
typedef struct Node
{
    int status ;
    int data ;
     Node *next;
    
}node;
struct graph
{
    int n;
    int e;
    node *list;
};
Node * create(int d)
{
    Node *ptr= (Node *)malloc(sizeof(Node));
    ptr->data=d;
    ptr->status=1;
    ptr->next=NULL;
    return ptr;

}
graph * createGraph()
{
    graph *p;
    p=(graph * )malloc(sizeof(graph));
    cout<<"\n enter the vertices"; cin>>p->n;
    cout<<"\n enter the edges"; cin>>p->e;
    p->list=(Node *)malloc(sizeof(Node)* p->n);
    for(int i=0;i<p->n;i++)
    {
    p->list[i].data=i;
    p->list[i].status=1;
    p->list[i].next=NULL;
    }
    int x,y;
    for(int i=0;i<p->e;i++)
    { cin>>x>>y;
        Node * ptr=&(p->list[x]);
          while(ptr->next != NULL)
           ptr=ptr->next;
        ptr->next=create(y);
    }
return p;
}

void breadth_First_Traversal(graph *&ptr)
{
    queue<Node *> q;
    
    Node *latest=&(ptr->list[0]);
    latest->status=2;
    q.push(latest);
    while (!q.empty())
    {
        latest = q.front();
        cout<<" \n traversal  of "<<latest->data;
        q.pop();
        latest->status=3;
        latest=latest->next;
        while(latest)
        { if((ptr->list[latest->data]).status == 1)
        {   ptr->list[latest->data].status = 2;
            q.push(&(ptr->list[latest->data]));
        }
            latest=latest->next;
        }
    }
}
void show(graph *p)
{
    int n=0;
    while(n<p->n)
    {
        Node *ptr=&(p->list[n]);
        cout<<"\n direct edge from "<<ptr->data<<" are ";
        ptr=ptr->next;
        while(ptr != NULL){
            cout<<"\n    * "<<ptr->data;
            ptr=ptr->next;

        }
        n++;
    }
}
int main(int argc, const char * argv[])
{
    graph *g=createGraph();
    breadth_First_Traversal(g);
    show(g);
    
    
    return 0;
}
