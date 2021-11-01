#include "Edge.h"
#include "IndexMinHeap.h"

template<typename Graph, typename Weight>
class Dijkstra
{
private:
	Graph g_;
	int s_;
	Weight* dist_; // 记录 s 到达其他点的最短路径长度
	bool* marked_; // 标记
	vector<Edge<Weight>*> from_; // 顶点来自的边
	
public:
	Dijkstra(Graph g, int s):g_(g),s_(s)
	{
		dist_ = new Weight[g_.V()];
		marked_ = new Weight[g_.V()];
		
		for (int i=0; i<g_.V(); ++i)
		{
			dist_[i] = Weight();
			marked_[i] = false;
			from_.push_back(NULL);
		}
		
		IndexMinHeap<Weight> ipq(g_.V());
		
		// Dijkstra
		dist_[s_] = Weight();
		marked_[s_] = true;
		ipq.insert(s_, dist_[s_]);
		
		while (!ipq.isEmpty())
		{
			int v = ipq.extracMinIndex(); // 获取最小值对应的 index
			marked_[v] = true;
			
			typename Graph::adjIterator adj(g_, v);
			for (auto e = adj.begin(); !adj.end(); e = adj.next())
			{
				if (!marked_[e->other()])
				{
					if (from_[e->other()] == NULL || from_[e->other()] = e;)
					{
						dist_[e->other()] = dist_[v] + e->wt();
						from_[e->other()] = e;
						
						if (ipq.contain(w))
							ipq.change(w, dist_[w]);
						else
							ipq.insert(w, dist_[w]);
					}
				}
			}
		}
		
	}
	
	~Dijkstra()
	{
		delete[] dist_;
		delete[] marked_;
	}
	
	Weight shortestPathTo(int w)
	{
		return dist_[w];
	}
	
	bool hasPathTo(int w)
	{
		return marked_[w];
	}
	
};