#include<iostream>
#include<vector>
using namespace std;

class UnionFindSet
{
public:
	//һ��ʼÿһ������ʾһ�������ļ���
	UnionFindSet(size_t n)
	{
		_v.resize(n, -1);
	}


	int FindRoot(int x)
	{
		//һֱ�ҵ�����ֹͣ
		while (_v[x] >= 0)
		{
			x = _v[x];
		}
		return x;
	}

	//�ж�x��y�Ƿ���һ�����ϣ���������Ǿͺϲ�
	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		//�������������ͬ�ģ���ô������������һ�����ϣ�����ͬ˵������һ�����ϣ��Ǿͽ��кϲ�
		if (root1 == root2)
			return false;
		//�ߵ������Ѿ�˵��������������һ�����ϵģ�������Ҫ�ϲ�
		_v[root1] += _v[root2];
		_v[root2] = root1;
		return true;
	}

	//�����У������ĸ�������Ϊ���ϵĸ���
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