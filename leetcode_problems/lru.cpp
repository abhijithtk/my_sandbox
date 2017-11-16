#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>
#include <set>
#include <list>


using namespace std;


class LRUCache {
    int m_capacity;
    unordered_map<int,pair<int,list<int>::iterator>> m;
    list<int> l;
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    list<int>::iterator fix_lru(int key, list<int>::iterator lit) {
        l.erase(lit);
        l.push_front(key);
        return l.begin();
    }
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        auto p = m[key];
        p.second = fix_lru(key, p.second);
        m[key] = p;
        return p.first;
    }

    void put(int key, int value) {
    	if(m.find(key) != m.end()){
	        auto p = m[key];
	        p.second = fix_lru(key, p.second);
	        m[key] = p;
			m[key] = {value, l.begin()};
			return;
    	}
        if(m.size() >= m_capacity){
            int remove = l.back();
            l.pop_back();
            m.erase(remove);
        }
        l.push_front(key);
        m[key] = {value, l.begin()};
    }
};

int main()
{
    LRUCache *cache = new LRUCache(1);

    cache->put(2, 1);
    //cache->put(2, 2);
    cout << cache->get(2) << endl;
    cache->put(3, 2);    // evicts key 2
    cout << cache->get(2) << endl;       // returns -1 (not found)
    //cache->put(4, 4);    // evicts key 1
    //cout << cache->get(1) << endl;       // returns -1 (not found)
    cout << cache->get(3) << endl;       // returns 3
    //cout << cache->get(4) << endl;

    //vector<vector<char> > v{{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    //obj.solve(v);
    //cout << obj.solve(v) << endl;
}