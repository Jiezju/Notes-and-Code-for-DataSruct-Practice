template<typename graph>
class Path
{
private:
	graph g_;
	int s_; // 源点
	int* visited_;
	int* from_;
	
	void _dfs(int s)
	{
		visited_[s] = 1;
		
		typename graph::adjIterator adj(g_, s);
		for (int i=adj.begin(); !=adj.end(); i=adj.next())
		{
			if (!visited_[i])
			{
				from_[i] = s;
				_dfs(i);
			}
		}
	}
	
public:
	Path(graph g, int s):g_(g),s_(s)
	{
		visited_ = new int [g.V()];
		from_ = new int [g.V()];
		
		for (int i=0; i<g.V(); i++)
		{
			visited_[i] = 0;
			from_[i] = -1;
		}
		
		// 寻路算法
		_dfs(s_);
		
	}
	
	~Path()
	{
		delete [] visited_;
		delete [] from_;
	}
	
	bool hasPath(int w)
	{
		return bool(visited_[w]);
	}
	
	void path(int w, vector<int>& vec)
	{
		stack<int> s;
		int p = from_[w];
		s.push(w);
		while (p != s_)
		{
			s.push(p);
			p = from_[p];
		}
		
		vec.clear();
		while (!s.empty())
		{
			vec.push_back(s.top());
			s.pop();
		}
	}
	
	
};