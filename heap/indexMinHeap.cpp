class IndexMinHeap
{
private:
	float* data_;
	int* indexes_;
	int* reverse_;
	int count_;
	int capacity_;
	
	void _shiftUp(int k)
	{
		while (k>0 && data_[indexes_[k/2]] > data_[indexes_[k]])
		{
			swap(indexes_[k/2], indexes_[k]);
			reverse_[indexes_[k/2]] = k;
			reverse_[indexes_[k]] = k/2;
			k/=2;
			
		}
	}
	
	void _shiftDown(int k)
	{
		while (2*k + 1< count_)
		{
			int j = 2*k+1;
			
			if (j+1 <count_ && data_[indexes_[j+1]] < data_[indexes_[j]])
				j+=1;
			
			if (data_[indexes_[j]] > data_[indexes_[k]])
				continue;
				
			swap(indexes_[j], indexes_[k]);
			reverse_[indexes_[j]] = j;
			reverse_[indexes_[k]] = k;
			
			k = j;
		}
	}
	
public:
	IndexMinHeap(int capacity):capacity_(capacity),count_(0)
	{
		data_ = new float[capacity_];
		indexes_ = new int[capacity_];
		reverse_ = new int[capacity_];
		
		for (int i=0; i< capacity_; ++i)
		{
			reverse_[i] = -1; // -1 表示索引不存在
		}
	}
	
	~IndexMinHeap()
	{
		delete[] data_;
		delete[] indexes_;
		delete[] reverse_;
	}
	
	int size()
	{
		return count_;
	}
	
	bool isEmpty()
	{
		return count_ == 0;
	}
	
	void insert(float item)
	{
		assert(count_ < capacity_);
		
		data_[count_] = item;
		indexes_[count_] = count_;
		reverse_[count_] = count_;
		
		count_++;
		_shiftUp(count_-1);
	}
	
	float getMax()
	{
		assert(count_>0);
		return data_[indexes_[0]];
	}
	
	bool contain(int i)
	{
		return reverse_[i] != -1;
	}
	
	void pop()
	{
		assert(count_ >0);
		swap(indexes_[0], indexes_[count_-1]);
		reverse[indexes_[0]] = 0;
		reverse[indexes_[count_-1]] = -1;
		count_--;
		_shiftDown(0);
	}
	
	void change(int i, float item)
	{
		assert(contain(i));
		data_[i] = item;
		
		int j = reverse_[i];
		_shiftDown(j);
		_shiftUp(j);
	}
}