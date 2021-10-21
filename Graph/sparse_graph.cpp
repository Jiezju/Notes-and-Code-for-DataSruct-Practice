#include <cassert>

class SparseGraph
{
private:
	int n_;
	int m_;
	bool directed_;
	vector<vector<int>> graph_;

public:
	SparseGraph(int count, bool directed):n_(count),m_(0),directed_(directed)
	{
		for (int i=0; i< n_; ++i)
			graph_.push_back(vector<int>());
	}
	
	~SparseGraph()
	{ }
	
	int V() const { return n_; }
	
	int E() const { return m_; }
	
	bool hasEdge(int w, int v)
	{
		assert(w >= 0 && w < n_);
		assert(v >= 0 && v < n_);
		
		for (int i=0; i < graph_[w].size(); i++)
		{
			if (graph_[w][i] == v)
				return true;
		}
		return false;
	}
	
	void addEdge(int w, int v)
	{
		assert(w >= 0 && w < n_);
		assert(v >= 0 && v < n_);
		
		if (hasEdge(w, v))
			return;
		
		graph_[w].push_back(v);
		if ( v != w && !directed_)
			graph_[v].push_back(w);
			
		m_++;
	}
	
	// SparseGraph 的迭代器设计
	class adjIterator
	{
	private:
		SparseGraph G_;
		int w_;
		int index_;
	
	public:
		adjIterator(SparseGraph g, int w): G_(g), w_(w), index_(0)
		{}
		
		~adjIterator()
		{}
		
		// 表示迭代器的首个元素
		int begin()
		{
			index_ = 0;
			if (index < g.graph_[w_].size())
				return g.graph_[w_][index_];
			return -1;
		}
		
		// 表示迭代器的下一个元素
		int next()
		{
			index_++;
			if (index < g.graph_[w_].size())
				return g.graph_[w_][index_];
				
			return -1
		}
		
		// 查看迭代是否终止
		bool end()
		{
			return index >= g.graph_[w_].size();
		}
	
	};
	
};