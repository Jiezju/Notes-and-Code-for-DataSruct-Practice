int partition(int arr[], int l, int r, int pivot)
{
	// arr[l+1,...i) <=v  arr[j,...r] >= v
	int i = l+1;
	int j = r;
	
	while (i <= j)
	{
		while (i<=r && arr[i] < pivot)
			i++;
		while (j>=l+1 && arr[j] > pivot)
			j--;
		
		if (i<=j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		
	}
	/*
	最后一次交换情形
		start                   j i                            end
		  |_____________________|_|_____________________________|
		|
		pivot 
	*/
	swap(arr[l], arr[j]); // i 在 >= v的位置， j在 <= v 的位置
	return j;
}

void __quick_sort(int arr[], int l, int r)
{
	if (l >= r)
		return;
		
	swap(arr[l], arr[rand() % (r-l+1) +l]);
	int pivot = arr[l];
	int index = partition(arr, l, r, pivot);
	
	__quick_sort(arr, l, index-1);
	__quick_sort(arr, index+1, r);
}

// two ways
void quick_sort(int arr[]，int n)
{
	srand(time(NULL));
	__quick_sort(arr，0，n-1);
}