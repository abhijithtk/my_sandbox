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
    // final solution. keep moving j until you find a duplicate. 
    // delete all elements until you reach that duplicate element. 
    // difference between j and i is the longest substring
     int lengthOfLongestSubstring1(string s) {
        set<char> ss;
        int ans = 0, i = 0, j = 0;
        while (i < s.size() && j < s.size()) {
            cout << s[j] << endl;
            // try to extend the range [i, j]
            if (ss.find(s[j]) == ss.end()){
                ss.insert(s[j++]);
                ans = max(ans, j - i);
            }
            else {
                ss.erase(s[i++]);
            }
        }
        return ans;
    }

	int lengthOfLongestSubstring1(string s) {
		map<char, int> m;
		int ans = 0;
		for (int i = 0, j = 0; j < s.size(); j++)
		{
			if(m.find(s[j]) != m.end()){
				i = max(i, m[s[j]]);
			}
			m[s[j]] = j + 1;
			ans = max(ans, j - i + 1 );
		}
		return ans;
	}
};

int main()
{
    string s("abcabcbb");
    Solution obj;
    //obj.solve(v);
    cout << obj.lengthOfLongestSubstring(s) << endl;
}
