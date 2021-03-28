#include <iostream>
#include <string>
using namespace std;

class Emisor { //Creación de una clase que cifre el mensaje.
private:
	int clave[2] = { 3,4 }; //Clave para cifrar el mensaje.
public:
	string cifrar(string mensaje) { //Función que cifra el mensaje y devuelve un string.
		string cifrado;
		string auxiliar = mensaje; //No manipulamos el mensaje original, más bien lo copiamos en una variable temporal.
		auxiliar.resize(clave[0] * clave[1], ' '); //Como el tamaño del mensaje es menor o igual al generado por la clave, redimensiono el string para poder trabajar con él.
		for (int i = 0; i < clave[1]; i++) { //Este doble for es mejor explicado en la imagen adjunta.
			for (int j = i; j < auxiliar.size(); j = j + clave[1]) {
				cifrado.push_back(auxiliar[j]);
			}
		}
		return cifrado; //Retorna el cifrado.
	}

};

class Receptor {
private:
	int clave[2] = { 3,4 }; //Clave para descifrar el mensaje.
public:
	string descifrar(string mensaje_cifrado) { //Función que descifra el mensaje y devuelve un string.
		string descifrado;
		string auxiliar = mensaje_cifrado; //No manipulamos el mensaje recibido, más bien lo copiamos en una variable temporal.
		for (int i = 0; i < clave[0]; i++) { //Este doble for es mejor explicado en la imagen adjunta.
			for (int j = i; j < auxiliar.size(); j = j + clave[0]) {
				descifrado.push_back(auxiliar[j]);
			}
		}
		return descifrado; //retorna el mensaje descifrado.
	}

};

int main() {
	string mensaje = "hola amigos";
	Emisor a;
	Receptor b;
	cout << "Cifrado: " << a.cifrar(mensaje) << endl;
	cout << "Descifrado: " << b.descifrar(a.cifrar(mensaje)) << endl;
}
