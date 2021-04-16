#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  //Convierte de int a string
	int a; cin >> a;
	ostringstream salida;
	salida << a;
	cout << salida.str();
}