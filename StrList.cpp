#include "StrList.h"

StringList::StringList()
{
	Head = nullptr;
	Tail = nullptr;
	List_size = 0;
}

StringList::~StringList()
{  
	if (Head == nullptr)
		return;

	while (Head->next != nullptr)
	{
		Head = Head->next;
		delete[] Head->prev->str;
		delete[] Head->prev;
	
	}
	
	if (Head->str != nullptr)
	{
		delete[] Head->str;
	}
	delete[] Head;

}

const ListNode * StringList::GetHead()
{
	return Head;
}

const ListNode * StringList::GetTail()
{
	return Tail;
}

void StringList::AddHead(const char *value)
{
	if (value == nullptr)
	{
		return;
	}
	ListNode *temp = new ListNode;
	temp->str = new char[strlen(value) + 1];
	strcpy(temp->str, value);
	List_size++;

	if (Head == nullptr)
	{
		Head = temp;
		temp->prev = nullptr;
		Tail = Head;
		Tail->next = nullptr;
	}
	else
	{
		Head->prev = temp;
		temp->next = Head;
		Head = temp;
	}
	Head->prev = nullptr;
}

void StringList::AddHead(const StringList *List)
{
	if (List->Head == nullptr || List->Tail == nullptr || List == nullptr)
	{
		return;
	}
	ListNode *temp;
	temp = List->Tail;
	while(temp != nullptr)
	{
		this->AddHead(temp->str);
		temp = temp->prev;
	}
	
}

void StringList::AddTail(const char *value)
{
	if(value == nullptr)
	{
		return;
	}
	ListNode *temp = new ListNode;
	temp->str = new char[strlen(value) + 1];
	strcpy(temp->str, value);
	List_size++;

	if (Head == nullptr)
	{
		Head = temp;
		temp->prev = nullptr;
		Tail = Head;
	}
	else
	{
		Tail->next = temp;
		Tail->next->prev = Tail;
		Tail = Tail->next;
	}
	Tail->next = nullptr;
	Head->prev = nullptr;
}

void StringList::AddTail(const StringList *List)
{
	if(List->Head == nullptr || List->Tail == nullptr || List == nullptr)
	{
		return;
	}
	ListNode *temp;
	temp = List->Head;
	while (temp != nullptr)
	{
		this->AddTail(temp->str);
		temp = temp->next;
	}
}

void StringList::RemoveAll()
{
	if (Head == nullptr)
		return;

	while (Head->next != nullptr)
	{
		Head = Head->next;
		delete[] Head->prev->str;
		delete[] Head->prev;
	}
	delete[] Head->str;
	delete[] Head;

	Head = nullptr;
	Tail = nullptr;
	List_size = 0;
}

void StringList::RemoveHead()
{
	if (Head != nullptr)
	{
		delete[] Head->str;
		Head = Head->next;
		delete[] Head->prev;
		List_size--;
	}
}

void StringList::RemoveTail()
{
	if (Tail != nullptr)
	{
		delete[] Tail->str;
		Tail = Tail->prev;
		delete[] Tail->next;
		Tail->next = nullptr;
		List_size--;
	}
}

void StringList::AppendExclusively(const StringList *List)
{
	ListNode *temp;
	ListNode *second_temp;
	int i;
	bool Check;
	i = List->List_size;
	temp = List->Head;
	
	while ( temp != nullptr)
	{
		second_temp = Head;
		Check = false;
		while(second_temp != nullptr)
		{
			if ((strcmp(temp->str,second_temp->str) == 0))
			{
				Check = true;
			}
			second_temp = second_temp->next;
		}
		if (Check == false)
		{
			this->AddTail(temp->str);
			Check = true;
		}
		temp = temp->next;
	}
}

void StringList::Splice(POSITION Where, StringList *List, POSITION first, POSITION last)
{
	ListNode *ptr1, *ptr2;
	int k = 0, l = 0;
	if (Where == nullptr)
	{
		return;
	}

	if (List->IsEmpty() == false)
	{
		if (first == nullptr || last == nullptr) return;
		ptr1 = Head;
		ptr2 = (ListNode*)List->GetHeadPosition();
		while (ptr2 != (ListNode*)first)
		{
			l++;
			ptr2 = (ListNode*)List->GetNext();
		}
		while (ptr1 != Where)
		{
			k++;
			ptr1 = ptr1->next;
		}
		while (ptr2 != last)
		{
			this->InsertAfter(ptr2->str, k);
			ptr2 = (ListNode*)List->GetNext();
			List->RemoveAt(l);
		}

	}
}

