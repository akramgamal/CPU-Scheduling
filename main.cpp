#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void FirstFit(int a[],int b[],int s1,int s2)
{
    int x[s1];
    for(int i=0;i<s1;i++){
     x[i]=a[i];
    }
    bool t[s1]= {};
    for(int i=0; i<s2; i++)
    {
        for(int j=0; j<s1; j++)
        {
            if(b[i]<=a[j])
            {
                cout<<"partition "<<j+1<<"("<<x[j]<<"KB) ="<<"process "<<i+1<<"("<<b[i]<<"KB)"<<",Rest of partition "<<j+1<<" ="<<a[j]-b[i]<<endl;
                a[j]=a[j]-b[i];
                t[j]=true;
                break;
            }
        }
    }
    for(int i=0; i<s1; i++)
    {
        if(!t[i])
            cout<<"partition "<<i+1<<"("<<a[i]<<"KB) = Empty"<<endl;
    }
}
void BestFit(int a[],int b[],int s1,int s2)
{
    int x[s1];
    for(int i=0;i<s1;i++){
     x[i]=a[i];
    }
    bool t[s1]= {};
    vector<pair<int,int>> v;
    for(int i=0; i<s2; i++)
    {
        for(int j=0; j<s1; j++)
        {
            if(b[i]<=a[j])
            {
                v.push_back(make_pair(a[j],j));
            }
        }
        if(v.size()==0){
            continue;
        }else{
        int m=v[0].first,m2=v[0].second;
        for(int k=1; k<v.size(); k++)
        {
            if(v[k].first<m)
            {
                m=v[k].first;
                m2=v[k].second;
            }
        }
        cout<<"partition "<<m2+1<<"("<<x[m2]<<"KB) = process "<<i+1<<"("<<b[i]<<"KB),Rest of partition "<<m2+1<<" ="<<m-b[i]<<endl;
        a[m2]=a[m2]-b[i];
        t[m2]=true;
        }
        v.clear();

    }
    for(int i=0; i<s1; i++)
    {
        if(!t[i])
        {
            cout<<"partition "<<i+1<<"("<<a[i]<<"KB) = Empty"<<endl;
        }
    }
}


void WorstFit(int a[],int b[],int s1,int s2)
{
    bool t[s1]= {};
    int x[s1];
    for(int i=0;i<s1;i++){
     x[i]=a[i];
    }

    vector<pair<int,int>> v;
    for(int i=0; i<s2; i++)
    {
        for(int j=0; j<s1; j++)
        {
            if(b[i]<=a[j])
            {
                v.push_back(make_pair(a[j],j));
            }
        }
        if(v.size()==0){
            continue;
        }else{
        int m=v[0].first,m2=v[0].second;
        for(int k=1; k<v.size(); k++)
        {
            if(v[k].first>m)
            {
                m=v[k].first;
                m2=v[k].second;
            }
        }
        cout<<"partition "<<m2+1<<"("<<x[m2]<<"KB) = process "<<i+1<<"("<<b[i]<<"KB),Rest of partition "<<m2+1<<" ="<<m-b[i]<<endl;
        a[m2]=a[m2]-b[i];
        t[m2]=true;
        }
        v.clear();
    }
    for(int i=0; i<s1; i++)
    {
        if(!t[i])
        {
            cout<<"partition "<<i+1<<"("<<a[i]<<"KB) = Empty"<<endl;
        }
    }
}
int main()
{
    int n1,n2,x;
    cout<<"Enter number of partition :"<<endl;
    cin>>n1;
    int partitions[n1];
    for(int i=0; i<n1; i++)
    {
        cout<<"Partition "<<i+1<<" size :";
        cin>>partitions[i];
    }
    cout<<"Enter number of processes :"<<endl;
    cin>>n2;
    int process[n2];
    for(int i=0; i<n2; i++)
    {
        cout<<"Process "<<i+1<<" size :";
        cin>>process[i];
    }
    cout<<"select the policy"<<endl;
    cin>>x;
    if(x==1)
        FirstFit(partitions,process,n1,n2);
    else if(x==2)
        BestFit(partitions,process,n1,n2);
    else if(x==3)
        WorstFit(partitions,process,n1,n2);
    return 0;
}
