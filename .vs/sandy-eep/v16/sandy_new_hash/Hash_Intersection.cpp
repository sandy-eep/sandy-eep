#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
vector<int> intersect(vector<int>& A, vector<int>& B) {
	unordered_map<int, int> m, n;
	unordered_set<int> s;

	vector<int> comn;
	for (int i = 0; i < A.size(); i++)
	{
		if (m.find(A[i]) != m.end())
		{
			m[A[i]]++;
		}
		else {
			m.insert({ A[i],1 });
		}
		
	}
	
	for (int i = 0; i < B.size(); i++)
	{
		if (n.find(B[i]) != n.end())
		{
			n[B[i]]++;
		}
		else {
			n.insert({ B[i],1 });
		}
		s.insert(B[i]);
	}
	for (int i = 0; i < B.size(); i++)
	{
		if (m.find(B[i]) != m.end())
		{
			if (m[B[i]] == n[B[i]] && m[B[i]] != 0&& n[B[i]] != 0)
			{
				comn.push_back(B[i]);
				m[B[i]]--;
				n[B[i]]--;
			}
			else
			{
				if (m[B[i]] < n[B[i]]&&m[B[i]]!=0)
				{
					comn.push_back(B[i]);
					m[B[i]]--;
				}
				else {
					if (n[B[i]] < m[B[i]] && n[B[i]] != 0)
					{
						comn.push_back(B[i]);
						n[B[i]]--;
					}
				}
			}
		}
	}
	return comn;
	}
	

int main()
{
	vector<int> a, b, c;
	a = { 1,2,2,1 };
	b = { 2,3,1,2};
	c = intersect(a, b);
	auto it = c.begin();
	while (it != c.end())
	{
		cout << " " << *it << " \n";
		it++;
	}
	return 0;
}
