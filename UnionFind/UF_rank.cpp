class UF
{
private:
	int* parent_;
	int* rank_;
	int count_;

public:
	UF(int count):count_(count)
	{
		parent_ = new int[count_];
		rank_ = new int[count_];
		for (int i=0; i<count_;i++)
		{
			parent_[i] = i;
			rank_[i] = 1;
		}
	}
	
	~UF()
	{
		delete[] parent_;
		delete[] rank_;
		count_ = 0;
	}
	
	int find(int p)
	{
		while (p != parent_[p]) 
		{
			// 路径压缩
			parent_[p] = parent_[parent_[p]];
			p = parent_[p];
		}
			
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
		
		if (rank_[pRoot] == rank_[qRoot])
		{
			parent_[pRoot] = qRoot;
			rank_[qRoot] += 1; // 只有在相等的时候维护
		}
		else if (rank_[pRoot] < rank_[qRoot])
		{
			parent_[pRoot] = qRoot;
		}
		else
		{
			parent_[qRoot] = pRoot;	
		}
	}
	
};