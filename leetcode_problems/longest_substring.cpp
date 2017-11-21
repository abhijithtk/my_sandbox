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