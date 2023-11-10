#pragma once

#include <cassert>
#include <stdint.h>

using namespace std;

template <typename T>
class SinglyLinkedList
{
public:
	struct Node
	{
		T item = T();
		Node *next = nullptr;
	};

	SinglyLinkedList()
	{
	}

	SinglyLinkedList(const SinglyLinkedList &list)
	{
		// TODO: 연결 리스트 복사
		Node *current = list.first_;
		while (current)
		{
			PushBack(current->item);
			current = current->next;
		}
	}

	~SinglyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		// TODO: 모두 삭제
		while (first_)
		{
			PopFront();
		}
		}

	bool IsEmpty()
	{
		return first_ == nullptr;
	}

	int Size()
	{
		int size = 0;

		// TODO: size를 하나하나 세어서 반환
		Node *temp = first_;

		while (temp)
		{
			temp = temp->next;
			size++;
		}
		return size;
	}

	T Front()
	{
		assert(first_);

		return first_->item; // TODO: 수정
	}

	T Back()
	{
		assert(first_);
		Node *getLast = first_;
		while (getLast->next)
			getLast = getLast->next;
		return getLast->item; // TODO: 수정
	}

	Node *Find(T item)
	{
		// TODO: item이 동일한 노드 포인터 반환
		Node *getNum = first_;

		while (getNum)
		{
			if (getNum->item == item)
				return getNum;

			getNum = getNum->next;
		}

		return nullptr;
	}

	void InsertBack(Node *node, T item)
	{
		// TODO:
		Node *insert = new Node;
		insert->item = item;
		insert->next = node->next;
		node->next = insert;
	}

	void Remove(Node *n)
	{
		assert(first_);

		// 하나 앞의 노드를 찾아야 합니다.
		// TODO:
		Node *prev = first_;

		while (prev->next)
		{
			if (prev->next == n)
				break;

			prev = prev->next;
		}

		prev->next = n->next;
		delete n;
	}

	void PushFront(T item)
	{
		// first_가 nullptr인 경우와 아닌 경우 나눠서 생각해보기
		// (결국은 두 경우를 하나로 합칠 수 있음)

		// 새로운 노드 만들기
		Node *temp = new Node;
		temp->item = item;
		temp->next = first_;
		first_ = temp;
	}

	void PushBack(T item)
	{
		if (first_)
		{
			// TODO:
			Node *getLast = first_;
			while (getLast->next != nullptr)
				getLast = getLast->next;

			Node *back = new Node;
			back->item = item;
			back->next = nullptr;

			getLast->next = back;
		}
		else
		{
			// TODO:
			PushFront(item);
		}
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopFront()" << endl;
			return;
		}

		assert(first_);

		// TODO: 메모리 삭제
		Node *temp = first_;
		first_ = first_->next;
		delete temp;
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		// 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.

		assert(first_);

		// TODO: 메모리 삭제
		if (Size() == 1)
		{
			delete first_;
			first_ = nullptr;
		}
		else
		{
			Node *current = first_;
			while (current->next->next)
				current = current->next;

			Node *temp = current->next;
			current->next = current->next->next;

			delete temp;
		}
	}

	void Reverse()
	{
		// TODO:
		Node *current = first_;
		Node *prev = nullptr;

		while (current)
		{
			Node *temp = prev;
			prev = current;
			current = current->next;
			prev->next = temp;
		}

		first_ = prev;
	}

	void SetPrintDebug(bool flag)
	{
		print_debug_ = flag;
	}

	void Print()
	{
		using namespace std;

		Node *current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << " ";

			while (current)
			{
				if (print_debug_)
				{
					// cout << "[" << current << ", " << current->item << ", " << current->next << "]";

					// 주소를 짧은 정수로 출력 (앞 부분은 대부분 동일하기때문에 뒷부분만 출력)
					cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
						 << current->item << ", "
						 << reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
				}
				else
				{
					cout << current->item;
				}

				if (current->next)
					cout << " -> ";
				else
					cout << " -> NULL";

				current = current->next;
			}
			cout << endl;
		}
	}

protected:
	Node *first_ = nullptr;

	bool print_debug_ = false;
};