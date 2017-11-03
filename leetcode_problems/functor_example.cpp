#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <functional>
#include <algorithm>


using namespace std;

class Functors {
public:
	bool operator()(int a, int b){
		return a < b;
	}
};

class abhi {
public:
	abhi() {}
	bool operator() (int i,int j) { return (i<j);}
};

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;


int main()
{
	abhi a;
    vector<int> v{5,6,9,2,1,5,3,8,3,2,9,4};
    sort(v.begin(), v.end(), myobject);
    for(auto i: v)
	    cout << i << endl;
}