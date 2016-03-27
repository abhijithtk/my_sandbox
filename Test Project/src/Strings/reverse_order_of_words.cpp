#include <iostream>
using namespace std;

void reverse(string &str, int st, int end)
{
    while(st < end)
    {
        char tmp = str[st];
        str[st] = str[end];
        str[end] = tmp;
        st++; end--;
    }
}

// To execute C++, please define "int main()"
void printReverse(string str)
{
    cout << str << endl;
    reverse(str,0,str.length() -1);
    cout << str << endl;
    unsigned int prev = 0;
    for( unsigned int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ')
        {
            reverse(str,prev,i - 1);
            prev = i + 1;
        }
    }
    cout << str << endl;
}

int main() {
  string words =  "ab baab aba ";
  printReverse(words);
  return 0;
}
