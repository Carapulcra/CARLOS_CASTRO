#include <iostream>
#include <string> 
using namespace std;

int mod(int a, int n){ //Función módulo 
	if(a>0){ //Caso positivo
		int q = a/n;
		int r = a-(q*n);
		return r;
	}
	else if(a<0){ //Caso negativo
		int q = a/n - 1;
		int r = a - (q*n);
		return r;
	}
	else return 0; // Si a = 0
}

string alfabeto = "abcdefghijklmnopqrstuvwxyz"; //Alfabeto como string universal porque es conocido por todos

class Cesar{
    private:
    int clave; //Clave privada
    public:
    Cesar(int _clave){
        clave = _clave; //Clave en el constructor
    }
    string cifrar(string original){ //Función de cifrado
        string cifrado;
        for(int i = 0; i < original.length(); i++){
            cifrado += alfabeto[mod(alfabeto.find(original[i])+clave,alfabeto.length())];
            //En la función módulo, paso la posición de la letra que se encuentra en original[i]
            //en el alfabeto, más la clave; y en el otro argumento paso el tamaño del alfabeto 
            //para efectuar la operación, concatenando el resultado al valor nuevo
        }
        return cifrado; //Retorna el mensaje cifrado
    }
    string descifrar(string recibido){ //Función de descifrado
        string descifrado;
        for(int i = 0; i < recibido.length(); i++){
            descifrado += alfabeto[mod(alfabeto.find(recibido[i])-clave,alfabeto.length())];
            //Misma operación que el cifrado, pero ahora se resta la clave para retornar
            //al valor original
        }
        return descifrado; //Retorna el mensaje descifrado
    }
};

void vulnerar_cesar(string cifrado){ //Función que trata de romper el cifrado Cesar, con alfabeto conocido
    int clave = 1; //Inicializo la clave en 1 pues es el primer posible valor
    while(clave < alfabeto.length()){ //Va hasta la clave 25
        string descifrado;
        for(int i = 0; i < cifrado.length(); i++){
            descifrado += alfabeto[mod(alfabeto.find(cifrado[i])-clave,alfabeto.length())];
            //Misma función de descifrado de la clase Cesar, pero siendo iterada múltiples veces
            //para hallar el mensaje original sin especificar la clave
        }
        cout << descifrado << " (clave = "<< clave << ")" << endl;
        //Iimprime cada posibilidad, buscando algún retorno con sentido
        clave++;
    }
}

int main(){
    string mensaje = "zanahoria"; //Mensaje original
    Cesar a(4);
    Cesar b(4);
    string cifrado = a.cifrar(mensaje);
    cout << "Cifrado: " <<cifrado << endl; //Mensaje cifrado
    string descifrado = b.descifrar(cifrado);
    cout << "Descifrado: " <<descifrado << endl; //Mensaje descifrado
    cout << "Rompimiento del cifrado: " << endl; 
    vulnerar_cesar(cifrado); //Vulneración
}
