#include <iostream>
#include <list>
using namespace std;
int main()
{
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		list<int> holes;
		holes.clear();
		for (int i = 1; i <= m; i++)
			holes.push_back(i);
		list<int>::iterator p = holes.begin();
		while (holes.size() > 1)
		{
			for (int i = 1; i < n; i++)
			{
				++p;
				if (p == holes.end())
					p = holes.begin();
			}
			p = holes.erase(p);
			if (p == holes.end())
				p = holes.begin();
		}
		cout << holes.front() << endl;
	}
}