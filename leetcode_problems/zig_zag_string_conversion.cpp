#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    	if (numRows == 1)
    		return s;
		std::vector<string> arr(numRows);
 		bool down = true;
 		int i = 0;
 		int row = 0;
 		while(i < s.length()) {
 			arr[row].push_back(s[i++]);
 			if(down)
 				row++;
 			else
 				row--;
 			if(row == (numRows - 1) )
 				down = false;
 			if (row == 0)
 				down = true;
 		}
 		string ret;
 		for(int i =0; i < numRows; i++){
 			//cout << arr[i] << endl;
 			ret += arr[i];
 		}
 		return ret;
    }
};


int main()
{
    Solution obj;
    cout << obj.convert("PAYPALISHIRING", 3) << endl;
}