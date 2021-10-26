#include <cassert>
#include "Edge.h"

template<typename Weight>
class DenseGraph
{
private:
	int n_; // 节点数
	int m_; // 边数
	bool directed_; // 是否有向
	vector<vector<Edge<Weight>*>> graph_;

public:
	DenseGraph(int count, bool directed):n_(count),m_(0),directed_(directed)
	{
		for (int i = 0; i<n_; ++i)
			graph_.push_back(vector<Edge<Weight>*>( n_, NULL));
	}
	
	~DenseGraph()
	{
		for (int i=0; i<n_; i++)
			for (int j=0; j<n_;j++)
				if (graph_[i][j] != NULL)
					delete graph_[i][j];
		n_ = 0;
		m_ = 0;
	}
	
	int V() const { return n_; }
	int E() const { return m_; }
	
	void addEdge(int w, int v, Weight weight)
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
		
		graph_[w][v] = new Edge<Weight>(w,v,weight); // 使用 new 创建指针
		
		if (!directed_)
			graph_[v][w] = new Edge<Weight>(w,v,weight);
			
		m_++;
	}
	
	bool hasEdge(int w, int v)
	{
		assert(w >= 0 && w < n_);
		assert(v >= 0 && v < n_);
		return graph_[w][v] != NULL;
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
		
		Edge<Weight>* begin()
		{
			index = -1;
			return next();
		}
		
		Edge<Weight>* next()
		{
			index_++;
			for (;index_ < g_.V(); ++index_)
				if (g_.graph_[w][index_])
					return g_.graph_[w][index_];
			return NULL;
		}
		
		bool end()
		{
			int i = index_;
			
			for (int i+=1; i<g_.V(); ++i)
				if (g_.graph_[w][i] != NULL)
					return false;
			return true;
		}
	};

};