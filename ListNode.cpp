template <class T>
class ListNode {
public:
	T Value;
	ListNode<T>* Next;
	ListNode<T>* Previous;
	ListNode(T value = nullptr, ListNode<T>* prev = nullptr, ListNode<T>* next = nullptr) {
		Value = value;
		Next = next;
		Previous = prev;
	}
};