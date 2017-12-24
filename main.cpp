#include "StrList.h"

int main()
{

	POSITION pos;
	StringList list1;
	StringList list2;
	StringList list3;

	cout << "AddTail(value):\n";
	list1.AddTail("I ");
	list1.AddTail("Love ");
	list1.AddTail("My ");
	list1.AddTail("Mommy! ");
	for (pos = list1.GetHeadPosition(); pos != nullptr; pos = list1.GetNext())
	{
			list1.Printnode(pos);
	}
	cout<<endl;
	cout <<"Size : "<< list1.Getsize() << " \n\n";

	cout << "AddHead(value):\n";
	list2.AddTail("Daddy! ");
	list2.AddHead("My ");
	list2.AddHead("Love ");	
	list2.AddHead("I ");
	list2.PrintList();
	cout << "Size : " << list1.Getsize() << " \n\n";

	cout << "AddTail(value):\n";
	list3.AddTail("You ");
	list3.AddTail("Are ");
	list3.AddTail("Cool, ");
	list3.AddTail("Daddy! ");
	list3.SetAt("Best, ", 2);
	list3.PrintList();
	cout << "Size : " << list1.Getsize() << " \n\n";

	cout << "AddHead(List):\n";
	list1.AddHead(&list2);
	list1.PrintList();
	cout << "Size : " << list1.Getsize() << " \n\n";

	cout << "AddTail(List):\n";
	list1.AddTail(&list2);
	list1.PrintList();
	cout << "Size : " << list1.Getsize() << " \n\n";

	cout << "RemoveTail(List):\n";
	list1.RemoveTail();
	list1.PrintList();
	cout << "Size : " << list1.Getsize() << " \n\n";

	cout << "RemoveHead(List):\n";
	list1.RemoveHead();
	list1.PrintList();
	cout << "Size : " << list1.Getsize() << " \n\n";

	cout << "RemoveAt(List):\n";
	list1.RemoveAt(3);
	list1.PrintList();
	cout << "Size : " << list1.Getsize() << " \n\n";

	cout << "AppendExclusively(List):\n";
	list1.AppendExclusively(&list3);
	list1.PrintList();
	cout << "Size : " << list1.Getsize() << " \n\n";

	cout << "Unique(List):\n";
	list1.Unique();
	list1.PrintList();
	cout << "Size : " << list1.Getsize() << " \n\n";

	cout << "InsertAfter('You, ', 0)" << endl;
	list1.InsertAfter("You, ", 0);
	list1.PrintList();
	cout << "Size : " << list1.Getsize() << " \n\n";

	cout << "InsertBefore(Love_my , 5)" << endl;
	list1.InsertBefore("Love_my ", 5);
	list1.PrintList();
	cout << "Size : " << list1.Getsize() << " \n\n";

	cout << "Splice(List):\n";
	list2.Splice(list2.GetHead()->next, &list1, list1.GetHead()->next, list1.GetTail()->prev->prev);
	cout << "list1 after Splice\n";
	list1.PrintList();
	cout << list1.Getsize() << " \n\n";

	cout << "list2 after Splice\n";
	list2.PrintList();
	cout << list2.Getsize() << " \n\n";
	cout<<endl;

	cout << "Find('Mommy!') : ";
	list2.Printnode(list2.Find("Mommy! "));

	cout << "Find('none') : ";
	list2.Printnode(list2.Find("none "));

	cout<<endl;
	cout << "Find_Index(Love ) =  " << list2.FindIndex("Love ") << endl << endl;

	cout << "All Good" << endl;

	system("pause");
	return 0;
}

