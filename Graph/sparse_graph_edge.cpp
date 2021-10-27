#include <cassert>
#include "Edge.h"

template<typename Weight>
class SparseGraph
{
private:
	int n_;
	int m_;
	bool directed_;
	vector<vector<Edge<Weight>*>> graph_;

public:
	SparseGraph(int count, bool directed):n_(count),m_(0),directed_(directed)
	{
		for (int i=0; i< n_; ++i)
			graph_.push_back(vector<Edge<Weight>*>());
	}
	
	~SparseGraph()
	{ }
	
	int V() const { return n_; }
	
	int E() const { return m_; }
	
	bool hasEdge(int w, int v)
	{
		assert(w >= 0 && w < n_);
		assert(v >= 0 && v < n_);
		
		for (auto iter = graph_[w].begin(); iter != graph_[w].end(); iter++)
		{
			if (iter->other(w) == v)
				return true;
		}
		
		return false;
	}
	
	void addEdge(int w, int v, Weight wt)
	{
		assert(w >= 0 && w < n_);
		assert(v >= 0 && v < n_);
		
		if (hasEdge(w, v))
		{
			delete graph_[w][v];
			if (!directed)
				delete graph_[v][w];
			m--;
		}
		
		Edge<Weight>* e = new Edge<Weight>(w, v, wt);
		graph_[w].push_back(e);
		if ( v != w && !directed_)
			graph_[v].push_back(e);
			
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
		Edge<Weight>* begin()
		{
			index_ = 0;
			if (index < g.graph_[w_].size())
				return g.graph_[w_][index_];
			return NULL;
		}
		
		// 表示迭代器的下一个元素
		Edge<Weight>* next()
		{
			index_++;
			if (index < g.graph_[w_].size())
				return g.graph_[w_][index_];
				
			return NULL;
		}
		
		// 查看迭代是否终止
		bool end()
		{
			return index >= g.graph_[w_].size();
		}
	
	};
	
};