#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

string alfabeto = "abcdefghijklmnopqrstuvwxyz";

int mod(int a, int n){
	if(a>0){
		int q = a/n;
		int r = a-(q*n);
		return r;
	}
	else if(a<0){
		int q = a/n - 1;
		int r = a - (q*n);
		return r;
	}
	else return 0;
}

int euclides(int a, int b){
	int r1 = a;
	int r2 = b;
	while(r2 != 0){
		int q = r1/r2;
		int r = r1 - q*r2;
		r1 = r2;
		r2 = r;
		if(r == 1){
			return r;
		}
	}
	return r1;
}

int euclides_extendido_inversa(int a, int b){
	//Euclides extendido que devuelve la inversa 
	int s, t;
	int r1 = a;
	int r2 = b;
	int s1 = 1;
	int s2 = 0;
	int t1 = 0;
	int t2 = 1;
	while(r2 != 0){
		int q = r1/r2;
		int r = r1 - q*r2;
		s = s1 - q*s2;
		t = t1 - q*t2;
		r1 = r2; 
		r2 = r;
		s1 = s2;
		s2 = s;
		t1 = t2;
		t2 = t;
	}
	return s1;
}

int inversa(int a, int b){
	int aux = euclides_extendido_inversa(a, b);
	//Como es posible que el número sea negativo, sacamos módulo
	//para estar seguros de que será positivo
	int inv = mod(aux,b);
	return inv;
}

class Afin{
	private:
	int a;
	int b;

	public:
	Afin(){ //Emisor
		GenerarClaves();
	}

	Afin(int a1, int b1){ //Receptor
		a = inversa(a1,alfabeto.length());
		b = b1;
	}

	int get_a(){ //Importante para saber la clave
		return a;
	}

	int get_b(){ //Importante para saber la clave
		return b;
	}
	
	void GenerarClaves(){
		srand(time(NULL));	
		a = rand()%20;
		while(euclides(a, alfabeto.length())!=1){
			a = rand()%20;
		}
		b = rand()%20;
	}

	string cifrar(string mensaje){
		string cifrado;
		for(int i = 0; i < mensaje.length();i++){
			int pos = alfabeto.find(mensaje[i]);
			pos = mod((a*pos + b),alfabeto.length());
			cifrado += alfabeto[pos];
		}
		return cifrado;
	}

	string descifrar(string mensaje_cifrado){
		string descifrado;
		for(int i = 0; i < mensaje_cifrado.length();i++){
			int pos = alfabeto.find(mensaje_cifrado[i]);
			pos = mod((a*(pos-b)),alfabeto.length());
			descifrado += alfabeto[pos];
		}
		return descifrado;
	}
};

int main(){
	string mensaje = "zanahorias";
  Afin a;
	Afin b(a.get_a(),a.get_b());
	cout << "Cifrado: " <<a.cifrar(mensaje) << endl;
	cout << "Descifrado: " <<b.descifrar(a.cifrar(mensaje));
}