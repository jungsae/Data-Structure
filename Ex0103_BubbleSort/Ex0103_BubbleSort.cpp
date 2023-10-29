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
	// int arr[] = {5, 1, 4, 2, 8}; // ��Ű�ǵ�� ����
	int arr[] = {5, 4, 3, 2, 1}; // Worst Case
	// int arr[] = {1, 2, 3, 5, 4}; // Best Case
	int n = sizeof(arr) / sizeof(arr[0]);

	Print(arr, n);
	cout << endl;

	// Bubble Sort
	{
		// ��Ʈ: Print()�� �����Ȳ Ȯ���ϸ鼭 ����
		// ��Ʈ: 2�� for ����
		// ��Ʈ: for ���� ���� ����
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - 1 - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr[j], arr[j + 1]);
				}
				Print(arr, n);
			}
			cout << endl;
		}
	}

	// Best case
	// Stability
}
