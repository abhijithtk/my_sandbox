// CPP program to find all subsets by backtracking.
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
 
// In the array A at every step we have two
// choices for each element either  we can
// ignore the element or we can include the
// element in our subset
void subsetsUtil(vector<char>& A, vector<vector<char> >& res,
                 vector<char>& subset, int index)
{
    for (int i = index; i < A.size(); i++) {
 
        // include the A[i] in subset.
        subset.push_back(A[i]);
        res.push_back(subset);
        cout << index << " " << i << " ";
        for(auto c : subset )
            cout << c << setw(index) << " ";
        cout << endl;
 
        // move onto the next element.
        subsetsUtil(A, res, subset, i + 1);
 
        // exclude the A[i] from subset and triggers
        // backtracking.
        subset.pop_back();
    }
 
    return;
}
 
// below function returns the subsets of vector A.
vector<vector<char> > subsets(vector<char>& A)
{
    vector<char> subset;
    vector<vector<char> > res;
 
    // include the null element in the set.
    res.push_back(subset);
 
    // keeps track of current element in vector A;
    int index = 0;
    subsetsUtil(A, res, subset, index);
 
    return res;
}
 
// Driver Code.
int main()
{
    // find the subsets of below vector.
    vector<char> array = {'f','o','u','r' };
 
    // res will store all subsets.
    // O(2 ^ (number of elements inside array))
    // because at every step we have two choices
    // either include or ignore.
    vector<vector<char> > res = subsets(array);
 
    // Print result
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
 
    return 0;
}
