//
//  main.cpp
//  Bankers_algorithm
//
//  Created by Aman Khullar on 4/9/17.
//  Copyright © 2017 Aman Khullar. All rights reserved.
//

#include<iostream>
using namespace::std;

class bank{
    int processes;
    int resources;
    int available[10];
    int max[10][10];
    int allocation[10][10];                                     //operator overloading needs to be done
    int need[10][10];                                           //multithreading needs to be implemented
    int request[10][10];
    int sum[10];
    int work[10];
    bool finish[10];
public:
    bank()
    {
        processes=0;
        resources=0;
        for(int i=0;i<10;i++)
        {
            sum[i]=0;
            available[i]=0;
            for(int j=0;j<10;j++)
            {
                max[i][j]=0;
                allocation[i][j]=0;
                need[i][j]=0;
                request[i][j]=0;
            }
        }
    }
    void input();
    void calculate();
    int resource_request();
    int safety_algorithm();
    int is_lessthan(int*,int*);
    void plus(int*,int*);
};
void bank::input()
{
    cout<<"Enter the number of processes\n";
    cin>>processes;
    cout<<"Enter the number of resource types\n";
    cin>>resources;
    cout<<"Enter the total instances of each resource type\n";
    for(int i=0;i<resources;i++)
        cin>>available[i];
    cout<<"Enter the maximum demand of each process of each resource type\n";
    for(int i=0;i<processes;i++)
    {
        for(int j=0;j<resources;j++)
        {
            cin>>max[i][j];
        }
    }
    cout<<"Enter the resource instances allocated to each process\n";
    for(int i=0;i<processes;i++)
    {
        for(int j=0;j<resources;j++)
        {
            cin>>allocation[i][j];
        }
    }
}
void bank::calculate()
{
    for(int i=0;i<resources;i++)
    {
        for(int j=0;j<processes;j++)
        {
            sum[i]+=allocation[j][i];
        }
        available[i]=available[i]-sum[i];
    }
    for(int i=0;i<processes;i++)
    {
        for(int j=0;j<resources;j++)
            need[i][j]=max[i][j]-allocation[i][j];
    }
}
int bank::is_lessthan(int *a,int *b)
{
    int i=0;
    while((*(a+i)<=*(b+i))&&i<resources)
        i++;
    if(i==resources)
        return 1;
    else
        return 0;
}
void bank::plus(int *a,int *b)
{
    for(int i=0;i<resources;i++)
        *(a+i)=(*(a+i)+(*(b+i)));
}
int bank::safety_algorithm()
{
    int number=0;
    for(int i=0;i<resources;i++)
        work[i]=available[i];
    for(int i=0;i<processes;i++)
        finish[i]=false;
    while(number!=processes)
    {
        for(int i=0;i<processes;i++)
        {
            for(int j=0;j<resources;j++)
            {
                if(finish[i]==false&&is_lessthan(need[i], work))
                {
                    plus(work,allocation[i]);
                    finish[i]=true;
                }
            }
        }
        number++;
    }
    int i=0;
    while(finish[i]==true&&i<processes)
        i++;
    if(i==processes)
        return 1;
    else
        return 0;
}
int bank::resource_request()
{
    int number=0;
    cout<<"Enter the process number you want to request\n";
    cin>>number;
    cout<<"Enter the number of instances of each resource type\n";
    for(int i=0;i<resources;i++)
    {
        cin>>request[number][i];
    }
    if(is_lessthan(request[number],need[number]))
       {
           if(is_lessthan(request[number], available))
           {
               for(int i=0;i<resources;i++)
               {
                   available[i]-=request[number][i];
                   allocation[number][i]+=request[number][i];
                   need[number][i]-=request[number][i];
               }
               return safety_algorithm();
           }
       }
    return 0;
}
int main()
{
    bank b1;
    b1.input();
    b1.calculate();
    if(b1.resource_request())
        cout<<"the process has been proceeded\n";
    else
        cout<<"the process cannot be proceeded\n";
    return 0;
}
