#pragma once
template<typename T>
class Forward_list
{
public:
	Forward_list();
	~Forward_list();

	T& operator[](const int index);
	int getSize();
	void pop_front();
	void clear();
	void push_front(T data);
	void InsertBefore(T data, int index);

private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data; //���� ����������� ����
		Node(T data = T(), Node* pNext = nullptr);
	};
	//���� ������ forward_list
	int Size;
	Node<T>* head;
};

template<typename T>
Forward_list<T>::Forward_list()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
Forward_list<T>::~Forward_list()
{
	clear();
}

template<typename T>
void Forward_list<T>::pop_front()
{
	Node<T>* temp = head; //������� ��������� ������, ���������� ����� ������ ������
	head = head->pNext; //����������� �������� �� ������ ������ �������, ������ ������ �� ���
	delete temp; //������� ��������� ������
	Size--; //��������� ������ ������ �� �������
}

template<typename T>
void Forward_list<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
void Forward_list<T>::push_front(T data)
{
	head = new Node<T>(data, head); //�������� � ������ ����� ������� � ����������� �� ������� ������ ������
	Size++;
}

template<typename T>
T& Forward_list<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head; //current ��������� �� ������ ������
	while (current != nullptr) //���� current �� ����� ��������� �� ��������� �������
	{
		if (counter == index)
		{
			return current->data; //���� �������� �������� ��������� � �������� ���������� ��������, �� ���������� ���� �������
		}
		current = current->pNext; //�������� �������� ����������� ����� ���������� ��������
		counter++; //������� � ��������� �������� �����
	}
}

template<typename T>
inline int Forward_list<T>::getSize() { return Size; }

template<typename T>
void Forward_list<T>::InsertBefore(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}