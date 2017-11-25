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
	vector<string> keys{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> letterCombinations(string digits) {
    	std::vector<string> res;
    	return combination("", digits, 0, res);
    }
    std::vector<string> combination(string output, string digits, int offset, std::vector<string> &res) {
    	if(output.size() >= digits.size()) {
    		res.push_back(output);
    		cout << output << endl;
    		return res;
    	}
    	string letters = keys[digits[offset] - '0'];
    	for (int i = 0; i < letters.size(); ++i)
    	{
    		combination(output + letters[i], digits, offset + 1, res );
    	}
    	return res;
    }
};

int main()
{
    //vector<vector<char> > v{{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    Solution obj;
    //obj.solve(v);
    //cout << obj.solve(v) << endl;
    for(auto i : obj.letterCombinations("8646439947"))
    	cout << i << endl;
}