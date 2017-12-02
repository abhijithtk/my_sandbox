#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>
#include <set>


using namespace std;


class Solution {
public:
	string thotha_sort(string s){
		char dict[26] = {0};
		for(auto &i: s){
			dict[i - 'a']++;
		}
		string ret;
		for(int i = 0; i < 26; i++){
			while(dict[i]){
				ret.push_back('a' + i);
				dict[i]--;
			}
		}
		return ret;
	}
	bool isAnagram(string s, string t) {
		int dict[26] = {0};
		if(s.size() != t.size())
			return false;
		for(int i =0; i < s.size(); i++) {
			dict[s[i] - 'a']++;
			dict[t[i] - 'a']--;
		}
		for(int i = 0; i < 26; i++) {
			if(dict[i])
				return false;
		}
		return true;
	}

    bool isAnagram(string s, string t) {
    	return thotha_sort(s) == thotha_sort(t);
    }
};
int main()
{
    //vector<vector<char> > v{{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    Solution obj;
    //obj.solve(v);
    cout << obj.isAnagram("abc","cba") << endl;
}