int solve(vector<int> &A, int B) {
unordered_map<int, int> m;
for(int i=0;i<A.size();i++)
{
    m.insert({A[i],i});
}
int count=0;
for(int i=0;i<A.size();i++)
{
    int x=A[i]^B;
    if(m.find(x)!=m.end()&&m[x]!=i)
    {
        count++;
    }
}
return count/2;
    
}
