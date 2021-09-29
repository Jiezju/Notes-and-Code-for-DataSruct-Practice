void _shiftDown(int k, int* data, int num)
{
	while (2*k+1 < num)
	{
		int j = 2*k +1;
		
		if (j+1 < num && data[j+1] > data[j])
			j += 1
		
		if (data[j] < data[k])
			break
		
		swap(data[j], data[k]);
		k = j;
	}
}

void heapify(int* data, int num)
{
	for (int i = (num-1 - 1) / 2; i >=0 ; i--)
	{
		_shiftDown(i, data, num);
	}
}

void heapSort(int* data, int num)
{
	heapify(data, num);
	
	for (int i=num-1; i>0 ; i--)
	{
		swap(data[0], data[i]);
		_shiftDown(0, data, i);
	}
}