// 区间 [0,n)
int binary_search(int arr[], int n, int target)
{
	int l = 0;
	int r = n-1;
	
	while (l<=r)
	{
		int mid = l + (r-l)/2;
		
		if (arr[mid] == target]])
			return mid;
			
		else if (arr[mid] > target)
			r = mid-1;
		else
			l = mid+1;
	}
	
	return -1;
}

// 递归版本
int _binary_search(int arr[], int left, int right, int target)
{
	int mid = l + (r-l) / 2;

	if (arr[mid] == target)
		return mid;
	else if (arr[mid] < target)
		return _binary_search(arr, mid+1, right, target);
	else
		return _binary_search(arr, l, mid-1, target);
		
	return -1;
}


int binary_search_recur(int arr[], int n, int target)
{
	return _binary_search(arr, 0, n-1, target);
}