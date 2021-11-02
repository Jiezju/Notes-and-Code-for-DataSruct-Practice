template<typename Graph, typename Weight>
class BellmanFord
{
private:
	Graph g_;
	int s_;
	Weight* dist_;
	vector<Edge<Weight>*> from_;
	bool hasNegativeCycle_;
	
	bool _detectNegtiveCycle()
	{
		// 再进行一次松弛操作
		for (int i=0; i<g_.V(); ++i)
		{
			typename Graph::adjIterator adj(g_, i);
			
			for (auto e = adj.begin(); !adj.end(); e = adj.next())
			{
				if (from_[e->v()] && (!from_[e->w()] || dist_[e->v()] + e->wt() < dist_[e->w()]))
				{
					return true;
				}
			}
		}
		return false;
	}
	
public:
	BellmanFord(Graph g, int s):g_(g),s_(s)
	{
		dist_ = new Weight[g_.V()];
		
		for (int i=0; i<g_.V(); ++i)
			from_.push_back(NULL);
			
		// BellmanFord
		dist_[s_] = Weight();
		for (int pass=1; pass<g_.V(); ++pass)
		{
			for (int i=0; i<g_.V(); ++i)
			{
				typename Graph::adjIterator adj(g_, i);
				
				for (auto e = adj.begin(); !adj.end(); e = adj.next())
				{
					if (from_[e->v()] && (!from_[e->w()] || dist_[e->v()] + e->wt() < dist_[e->w()]))
					{
						dist_[e->w()] = dist_[e->v()] + e->wt();
						from_[e->w()] = e;
					}
				}
			}
		}
		
		hasNegativeCycle_ = _detectNegtiveCycle();
		
	}
	
	~BellmanFord()
	{
		delete[] dist_;
	}
	
	bool negativeCycle()
	{
		return hasNegativeCycle_;
	}
	
	bool shortestPathTo(int w)
	{
		assert(w>=0 && w<g_.V());
		return dist_[w];
	}
	
	bool hasPathTo(int w)
	{
		assert(w>=0 && w<g_.V());
		return from_[w] != NULL;
	}
	
};