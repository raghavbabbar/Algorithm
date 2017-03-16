//
//  main.cpp
//  nmst2
//
//  Created by raghav babbar on 15/03/17.
//  Copyright © 2017 raghav babbar. All rights reserved.
//

//
//  main.cpp
//  classnmst
//
//  Created by raghav babbar on 15/03/17.
//  Copyright © 2017 raghav babbar. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
#define infinity 9999
int main(int argc, const char * argv[])
{
    int weight[5][5]={infinity,10      ,   infinity,5     ,infinity  ,
                     10      ,infinity,   5       ,5      ,10      ,
                     infinity,5       ,infinity,   infinity,  infinity,
                     5        ,5      ,infinity ,infinity,20         ,
                     infinity ,10     ,infinity ,20       ,infinity
    
    };

    for(int i=0;i<5;i++)
    {  for(int j=0;j<5;j++)
            cout<<weight[i][j]<<"     ";
    cout<<"\n";
    }
    
    //The Floyd-Warshall Algorithm
    for(int k=0;k<5;k++)
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
            {
            if(weight[i][j]>weight[i][k]+weight[k][j]&&i!=j)
                weight[i][j]=weight[i][k]+weight[k][j];
            
            }
    
    
    
    for(int i=0;i<5;i++)
    {  for(int j=0;j<5;j++)
        cout<<weight[i][j]<<"     ";
        cout<<"\n";
    }
}
