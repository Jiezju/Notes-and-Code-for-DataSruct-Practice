#include <cassert>

class DenseGraph
{
private:
	int n_; // 节点数
	int m_; // 边数
	bool directed_;
	vector<vector<bool>> graph_;

public:
	DenseGraph(int count, bool directed):n_(count),m_(0),directed_(directed)
	{
		for (int i = 0; i<n_; ++i)
			graph_.push_back(vector<bool>( n_, false));
	}
	
	~DenseGraph()
	{
		graph_.clear();
		n_ = 0;
		m_ = 0;
	}
	
	int V() const { return n_; }
	int E() const { return m_; }
	
	void addEdge(int w, int v)
	{
		assert(w >= 0 && w < n_);
		assert(v >= 0 && v < n_);
		
		if (hasEdge(w, v))
			return;
		
		graph_[w][v] = true;
		
		if (!directed_)
			graph_[v][w] = true;
			
		m_++;
	}
	
	bool hasEdge(int w, int v)
	{
		assert(w >= 0 && w < n_);
		assert(v >= 0 && v < n_);
		return graph_[w][v];
	}

};