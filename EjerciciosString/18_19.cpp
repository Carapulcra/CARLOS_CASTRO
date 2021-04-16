#include <iostream>
#include <string>
using namespace std;

//Ejercicio 18.19
string insertar(string palabra){
	string nuevo = palabra;
	nuevo.insert(palabra.length()/2,"******");
	return nuevo;	
}

int main() {
  cout << insertar("holas");
}