#include<iostream>
#include<math.h>
#include<string>
#define prime 3
using namespace std;

int calculateHash(int old_hash, int m, int old_char, int new_char)
{
	int i, new_hash;
	new_hash = old_hash - old_char;
	new_hash /= prime;
	new_hash += pow(prime, m-1);
	return new_hash;
}

int calculateHash(string str)
{
	int hash = 0, i;
	for(i = 0; i<str.length(); ++i)
	{
		hash += pow((int)str[i], i);
	}
	cout<<hash<<"\n";
	return hash;
}

int rabinKarp(string text, string pattern)
{
	int p_hash = calculateHash(pattern);
	int m = pattern.length();
	int sub_text_hash = calculateHash(text.substr(0, m));
	
	for(int i = 0; i <= (text.length() - m); ++i)
	{
		if(sub_text_hash == p_hash)
		{
			if(!pattern.compare(text.substr(i, m)) )
				return i;
		}
		else if(i != (text.length() - m))
		{
			sub_text_hash = calculateHash(sub_text_hash, m, text[i*m], text[(i*m)+m-1]);
		}
		else
		return -1;
	}
	return -1;
}

int main()
{
	int result;
	string text, pattern;
	cin>>text>>pattern;
	result = rabinKarp(text, pattern);
	if(result == -1)
		cout<<"no match case";
	else
		cout<<"first index from text matched with pattern is @"<<result+1;
	return 0;		
}
