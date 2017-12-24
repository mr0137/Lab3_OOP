#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>

#pragma warning (disable : 4996) 

using namespace std;

struct ListNode{
	char *str;
	ListNode* next;
	ListNode* prev;
};

typedef const ListNode* POSITION;

class StringList{
private:
	ListNode *Head;
	ListNode *Tail;
	ListNode *id;
	int List_size;
public:
	//Constructs an empty list for ListNode objects.
	 StringList(void);
	~StringList(void);

		//Head/Tail Access 
	const ListNode* GetHead();//Returns the head element of the list 
	const ListNode* GetTail();//Returns the tail element of the list 
	
		//Operations 
	//Adds an element to the head of the list (makes a new head).
	void AddHead(const char *value);
	//Adds all the elements in another list to the head of the list (makes a new head).
	void AddHead(const StringList *List);
	//Adds an element to the tail of the list (makes a new tail).
	void AddTail(const char *value);
	//Adds all the elements in another list to the tail of the list (makes a new tail).
	void AddTail(const StringList *List);
	//Removes all the elements from this list.
	void RemoveAll();
	//Removes the element from the head of the list.
	void RemoveHead();
	//Removes the element from the tail of the list.
	void RemoveTail();
 	void AppendExclusively(const StringList *List);
	void Splice(POSITION Where, StringList *List, POSITION first, POSITION last);
	//removes all duplicate elements
	void Unique();


		//Iteration 
	//Gets the next element for iterating.
	POSITION GetNext();
	//Gets the previous element for iterating.
	POSITION GetPrev();

	
		//Retrieval/Modification
	POSITION GetHeadPosition();


	//Gets the element at a given position.
	const char* GetAt(int count)const;
	//Removes an element from this list as specified by position.
	void RemoveAt(int count);
	//Sets the element at a given position.
	void SetAt(char *elem, int count);

		//Insertion 
	//Inserts a new element after a given position.
	void InsertAfter(char *elem, int count);
	//Inserts a new element before a given position.
	void InsertBefore(char *elem, int count);

		//Searching 
	//Gets the position of an element specified by string value.
	const ListNode* Find(const char *elem);
	//Gets the position of an element specified by a zero-based index.
	int FindIndex(char *elem)const;

		//Status 
	//Returns the number of elements in this list.
	int Getsize()const;
	//Tests for the empty list condition (no elements).
	bool IsEmpty()const;
	//Print node
	void Printnode(POSITION p);
	//Print all list
	void PrintList();
};
