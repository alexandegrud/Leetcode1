#include <iostream>
using namespace std; 


class Myvector {
public:
	int* array; 
	size_t size = 0; 
	size_t capacity;


	Myvector(int i) {
		capacity = i;
		array = new int[i]; 
	}
	Myvector() = default; 
	
	void push_back(int val) {
		if (size == capacity) {
			capacity = capacity * 2;
			array[size] = val;
			size++; 
		}
		else {
			array[size] = val;
			size++; 
		}
	}
	void push_front(int val) {
		if (size == capacity) {
			capacity = capacity * 2; 
			int t = array[size - 1]; 
			for (size_t i = 0; i < size; i++) {
				array[i + 1] = array[i];
			}
			array[0] = val;
			size++;
			array[size - 1] = t;
		}
		else {
			for (size_t i = 0; i < size ; i++) {
				array[i + 1] = array[i];
			} 
			array[0] = val;
			size++;
			
		}
	}
	void pop_front() {
		for (size_t i = 1; i < size ; i++) {
			array[i - 1] = array[i]; 
		}
		size--;
	}

	void pop_back() {
		size--; 
	}

	void insert(int pos, int val) {
		if (pos < 0 || pos > size) {
			return;
		}
		else {
			push_back(val);
			int t;
			for (size_t i = size - 1; i > pos; i--) {
				t = array[i - 1];
				array[i - 1] = array[i];
				array[i] = t;
			}
		}
	}

	void remove(int begin, int end, int val) {
		int t;
		for (size_t i = begin; i < end; i++) {
			if (array[i] == val) {
				for (size_t j = i; j < size; j++) {
					t = array[j + 1];
					array[j + 1] = array[j];
					array[j] = t;
				}
			}
		}
		size--; 
	}

	void print () {
		for (size_t i = 0; i < size; i++) {
			cout << array[i] << " "; 
		}
	}
};
void Test1()
{
	Myvector v(4);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.print();
}

void Test2() {
	Myvector v(3);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.print();
}

void Test3() {
	Myvector v(2);
	v.push_back(0);
	v.push_back(1); 
	v.pop_back();
	v.print(); 
}

void Test4() {
	Myvector v(2);
	v.push_front(1); 
	v.push_front(2);
	v.push_front(3);
	//v.push_front(4);
	v.print();
}

void Test5() {
	Myvector v(4);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.pop_front();
	v.print();
}

void Test6() {
	Myvector v(4);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.insert(0, 10);
	v.print();
}

void Test7() {
	Myvector v(4);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.remove(0, 3, 2);
	v.print();
}




int main() {

	Test1();
	cout << endl;
	Test2(); 
	cout << endl;
	Test3(); 
	cout << endl;
	Test4();
	cout << endl;
	Test5(); 
	cout << endl;
	Test6();
	cout << endl;
	Test7(); 
	
	
	
}


