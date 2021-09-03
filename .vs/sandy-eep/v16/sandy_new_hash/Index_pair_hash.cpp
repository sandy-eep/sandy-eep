#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
vector<int> twoSum(const vector<int>& A, int B) {
	unordered_map<int, vector<int>>  m;
	vector<int> idx;
	for (int i = 0; i < A.size(); i++)
	{
		m[A[i]].push_back(i);
	}
	int idm = A.size() + 1, ida = A.size() + 1;
	for (int i = 0; i < A.size(); i++)
	{
		int k = B - A[i];
		if (m.find(k) != m.end())
		{
			for (int j = 0; j < m[k].size(); j++)
			{
				if (m[k][j] < idm && i < m[k][j])
				{
					idm = m[k][j];
					ida = i;
				}
			}
		}
	}
	if (idm != A.size() + 1 && ida != A.size() + 1)
	{
		idx.push_back(ida+1);
		idx.push_back(idm+1);
		return idx;
	}
	else {
		return idx;
	}
}
int main()
{
	vector<int> a = { 2, 5, 0, -6, 7, -4, 0, 4, 3, 0, -2, 0, 9, -3, -9, -3, 9, 3, 2 };

	vector<int> b = twoSum(a, 0);
	auto c = b.begin();
	while (c != b.end())
	{
		cout << *c << "\n";// << "Here in output now\n";
		c++;
	}
	return 0;
}

