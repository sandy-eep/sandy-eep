#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int solve(vector<int>& A)
{
	vector<int> Lmax, Rmax;
	int n = A.size();
	Lmax.resize(A.size());
	Rmax.resize(A.size());
	
	int lmax = A[0];
	int rmax = A[n - 1];
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] >= lmax)
		{
			lmax = A[i];
			Lmax[i] = lmax;
			
		}
		else
		{
			Lmax[i] = lmax;
		}
	}
	
	for (int i = n - 1; i >= 0; i--)
	{
		if (A[i] >= rmax)
		{
			rmax = A[i];
			Rmax[i] = rmax;

		}
		else
		{
			Rmax[i] = rmax;
		}
	}
	
	int sum = 0;
	for (int i = 0; i < A.size(); i++)
	{
		sum += (Rmax[i] < Lmax[i] ? Rmax[i] : Lmax[i]) - A[i];
	}
	return sum;
}
int main()
{
	vector<int> v = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	for (int i = 0; i < v.size(); i++)
	{
		cout<< v[i];
	}
	cout << endl;
	int sum = solve(v);
	cout << "Total Water Harvested= " << sum <<"mm"<< endl;
}