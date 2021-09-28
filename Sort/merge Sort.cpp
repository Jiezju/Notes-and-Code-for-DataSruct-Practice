void merge(int arr[], int l, int mid, int r)
{
	int mem[r-l+1];
	for (int i=l; i<=r; i++)
	{
		mem[i-l] = arr[i];
	}
	
	int j = l;
	int k = mid+1;
	for (int i=l; i<=r ; i++)
	{
		if (j>mid)
		{
			arr[i] = mem[k-l];
			k++;
		}
		else if (k>r)
		{
			arr[i] = mem[j-l];
			j++;
		}
		else if (mem[j-l] < mem[k-l])
		{
			arr[i] = mem[j-l];
			j++;
		}
		else
		{
			arr[i] = mem[k-l];
			k++;
		}
	}
}

void insertion_sort(int arr[], int l, int r)
{
	for (int i=l+1; i<=r; i++)
	{
		int e = arr[i];
		for (j = i; j>l && arr[j-1]>e; j--)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
}

void _mergeSort(int arr[], int l, int r)
{
	/*if (l>=r)
		return;
	*/
	if (r-l <=15)
	{
		insertion_sort(arr, l, r);
		return;
	}
		
	
	int mid = l + (r-l)/2;
	_mergeSort(arr, l, mid);
	_mergeSort(arr, mid+1,r);
	
	if (arr[mid] < arr[mid+1])
		merge(arr, l, mid, r);
}

void mergeSort(int arr[], int n)
{
	_mergeSort(arr, 0, n-1)
}


/*自底向上的merge sort*/
void merge(int arr[], int l, int mid, int r)
{
	int mem[r-l+1];
	
	for (int i=l; i<=r; ++i)
	{
		mem[i-l] = arr[i];
	}
	
	int j = l;
	int k = mid+1;
	for (int i=l; i<=r; ++i)
	{
		if (j>mid)
		{
			arr[i] = mem[k-l];
			k++;
		}
		else if (k>r)
		{
			arr[i]= mem[j-l];
			j++;
		}
		else if (mem[j-l] < mem[k-l])
		{
			arr[i] = mem[j-l];
			j++;
		}
		{
			arr[i] = mem[k-l];
			k++; 
		}
	}
}


void mergeSortBU(int arr[], int n)
{
	// 控制每轮进行排序的数量
	for (int sz=1; sz<n; sz*2)
	{
		// 遍历每一轮排序的子数组起始位置，进行所有子数组排序
		for (int i=0; i+sz<n; i+=sz+sz) // 每次对2*sz的数组进行排序
		{
			merge(arr, i, i+sz-1, std::min(i+sz+sz-1, n-1))
		}
	}
}
 