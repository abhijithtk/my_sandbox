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
    // final accepted
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        //s.insert(endWord);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()) {
            pair<string, int> p = q.front();
            string word = p.first;
            cout << word << endl;
            q.pop();
            if(word == endWord)
                return p.second;
            for(int i = 0; i < word.size(); i++){
                for(int j = 0; j < 26; j++) {
                    char temp = word[i];
                    word[i] = 'a' + j;
                    if(s.find(word) != s.end()) {
                        q.push({word, p.second + 1});
                        s.erase(word);
                    }
                    word[i] = temp;
                }

            }
        }
        return 0;
    }
    int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.insert(endWord);

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
        	pair<string, int> p = q.front();
        	string word = p.first;
        	cout << "OUTHER:" << word << endl;
        	q.pop();
            if(word == endWord){
                return p.second;
            }

            for(int i=0; i<word.size(); i++){
                for(char c='a'; c<='z'; c++){
                    char temp = word[i];
                    if(word[i]!=c){
                        word[i]=c;
                    }
                    string newWord = word;
                    if(s.find(newWord) != s.end()){
                		cout << newWord << endl;
                        q.push({newWord, p.second +1});
                        s.erase(newWord);
                    }

                    word[i]=temp;
                }
            }
        }
        return 0;
    }
};

int main()
{
    vector<string> v{"hnt","hot","dot","dog","lot","log","cog"};
    Solution obj;
    //obj.solve(v);
    cout << obj.ladderLength("hit", "cog", v) << endl;
}