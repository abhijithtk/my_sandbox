#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

typedef map<char,int> Map;
typedef queue<char> Queue;

char find(string str)
{
    Map m;
    Queue q;
    Map::iterator it;
    for(unsigned int i = 0; i < str.length(); i++)
    {
        cout << str[i] << endl;
        if((it = m.find(str[i])) == m.end())
        {
            m.insert(std::pair<char,int>(str[i],1));    
            q.push(str[i]);
        }
        else
        {
            it->second++;
        }
    }
    while(! q.empty())
    {
        char x = q.front();
        //cout << x << endl;
        if((it = m.find(x)) != m.end()  && it->second == 1)
            return x;
        q.pop();
    }
    return 0;
}

using namespace std;

int main()
{
    string str("abbacde");
    cout << "Find=" << find(str) << endl;
    return 0;
}
