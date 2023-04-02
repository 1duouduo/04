#include <iostream>
using namespace std;
//直接插入排序
void insertSort(int arr[], int n)
{
	int temp, i, j;
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		temp = arr[i];
		while (temp < arr[j] && j>= 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}
//简单选择排序
void selectSort(int arr[], int n)
{
	int i, j, k;
	int temp;
	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
			if (arr[k] > arr[j])
				k = j;
		temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}
}
//冒泡排序
void bubleSort(int arr[], int n)
{
	int i, j, flag;
	int temp;
	for (i = n - 1; i >= 1; i--)
	{
		flag = 0;
		for (j = 1; j <= i; j++)
			if (arr[j - 1] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				flag == 1;
			}
		if (flag == 0)
			return;
	}
}
//希尔排序
void shellSort(int arr[], int n)
{
	int temp;
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;	
		}
		
	}
}
//快速排序
void quickSort(int arr[], int low, int high)
{
	int temp;
	int i = low, j = high;
	if (low < high)
	{
		temp = arr[low];
		while (i < j)
		{
			while (j > i && arr[j] > = temp)
				j--;
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}
			while (i < j && arr[i] < temp)
				i++;
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
		}
		arr[i] = temp;
		quickSort(arr, low, i - 1);
		quickSort(arr, i + 1, high);
	}
}
//堆排序
void sift(int arr[], int low, int high)
{
	int i = low, j = 2 * i + 1;
	int temp = arr[i];
	while (j <= high)
	{
		if (j < high && arr[j] < arr[j + 1])
			j++;
		if (temp < arr[j])
		{
			arr[i] = arr[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
	arr[i] = temp;
}
void heapSort(int arr[], int n)
{
	int i;
	int temp;
	for (i = n / 2 - 1; i >= 0; i--)
		sift(arr, i, n - 1);
	for (i = n - 1; i > 0; i--)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		sift(arr, 0, i - 1);
	}
}
//归并排序
void merge(int arr[], int low, int mid, int high)
{
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[low + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];
	i = 0;
	j = 0;
	k = low;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
		k++;
	}
	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];
}
void mergeSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);

	}
}
//基数排序
//从末位数字开始排序，然后从倒数第二位数字开始排序，直至最后首位数字进行排序，排序完成
int main()
{

}