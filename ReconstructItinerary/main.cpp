#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    void print(string key,multiset<string> mulset)
    {
        cout<<key<<"\t";
        for(string str : mulset)
        {
            cout<<str<<" ";
        }
        cout<<endl;
    }

    //DFS 深度遍历获取路径
    void visit(map<string,multiset<string> >& itinerary,string airport,vector<string>& result)
    {
        while(itinerary[airport].size() >0 )
        {
            string nextAirport = *itinerary[airport].begin();
            itinerary[airport].erase(itinerary[airport].begin());
            visit(itinerary,nextAirport,result);
        }
        result.push_back(airport);
    }

    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        vector<string> result;
        map<string,multiset<string> > itinerary;
        for(pair<string, string> ticket:tickets)//添加到一棵树中
        {
            itinerary[ticket.first].insert(ticket.second);
            //print(ticket.first,itinerary[ticket.first]);
        }
        visit(itinerary,"JFK",result);
        return vector<string>(result.rbegin(),result.rend());
    }
};

int main()
{
    Solution* s = new Solution();
    vector<pair<string, string> > tickets;
    tickets.push_back(make_pair("JFK","KUL"));
    tickets.push_back(make_pair("JFK","NRT"));
    tickets.push_back(make_pair("NRT","JFK"));
    vector<string> result = s->findItinerary(tickets);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }
    delete s;
    return 0;
}
