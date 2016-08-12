#include <iostream>
#include <vector>

using namespace std;

class Finder {

public:
    int partition(vector<int>& num,int left,int right)
	{
    	int pivot = num[left];
        int i,j;
        i = left;
        j = right;
        while(i<j)
        {
        	while(i<j && num[j]<=pivot)
        	{
            	j--;
        	}
        	if(i<j)
        	{
            	num[i] = num[j];
            	i++;
        	}
        	while(i<j && num[i] > pivot)
        	{
            	i++;
        	}
       		if(i<j)
        	{
            	num[j] = num[i];
            	j--;
        	}
    	}
    	num[i] = pivot;
    	return i;
	}

	int print(vector<int> num)
	{
	    for(int i=0;i<num.size();i++)
        {
            cout<<num[i]<<" ";
        }
        cout<<endl;
	}

    void qsort(vector<int>& num,int left,int right,int K)
	{
    	if(left < right)
    	{
        	int pos = partition(num,left,right);
        	//print(num);
        	//cout<<endl<<pos<<"::"<<endl;
        	//std::cin.get();
            if(pos == K-1)
            {
                return;
            }
            else if(pos > K-1)
            {
            	qsort(num,left,pos-1,K);
            }
            else if(pos < K-1)
            {
        		qsort(num,pos+1,right,K);
            }
    	}
	}

    int findKth(vector<int> a, int n, int K) {
        // write code here
        qsort(a,0,n-1,K);
        //print(a);
        return a[K-1];

    }
};

int main()
{
    //vector<int> a = {6,2,9,8,3,5,7,25,45,4,10,13};
    vector<int> a = {1332802,1177178,1514891,871248,753214,123866,1615405,328656,1540395,968891,1884022,252932,1034406,1455178,821713,486232,860175,1896237,852300,566715,1285209,1845742,883142,259266,520911,1844960,218188,1528217,332380,261485,1111670,16920,1249664,1199799,1959818,1546744,1904944,51047,1176397,190970,48715,349690,673887,1648782,1010556,1165786,937247,986578,798663};
    Finder* finder = new Finder();
    //int kth = finder->findKth(a,12,8);
    int kth = finder->findKth(a,49,24);
    std::cout<<kth<<endl;
}
