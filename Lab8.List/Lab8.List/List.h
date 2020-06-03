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
	void InsertBefore(T data, int index);
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
		Node <T>* temp = head; //указывает на начало списка
		head = new Node <T>(data, head); //в начало списка добавл€ем элемент
		temp->pPrev = head; //элементу, идущему перед temp, присваиваетс€ ссылка на начало списка
	}
	else if (Size == 1)
	{
		head = new Node <T>(data, head); //добавл€ем элемент
		tail->pPrev = this->head; //предыдущий элемент у tail = head
	}
	else if (Size == 0)
	{
		head = tail = new Node <T>(data, head, tail); //добавл€ем новый элемент, €вл€ющийс€ "головой" и "хвостом списка"
	}
	Size++;
}

template <typename T>
void List <T>::push_back(T data)
{
	if (Size > 1)
	{
		Node <T>* temp = tail; //указывает на конец списка
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
		delete temp;
	}
	else if (Size == 1)
	{
		Node <T>* temp = head;
		head = tail = head->pNext;
		delete temp;
	}
	Size--;
}

template <typename T>
void List <T>::pop_back()
{
	if (Size > 1)
	{
		Node <T>* temp = tail; //создаем временный объект, содержащий ссылку на tail 
		tail = tail->pPrev; //tail присваиваем ссылку на элемент, идущий перед ним
		delete temp;
	}
	else if (Size == 1)
	{
		Node <T>* temp = tail;
		head = tail = tail->pPrev; //если в списке 1 элемент, то head = tail
		delete temp;
	}
	Size--;
}

template <typename T>
void List <T>::InsertBefore(T data, int index)
{
	if (index == 0)
		push_front(data);
	else
	{
		Node<T>* current = this->head;
		for (int i = 0; i < index - 1; i++) //цикл выполн€етс€ пока current не будет указывать на элемент, предшествующий элементу с выбранным индексом
		{
			current = current->pNext; //текущему элементу присваиваем адрес следующего
		}
		Node<T>* newNode = new Node<T>(data, current->pNext, current); //вставл€ем элемент
		current->pNext = newNode; //присваиваем полю "адрес" старого элемента адрес на новый элемент
		Node<T>* next = newNode->pNext; //указателю next присваиваем адрес следующего элемента, после вставленного в список
		next->pPrev = newNode; //предыдущему элементу у next приваиваетс€ адрес на вставленный элемент
	}
	Size++;
}

template <typename T>
void List <T>::erase(int index)
{
	if (index == 0)
		pop_front();
	else if (index + 1 < Size)
	{
		Node<T>* current = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->pNext;
		}
		Node<T>* toDelete = current->pNext; //временному указателю присваиваем ссылку на следующий элемент после текущего указател€
		current->pNext = toDelete->pNext; //следующему указателю присваиваем адрес на следующий элемент временного указател€ ((current->pNext)->pNext)
		Node<T>* next = toDelete->pNext;
		delete toDelete; //удал€ем временный указатель
		next->pPrev = current; //предыдущему элементу next приваиваем адрес на текущий элемент
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