#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef pair<int,int> Job;

bool comparision(Job job1,Job job2)
{
    if(job1.first < job2.first)
    {
        return true;
    }else if(job1.first == job2.first)
    {
        if(job1.second<=job2.second)
        {
            return true;
        }else{
            return false;
        }
    }else
    {
        return false;
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        int sumTime = 0;
        vector<Job> vec;
        for(int i=0;i<n;i++)
        {
            int startTime = 0;
            int cpuTime = 0;
            cin>>startTime>>cpuTime;
            Job job(startTime,cpuTime);
            vec.push_back(job);
        }
        sort(vec.begin(),vec.end(),comparision);
        int time = 0;
        for(int i=0;i<vec.size();i++)
        {
            Job job = vec[i];
            if(time < job.first)//Job还没有提交
            {
                time = job.first;
                //没有等待时间
                time = job.first + job.second;
            }else
            {
                sumTime += time - job.first;
                time = time + job.second;
            }
        }
        cout<<setprecision(4)<<sumTime/float(n)<<endl;
    }
    return 0;
}
