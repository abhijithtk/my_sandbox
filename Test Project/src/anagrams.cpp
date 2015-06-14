#include <iostream>

bool areAnagrams(const char* s1, const char* s2)
{
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    if(l1 != l2)
        return false;
    int h[256] = {0};

    while(*s1 && *s2)
    {

        h[(int)*s1]++;
        h[(int)*s2]--;
        s1++; s2++;
    }
    if(*s1 || *s2)
    {
        return false;
    }
    for(int i = 0; i < 256; i++)
    {
        if(h[i] >0 || h[i] < 0)
            return false;
    }
    return true;
}

int main()
{
	cout << areAnagrams("aab","aaa") << endl;
	return 0;
}
