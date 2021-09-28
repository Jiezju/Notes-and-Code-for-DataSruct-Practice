void insertionSort(int arr[], int n)
{
	for (int i=1; i<n; ++i)
	{
		int e = arr[i];
		for (int j=i; j>0; --j)
		{
			if (arr[j-1]>e)
				arr[j] = arr[j-1];
			else
				break; // 提前终止条件（insertionSort 的优势）
		}
		// 退出条件 j==0 或 arr[j-1]<= e
		arr[j] = e;
	}
}

// 另一种写法
void insertionSort(int arr[], int n)
{
	for (int i=1; i<n; ++i)
	{
		int e = arr[i];
		
		for (int j=i;j>0 && arr[j-1] > e; --j)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
}