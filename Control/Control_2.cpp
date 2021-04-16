#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	//Convierte de string a int
	string cadena;
	getline(cin, cadena);
  istringstream salida(cadena);
	int num;
	salida >> num;
	cout << num;
}