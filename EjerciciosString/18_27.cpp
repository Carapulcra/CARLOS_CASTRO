#include <iostream>
#include <string>
using namespace std;

void ordenamientoSeleccion( string [], const int, bool (*)(string,string));
bool ascendente(string, string);
bool descendente(string, string);

int main(){
  const int tamanioArreglo = 10;
  int orden;
  int contador;
  string a[tamanioArreglo]={"armario","luna","rosa","rosario","cemento","pared","sala","lima","jaguar","mesa"};
  cout<<"Escriba 1 para orden ascendente" << endl << "Escriba 2 para orden descendente: ";
  cin>>orden;
  cout<<"Elementos de datos en el orden original:" << endl;

  for(contador=0;contador<tamanioArreglo;contador++){
    cout << a[contador] <<"  ";
	}
	cout << endl;
  if(orden == 1){
    ordenamientoSeleccion(a, tamanioArreglo, ascendente);
    cout<<"Elementos datos en orden ascendente:" << endl;
  }
  else if(orden == 2){
    ordenamientoSeleccion(a,tamanioArreglo,descendente);
    cout<<"<Elementos en orden descendente:" << endl;
  }

  for(contador=0;contador<tamanioArreglo;contador++){
    cout << a[contador]<<"  ";
	}
  cout<<endl;

  return 0;
}

void ordenamientoSeleccion(string trabajo[], const int tamanio, bool (*compara)(string,string))
{
  int menorOMayor;
  for(int i=0; i<tamanio-1;i++)
  {
    menorOMayor=i;
    for(int index=i+1;index<tamanio; index++)
      if(!(*compara)(trabajo[menorOMayor],trabajo[index]))
        menorOMayor = index;

    trabajo[menorOMayor].swap(trabajo[i]);
  }
}

bool ascendente(string a, string b)
{
  return a<b;
}

bool descendente(string a, string b)
{
  return a>b;
}