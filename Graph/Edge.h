template<typename Weight>
class Edge
{
private:
	int w_,v_; // 两个顶点 默认 w_ -> v_
	Weight weight_; // 一个权值

public:
	Edge(int w, int v, Weight weight):w_(w),v_(v),weight_(weight)
	{}
	
	Edge() {}
	~Edge() {}
	
	int v() const { return v_; }
	int w() const { return w_; }
	
	Weight wt() const { return weight_; }
	
	int other(int s)
	{
		assert(s == w_ || s==v_);
		return s == w_ ? v_:w_;
	}
	
	friend ostream& operator<<(ostream& os, const Edge& e)
	{
		os<<s.w_<<"->"<<s.v_<<":"<<e.weight_;
		return os;
	}
	
	bool operator< (const Edge& e)
	{
		return this->weight_ < e.weight_;
	}
	
	bool operator> (const Edge& e)
	{
		return this->weight_ > e.weight_;
	}
	
	bool operator>= (const Edge& e)
	{
		return this->weight_ >= e.weight_;
	}
	
		bool operator<= (const Edge& e)
	{
		return this->weight_ <= e.weight_;
	}
	
		bool operator== (const Edge& e)
	{
		return this->weight_ == e.weight_;
	}
};