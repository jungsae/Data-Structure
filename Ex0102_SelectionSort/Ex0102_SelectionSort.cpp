#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

struct Element
{
	int key;
	char value;
};

bool CheckSorted(int *arr, int size)
{
	// TODO: ���� Ȯ�� �Լ� ����
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

void Print(Element *arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i].key << " ";
	cout << endl;

	for (int i = 0; i < size; i++)
		cout << arr[i].value << " ";
	cout << endl;
}

int main()
{
	// 3�� ����
	{
		for (int k = 0; k < 3; k++)
			for (int j = 0; j < 3; j++)
				for (int i = 0; i < 3; i++)
				{

					int arr[3] = {i, j, k};
					int size = sizeof(arr) / sizeof(arr[0]);

					for (int e = 0; e < size; e++)
					{
						cout << arr[e] << " " << flush;
					}

					cout << " -> " << flush;

					// TODO: ���� �غ���
					for (int e = size - 1; e >= 0; e--)
					{
						// cout << 'a' << endl;
						for (int f = e - 1; f >= 0; f--)
						{
							if (arr[e] < arr[f])
							{

								swap(arr[e], arr[f]);
							}
						}
					}

					for (int e = 0; e < size; e++)
					{
						cout << arr[e] << " " << flush;
					}

					cout << boolalpha;
					cout << CheckSorted(arr, size); // ���� �Ǿ��� Ȯ��
					cout << endl;
				}
	}

	// return 0; // <- �ǽ��� �ӽ�

	// 5�����? �� ���ٸ�?
	{
		// 8 4 2 8 3
		// TODO: ???

		// 8 3 2 5 1 1 2 5 8 9
		// TODO: ???

		// 100�����?
	}

	// ���� ���� �� ã��
	// {
	// int arr[] = {8, 3, 2, 5, 1, 1, 2, 5, 8, 9}; // ������ ���ڵ�, ���� ����
	// int size = sizeof(arr) / sizeof(arr[0]);

	// assert(size > 0); // size�� 1�̻��̶�� ����

	// // TODO:
	// int min_number = arr[0];
	// int idx = 0;
	// for (int i = 1; i < size; i++)
	// {
	// 	if (arr[i] < min_number)
	// 	{
	// 		min_number = arr[i];
	// 		idx = i;
	// 	}
	// }
	// cout << "Minimum number is " << min_number << endl;
	// cout << "The index # is " << idx << endl;

	// return 0;
	// }

	// ���� ���� ���� �ε��� ã��
	// {
	// 	int arr[] = {8, 3, 2, 5, 1, 1, 2, 5, 8, 9};
	// 	int size = sizeof(arr) / sizeof(arr[0]);

	// 	assert(size > 0); // size�� 1�̻��̶�� ����

	// 	// TODO:
	// 	// int min_number = arr[0];
	// 	int min_index = 0;
	// 	for (int i = 1; i < size; i++)
	// 	{
	// 		if (arr[i] < arr[min_index])
	// 		{
	// 			min_index = i;
	// 		}
	// 	}

	// 	cout << "The index of min is " << min_index << endl;
	// 	cout << "Minimum number is " << arr[min_index] << endl;

	// 	return 0;
	// }

	// Selection Sort
	// ��Ʈ: swap()
	// {
	// 	int arr[] = {8, 3, 2, 5, 1, 1, 2, 5, 8, 9};
	// 	int size = sizeof(arr) / sizeof(arr[0]);

	// 	int min_index;
	// 	for (int i = 0; i < size - 1; i++)
	// 	{

	// 		// TODO:
	// 		Print(arr, size);
	// 		bool check = false;
	// 		min_index = i;
	// 		for (int j = i + 1; j < size; j++)
	// 		{
	// 			if (arr[min_index] > arr[j])
	// 			{
	// 				min_index = j;
	// 			}
	// 		}

	// 		swap(arr[i], arr[min_index]);
	// 		check = CheckSorted(arr, size);
	// 		cout << boolalpha;
	// 		if (check == true)
	// 		{
	// 			cout << check << endl;
	// 			Print(arr, size);
	// 			break;
	// 		}
	// 		else
	// 		{
	// 			cout << check;
	// 			cout << endl;
	// 		}
	// 	}

	// 	return 0;
	// }

	// �� Ƚ�� ������, �� ȿ������ ����� ������?
	// https://en.wikipedia.org/wiki/Sorting_algorithm
	{
		ofstream ofile("log.txt");
		for (int size = 1; size < 1000; size++)
		{
			int count = 0;
			int *arr = new int[size];
			for (int s = 0; s < size; s++)
			{
				arr[s] = size - s;
			}

			// TODO: count ++;
			int min_index;
			for (int i = 0; i < size - 1; i++)
			{
				for (int j = i + 1; j < size; j++)
				{
					count++;
					if (arr[j] < arr[min_index])
					{
						min_index = j;
					}
				}
				swap(arr[i], arr[min_index]);
			}

			// cout << size << ", " << count << endl;
			ofile << size << ", " << count << endl;
			// Print(arr, size);

			delete[] arr;
		}

		ofile.close();

		return 0;
	}

	// [2, 2, 1]
	// [1, 2, 2] // ù 2�� ���������� �̵�

	// ������ Ȯ��(unstable)
	{
		Element arr[] = {{2, 'a'}, {2, 'b'}, {1, 'c'}};
		int size = sizeof(arr) / sizeof(arr[0]);

		Print(arr, size); // arr�� Element�� �迭

		// TODO:

		Print(arr, size); // arr�� Element�� �迭
	}
}
