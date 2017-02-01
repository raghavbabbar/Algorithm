//
//  main.cpp
//  heap_tree
//
//  Created by raghav babbar on 02/02/17.
//  Copyright © 2017 raghav babbar. All rights reserved.
//

#include <iostream>
using namespace std;
#define max 20
class heaptree
{int heap[max];
int n;
public:
    heaptree()
    {n=-1;
    }
    void insert_item(int);
    int delete_head();
    void display();
};
void heaptree:: insert_item(int item )
{
    n+=1;
if(n>=max)
{cout<<"\n overflow ";
    return;
}
    heap[n]=item;
    int p=n;
    int parent=(n-1)/2;
    int data=item;
    int f=0;
      while((parent!=p)&&item>heap[parent])
      { heap[p]=heap[parent];
          p=parent;
          parent=(p-1)/2;
          f=2;}
     if(f)
      heap[parent]=item;
}
int heaptree::delete_head()
{
    int t=heap[0];
    heap[0]=heap[n];
    n--;
    int i=0,temp;
    int downi;
    while(true)
    {downi=i;
    if((downi*2+1)<=n&&heap[downi*2+1]>heap[i])
        i=downi*2+1;
     if((downi*2+2)<=n&&heap[downi*2+2]>heap[i])
         i=downi*2+2;
      if(downi==i)
          break;
        temp=heap[downi];
        heap[downi]=heap[i];
        heap[i]=temp;
    }
    
    return t;
}
void heaptree::display()
{
    for (int i=0;i<=n;i++) {
        cout<<" "<<heap[i];
    }

}
int main(int argc, const char * argv[]) {
    heaptree h;
    while (true) {
        cout<<"\n eneter the choice";
        int i,tt;
        cin>>i;
        switch (i) {
            case 1:cout<<"\n enter the item";
                cin>>tt;
                h.insert_item(tt);
                break;
            case 2:h.display(); break;
            case 3:cout<<"deleting element "<<h.delete_head(); break;
            default: exit(0);
                break;
        }
    }
    return 0;
}
