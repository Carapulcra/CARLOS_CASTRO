#include <iostream>
#include <string>
using namespace std;
//Ejercicio 18.7 a)
string cifrar_rot13(string mensaje){
	string alfabeto = "abcdefghijklmnopqrstuvwxyz";
	string cifrado;
	for(int i = 0; i < mensaje.length();i++){
		int agregar = alfabeto.find(mensaje[i]) + 13;
		if(agregar>25){
			agregar = agregar%26;
		}
		cifrado = cifrado + alfabeto[agregar];		
	}
	return cifrado;
}

//Ejercicio 18.7 b)
string descifrar_rot13(string mensaje_c){
	string alfabeto = "abcdefghijklmnopqrstuvwxyz";
	string descifrado;
	for(int i = 0; i < mensaje_c.length();i++){
		int agregar = alfabeto.find(mensaje_c[i]) - 13;
		if(agregar<0){
			agregar = 26 + agregar;
		}
		descifrado = descifrado + alfabeto[agregar];		
	}
	return descifrado;
}

/*Ejercicio 18.7 c) 
	Yo creo que haciendo uso de las posiciones. Es común que el formato de una palabra sea consonante, vocal, consonante. Identificamos las que podrían ser vocales y en el alfabeto vemos la distancia entre estas para tener mayor probabilidad de encontrar las vocales y así la clave.
*/

int main(){
	string cifrado = cifrar_rot13("holazanahoria");
  cout << cifrado << endl;
	string descifrado = descifrar_rot13(cifrado);
}