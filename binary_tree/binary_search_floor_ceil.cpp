// https://blog.csdn.net/Jae_Wang/article/details/80610511?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_title~default-0.no_search_link&spm=1001.2101.3001.4242

// 查找 floor 元素
int binary_search_floor(int arr[], int n, int target)
{
	// 左边起始点，左边可能没有与target 相同的
	int l = -1;
	int r = n-1;
	
	while (l<r)
	{	
		// 向上取整，奇数位置 + 1
		int mid = l + (r - l + 1)/2;
		// 右边走的快
		if (arr[mid] >= target)
			r = mid - 1;
		// 左边走的慢
		else
			l = mid;
	}
	
	// 由于右边走的快，可能走过了，回头看一下
	if ( l < n - 1 && arr[l+1] == target)
		return l+1;
	
	return l;
}

// 查找 floor 元素
int binary_search_floor(int arr[], int n, int target)
{
	int l = 0;
	int r = n;
	
	while ( l<r )
	{
		int mid = l + (r-l)/2;
		// 左边走的快
		if (arr[mid] <= target)
			l = mid + 1;
		else // arr[mid] > target
			r = mid;
	}
	
	if (r > 0 && arr[r-1] == target)
		return r-1;
		
	return r;
}