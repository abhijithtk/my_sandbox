#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        pair<int, int> maxprofit(0, -1);
        pair<int, int> minprice(INT_MAX, -1);
        for(int i = 0; i < prices.size(); ++i ) {
            if(prices[i] < minprice.first) {
                minprice.first = prices[i];
                minprice.second = i;
            }
            else if (prices[i] - minprice.first > maxprofit.first) {
                maxprofit.first = prices[i] - minprice.first;
                maxprofit.second = i;
            }
        }
        cout << "minprofit index=" << minprice.second << endl;
        cout << "maxprofit index=" << maxprofit.second << endl;
        return maxprofit.first;
    }
};

int main()
{
    vector<int> v{7,1,5,4, 3, 6};
    Solution obj;
    cout << obj.maxProfit(v) << endl;
}