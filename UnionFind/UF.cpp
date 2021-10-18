#include <cassert>

class UnionFind
{
private:
	int* parent_;
	int* size_; // size_[i] 表示以 i 为根的集合的元素个数
	int count_;
	
public:
	UnionFind(int count): count_(count)
	{
		parent_ = new int[count_];
		size_ = new int[count_];
		
		for (int i=0; i<count_; ++i)
		{
			parent_[i] = i;
			size_[i] = 1;
		}
	}
	
	~UnionFind()
	{
		delete [] parent_;
		delete [] size_;
		count_ = 0;
	}
	
	int find(int p)
	{
		assert(p > 0 && p < count_);
		while (parent_[p] != p)
			p = parent_[p];
		return p;
	}
	
	bool isConnected(int p, int q)
	{
		return find(p) == find(q);
	}
	
	void UnionElements(int p, int q)
	{
		int pRoot = find(p);
		int qRoot = find(q);
		
		if (size_[pRoot] < size_[qRoot]))
		{
			parent_[pRoot] = qRoot;
			size_[qRoot] += size_[pRoot];  // qRoot 的根 加入 pRoot 的根
		}
		else
		{
			parent_[qRoot] = pRoot;
			size_[pRoot] += size_[qRoot]; 
		}
	}
	
};