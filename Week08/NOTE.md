学习笔记
1.冒泡排序(每次找出最大)
void BubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
                std::swap(arr[j],arr[j+1]);
        }
    }
}
2.选择排序(每次找出最小)
void selectSort(int intArray[],int array_size)
{
    //选择排序思路数组中的第一个元素和剩余的数组元素分别比较如果第一个元素大于其他数组元素
    //交换值一轮下来可以确定数组中的最小(最大)值二轮下来确定次最小(最大)值 
    for(int i=0; i<array_size-1; i++)
    {
        for(int j=i+1; j<array_size; j++)
        {
            int temp;
            if(intArray[i] > intArray[j])
            {
                temp = intArray[i];
                intArray[i] = intArray[j];
                intArray[j] = temp;
            }
        }
    }
}
3.插入排序(假设有一个已排序好的数组，将新的元素插入到数组中)
void InsertionSort(int a[], int size)
{
	int i;			//有序区间的最后一个元素的位置,i+1就是无序区间最左边元素的位置
	for(i = 0; i < size-1; ++i){
		int tmp = a[i + 1];  //tmp是待插入到有序区间的元素,即无序区间最左边的元素
		int j = i;
		while(j >= 0 && tmp < a[j]){		//寻找插入的位置 
			a[j + 1] = a[j];				//比tmp大的元素都往后移动 
			--j;
		}
		a[j + 1] = tmp;
	}
}
4.并归排序
void mergeSort(vector<int> &nums, int left, int right) {
	if (left >= right) return;
	
	int mid = left + (right - left) / 2;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid+1, right);
	
	merge(nums, left, mid, right);
}
void merge(vector<int> &nums, int left, int mid, int right) {
	vector<int> tmp(right-left+1);
	int i = left, j = mid+1, k = 0;
	
	while (i <= mid && j <= right) {
		tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
	}
	while (i <= mid) tmp[k++] = nums[i++];
	while (j <= right) tmp[k++] = nums[j++];
	
	for (i = left, k = 0; i <= right;) nums[i++] = tmp[k++];
}

5.快速排序
int random_partition(vector<int>& nums, int l, intr) {
  int random_pivot_index = rand() % (r - l +1) + l;  //随机选择pivot
  int pivot = nums[random_pivot_index];
  swap(nums[random_pivot_index], nums[r]);
  int i = l - 1;
  for (int j=l; j<r; j++) {
    if (nums[j] < pivot) {
      i++;
      swap(nums[i], nums[j]);
    }
  }
  int pivot_index = i + 1;
  swap(nums[pivot_index], nums[r]);
  return pivot_index;
}
void random_quicksort(vector<int>& nums, int l, int r) {
  if (l < r) {
    int pivot_index = random_partition(nums, l, r);
    random_quicksort(nums, l, pivot_index-1);
    random_quicksort(nums, pivot_index+1, r);
  }
}