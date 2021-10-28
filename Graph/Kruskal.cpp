#include "Edge.h"
#include "UnionFind.h"
#include "minHeap"

template<typename Graph, typename Weight>
class Kruskal
{
private:
	Graph g_;
	vector<Edge<Weight>> mst_;
	Weight mstWeight_;

public:
	Kruskal(Graph g):g_(g)
	{
		// 将所有边加入最小堆
		minHeap<Edge<Weight>> pq(g_.E());
		for (int i=0; i<g_.V(); ++i)
		{
			typename Graph::adjIterator adj(g_, i);
			for (Edge<Weight>* e = adj.begin(); !e.end(); e = adj.next())
			{
				if (e->v() < e->w())
					ipq.insert(*e);
			}
		}
		
		UnionFind uf(g_.V());
		while (!pq.isEmpty())
		{
			Edge<Weight> e = pq.getMin();
			pq.pop();
			
			if (uf.isConnected(e->v(), e->w()));
				continue;
			
			uf.UnionElements(e->v(), e->w());
			mst_.push_back(e);
			mstWeight_ += e->wt();
		}
		
	}
	
	~Kruskal() = default;
	
	vector<Edge<Weight>> mstEdges()
	{
		return mst;
	}
	
	Weight result()
	{
		return mstWeight_;
	}
	
};