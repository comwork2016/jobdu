#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bool isPrime(int x)
{
	for(int i=2;i*i<=x;i++) // <=
	{
		if(x % i == 0)
			return false;
	}
	return true;
}

int getPrimePair(const vector<int>& primes,const bitset<1000>& primeBit,int sum)
{
    int count = 0;
    for(int i=0;i<primes.size();i++)
    {
        int p = primes[i];
        if(p <= sum - p && primeBit[sum - p] == 1)
        {
            count++;
            cout<<sum<<" = "<<p<<" + "<<sum-p<<endl;
        }
        if(p > sum)
        {
            break;
        }
    }
    return count;
}

int main()
{
    bitset<1000> primeBit;
    vector<int> primes;
    for(int i=2;i<1000;i++)
    {
        if(isPrime(i))
        {
            primeBit[i] = 1;
            primes.push_back(i);
        }
    }
    int sum;
    while(cin>>sum)
    {
        cout<<getPrimePair(primes,primeBit,sum)<<endl;
    };
    return 0;
}
