#include <iostream>
#include <cassert>
#include <algorithm> // swap

using namespace std;

int BinarySearch(int *arr, int n, int x)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2; // 정수 나누기 (버림)

		cout << "middle " << middle << endl;

		if (x < arr[middle])
		{
			right = middle - 1;
			cout << "right " << right << endl;
		}
		else if (x > arr[middle])
		{
			left = middle + 1;
			cout << "left " << left << endl;
		}
		else
		{
			cout << "Found " << middle << endl;
			return middle;
		}
	}

	cout << "Not found" << endl;
	return -1; // Not found
}

int RecurBinarySearch(int *arr, int left, int right, int x) // n 대신에 left, right
{
	if (left <= right)
	{
		int middle = (left + right) / 2;

		if (x < arr[middle])
		{
			right = middle - 1;
			return RecurBinarySearch(arr, left, right, x); // TODO:
		}
		else if (x > arr[middle])
		{
			left = middle + 1;
			return RecurBinarySearch(arr, left, right, x); // TODO:
		}
		else
		{
			return middle; // TODO:
		}
	}

	return -1;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	int input;
	cin >> input;
	// cout << BinarySearch(arr, n, input) << endl;
	cout << "찾으시는 숫자는 " << RecurBinarySearch(arr, 0, n - 1, input) << "번째 인덱스에 있습니다." << endl;

	return 0;
}
