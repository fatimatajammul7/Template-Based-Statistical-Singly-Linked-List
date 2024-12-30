#include<iostream>
using namespace std;

template<class T>
class Singly_Linked_List;

template<class T>
class Node
{
private:
	T data;
	Node* next;
public:
	template <class T>
	friend class Singly_Linked_List;
	template <class T>
	friend T Range(Singly_Linked_List<T> );
	template <class T>
	friend T Median(Singly_Linked_List<T> );
	template <class T>
	friend T Mode(Singly_Linked_List<T> );
	Node()
	{
		next = NULL; 
	}
	
	Node(T d, Node<T>* n=0)
	{
		data=d;
		next=n;
	}
	~Node()
	{
		if(next)
			next=NULL;
	}
};

template<class T>
class Singly_Linked_List
{

public:
	template <class T>
	friend T Range(Singly_Linked_List<T> );
	template <class T>
	friend T Median(Singly_Linked_List<T> );
	template <class T>
	friend T Mode(Singly_Linked_List<T> );
	Singly_Linked_List()
	{ 
		head = 0;
		tail= 0; 
		size=0;
	}
	~Singly_Linked_List()
	{ 
		Node<T>* temp=head;
		for(; temp->next!=0;temp=temp->next)
		{
			head=temp->next;
			delete temp;
			temp=head;
		}
		tail=NULL;
		
	}

	Singly_Linked_List(const Singly_Linked_List<T>& rhs)
	{
		size=rhs.size;
		head=new Node<T>(rhs.head->data,0);
		Node<T>*ptr=rhs.head;
		Node<T>* ptr2=head;

		while(ptr->next!=0)
		{
			ptr2->next= new Node<T>(ptr->next->data,0);
			ptr2=ptr2->next;
			ptr=ptr->next;

		}
		tail=ptr2;
	}
	void insertAtStart(T const element);
	void print() const;
	void Sort();
	void insertAtEnd(T const element );
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
};


template<class T>
void Singly_Linked_List<T>::print() const
{
	Node<T>* TempPtr=head;
	for(; TempPtr!=0; TempPtr=TempPtr->next)
	{
		cout<<TempPtr->data<<" ";
	}
	cout<<endl;
}

template<class T>
void Singly_Linked_List<T>::insertAtStart(T const element)
{
	Node<T>* TempPtr=new Node<T>(element, head);
	head=TempPtr;
	if (tail==0)
		tail=head;
	size++;
}

template<class T>
void Singly_Linked_List<T>::insertAtEnd(T const element)
{
	Node<T>* TempPtr=new Node<T>(element, NULL);
	if(tail!=NULL)
	{
		tail->next=TempPtr;
		tail=TempPtr;
	}
	if(head==NULL)
	{
		head=TempPtr;
	}
	size++;
}

template<class T>
void Singly_Linked_List<T>::Sort()
{
	Node<T>* Temp=0;
	Node<T>* FirstPtr=head;
	Node<T>* SecondPtr=head;
	for(int i=0; i<size-1; i++)
	{
		FirstPtr=head;
		SecondPtr=FirstPtr->next;
		for(int j=0; j<size-1-i; j++)
		{
			if(FirstPtr->data > SecondPtr->data)
			{
				int temp=FirstPtr->data;
				FirstPtr->data=SecondPtr->data;
				SecondPtr->data=temp;
			}
			if(SecondPtr->next!=0)
			{
				SecondPtr=SecondPtr->next;
				FirstPtr=FirstPtr->next;
			}
			
		}
	}
	return;
}

template<class T>
T Range(Singly_Linked_List<T> list)
{
	list.Sort();
	Node <T>* TempPtr=list.head;
	T Min=TempPtr->data;
	TempPtr=TempPtr->next;
	T Max=0;
	for(int i=1; i<list.size; i++)
	{
		Max=TempPtr->data;
		TempPtr=TempPtr->next;
	}
	return Max-Min;
}

template<class T>
T Median(Singly_Linked_List<T> list)
{
	list.Sort();
	int middleValue=list.size/2 + 1;
	T M;
	Node <T>* TempPtr=list.head;
	for(int i=0; i<middleValue; i++)
	{
		M=TempPtr->data;
		TempPtr=TempPtr->next;
	}
	return M;
}

template<class T>
T Mode(Singly_Linked_List<T> list)
{
	T digit, occurence, temp, mode;
	list.Sort();
	Node <T>* FirstPtr=list.head;
	Node <T>* SecondPtr=list.head;
	SecondPtr=SecondPtr->next;
	temp=1;
	occurence=1;
	for(int i=0; i<list.size-1; i++)
	{
		if(FirstPtr->data==SecondPtr->data)
		{
			if(i==0)
				temp++;
			occurence++;
			if(temp<=occurence)
			{
				temp=occurence;
				mode=FirstPtr->data;
			}
		}
		else
		{
			occurence=1;
		}
		if(SecondPtr->next!=0)
			SecondPtr=SecondPtr->next;
		if(FirstPtr->next!=0)
			FirstPtr=FirstPtr->next;
			
	}
	return mode;
}


int main()
{
	Singly_Linked_List<int> myList;
	myList.insertAtStart(90);
	myList.insertAtEnd(94);
	myList.insertAtEnd(53);
	myList.insertAtEnd(68);
	myList.insertAtEnd(79);
	myList.insertAtEnd(94);
	myList.insertAtEnd(53);
	myList.insertAtEnd(65);
	myList.insertAtEnd(87);
	myList.insertAtEnd(90);
	myList.insertAtEnd(70);
	myList.insertAtEnd(69);
	myList.insertAtEnd(65);
	myList.insertAtEnd(89);
	myList.insertAtEnd(85);
	myList.insertAtEnd(53);
	myList.insertAtEnd(47);
	myList.insertAtEnd(61);
	myList.insertAtEnd(27);
	myList.print();


	cout<<"Range:\t";
	cout<<Range(myList);
	cout<<endl;
	cout<<"Median:\t";
	cout<<Median(myList);
	cout<<endl;
	cout<<"Mode:\t";
	cout<<Mode(myList);
	cout<<endl;
	
	system("pause");
	return 0;
}