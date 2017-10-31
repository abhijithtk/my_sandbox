#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    int thirdMax2(vector<int>& nums) {
        set<int> s;
        for(auto i: nums){
            s.insert(i);
            if(s.size() > 3){
                s.erase(s.begin());
            }
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }

    int thirdMax(vector<int>& nums) {
        priority_queue<int, std::vector<int>, less<int>> pq;

        unordered_map<int, int> m;
        for(auto &i : nums) {
            m[i]++;
        }
        for(auto &i : m) {
            pq.push(i.first);
        }
        int ret;
        int k = 3;
        int max = INT_MIN;
        while(k > 0 && !pq.empty()){
            ret = pq.top();
            max = ret > max ? ret : max;
            cout << ret << endl;
            pq.pop();
            k--;
        }
        if(k == 0)
            return ret;
        return max;
    }
};

int main()
{
	int k =3;
    vector<int> v{2, 2,0, 1};
    Solution obj;
    cout << obj.thirdMax(v) << endl;
}