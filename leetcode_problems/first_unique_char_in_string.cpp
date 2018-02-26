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
// This is for a stream of chars
void findFirstNonRepeating()
{
    // inDLL[x] contains pointer to a DLL node if x is present 
    // in DLL. If x is not present, then inDLL[x] is NULL
    struct node *inDLL[MAX_CHAR];
 
    // repeated[x] is true if x is repeated two or more times.
    // If x is not seen so far or x is seen only once. then 
    // repeated[x] is false
    bool repeated[MAX_CHAR];
 
    // Initialize the above two arrays
    struct node *head = NULL, *tail = NULL;
    for (int i = 0; i < MAX_CHAR; i++)
    {
        inDLL[i] = NULL;
        repeated[i] = false;
    }
 
    // Let us consider following stream and see the process
    char stream[] = "geeksforgeeksandgeeksquizfor";
    for (int i = 0; stream[i]; i++)
    {
        char x = stream[i];
        cout << "Reading " << x << " from stream n";
 
        // We process this character only if it has not occurred
        // or occurred only once. repeated[x] is true if x is 
        // repeated twice or more.s
        if (!repeated[x])
        {
            // If the character is not in DLL, then add this at 
            // the end of DLL.
            if (inDLL[x] == NULL)
            {
                appendNode(&head, &tail, stream[i]);
                inDLL[x] = tail;
            }
            else // Otherwise remove this character from DLL
            {
                removeNode(&head, &tail, inDLL[x]);
                inDLL[x] = NULL;
                repeated[x] = true; // Also mark it as repeated
            }
        }
 
        // Print the current first non-repeating character from
        // stream
        if (head != NULL)
            cout << "First non-repeating character so far is "
                 << head->a << endl;
    }
}

    int firstUniqChar(string s) {
        if(s.empty())
            return -1;
        unordered_map<char, pair<int, int>> countMap;
        for(int i = 0; i < s.size(); i++) {
        	if(countMap.find(s[i]) == countMap.end()) {
        		countMap.insert({s[i], {i, 1}});
        	}
        	else {
        		countMap[s[i]].second++;
        	}
        }
        int min = INT_MAX;
        for(auto o : countMap) {
        	if(o.second.second == 1)
        		min = std::min(min, o.second.first);
        }
        return min == INT_MAX? -1 : min;
    }
};

int main()
{
    string s("loveleetcode");
    Solution obj;
    //obj.solve(v);
    cout << obj.firstUniqChar(s) << endl;
}
