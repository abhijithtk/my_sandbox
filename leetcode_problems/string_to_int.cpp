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
	string stripWhiteSpace(string &str) {
		int j = 0;
		for(int i = 0; i < str.size(); i++){
			if(str[i]==' ')
				continue;
			else
				str[j++] = str[i];
		}
		str[j] = '\0';
		return str.substr(0, j + 1);
	}

    int myAtoi(string str) {
		int res = 0;
		bool other = false;
		bool minus = false;
		str = stripWhiteSpace(str);
    	for(int i = 0; i < str.size(); i++) {
    		if(str[i] == '+'){
    			if(other)
    				return 0;
    			other = true;
    			continue;
    		}
    		else if (str[i] == '-'){
    			if(other)
    				return 0;
				other = true;
    			minus = true;
    			continue;
    		}
    		else if(str[i] >= '0' && str[i] <= '9'){
    			res = res*10 + (str[i] - '0');
    		}
    		else
    			break;
    	}
		return minus ? -1*res : res;
    }
};

int main()
{
    //vector<vector<char> > v{{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    Solution obj;
    //obj.solve(v);
    cout << obj.myAtoi("    -1") << endl;
}