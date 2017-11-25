#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>
#include <set>
#include <list>
#include <unordered_set>


using namespace std;


class Solution {
public:
	unordered_map<string, string> mem;
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.size() == 0)
            return 1;
        for(int i = 1; i <= s.size(); i++) {
            if(wordDict.find(s.substr(0, i)) != wordDict.end() && wordBreak(s.substr(i, s.size() - i), wordDict))
                return 1;
        }
        return 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> ss(wordDict.begin(), wordDict.end());
        //return wordBreak(s, ss);
        cout << wordBreak3(s, ss) << endl;
        return true;
    }
    bool wordBreak2(string s, unordered_set<string>& wordDict) {
    	std::vector<string> v;
    	bool *f = new bool[s.size() + 1];
    	f[0] = true;
    	for(int i = 1; i <= s.size(); i++) {
    		for(int j = 0; j < i; j++) {
    			cout << "i=" << i << ",j=" << j << " " <<  s.substr(j, i)  << endl;
    			if(f[j] && (wordDict.find(s.substr(j,i)) != wordDict.end())) {
    				f[i] = true;
    				v.push_back(s.substr(j,i));
    			}
    		}
    	}
    	for(auto &i : v) {
    		cout << i << endl;
    	}
    	return f[s.size()];
    }
	string wordBreak3(string s, unordered_set<string>& wordDict) {
		if(wordDict.find(s) != wordDict.end())
			return s;
		if(mem.find(s) != mem.end())
			return mem[s];
		for(int i = 1; i < s.size(); i++) {
			if(wordDict.find(s.substr(0, i)) != wordDict.end()){
				string prefix = s.substr(0, i);
				string suffix = s.substr(i, s.size());
				string ret = wordBreak3(suffix, wordDict);
				if(ret != "") {
					cout << "P=" << prefix << ".S=" << suffix << ",F" << s << endl;
					//mem.insert({s, prefix + " " + suffix});
					return prefix + " " + ret;
				}
			}
		}
		mem.insert({s, ""});
		return "";
	}
};

int main()
{
    vector<string> v{"leet","code","eet","mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    Solution obj;
    //obj.solve(v);
    cout << obj.wordBreak("ilikesammobilesungs", v) << endl;
}