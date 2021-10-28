#include "IndexMinHeap"
#include "Edge.h"

template<typename Graph, typename Weight>
class Prim
{
private:
	Graph g_;
	IndexMinHeap<Weight> ipq_;
	vector<Edge<Weight>*> edgeTo_; // 数组记录更新的横切边值
	bool* marked_;
	vector<Edge<Weight>> mst_;
	Weight mstWeight_;
	
	void _visit(int s)
	{
		if (marked_[i])
			return;
		
		// 标记访问点
		marked_[i] = true;
		
		typename Graph::adjIterator adj(g_, s);
		
		// 加入横切边
		for (Edge<Weight>* e=adj.begin();!adj.end(); e=adj.next())
		{
			int w = e->other(s);
			// 确认 w 没访问过
			if (!marked_[w])
			{	
				// 空的边更新 
				if (!edgeTo_[w])
				{
					edgeTo_[w] = e;
					ipq.insert(w, e->wt());
				}
				// 小的边更新
				else if (e->wt() < edgeTo_[w]->wt())
				{
					edgeTo_[w] = e;
					ipq.change(w, e->wt());
				}
			}
		}
	}

public:
	Prim(Graph g):g_(g)
	{
		marked_ = new bool[g_.V()];
		
		for (int i = 0; i<g_.V(); ++i)
		{
			marked_[i] = false;
			edgeTo_.push_back(NULL);
		}
		mst.clear();
		
		// prim
		_visit(0);
		while (!ipq.isEmpty())
		{
			int v = ipq.extractMinIndex(); // 获取最小横切边的另一个顶点
			// 更新结果
			mst_.push_back(*edgeTo_[v]);
			mstWeight_ += edgeTo_[v]->wt();
			
			_visit(v);
			
		}
	}
	
	~Prim()
	{
		delete[] marked_;
	}
	
	vector<Edge<Weight>> mstEdges()
	{
		return mst;
	}
	
	Weight result()
	{
		return mstWeight_;
	}
	
	
};