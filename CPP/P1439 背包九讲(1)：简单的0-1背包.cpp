#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ps;
void PSet(int n)
{
    vector<vector<int>> psl;
    vector<vector<int>>::iterator it;
    vector<int> s;
    ps.push_back(s);
    for (int i = 1; i <= n; i++)
    {
        psl = ps;
        for (it = psl.begin(); it != psl.end(); it++)
            (*it).push_back(i);
        for (it = psl.begin(); it != psl.end(); it++)
            ps.push_back(*it);
    }
}

void Knap(int w[], int v[], int W)
{
    int count = 0;
    int sumw, sumv;
    int maxi, maxsumw = 0, maxsumv = 0;
    vector<vector<int>>::iterator it;
    vector<int>::iterator sit;
    for (it = ps.begin(); it != ps.end(); it++)
    {
        //    cout<<count+1<<"\t";
        sumw = 0;
        sumv = 0;
        for (sit = (*it).begin(); sit != (*it).end(); sit++)
        {
            //        cout<<*sit<<" ";
            sumv += v[*sit - 1];
            sumw += w[*sit - 1];
        }
        // cout << "\t" << sumw << "\t" << sumv;
        if (sumw <= W)
        {
            //   cout<<"\tyes"<<endl;
            if (sumv > maxsumv)
                maxsumv = sumv;
        }
        //    else cout<<"\tno"<<endl;
        count++;
    }
    cout << maxsumv << endl;
    ps.clear();
}

int main()
{
    int V;
    while (cin >> V)
    {
        int n;
        int volume[31], value[31];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> volume[i] >> value[i];
        }
        PSet(n);
        Knap(volume, value, V);
    }
}
