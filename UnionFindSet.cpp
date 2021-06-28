#include<iostream>
#include<vector>
using namespace std;

class UnionFindSet
{
public:
	//一开始每一个都表示一个独立的集合
	UnionFindSet(size_t n)
	{
		_v.resize(n, -1);
	}


	int FindRoot(int x)
	{
		//一直找到负数停止
		while (_v[x] >= 0)
		{
			x = _v[x];
		}
		return x;
	}

	//判断x和y是否在一个集合，如果不在那就合并
	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		//如果两个根是相同的，那么这两个数就在一个集合，不相同说明不在一个集合，那就进行合并
		if (root1 == root2)
			return false;
		//走到这里已经说明了两个数不是一个集合的，所以需要合并
		_v[root1] += _v[root2];
		_v[root2] = root1;
		return true;
	}

	//数组中，负数的个数，即为集合的个数
	size_t Count()
	{
		size_t Count = 0;
		for (auto& e : _v)
		{
			if (e < 0)
				++Count;
		}
		return Count;
	}
private:
	vector<int> _v;
};