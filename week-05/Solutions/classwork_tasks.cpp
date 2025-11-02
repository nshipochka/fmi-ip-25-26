#include <iostream>

// Task 1
void shiftRight(int arr[], int& size, int shiftPosition) {
	if (shiftPosition < 0 || shiftPosition > size - 1) {
		std::cout << "Invalid index";
		return;
	}

	for(int i = size - 1; i >= shiftPosition; --i) {
		arr[i] = arr[i - 1];
	}
	size++;
}

void insertElement(int arr[], int& size, int position, int newElement) {
	shiftRight(arr, size, position);
	arr[position] = newElement;
}

void removeElement(int arr[], int& size, int position) {
	if (position < 0 || position > size - 1) {
		std::cout << "Invalid index";
		return;
	}
	for (int i = position; i < size; ++i) {
		arr[i] = arr[i + 1];
	}
	size--;
}

// Task 2
void insertEvenElements(int arr1[], int arr2[], int size1, int& size2) {
	for (int i = 0; i < size1; i += 2) {
		arr2[size2] = arr1[i];
		size2++;
	}
}

// Task 3
void changeValue(int* a) {
	*a += 5;
}

void changeValueRef(int& a) {
	a += 5;
}

// Task 4
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swapPtr(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	
	int a = 4;
	int* ptr1 = &a;
	int* ptr2 = ptr1;
	changeValue(ptr2);

	const int capacity = 100;
	int arr[capacity];
	// size
	// i < size
	// cin >> arr[i]
	
	// size + 1 <= capacity

	// insert element

	// capacity < even numbers count
	// insert even elements
	return 0;
}