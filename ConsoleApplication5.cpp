#include <iostream>
#include <string> 
#include <map>
using namespace std;
#include "pch.h"

struct Info
{
	string User;
	string Module;
};

string ReplaceAll(string str, string keyword, string value)
{
	while (true)
	{
		int pos = str.find(keyword);
		if (pos == -1)
		{
			return str;
		}
		str = str.replace(pos, keyword.length(), value);
	}
	return str;
}

// Passing on each dictionary key, if the key is in the format string, we replace it
string Make(const string& format,		// {Date} {Module} {User} 
	const map<string, string>& values   // {User} : John
)
{
	string str = format;
	for (auto it = values.begin(); it != values.end(); it++)
	{
		str = ReplaceAll(str, it->first, it->second);
	}
	return str;
}

string ToString(const string& format,
	const Info& info)
{
	map<string, string> values;
	values["{User}"] = info.User;
	values["{Module}"] = info.Module;
	values["{endline}"] = "\n";
	return Make(format, values);
}

int main()
{
	string format = "user = {User}, module = {Module}, {User} {endline}";
	Info t;
	t.Module = "black oil";
	t.User = "anna.cheskis";

	string str = ToString(format, t);
	cout << str;
	cin >> str;

	return 0;
}