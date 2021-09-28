void _quick_sort(int arr[], int l, int r)
{
	if (l>=r)
		return;
	
	swap(arr[l], arr[rand() % (r-l +1 ) +l]);
	int pivot = arr[l];
	
	int lt = l; // arr[l+1...lt] <v
	int gt = r+1; // arr[gt..r]>v
	int i = l+1; // arr[lt+1...i) == v
	while (i<gt)
	{
		if (arr[i]==pivot)
		{
			i++;
		}
		else if (arr[i] < pivot)
		{
			swap(arr[i], arr[lt+1]);
			lt++;
			i++;
		}
		else
		{
			swap(arr[i], arr[gt-1]);
			gt--;
		}
	}
	swap(arr[l], arr[lt]);
	
	
	__quick_sort(arr, l,lt-1);
	__quick_sort(arr, gt,r);

}

void quick_sort(int arr[], int n)
{
	srand(time(NULL));
	_quick_sort(arr, 0, n-1);
}