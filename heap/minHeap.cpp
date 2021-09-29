template<typename T>
class minHeap
{
private:
	T* data_;
	int count_;
	int capacity_;
	
	void _shiftUp(int k)
	{
		while (k>1 && data_[k/2] > data_[k])
		{
			swap(data_[k/2], data_[k]);
			k /= 2;
		}
	}
	
	void _shiftDown(int k)
	{
		while (2*k < count_)
		{
			int j = 2*k;
			if (j+1 < count_ and data_[j+1] < data_[j])
				j += 1;
			
			if (data_[j] > data_[k])
				break;
			
			swap(data_[j], data_[k]);
			k = j;
		}
	}
	
public:
	minHeap(int capacity):capacity_(capacity), count_(0)
	{
		data_ = new T[capacity_ + 1];
	}
	
	int size()
	{
		return count_;
	}
	
	bool isEmpty()
	{
		return count_ == 0;
	}
	
	void insert(T ele)
	{
		assert(count_ + 1< capacity_)
		
		data_[count_++] = ele
		
		_shiftUp(count_);
	}
	
	T getMin()
	{
		return data_[1];
	}
	
	void pop()
	{
		assert(count_ > 1)
		
		swap(data_[count_], data_[1]);
		
		count_--;
		
		_shiftDown(0);
	}
}