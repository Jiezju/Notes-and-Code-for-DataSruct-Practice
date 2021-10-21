#include <cassert>

class DenseGraph
{
private:
	int n_; // 节点数
	int m_; // 边数
	bool directed_; // 是否有向
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
	
	class adjIterator
	{
	private:
		DenseGraph g_;
		int w_;
		int index_;
	
	public:
		adjIterator(DenseGraph G, int w):g_(G),w_(w),index_(-1)
		{}
		
		~adjIterator = default;
		
		int begin()
		{
			index = -1;
			return next();
		}
		
		int next()
		{
			index_++;
			for (;index_ < g_.V(); ++index_)
				if (g_.graph_[w][index_])
					return index_;
			return -1;
		}
		
		bool end()
		{
			int i = index_;
			
			for (int i+=1; i<g_.V(); ++i)
				if (g_.graph_[w][i] == true)
					return false;
			return true;
		}
	};

};