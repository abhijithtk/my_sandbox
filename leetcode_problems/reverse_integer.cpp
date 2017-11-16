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
    int reverse(int x) {
    	bool sign = false;
    	if(x < 0){
    		sign = true;
    		x = x*-1;
    	}
    	int res = 0;
    	while(x > 0){
    		res = ((res*10) + (x%10));
    		x = x/10;
    	}
    	if(res < INT_MIN || res > INT_MAX)
    		return 0;
    	return sign ? -1 *res : res;
    }
};

int main()
{
    //vector<vector<char> > v{{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    Solution obj;
    //obj.solve(v);
    cout << obj.reverse(-123) << endl;
}