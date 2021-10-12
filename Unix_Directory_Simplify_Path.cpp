#include<iostream>
#include<vector>
#include<string>
using namespace std;
string solve(string A) {
	vector<string> v;
	//string str;
	for (int i = 0; i < A.length(); i++)
	{
		string dir = "";
		while (i < A.length() && A[i] != '/')
		{
			dir += A[i];
			i++;
		}
		if (dir == "..")
		{
			if (!v.empty())
			{
				v.pop_back();
			}
		}
		else if (dir == "." || dir == "")
		{
			int a = 0;
		}
		else {
			v.push_back(dir);
		}
	}
	string str = "";
	for (auto i : v)
	{
		str += "/" + i;
	}
	if (str == "")
	{
		return "/";
	}
	return str;
}

int main()
{
	string str = "/a/./b/../../c/";
	string str2 = solve(str);
	cout << str2;
}