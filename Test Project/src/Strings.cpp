
#include <iostream>
#include <sstream>
using namespace std;

// '33777721' -> '23471211'

void removeDup(string ip)
{
    unsigned int i = 0;
    std::string tmp;
    char prev = '\0';
    while(i < ip.size())
    {
        if(prev != ip[i])
        {
            prev = ip[i];
            tmp.push_back(ip[i]);
        }
      i++;
    }
    tmp.push_back(ip[i]);
    cout << tmp << endl;
}

void reverse(string ip)
{
    unsigned int  len = ip.size(); 
    unsigned int i  = 0;
    unsigned int j = len - 1;
    if(i == j)
      return;
  
    while(i < j)
    {
        char t = ip[j];
        ip[j] = ip[i];
        ip[i] = t;
        i++;
        j--;
    }
    ip.push_back('\0');
    cout << ip << endl;
}

bool palindrome(string ip)
{
    unsigned int  len = ip.size(); 
    unsigned int i  = 0;
    unsigned int j = len - 1;
    if(i == j)
      return true;
  
    while(i < j)
    {
        if(ip[i] != ip[j])
          return false;
        i++;
        j--;
    }
    return true;
}

// To execute C++, please define "int main()"

int main() {
  //for (int i = 0; i < 5; i++) {
  //  cout << "Hello, World\n";
  // }
  removeDup("33777721");
  reverse("aaabaabcdab");
  cout << palindrome("aaabaabaaa") << endl;
  return 0;
}
