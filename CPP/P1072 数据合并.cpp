#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int m;
    while (cin>>m)
    {
        int n;
        cin>>n;
        vector<int> a,b;
        for (int i = 0; i < m+n; i++)
        {
            int t;
            cin>>t;
            a.push_back(t);            
        }
        sort(a.begin(),a.end());
        for (auto &&i : a)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
