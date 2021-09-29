class IndexMaxHeap
{
private:
	int* data_;
	int* indexes_;
	int capacity_;
	int count_;
	
	void _shiftUp(int k)
	{
		while (k > 0 && data_[indexes_[(k-1)/2]] < data_[indexes_[k]])
		{
			swap(indexes_[(k-1)/2], indexes_[k]);
			k = (k-1)/2;
		}
	}
	
	void _shiftDown(int k)
	{
		while (2*k + 1 < count_)
		{
			int j = 2*k + 1;
			
			if (j+1 < count_ && data_[indexes_[j+1]] > data_[indexes_[j]])
				j += 1;
			
			if (data_[indexes_[j]] < data_[indexes_[k]])
				break;
			
			swap(indexes_[j], indexes_[k]);
			k = j;
		}
	}
	
public:
	IndexMaxHeap(int capacity): capacity_(capacity), count_(0)
	{
		data_ = new int[capacity_];
		indexes_ = new int[capacity_];
		
		for (int i=0; i<count_; i++)
		{
			indexes_[i] = i;
		}
	}
	
	~IndexMaxHeap()
	{
		delete[] data_;
		delete[] indexes_;
	}
	
	int size()
	{
		return count_;
	}
	
	bool isEmpty()
	{
		return count_ == 0;
	}
	
	void insert(int item)
	{
		assert(count_ < capacity_);
		
		data[count_] = item;
		_shiftUp(count_);
	}
	
	int getMax()
	{
		assert(count_ > 0);
		return data_[indexes_[0]];
	}
	
	int getMaxIndex()
	{
		assert(count_ > 0);
		return indexes_[0];
	}
	
	void pop()
	{
		assert(count_>0);
		
		swap(indexes_[0], indexes_[count_-1]);
		count_--;
		
		_shiftDown(0);
	}
	
	void change(int i, int newItem)
	{
		// i 表示 data 第i个元素，首先需要找到 数组第i个元素在堆中的位置
		assert(i>=0 && i<count_);
		data_[i] = newItem;
		
		for (int j =0;j<count_;j++)
		{
			if (indexes_[j] == i)
			{
				_shiftUp(j);
				_shiftDown(j);
				return;
			}
		}
	}
}