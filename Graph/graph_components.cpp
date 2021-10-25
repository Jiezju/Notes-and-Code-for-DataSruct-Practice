template<typename graph>
class GraphComponents
{
private:
	graph g_;
	int* visited_;
	int ccount_;
	
	void _dfs(int s)
	{
		visited_[s] = 1;
		
		typename graph::adjIterator adj(g_, s); // typename 声明 adjIterator 是 graph 的一个类
		for (int w = adj.begin(); !adj.end(); w = adj.next())
		{
			if (!visited_[w])
				_dfs(w);
		}
	}
	
public:
	GraphComponents(graph g): g_(g), ccount_(0)
	{
		visited_ = new int[g.V()];
		
		for (int i=0; i < g.V(); ++i)
			visited_[i] = 0;
		
		for (int i=0; i < g.V(); ++i)
		{
			if (!visited_[i])
			{
				_dfs(i);
				ccount_++;
			}
		}
	}
	
	~GraphComponents()
	{
		delete[] visited_;
	}
	
	int count const ()
	{
		return ccount_;
	}
	
};