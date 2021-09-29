class MaxHeap
{
private:
	int* data_;
	int count_;
	int capacity_;
	
	void _shiftUp(int k)
	{
		while ( k>1 && data_[k/2] < data_[k])
		{
			swap(data_[k/2], data_[k]);
			k = k/2;
		}
	}
	
	void _shiftDown(int k)
	{
		while (2*k<count_)
		{
			int j = 2*k;
			
			if (j+1<count_ && data_[j+1] > data_[j])
				j = j+1;
			
			if (data_[j] <= data_[k])
				break;
			
			swap(data_[j], data_[k]);
			k = j;
		}
	}
	
public:
	MaxHeap(int capacity):capacity_(capacity), count_(0)
	{
		data_ = new int[capacity_ + 1]; // 索引从 1 开始
	}
	
	~MaxHeap()
	{
		delete[] data_;
	}
	
	int size()
	{
		return count_;
	}
	
	bool isEmpty()
	{
		return count_ == 0;
	}
	
	int getMax()
	{
		if (count_ == 0)
			return -1;
		
		return data_[1];
	}
	
	void insert(int item)
	{
		if (count_ + 1 > capacity_)
			return;
		
		data_[count_+1] = item;
		count_++;
		_shiftUp(count_);
	}
	
	void pop()
	{
		if (count_ == 0)
			return;
			
		int ret = data_[1];
		swap(data_[1], data_[count_]);
		count_--;
		_shiftDown(1);
	}
	
}