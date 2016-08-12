#pragma warning(disable:4786)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum PokerType
{
	One,Two,Three,Junko,Boom,Joker
};

typedef pair<PokerType,int> PokerSize;

/**
·Ö¸ô×Ö·û´®
*/
vector<std::string>  splitString(const string& str_Source,const string& str_pattern=" ")
{
    std::vector<std::string> result;
    std::string str = str_Source + str_pattern;
    int strsize=str.size();
    int patternSize = str_pattern.size();
    std::string::size_type pos;
    for(int i=0; i<strsize; i++)
    {
        pos =str.find(str_pattern,i);
        if(pos!=std::string::npos && pos<strsize)
        {
            std::string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+patternSize-1;
        }
    }
    return result;
}

int getPokerNumber(string poker)
{
	int number = 0;
	if(poker == "10")
	{
		number = 10;
	}else if(poker == "J")
	{
		number = 11;
	}else if(poker == "Q")
	{
		number = 12;
	}else if(poker == "K")
	{
		number = 13;
	}else if(poker == "A")
	{
		number = 14;
	}else if(poker == "2")
	{
		number = 15;
	}else if(poker == "joker")
	{
		number = 16;
	}else if(poker =="JOKER")
	{
		number = 17;
	}else
	{
		number = poker[0] - '0';
	}
	return number;
}

PokerSize getPokerSize(string poker)
{
	vector<string> vec_pokers = splitString(poker);
	int size = vec_pokers.size();
	PokerType pt;
	int number = getPokerNumber(vec_pokers[0]);
	switch(size)
	{
	case 1:
		pt = (PokerType)One;
		break;
	case 2:
		if(number == 16 || number ==17)//joker
		{
			pt = (PokerType)Joker;
		}
		else
		{
			pt = (PokerType)Two;
		}
		break;
	case 3:
		pt = (PokerType)Three;
		break;
	case 4:
		pt = (PokerType)Boom;
		break;
	default:
		pt = (PokerType)Junko;
		break;
	}
	PokerSize ps(pt,number);
	return ps;
}

string getBiggerPoker(string p1,string p2)
{
	PokerSize ps1 = getPokerSize(p1);
	PokerSize ps2 = getPokerSize(p2);
	if(ps1.first == (PokerType)Joker)
	{
		return p1;
	}
	else if(ps2.first == (PokerType)Joker)
	{
		return p2;
	}
	else if(ps1.first == ps2.first)
	{
		if(ps1.second > ps2.second)
		{
			return p1;
		}else
		{
			return p2;
		}
	}
	else if(ps1.first == (PokerType)Boom)
	{
		return p1;
	}
	else if(ps2.first == (PokerType)Boom)
	{
		return p2;
	}
	return "ERROR";
}

int main()
{
	string poker;
	while(getline(cin,poker))
	{
		string p1;
		string p2;
		size_t st_sep = poker.find('-');
		p1 = poker.substr(0,st_sep);
		p2 = poker.substr(st_sep+1);
		cout<<getBiggerPoker(p1,p2)<<endl;
	}
	return 0;
}