#pragma once
template <typename T>
class List
{
public:
	List <T>();
	~List <T>();

	int getSize() { return Size; }

	void clear();
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();
	void erase(int index);

	T& operator [] (const int index);

private:
	template <typename T>
	class Node
	{
	public:
		T data;
		Node* pNext;
		Node* pPrev;
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	int Size;
	Node <T>* head;
	Node <T>* tail;
};

template <typename T> List <T>::List()
{
	head = nullptr;
	tail = nullptr;
	Size = 0;
}

template <typename T> List <T>::~List()
{
	clear();
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template <typename T>
void List <T>::push_front(T data)
{
	if (Size > 1)
	{
		Node <T>* temp = head; //��������� �� ������ ������
		head = new Node <T>(data, temp, tail); //� ������ ������ ��������� �������
	   	temp->pPrev = head; //��������, ������� ����� temp, ������������� ������ �� ������ ������
		tail->pNext = head;
	}
	else if (Size == 1)
	{
		head = new Node <T>(data, tail, tail); //��������� �������
		tail->pPrev = tail->pNext = this->head; //���������� � ��������� ������� � tail = head
	}
	else if (Size == 0)
	{
		head = tail = new Node <T>(data); //��������� ����� �������, ���������� "�������" � "������� ������"
		head->pNext = head;
		head->pPrev = head;
	}
	Size++;
}

template <typename T>
void List <T>::push_back(T data)
{
	if (Size > 1)
	{
		Node <T>* temp = tail; //��������� �� ����� ������
		tail = new Node <T>(data, nullptr, tail);
		temp->pNext = tail;
	}
	else if (Size == 1)
	{
		tail = new Node <T>(data, nullptr, tail);
		head->pNext = this->tail;
	}
	else if (Size == 0)
	{
		head = tail = new Node <T>(data, head, tail);
	}
	Size++;
}

template <typename T>
void List <T>::pop_front()
{
	if (Size > 1)
	{
		Node <T>* temp = head;
		head = head->pNext;
		head->pPrev = tail;
		tail->pNext = head;
		delete temp;
	}
	else if (Size == 1)
	{
		Node <T>* temp = head;
		head = tail = nullptr;
		delete temp;
	}
	Size--;
}

template <typename T>
void List <T>::pop_back()
{
	if (Size > 1)
	{
		Node <T>* temp = tail; //������� ��������� ������, ���������� ������ �� tail 
		tail = tail->pPrev; //tail ����������� ������ �� �������, ������ ����� ���
		tail->pNext = head;
		head->pPrev = tail;
		delete temp;
	}
	else if (Size == 1)
	{
		Node <T>* temp = tail;
		head = tail = nullptr; //���� � ������ 1 �������, �� head = tail = nullptr
		delete temp;
	}
	Size--;
}


template <typename T>
void List <T>::erase(int index)
{
	if (index == 0)
	{
		pop_front();
		return;
	}
	else if (index + 1 == Size)
	{
		pop_back();
		return;
	}
	else if (index + 1 < Size)
	{
		Node<T>* current = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->pNext;
		}
		Node<T>* toDelete = current->pNext; //���������� ��������� ����������� ������ �� ��������� ������� ����� �������� ���������
		current->pNext = toDelete->pNext; //���������� ��������� ����������� ����� �� ��������� ������� ���������� ��������� ((current->pNext)->pNext)
		Node<T>* next = toDelete->pNext;
		delete toDelete; //������� ��������� ���������
		next->pPrev = current; //����������� �������� next ���������� ����� �� ������� �������
	}
	Size--;
}

template <typename T>
T& List <T>::operator[] (const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}