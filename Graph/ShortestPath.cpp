#include <queue>

template<typename graph>
class ShortestPath
{
private:
	graph g_;
	int s_;
	int* visited_;
	int* from_;
	int* ord_; // ord_[i] 表示 i 节点到 s_ 的距离
	
	void _bfs()
	{
		queue<int> q;
		queue.push(s_);
		visited_[s_] = 1
		ord_[s_] = 0;
		from_[s_] = s_;
		
		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			
			typename graph::adjIterator adj(g_, v);
			for (int i=adj.begin(); !adj.end(); i=adj.next())
			{
				if (!visited_[i])
				{
					q.push(i);
					visited_[i] = 1;
					from_[i] = v;
					ord_[i] = ord_[v] + 1;
				}
			}
		}
		
	}

public:
	ShortestPath(graph g, int s):g_(g),s_(s)
	{
		assert( s>=0 && s<g_.V());
		visited_ = new int [g_.V()];
		from_ = new int [g_.V()];
		ord_ = new int [g_.V()];
		
		for (int i=0; i<g_.V(); ++i)
		{
			visited_[i] = 0;
			from_[i] = -1;
			ord_[i] = 0;
		}
		
		// 路径记录
		_bfs();
	}
	
	~ShortestPath()
	{
		delete[] visited_;
		delete[] from_;
		delete[] ord_;
	}
	
	bool hasPath(int w)
	{
		assert(w>=0 && w<g_.V());
		return visited_[w];
	}
	
	void path(int w, vector<int>& vec)
	{
		int p = from_[w];
		stack<int> s;
		s.push(w);
		while (p != s_)
		{
			s.push(p);
			p = from_[p];
		}
		
		vec.clear()
		while (!s.empty())
		{
			vec.push_back(s.top());
			s.pop();
		}
	}
	
	int length(int w)
	{
		assert(w>=0 && w<g_.V());
		return ord_[w];
	}
	
	
};