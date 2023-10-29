#include <iostream>

using namespace std;

bool CheckSorted(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}

void Print(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	// ���������� �ϳ��� �б� (���� ������ �߰� �ܰ�)
	{
		int arr[] = {1, 2, 4, 5, 3, 6};
		int n = sizeof(arr) / sizeof(arr[0]);

		// Print(arr, n);

		// // i = 4�� ��쿡 ���ؼ� ����
		// int i = 4;
		// int key = arr[i];

		// for (...)
		// int j = i;
		// for (; j > 0 && arr[j - 1] > key; j--)
		// {
		// 	// TODO:
		// 	arr[j] = arr[j - 1];

		// 	Print(arr, n);
		// }

		// arr[j] = key;

		// Print(arr, n);
		// cout << endl;
	}

	int arr[] = {8, 3, 2, 5, 1, 2};
	// int arr[] = {6, 5, 4, 3, 2, 1}; // Worst
	// int arr[] = { 1, 2, 3, 4, 5, 6 }; // Best
	int n = sizeof(arr) / sizeof(arr[0]);

	// Insertion Sort
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			int key = arr[i];
			int j = i;
			for (; j > 0 && key < arr[j - 1]; j--)
				arr[j] = arr[j - 1];
			cout << "j = " << j << endl;
			arr[j] = key;
			// if (arr[i - 1] > arr[i])
			// {
			// 	int key = arr[i];
			// 	int j = i;
			// 	for (; j > 0 && arr[j - 1] > key; j--)
			// 	{
			// 		arr[j] = arr[j - 1];
			// 	}
			// 	arr[j] = key;
			// }
		}
		Print(arr, n);
	}

	// Print(arr, n);

	// Stability
}
