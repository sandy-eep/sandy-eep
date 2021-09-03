#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
vector<int> twoSum(const vector<int>& A, int B) {
	unordered_map<int, int> m, n;
	vector<int> idx;
	int count = 1;
	for (int i = 0; i < A.size(); i++)
	{
		m.insert({ A[i],i });
		auto it = n.find(A[i]);
		if (it != n.end())
		{
			//count++;
			n[A[i]]++;//n.insert({ A[i],count });
		}
		else
		{
			n.insert({ A[i],1 });
		}
	}
	if (n[B - A[0]] == A.size() && B - A[0] == 0)
	{
		idx.push_back(1);
		idx.push_back(2);
		return idx;
	}
	for (auto it = m.begin(), k = n.begin(); it != m.end(), k != n.end(); it++, k++)
	{
		cout << "Key: " << k->first << "," << "value: " << k->second << "\n";
		//cout << "Key: " << it->first << "," << "value: " << it->second << "\n";
	}
	int ida = A.size(), idm = A.size();
	for (int i = 0; i < A.size(); i++)
	{
		int k = B - A[i]; //4 
		auto it = m.find(k);

		if (it != m.end())   //
		{
			if (m[k] != i) {
				//cout << "Here";
				if (m[k] < idm && i < m[k])
				{
					idm = m[k];
					ida = i;
				}
				//idm=(m[k])<idm? (m[k]):idm; //idm=12;
				//ida = i < ida ? i : ida;// ida=1;
				//return idx;
			}
		}
	}
	if (ida != A.size() + 1 && idm != A.size())
	{
		idx.push_back(ida + 1);
		idx.push_back(idm + 1);
	}
	return idx;
}
int main()
{
	vector<int> a = { 1,1,1 };

	vector<int> b = twoSum(a, 2);
	auto c = b.begin();
	while (c != b.end())
	{
		cout << *c << "\n";// << "Here in output now\n";
		c++;
	}
	return 0;
}