void StringList::Unique()
{
	ListNode *current = Head, *current2 = Head, *buffer;
	if (List_size != 1 || List_size != 0)
	{
		while (current2 != nullptr)
		{
			current = current2;

			while (current->next != nullptr)
			{
				if (strcmp(current2->str, current->next->str) == 0)
				{
					buffer = current->next->next;
					delete[] current->next;
					current->next = buffer;
					if (buffer != nullptr)
					{
						buffer->prev = current;
					}
					List_size--;
					continue;
				}
				current = current->next;
			}
			current2 = current2->next;
		}
		current->next = nullptr;
	}
}

POSITION StringList::GetNext()
{
	if (id != nullptr)
		id = id->next;
	return POSITION(id);
}

POSITION StringList::GetPrev()
{
	if (id != nullptr)
		id = id->prev;
	return POSITION(id);
}

POSITION StringList::GetHeadPosition()
{
	id = Head;
	return POSITION(Head);
}

const char * StringList::GetAt(int count) const
{
	ListNode *temp = Head;
	int i = 0;
	while (i < count)
	{
		temp = temp->next;
		i++;
		if (temp == nullptr)
		{
			return "NULL";
		}
	}
	return temp->str;
}

void StringList::RemoveAt(int count)
{
	if (count > List_size || count < 0)
	{
		return;
	}
	int i = 0;
	ListNode *tail, *ptr1, *ptr2 = Head;

	while (i < count)
	{
		ptr2 = ptr2->next;
		i++;
	}
	tail = ptr2->prev;
	ptr1 = ptr2->next;
	if (tail == nullptr) {
		this->RemoveHead();
		return;
	}
	if (ptr1 == nullptr) {
		this->RemoveTail();
		return;
	}
	tail->next = ptr1;
	ptr1->prev = tail;
	List_size--;
	
	delete[] ptr2;
}

void StringList::SetAt(char * elem, int count)
{
	if (count > List_size || count < 0 || elem == nullptr)
	{
		return;
	}
	int i = 0;
	ListNode  *ptr = Head;
	while (i < count)
	{
		ptr = ptr->next;
		i++;
	}
	delete[] ptr->str;
	ptr->str = new char[strlen(elem) + 1];
	strcpy(ptr->str, elem);
}

void StringList::InsertAfter(char * elem, int n)
{
	if (elem == nullptr)
	{
		return;
	}
	int i;
	ListNode *ptr, *p;
	if (n < List_size && n >= 0)
	{
		ptr = Head;
		for (i = 0; i < n; i++)
			ptr = ptr->next;
		if (ptr->next != nullptr)
		{
			p = new ListNode;
			p->str = new char[strlen(elem) + 1];
			strcpy(p->str, elem);
			p->prev = ptr;
			p->next = ptr->next;
			ptr->next = p;
			p->next->prev = p;

			List_size++;
		}
		else
			this->AddTail(elem);
	}

}

void StringList::InsertBefore(char * elem, int n)
{
	if (elem == nullptr) return;
	int i;
	ListNode *ptr, *p;
	if (n < List_size && n >= 0)
	{
		ptr = Head;
		for (i = 0; i < n; i++)
			ptr = ptr->next;
		if (ptr->prev != nullptr)
		{
			p = new ListNode;
			p->str = new char[strlen(elem) + 1];
			strcpy(p->str, elem);
			p->next = ptr;
			p->prev = ptr->prev;
			ptr->prev = p;
			p->prev->next = p;

			List_size++;
		}
		else
			this->AddHead(elem);
	}

}

const ListNode * StringList::Find(const char * elem)
{
	if (elem == nullptr) return nullptr;
	ListNode * temp = Head;
	while (temp != nullptr) 
	{
		if (strcmp(temp->str, elem) == 0)
		{
			break;
		}
		temp = temp->next;
	}
	return temp;
}

int StringList::FindIndex(char *elem) const
{
	if (elem == nullptr) return -1;
	ListNode * temp = Head;
	int i = 0;
	while (temp != nullptr) 
	{
		if (strcmp(temp->str, elem) == 0)
		{
			return i;
		}
		i++;
		temp = temp->next;
	}
	return -1;
}

int StringList::Getsize() const
{
	return List_size;
}

bool StringList::IsEmpty() const
{
	return List_size == 0;
}

void StringList::Printnode(POSITION p)
{
	if (p == nullptr || p->str == nullptr)
	{		
			cout<< "NULL"<< endl;
			return;
	}
	cout << p->str << " ";
}

void StringList::PrintList()
{
	ListNode *temp = (ListNode*)GetHead();
	while (temp != nullptr) 
	{
		this->Printnode(temp);
		temp = temp->next;
	}
	cout << endl;
}

