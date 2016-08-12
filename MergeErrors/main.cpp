#pragma warning(disable:4786)
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<string,int> Err;

struct ErrMerge
{
	Err err;
	int count;
	ErrMerge(Err err,int count):err(err),count(count){}
};

bool comparison(ErrMerge em1,ErrMerge em2)
{
	return em1.count>em2.count;
}

int main()
{
	string str;
	int line;
	vector<ErrMerge> vec_ErrMerge;
	map<Err,int> map_ErrIndex;
	while(cin>>str>>line)
	{
		size_t n_Sep = str.find_last_of('\\');
		if(n_Sep != string::npos)
		{
			str = str.substr(n_Sep+1);
		}
		Err err(str,line);
		//ºÏ²¢
		if(map_ErrIndex.find(err) == map_ErrIndex.end())
		{
			ErrMerge em(err,1);
			int size = vec_ErrMerge.size();
			vec_ErrMerge.push_back(em);
			map_ErrIndex[err] = size;
		}else
		{
			int index = map_ErrIndex[err];
			ErrMerge oem = vec_ErrMerge[index];
			oem.count += 1;
			vec_ErrMerge[index] = oem;
		}
	}
	sort(vec_ErrMerge.begin(),vec_ErrMerge.end(),comparison);
	int i=0;
	for(i=0;i<vec_ErrMerge.size() && i<8;i++)
	{
		ErrMerge em = vec_ErrMerge[i];
		string str = em.err.first;
		if(str.length()>16)
		{
			str = str.substr(str.length()-16);
		}
		cout<<str<<" "<<em.err.second<<" "<<em.count<<endl;
	}
	return 0;
}