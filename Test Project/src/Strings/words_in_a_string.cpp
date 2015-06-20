/*
 * words_in_a_string.cpp
 *
 *  Created on: Jun 14, 2015
 *      Author: Abhijith
 */
#include <iostream>
using namespace std;
int countWords(const char *s)
{
	int count = 0;
	bool st_space = false;
	while(*s)
	{
		if(*s != ' ')
			st_space = false;
		else if(st_space)
		{
			s++;
			continue;
		}
		st_space = true;
		count++;
		s++;
	}
	return count;
}

int main()
{
	const char *s = "there is only one me, me!";
	cout << s << endl;
	cout << countWords(s) << endl;
	return 0;
}




