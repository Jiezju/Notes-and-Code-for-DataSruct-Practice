#include <queue>
#include "Edge.h"

template<typename Graph, typename Weight>
class LazyPrim
{
private:
	Graph g_;
	priority_queue<Edge<Weight>,vector<Edge<Weight>>,greater<Edge<Weight>> > minHeap_;
	vector<Edge<Weight>> mst_;
	Weight mstWeight_;
	bool* marked_;
	
	void _visit(int w)
	{
		if (marked_[w])
			return;
		
		// 标记
		marked_[w] = true;
		// 将边加入 最小堆
		typename Graph::adjIterator adj(g_, w);
		for (Edge<Weight>* e = adj.begin(); !adj.end(); e=adj.next())
		{
			if (!marked_[e->other(w)])
				minHeap_.push(*e);
		}
		
	}
	
public:
	LazyPrim(Graph g): g_(g)
	{
		marked_ = new bool[g_.V()];
		
		for (int i=0; i<g_.V(); i++)
		{
			marked_[i] = 0;
		}
		
		_visit(0);
		
		while (!minHeap_.empty())
		{
			Edge<Weight> e = minHeap_.top();
			minHeap_.pop();
			
			if (marked_[e->v()] == marked_[e->w()])
				continue;
			
			mst_.push_back(e);
			mstWeight_ += e.wt();
			if (marked_[e->v()])
				_visit(e->w());
			else
				_visit(e->v());
				
		}		
	}
	
	~LazyPrim()
	{
		delete[] marked_;
	}
};