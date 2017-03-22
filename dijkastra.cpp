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
    int wadj[6][6]={INFINITY,4,1,INFINITY,INFINITY,INFINITY,
                      4,INFINITY,2,1,6,INFINITY,
                      1,2,INFINITY,INFINITY,5,INFINITY,
                      INFINITY,1,INFINITY,INFINITY,3,4,
                      INFINITY,6,5,3,INFINITY,6,
                      INFINITY,INFINITY,INFINITY,4,6,INFINITY
    
    
    };//w8 adjency matrix
    int n=6;
    int cost[10]={0};
    int path[10]={0};
    int sh[10]={0};
    int source;
    cout<<"\n enter the source vertex:";
    cin>>source;
    source--;
    for (int i=0; i<n;i++) {
        if(wadj[source][i]!=INFINITY)
        {cost[i]=wadj[source][i];
            path[i]=source+1;
        }
        else
        {cost[i]=INFINITY;
        }
    }
    sh[source]=1;
    cost[source]=0;
        int flag=1;
    int j;
    while(flag)
    {j=min(cost,sh,6);
        sh[j]=1;
        for(int i=0;i<n;i++)
        { cout<<"\ni="<<i<<"sh="<<sh[i]<<" w8="<<wadj[j][i];
            
            if(sh[i]!=1)
        {if(wadj[j][i]!=INFINITY)
        {
            if((cost[j]+wadj[j][i])<cost[i])
        {cost[i]=cost[j]+wadj[j][i];
            path[i]=j+1;
        }
        }
        
        }
            
        }
        
        flag=0;
        for(int i=0;i<n;i++)
            if(sh[i]==0)
            {   flag=1;
                break;
            }
    
    }
    int dest;
    cout<<"\n eneter the destination vertex";
    cin>>dest;
    int shortpath[10];

    cout<<"\n path from "<<source+1<<"  To "<<dest<<"  is ="<<source<<" ->";
    int m=path[dest-1];
    int index=0;
    cout<<"\nii="<<index;
    while (m!=source+1) {
           cout<<"\nii="<<index;
        shortpath[index] = m;
        m=path[m];
        index++;
        
    }
    
    for(int k=index-1;k>=0;k--)
        cout<<" ->"<<shortpath[k];
return 0;
}
int min(int cost[],int sh[],int n)
{ int min_index;
int min1=9999;
for(int i=0;i<n;i++)
{
if(sh[i]==0)
{ if(cost[i]<min1)
{
 min1=cost[i];
 min_index=i;
}
}

}
cout<<"\n returning"<<min_index<<"\n";
return min_index;

}
