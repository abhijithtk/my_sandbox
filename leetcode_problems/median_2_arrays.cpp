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
	double getMedian(int v[], int n) {
		if(n%2 == 0)
			return (v[n/2 - 1] + v[n/2])/2;
		return v[n/2];
	}

	double getMedian(int nums1[], int nums2[], int n) {
		if(n <= 0)
			return -1;
		if(n == 1)
			return (nums1[0] + nums2[0])/2;
		if(n == 2)
			return (max(nums1[0], nums2[0]) + min(nums1[1],nums2[1]))/2;
		int m1 = getMedian(nums1, n);
		int m2 = getMedian(nums2, n);
		if(m1 == m2)
			return m1;
		if(m1 < m2){
			if(n % 2 == 0)
				return getMedian(nums1 + n/2 - 1, nums2, n - n/2 + 1);
			return getMedian(nums1 + n/2, nums2, n - n/2);
		}
		if(n %2 == 0)
			return getMedian(nums1, nums2 + n/2 - 1, n - n/2 + 1);
		return getMedian(nums1, nums2, n - n/2);
	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int *arr1 =  new int[nums1.size()];
    	int *arr2 =  new int[nums2.size()];
    	for(int i = 0; i < nums1.size(); i++)
    		arr1[i] = nums1[i];

    	for(int i = 0; i < nums2.size(); i++)
    		arr2[i] = nums2[i];

    	return getMedian(arr1, arr2, nums1.size());
    }
};

int main()
{
    vector<int> v1{1, 2, 3, 6};
    std::vector<int> v2{4, 6, 8, 10};
    Solution obj;
    //obj.solve(v);
    cout << obj.findMedianSortedArrays(v1, v2) << endl;
}