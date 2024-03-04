#include <iostream>
using namespace std;


double answer(double a) {
	return round(a); 
}

string answer(string a) {
	return "Well, what do you want from me"; 
}

string answer(int a) {
	return "The number is already an integer"; 
}



int main() {
	cout << answer(2.7) << endl;
	cout << answer("World") << endl;
	cout << answer(1);

}