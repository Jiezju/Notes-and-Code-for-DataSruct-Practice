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
};