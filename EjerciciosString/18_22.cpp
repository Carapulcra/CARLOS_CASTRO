#include <iostream>
#include <string>
using namespace std;

void imprimir_volteado(string palabra){
	for(int i = 0; i < palabra.length()/2; i++){
		char temp = palabra[i];
		palabra[i] = palabra[palabra.length()-1-i];
		palabra[palabra.length()-1-i] = temp;
	}
	cout << palabra;
}


int main() {
  imprimir_volteado("zanahoria");
}