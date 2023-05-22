#include <iostream>
#include "List.cpp"
#include <string>

int main()
{
	List<int> TestList = *new List<int>();
	srand(time(0));
	int size = 10;
	std::cout << "Generating rand list: " << size << std::endl;
	for (int i = 0; i <= size; i++) {
		TestList.Add(rand());
	}
	std::cout << "Showing list: " << std::endl;
	for (int i = 0; i < TestList.Size(); i++) {
		std::cout << "Element " << i+1 << ": " << TestList.Get(i) << std::endl;
	}
	std::cout << "Element pushed at 0 with 110 number" << std::endl;
	TestList.Push(0, 110);
	std::cout << "Element pushed at 1 with 111 number" << std::endl;
	TestList.Push(1, 111);
	std::cout << "Element pushed at 2 with 112 number" << std::endl;
	TestList.Push(2, 112);
	std::cout << "Element deleted at 3 index" << std::endl;
	TestList.Del(3);
	std::cout << "Showing list: " << std::endl;
	for (int i = 0; i < TestList.Size(); i++) {
		std::cout << "Element " << i + 1 << ": " << TestList.Get(i) << std::endl;
	}
	std::cout << "Removing Even" << std::endl;
	TestList.RemoveEven();
	std::cout << "Showing list: " << std::endl;
	for (int i = 0; i < TestList.Size(); i++) {
		std::cout << "Element " << i + 1 << ": " << TestList.Get(i) << std::endl;
	}
	std::cout << "Creating second list" << std::endl;
	List<int> SecondList = *new List<int>();
	for (int i = 0; i <= 3; i++) {
		SecondList.Add(rand());
		SecondList.Get(i);
	}
	std::cout << "Showing second list: " << std::endl;
	for (int i = 0; i < SecondList.Size(); i++) {
		std::cout << "Element " << i + 1 << ": " << SecondList.Get(i) << std::endl;
	}
	std::cout << "Insert second list to first list at 2 index" << std::endl;
	TestList.Insert(2, &SecondList);
	std::cout << "Showing list: " << std::endl;
	for (int i = 0; i < TestList.Size(); i++) {
		std::cout << "Element " << i + 1 << ": " << TestList.Get(i) << std::endl;
	}
	std::cout << "Sorting list" << std::endl;
	TestList.BubbleSort();
	std::cout << "Showing list: " << std::endl;
	for (int i = 0; i < TestList.Size(); i++) {
		std::cout << "Element " << i + 1 << ": " << TestList.Get(i) << std::endl;
	}
}