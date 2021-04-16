#include <iostream>
#include <string>
using namespace std;

void ahorcado(string palabra){
	bool jugar = true;
	int jugadas = 0;
	int cont = 0;
	string palabra_secreta = palabra;
	string oculto = palabra;
	oculto.replace(0,oculto.length(),oculto.length(),'*');
	while(jugar){
		cout << "Adivine la palabra: " << oculto << endl;
		cout << "Diga una letra: "; char aux; cin >> aux;
		int veces = 0;
		for(int i = 0; i < palabra_secreta.length(); i++){
			if(aux == palabra_secreta[i]){
				oculto[i] = aux;
				veces++;
			}
		}
		jugadas++;
		if(veces == 0){
			cout << "Intento Fallido" << endl;
			cont++;
			switch(cont){
				case 1:
				cout << " O" << endl; 
				break;
				case 2:
				cout << " O" << endl;
				cout << "/" << endl; 
				break;
				case 3:
				cout << " O" << endl;
				cout << "/|" << endl;
				break;
				case 4:
				cout << " O" << endl;
				cout << "/|\\" << endl;
				break;
				case 5:
				cout << " O" << endl;
				cout << "/|\\" << endl;
				cout << " |" << endl;
				break;  						
				case 6:
				cout << " O" << endl;
				cout << "/|\\" << endl;
				cout << " |" << endl;
				cout << "/" << endl;
				break;
				case 7:
				cout << " O" << endl;
				cout << "/|\\" << endl;
				cout << " |" << endl;
				cout << "/ \\" << endl;
				cout << "Ahorcado" << endl;
				break;		
			}
		}
		if(oculto == palabra_secreta || cont == 7){
			cout << "Intentos: " << jugadas <<endl;
			if(oculto == palabra_secreta) cout << "Felicidades!!! Adivino mi palabra. Desea jugar otra vez? Y/N ";
			else if(cont == 7) cout << "Perdio. Desea jugar otra vez? Y/N ";
			char respuesta; cin >> respuesta;
			if(respuesta == 'y' || respuesta == 'Y'){
				jugar = true;
				cont = 0;
				palabra_secreta = palabra;
				oculto = palabra;
				oculto.replace(0,oculto.length(),oculto.length(),'*');
			}
			else if(respuesta == 'n' || respuesta == 'N'){
				cout << "Gracias por jugar";
				jugar = false;
			}
		}				
	}
}

int main() {
  ahorcado("perro");
}