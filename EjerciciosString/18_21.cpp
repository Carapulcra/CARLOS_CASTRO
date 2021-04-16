#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//Ejercicio 18.21
void en_tokens(string texto){
  char* nuevo = new char[texto.length()+1];
  texto.copy(nuevo, texto.length(),0);
  nuevo[texto.length()]='\0';
  char* p;
  p = strtok(nuevo," .,");
  while(nuevo!=NULL){
    cout<<nuevo<<endl;
    nuevo=strtok(NULL," .,");
  }
}
int main() {
  en_tokens("Hola, soy Carlos.");
}