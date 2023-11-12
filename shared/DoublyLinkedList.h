#pragma once

#include <cassert>
#include <stdint.h>
#include <algorithm>

template <typename T>
class DoublyLinkedList
{
public:
	struct Node
	{
		T item = T();

		Node *left = nullptr;
		Node *right = nullptr;

		// 참고: prev/next가 아니라 left/right
	};

	DoublyLinkedList()
	{
	}

	DoublyLinkedList(const DoublyLinkedList &list)
	{
		Node *current = list.first_;
		while (current)
		{
			this->PushBack(current->item);
			current = current->right;
		}
	}

	~DoublyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		while (first_)
			PopFront();
	}

	bool IsEmpty()
	{
		return first_ == nullptr;
	}

	int Size()
	{
		int size = 0;

		// TODO:
		Node *current = first_;

		while (current)
		{
			size++;
			current = current->right;
		}

		return size;
	}

	void Print()
	{
		using namespace std;

		Node *current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << endl;

			cout << " Forward: ";
			// TODO:
			while (1)
			{
				cout << current->item << ' ';

				if (!current->right)
					break;

				current = current->right;
			}
			cout << endl;

			cout << "Backward: ";
			// TODO:
			while (1)
			{
				cout << current->item << ' ';

				if (!current->left)
					break;

				current = current->left;
			}
			cout << endl;
		}
	}

	Node *Find(T item)
	{
		Node *current = first_;
		while (current)
		{
			if (current->item == item)
				return current;
			else
				current = current->right;
		}
		return nullptr; // TODO:
	}

	void InsertBack(Node *node, T item)
	{
		if (IsEmpty())
		{
			PushBack(item);
		}
		else
		{
			// TODO:
			Node *current = first_;

			while (current != node)
				current = current->right;

			Node *next = current->right;

			Node *temp = new Node;
			temp->item = item;

			current->right = temp;
			temp->left = current;
			temp->right = next;
			next->left = temp;
		}
	}

	void PushFront(T item)
	{
		// TODO:
		Node *n_node = new Node;
		n_node->item = item;
		n_node->right = first_;

		if (first_)
			first_->left = n_node;

		first_ = n_node;
		n_node->left = nullptr;
	}

	void PushBack(T item)
	{
		if (first_)
		{
			Node *getLast = first_;
			while (getLast->right)
				getLast = getLast->right;

			Node *temp = new Node;
			temp->item = item;
			temp->right = nullptr;
			temp->left = getLast;

			getLast->right = temp;
		}

		else
			PushFront(item);
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

		// TODO:
		Node *temp = first_;
		first_ = first_->right;
		if (first_)
			first_->left = nullptr;

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

		// TODO:
		Node *current = first_;
		Node *prev = nullptr;
		if (current->right)
		{
			while (current->right)
			{
				prev = current;
				current = current->right;
			}

			delete current;
			prev->right = nullptr;
		}
		else
		{
			delete first_;
			first_ = nullptr;
		}
	}

	void Reverse()
	{
		// TODO:
		if (IsEmpty())
			return;

		else
		{
			Node *current = first_;
			Node *prev = nullptr;

			while (current)
			{
				prev = current;
				current = current->right;

				std::swap(prev->left, prev->right);
			}

			first_ = prev;
		}
	}

	T Front()
	{
		assert(first_);

		return first_->item; // TODO:
	}

	T Back()
	{
		assert(first_);
		Node *current = first_;
		while (current->right)
			current = current->right;

		return current->item; // TODO:
	}

protected:
	Node *first_ = nullptr;
};