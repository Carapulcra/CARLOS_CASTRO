#include <iostream>
#include <string>
using namespace std; 

//Ejercicio 18.11
string concatenar_nombre(string nombre, string apellido){
	return nombre+" "+apellido; 
}

int main() {
  concatenar_nombre("Carlos","Castro");
}