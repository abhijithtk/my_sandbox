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
#include <algorithm>


using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    	if(s == "")
    		return true;
    	int i = 0;
    	int j = s.size() - 1;
    	transform(s.begin(), s.end(), s.begin(), ::tolower);
    	while(i < j) {
    		if((s[i] < '0' || s[i] > '9') && (s[i] < 'a' || s[i] > 'z')) {
    			i++;
    			continue;
    		}
    		else if((s[j] < '0' || s[j] > '9') && (s[j] < 'a' || s[j] > 'z')) {
    			j--;
    			continue;
    		}
    		else if (s[i] != s[j])
    			return false;
    		else {
    			i++; j--;
    		}
    	}
    	return true;
    }
};

int main()
{
    //vector<vector<char> > v{{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    Solution obj;
    //obj.solve(v);
    cout << obj.isPalindrome("0P") << endl;
}