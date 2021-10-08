int patition(int arr[], int l, int r)
{
	int pivot = arr[l]
	// arr[l+1...j] < v ; arr[j+1...i) > v
	int j = l;
	for (int i = l+1; i <= r; ++i)
	{
		// arr[i] > v; ++i
		if (arr[i] < v)
		{
			swap(arr[j+1], arr[i]);
			j++;
		}
	}
	swap(arr[j], arr[l]);
	
	return j;
}

int patition_random_select_pivot(int arr[], int l, int r)
{
	srand(time(NULL))
	
	swap(arr[l], arr[rand() % (r-l+1) + l]);
	// 由于 pivot 的随机选择导致 相等情形下，排在后面的元素可能被提前，排序不稳定
	int pivot = arr[l]
	// arr[l+1...j] < v ; arr[j+1...i) > v
	int j = l;
	for (int i = l+1; i <= r; ++i)
	{
		// arr[i] > v; ++i
		if (arr[i] < v)
		{
			swap(arr[j+1], arr[i]);
			j++;
		}
	}
	swap(arr[j], arr[l]);
	
	return j;
}

void __quickSort(int arr[], int l, int r)
{
	if (l>=r)
		return;
	

	int index = patition(arr, l, r);
	 
	__quickSort(arr, l, index-1);
	__quickSort(arr, index+1, r);
}

void quickSort(int arr[], int n)
{
	__quickSort(arr, 0, n-1)
}

