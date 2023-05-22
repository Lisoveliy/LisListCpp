#include "ListNode.cpp"

template <class T>
class List {
	ListNode<T>* MainNode;
	int Length;
	ListNode<T>* GetNode(int index) {
		auto temp = MainNode;
		for (int i = 0; i < index; i++) {
			temp = temp->Next;
		}
		return temp;
	}
public:
	List() {
		MainNode = nullptr;
		Length = 0;
	}
	~List() {
		int len = Length;
		auto nextnode = MainNode;
		for(int i = 0; i < len; i++)
		{
			delete nextnode->Previous;
			nextnode = nextnode->Next;
		}
	}
	/*
	 *	Delete List
	 */
	void Del(int index) {
		auto temp = GetNode(index);
		if (temp->Next != nullptr)
			temp->Next->Previous = temp->Previous;
		if (temp->Previous != nullptr)
			temp->Previous->Next = temp->Next;
		delete temp;
		Length--;
	}
	/*
	 *	Update List
	 */
	 //Add in end of the list
	void Add(T value) {
		if (MainNode == nullptr) {
			MainNode = new ListNode<T>(value);
			return;
		}
		ListNode<T>* temp = MainNode;
		while (temp->Next != nullptr)
		{
			temp = temp->Next;
		}
		temp->Next = new ListNode<T>(value, temp);
		Length++;
	}
	//Add value into index
	void Push(int index, T value) {
		ListNode<T>* oldNode = GetNode(index);
		ListNode<T>* newNode = new ListNode<T>(value, oldNode->Previous, oldNode);
		if (oldNode->Previous != nullptr)
		{
			oldNode->Previous->Next = newNode;
		}
		else {
			MainNode = newNode;
		}
		oldNode->Previous = newNode;
		Length++;
	}
	//Set list value by index
	void Set(int index, T value) {
		ListNode<T>* temp = GetNode(index);
		temp->Value = value;
	}
	/*
	 *	Read List
	 */
	T Get(int index) {
		ListNode<T>* temp = GetNode(index);
		return temp->Value;
	}
	int Size() {
		return Length;
	}
	void RemoveEven() {
		int counter = 0;
		ListNode<T>* temp = MainNode;
		Length++;
		while (temp != nullptr) {
			auto next = temp->Next;
			if (counter % 2 == 0) {
				if (temp == MainNode) {
					MainNode = next;
					next->Previous = nullptr;
				}
				else if (temp->Previous != nullptr)
				{
					temp->Previous->Next = next;
					if (next != nullptr)
						next->Previous = temp->Previous;
				}
				Length--;
			}
			counter++;
			temp = next;
		}
	}
	void Insert(int index, List<T>* Insertion) {
		for (int i = index; i < Insertion->Size() + index; i++) {
			Push(i, Insertion->Get(i - index));
		}
	}
	void BubbleSort() {
		bool sorted = false;
		while (!sorted)
		{
			for (int i = 0; i < Size(); i++) {
				auto node = GetNode(i);
				if (node->Next != nullptr)
					if (node->Value > node->Next->Value) {
						T temp = node->Value;
						node->Value = node->Next->Value;
						node->Next->Value = temp;
					}
			}
			sorted = true;
			for (int i = 0; i < Size(); i++) {
				auto node = GetNode(i);
				if (node->Next != nullptr)
					if (node->Value > node->Next->Value) {
					sorted = false;
				}
			}
		}
	}
};