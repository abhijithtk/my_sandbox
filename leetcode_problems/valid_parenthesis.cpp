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
	char getMatching(char s){
		if(s == '(')
			return ')';
		else if(s == ')')
			return '(';
		else if(s == '{')
			return '}';
		if(s == '}')
			return '{';
		else if(s == '[')
			return ']';
		else if (s == ']')
			return '[';
		return '\0';
	}

    bool isValid1(string s) {
    	map<char, int> m;
    	char prev = '\0';
		for(int i = 0; i < s.size(); i++) {
			cout << s[i] << endl;
			if (prev != '\0' && prev != getMatching(s[i]))
				return false;
			if(s[i] == '{' || s[i] == '(' || s[i] == '[')
				m[s[i]]++;
			else
				m[getMatching(s[i])]--;
			if(m[getMatching(s[i])] < 0)
				return false;
			prev = s[i];
		}
		for(auto &i : m){
			if(i.second > 0)
				return false;
		}
		return true;
    }
    bool isValid(string s){
    	stack<char> st;
    	for(int i = 0; i < s.size(); i++) {
			if(s[i] == '{' || s[i] == '(' || s[i] == '['){
				st.push(s[i]);
			}
			else if (!st.empty() && s[i] == '}' && st.top() == '{') {
				st.pop();
			}
			else if (!st.empty() && s[i] == ']' && st.top() == '[') {
				st.pop();
			}
			else if (!st.empty() && s[i] == ')' && st.top() == '(') {
				st.pop();
			}
			else
				return false;
    	}
		if(st.empty())
			return true;
		return false;
    }
};

int main()
{
    //vector<vector<char> > v{{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    Solution obj;
    //obj.solve(v);
    cout << obj.isValid("]") << endl;
}