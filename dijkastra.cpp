//
//  main.cpp
//  dijkastra algo
//
//  Created by raghav babbar on 19/03/17.
//  Copyright © 2017 raghav babbar. All rights reserved.
//

#include <iostream>
using namespace std;
#define INFINITY 9999
int min(int[],int[],int);
int main(int argc, const char * argv[])
{
    int wadj[10][10];//w8 adjency matrix
    int n,edges,srcV,destV,weight;
    cout<<"\n enter the number of vertices and edges";
    cin>>n>>edges;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    wadj[i][j]=INFINITY;
    cout<<"\n enter the source ,destination vertex and their weight";
    for (int i=0; i<edges; i++)
    {
        cin>>srcV>>destV>>weight;
        wadj[srcV][destV]=weight;
        wadj[destV][srcV]=weight;
    }
    //DIJKASTRA START
    int sh[10]={0};
    int cost[10];
    int path[10]={0};
    int start;
    cin>>start;
    for(int i=1;i<=n;i++)
    { if(wadj[start][i]==INFINITY)
    {cost[i]=INFINITY;
    }
        else
        {
            cost[i]=wadj[start][i];
            path[i]=start;
        }
    
    }
    
    sh[start]=1;
    cost[start]=0;
    int flag=0;
    while(!flag)
    { int j;
    j=min(cost,sh,n);
        sh[j]=0;
        for(int i=1;i<=n;i++)
        {
         if(sh[i]!=1)
         {
         if(wadj[j][i]!=INFINITY)
         if(wadj[j][i]+cost[j]<cost[i])
         {cost[i]=wadj[j][i]+cost[j];
             path[i]=j;
         }
         }
        }
        flag=1;
        for(int i=1;i<=n;i++)
            if(sh[i]==0)
            {flag=0;
                break;
            }
    }
    // to display the shortest path from source vertex & cost;

    cout<<"\n enter the destination vertex to know its shorets disdance from source vertex";
    int d;
    cin>>d;
    cout<<"cost="<<cost[d];
    int ss=path[d];
    int i=0;
    int shortestPAth[10];
    while(ss!=start)
    {shortestPAth[i]=ss;
        i++;
        ss=path[ss];
    }
   cout<<"\n shortest path is "<<path[d];
    for(int t=0;t<i;t++)
        cout<<"->"<<shortestPAth[t];
return 0;
}
int min(int cost[],int sh[],int n)
{ int min_index;
int min1=9999;
for(int i=1;i<=n;i++)
{
if(sh[i]==0)
{ if(cost[i]<min1)
{
 min1=cost[i];
 min_index=i;
}
}

}

return min_index;

}
