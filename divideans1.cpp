
//----------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
//----------------------------------------------------------------------
bool ans_check(set<int> data,int ans,int num);
int find_ans(set<int> data,int left,int right,int num);
//----------------------------------------------------------------------
int main()
{
    set<int> data;
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
        int tmp;cin>>tmp;
        data.insert(tmp);
    }
    set<int>::iterator data_it;
    data_it=data.begin();
    int min=*data_it;
    data_it=data.end();data_it--;
    int max=*data_it;
    int derta=max-min;
    int ans;ans=find_ans(data,0,derta,b);
    cout<<ans<<endl;
    return 0;
}
//----------------------------------------------------------------------
bool ans_check(set<int> data,int ans,int num)
{
    set<int>::iterator data_it;
    data_it=data.begin();
    int next_num_min;
    next_num_min=*data_it;
    do
    {
        if((*data_it)>=next_num_min)
        {
            num--;
            next_num_min=(*data_it)+ans;
        }
        if(num==0) return true;
        data_it++;
    }while(data_it!=data.end());
    return false;
}
//----------------------------------------------------------------------
int find_ans(set<int> data,int left,int right,int num)
{
    if(left>=right) return left;
    int mid;mid=ceil((left+right)/2.0);
    if(ans_check(data,mid,num))
        return find_ans(data,mid,right,num);
    else
        return find_ans(data,left,mid-1,num);    
}
//----------------------------------------------------------------------
