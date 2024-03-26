#include <iostream>
using namespace std; 


class Myvector {
public:
	int* array; 
	size_t size = 0; 
	size_t capacity;


	Myvector(int i) {
		if (i < 0) {
			cout << "invalid value"; 
			return;
		}
		capacity = i;
		array = new int[i]; 
	}
	Myvector() = default; 

	~Myvector() {
		if ( capacity != 0) {
			delete[] array; 
		}
	}

	Myvector(const Myvector& other) {
		size = other.size;
		capacity = other.capacity;
		array = new int[other.size];
		for (size_t i = 0; i < other.size; i++) {
			array[i] = other.array[i];
		}
	}

	Myvector& operator = (const Myvector& other) {
		size = other.size;
		capacity = other.capacity;
		if (array != nullptr) {
			delete[] array;
		}
		array = new int[other.size];
		for (size_t i = 0; i < other.size; i++) {
			array[i] = other.array[i];
		}
		return *this;
	}

	bool operator ==(const Myvector& other) {
		if (size != other.size || capacity != other.capacity) {
			return false;
		}
		for (size_t i = 0; i < size; i++) {
			if (array[i] != other.array[i]) {
				return false;
			}
			if(size == i + 1) {
				return true;
			}
		}
	}

	bool operator!=(const Myvector& other) {
		if (size != other.size || capacity != other.capacity) {
			return true;
		}
		for (size_t i = 0; i < size; i++) {
			if (array[i] != other.array[i]) {
				return true;
			}
			if (size == i + 1) {
				return false;
			}
		}
	}
	
	void push_back(int val) {
		if (size == capacity) {
			capacity = capacity * 2;
			int* temp = new int[capacity]; 
			for (size_t i = 0; i < size; i++) {
				temp[i] = array[i];
			}
			delete[] array; 
			array = temp; 
			
		}
		array[size] = val;
		size++;
	}
	void push_front(int val) {
		if (size == 0) {
			array[0] = val;
			size++;
			return;
		}
		if (size == capacity) {
			capacity = capacity * 2; 
			int* temp = new int[capacity];
			for (size_t i = 0; i < size; i++) {
				temp[i] = array[i];
			}
			delete[] array;
			array = temp;
		}
		int t = array[size - 1];
		for (size_t i = size - 1; i > 0; i--) {
			array[i] = array[i - 1];
		}
		array[0] = val;
		size++;
		array[size - 1] = t;
			
		
	}
	void pop_front() {
		if (size == 0) {
			cout << "There are no elements to delete, size = 0";
			return;
		}
		for (size_t i = 1; i < size ; i++) {
			array[i - 1] = array[i]; 
		}
		size--;
	}

	void pop_back() {
		if (size == 0) {
			cout << "There are no elements to delete, size = 0";
			return;
		}
		size--; 
	}

	void insert(int pos, int val) {
		if (pos < 0 || pos > size) {
			cout << "Invalid value of position";
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

	void remove_if(int begin, int end, int val) {
		if (begin < 0 || begin > size || end > size || begin > end) {
			cout << "Invalid value" << endl;
			return;
		}
		for (size_t i = begin; i < end; i++) {
			if (array[i] == val) {
				for (size_t j = i; j < size - 1; j++) {
					swap(array[j], array[j + 1]);
				}
			}
		}
		size--; 
	}

	void remove(int begin, int end) {
		if (begin < 0 || begin > size || end > size || begin > end) {
			cout << "Invalid value" << endl; 
			return;
		}
		for (size_t i = begin; i < end; i++) {
			swap(array[i], array[size - 1]);
			size--;
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
	cout << "Push_back First test:" << endl;
	Myvector v(4);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.print();
}

void Test2() {
	cout << "Push_back test:" << endl; 
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
	cout << "Pop_back:" << endl; 
	Myvector v(2);
	v.push_back(0);
	v.push_back(1); 
	v.pop_back();
	v.print(); 
}

void Test4() {
	cout << "Push_front:" << endl;
	Myvector v(3);
	v.push_front(1); 
	v.push_front(2);
	v.push_front(3);
	v.push_front(4);
	v.print();
}

void Test5() {
	cout << "Push_front:" << endl;
	Myvector v(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_front(4);
	v.print();
}

void Test6() {
	cout << "Pop_front:" << endl; 
	Myvector v(4);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.pop_front();
	v.print();
}

void Test7() {
	cout << "Insert:" << endl;
	Myvector v(4);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.insert(2, 10);
	v.print();
}

void Test8() {
	cout << "Remove_if:" << endl; 
	Myvector v(4);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.remove_if(0, 3, 2);
	v.print();
}

void Test9() {
	cout << "Remove:" << endl; 
	Myvector v(5);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.remove(1, 3); 
	v.print(); 
}

void Test10() {
	cout << "Copy class:" << endl;
	Myvector v(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	Myvector b(v);
	b.push_back(4);
	b.print(); 
}

void Test11() {
	cout << "The Assignment operator:" << endl;
	Myvector v(4);
	v.push_back(1);
	v.push_back(2);
	Myvector a(3);
	a.push_back(9);
	a.push_back(10);
	Myvector c(1);
	c.push_front(10000); 
	v = a = c; 
	v.print();
	cout << endl;
	a.print();
}

void Test12() {
	cout << "Pop_back when size 0:" << endl;
	Myvector v(0);
	v.pop_back();
}

void Test13() {
	cout << "Pop_front when size 0:" << endl;
	Myvector v(0);
	v.pop_front();
}

void Test14() {
	cout << "Insert when position > size:" << endl;
	Myvector v(0); 
	v.insert(1, 1);
}

void Test15() {
	cout << "Insert when position < 0:" << endl;
	Myvector v(0);
	v.insert(-1, 1);
}

void Test16() {
	cout << "Remove when begin < 0:" << endl;
	Myvector v(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.remove(-1, 2);
}

void Test17() {
	cout << "Remove when begin > end" << endl;
	Myvector v(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.remove(3, 2);
}

void Test18() {
	cout << "Remove when begin or end > size" << endl;
	Myvector v(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.remove(4, 5);
}

void Test19() {
	cout << "Negative value:" << endl;
	Myvector v(-2);
}

void Test20() {
	cout << "Comparison of class objects:" << endl;
	Myvector v(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	Myvector b(3);
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);

	bool result = v == b;
	cout << result;
}

void Test21() {
	cout << "Comparison of class when other size or capacity:" << endl;
	Myvector v(3);
	v.push_back(1);
	v.push_back(2);
	
	Myvector b(3);
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);

	bool result = v == b;
	cout << result;
}

void Test22() {
	cout << "Comparison of class when (!=):" << endl;
	Myvector v(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	Myvector b(3);
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);

	bool result = v != b;
	cout << result;
}

void Test23() {
	cout << "Comparison of class when (!=):" << endl;
	Myvector v(2);
	v.push_back(1);
	v.push_back(2);

	Myvector b(3);
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);

	bool result = v != b;
	cout << result;
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
	cout << endl;
	Test8(); 
	cout << endl;
	Test9();
	cout << endl;
	Test10();
	cout << endl;
	Test11();
	cout << endl;
	Test12();
	cout << endl;
	Test13();
	cout << endl;
	Test14();
	cout << endl;
	Test15();
	cout << endl;
	Test16();
	cout << endl;
	Test17();
	cout << endl;
	Test18();
	cout << endl;
	Test19();
	cout << endl;
	Test20();
	cout << endl;
	Test21();
	cout << endl;
	Test22();
	cout << endl;
	Test23();
}


