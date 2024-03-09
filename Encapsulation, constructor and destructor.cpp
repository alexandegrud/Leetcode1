#include <iostream>
#include <string>
using namespace std;


class cat {
	friend int main();
private:
	string sound = "meow meow";
public:
	string name = "Emi";
	int age = 4; 
	string breed = "Maine Coon";

	void voice() {
		cout << sound; 
	}
	cat() {
		cout << "Start work of constructor" << endl;
	}
	~cat() {
		cout << endl << "Start work of destructor"; 
	}
};

int main() {
	cat cat; 
	
	cout << cat.name << endl << cat.age << endl << cat.breed << endl;
	cat.voice(); 

}