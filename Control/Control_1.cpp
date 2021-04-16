#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  cout << "Ingrese cadena: "; //a
	string cadena; getline(cin, cadena);
	cout << endl;
	cout << "Ingrese tamaño de bloques: "; //b
	int tam; cin >> tam;
	string guardado;
	vector<string> vec(0);
	for(int i = 0; i < cadena.length();i=i+tam){ //c
		string aux = cadena.substr(i,tam);
		if(aux.length()!=tam){
			for(int i = 0; i < tam - (cadena.length()%tam);i++){
				aux.push_back('X'); //d
			}
			guardado+=aux; //e
		}
		else{
			guardado+=aux; //e
			guardado+="*";
		}
		vec.push_back(aux); //f
		cout << aux << endl;
	}
	cout << "============================" << endl;
	cout << guardado << endl;
	cout << "============================" << endl;
	for(int i = 0; i < vec.size();i++){ //g
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << "============================" << endl;
}