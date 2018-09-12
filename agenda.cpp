#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

template <class T>

class Datos{
public:
  Datos *siguiente;
  T DNI;
  T nombre;
  T direccion;
  T telefono;
  T edad;

  Datos(){
    DNI = NULL;
    nombre = NULL;
    direccion = NULL;
    telefono = NULL;
    edad = NULL;
    siguiente = NULL;
  }
  Datos(T dni, T nom, T dir,T tel, T eda){
    DNI = dni;
    nombre = nom;
    direccion = dir;
    telefono = tel;
    edad = eda;
    siguiente = NULL;
  }
};

template <class T>
class Agenda{
public:
  Datos<T> *primero;
  Datos<T> *ultimo;

  Agenda(){
    primero = ultimo=NULL;
  }

  bool esVacia(){
    if(primero != NULL) return false;
    //std::cout << "\nLA LISTA SE ENCUENTRA VACIA" << '\n';
    return true;
  }

  void insertar (T dni, T nom, T dir,T tel, T edad){
    Datos<T> *nuevo= new Datos<T>(dni,nom,dir,tel,edad);
    Datos<T> *aux = primero;

    if(esVacia()) {
      primero=ultimo=nuevo;
      std::cout << "\n El contacto se añadio correctamente" << '\n';
      return;
    };

    if ((primero->DNI == dni) || (ultimo->DNI == dni)) {

      std::cout << "\n No se ingreso el registro por coincidencia en el DNI" << '\n';
      return;

    }
    else{
      while ((aux->siguiente != NULL)&&(aux->DNI != dni)) {
        aux=aux->siguiente;
      }
      if(aux->DNI == dni) {
        std::cout << "\n No se ingreso el registro por coincidencia en el DNI" << '\n';
        return;
      }
      aux->siguiente=nuevo;
      ultimo=nuevo;
    }

    std::cout << "\n El contacto se añadio correctamente" << '\n';

  }



  void insertar_sin (T dni, T nom, T dir,T tel, T edad){
    Datos<T> *nuevo= new Datos<T>(dni,nom,dir,tel,edad);
    Datos<T> *aux = primero;

    if(esVacia()) {
      primero=ultimo=nuevo;
      //std::cout << "\n El contacto se añadio correctamente" << '\n';
      return;
    };

    if ((primero->DNI == dni) || (ultimo->DNI == dni)) {

      //std::cout << "\n No se ingreso el registro por coincidencia en el DNI" << '\n';
      return;

    }
    else{
      while ((aux->siguiente != NULL)&&(aux->DNI != dni)) {
        aux=aux->siguiente;
      }
      if(aux->DNI == dni) {
        //std::cout << "\n No se ingreso el registro por coincidencia en el DNI" << '\n';
        return;
      }
      aux->siguiente=nuevo;
      ultimo=nuevo;
    }

    //std::cout << "\n El contacto se añadio correctamente" << '\n';

  }

  void eliminar(T dato){
    Datos<T>*aux1=primero;
    Datos<T>*aux2=primero->siguiente;

    if(esVacia()){
      std::cout << "\n LA LISTA SE ENCUENTRA VACIA" << '\n';
      return;
    }

    if (primero->DNI ==dato){
      primero = aux1->siguiente;
      std::cout << "\n   CONTACTO ELIMNADO" << '\n';
      return;
    }

    else{
      while (aux2 != NULL) {

        if (aux2->DNI == dato){
          if(aux2==ultimo) ultimo=aux1;
          aux1->siguiente = aux2->siguiente;
          std::cout << "\n   CONTACTO ELIMNADO" << '\n';
          return;
        }
        aux1=aux1->siguiente;
        aux2=aux2->siguiente;
      }
    }
    std::cout << "\n EL CONTACTO NO EXISTE" << '\n';
  }

  bool buscar( T dato){
    Datos<T> *aux=primero;

    if(esVacia())return false;

    while (aux != NULL) {
      if (aux->DNI == dato){
        std::cout << "\n    Contacto Encontrado" << '\n';
        std::cout << "\nDNI del Contacto : "<< aux->DNI << '\n';
        std::cout << "NOMBRE del Contacto : "<< aux->nombre << '\n';
        std::cout << "DIRECCION del Contacto : "<< aux->direccion << '\n';
        std::cout << "TELEFONO del Contacto : "<< aux->telefono<< '\n';
        std::cout << "EDAD del Contacto : "<< aux->edad << '\n';
        return true;
      }
      aux=aux->siguiente;
    }
    //std::cout << "no esta" << '\n';
    return false;
  }

  void mostrar(){
    Datos<T> *temp = primero;
    if (esVacia()) return;

    while (temp!=NULL) {
      cout << " "<<temp->DNI<<" - "<<temp->nombre<<" - " <<temp->direccion<<" - " <<temp->telefono<<" - " <<temp->edad <<'\n';
      temp=temp->siguiente;
    }

    //std::cout << "el primer dato es :"<< primero->nombre << '\n';
    //std::cout << "el ultimo dato es :"<< ultimo->nombre << '\n';
  }



  void imprimir_R(Datos<T> *  p, ostream & os)
    {
        if(!p)return ;
        os<<p->DNI<<endl;
        os<<p->nombre<<endl;
        os<<p->direccion<<endl;
        os<<p->telefono<<endl;
        os<<p->edad<<endl;
        os<<"-------------"<<endl;
        return imprimir_R(p->siguiente,os);

    }


  friend ostream & operator<<(ostream & os, Agenda<T> & L)
   {
       L.imprimir_R(L.primero,os);
       return os;
   }


   void leer_archivo(){

     T linea,dni,nom,dir,tel,eda;

     ifstream in;
     in.open("Contactos2.txt");

     in >> linea;
     while (!in.eof()) {
         if (linea=="-------------"){
             in >> linea;
         }
         else{
           //std::cout << "no hay lineas" << '\n';

           for(int i=0;i<5;i++){
             if (i==0) dni=linea;
             else if (i==1) nom=linea;
             else if (i==2) dir=linea;
             else if (i==3) tel=linea;
             else if (i==4) eda=linea;
             in >> linea;
           }
           insertar_sin(dni,nom,dir,tel,eda);
           in >> linea;

         //std::cout << linea << '\n';
           //insertar_fin(linea);
           //in >> linea;
         }
     }
     in.close();
   }



};

int main() {
  string dni, nom, dir, tel,ed, dato;
  ofstream F("Contactos.txt");
  Agenda<string> ag1;

  int opcion;

  do {
    system("cls");
    std::cout << "\n         BIENVENIDO " << '\n';
    std::cout << "\n1.- Ingresar Contacto" << '\n';
    std::cout << "2.- Buscar Contacto" << '\n';
    std::cout << "3.- Eliminar Contacto" << '\n';
    std::cout << "4.- Mostrar Contactos" << '\n';
    std::cout << "5.- Cargar Contactos a un archivo externo" << '\n';
    std::cout << "6.- Cargar Contactos desde un archivo externo" << '\n';
    std::cout << "0.- Salir" << '\n';
    std::cout << "\nIngrese la opcion deseada : ";
    std::cin >> opcion;

    switch (opcion) {
      case 0:// para salir del dato
        std::cout << "\n HASTA LUEGO" << '\n';
        break;
      case 1:
        std::cout << "\nIngrese el DNI       : ";
        std::cin >> dni;
        if(dni.length()!=8){ //agregar condicion para que sean solo numeros
          std::cout << "\nEl dni ingresado es incorrecto" << '\n';
          getch();
          break;
        }

        std::cout << "Ingrese el nombre    : " ;
        std::cin >> nom;

        std::cout << "Ingrese la direccion : ";
        std::cin >> dir;

        std::cout << "Ingrese el telefono  : " ;
        std::cin >> tel;

        std::cout << "Ingrese la edad      : " ;
        std::cin >> ed;

        ag1.insertar(dni,nom,dir,tel,ed);

        getch();
        break;

      case 2:
        if(ag1.esVacia()){
          std::cout << "\n   LA LISTA SE ENCUENTRA VACIA" << '\n';
          getch();
          break;
        }

        std::cout << "\nIngrese el DNI del contacto : ";
        std::cin >> dni;
        if (ag1.buscar(dni)){
          getch();
          break;
        }
        std::cout << "\n El DNI no existe " << '\n';
        getch();
        break;

      case 3:
        if(ag1.esVacia()){
          std::cout << "\n   LA LISTA SE ENCUENTRA VACIA" << '\n';
          getch();
          break;
        }
        std::cout << "\nIngrese el DNI del contacto a eliminar : " << '\n';
        std::cin >> dni;
        ag1.eliminar(dni);
        getch();
        break;

      case 4:
        if(ag1.esVacia()){
          std::cout << "\n   LA LISTA SE ENCUENTRA VACIA" << '\n';
          getch();
          break;
        }

        std::cout << "\n    DNI   -   NOMBRE   -    DIRECCION      -   TELEFONO -  EDAD" << '\n';
        std::cout << '\n';
        ag1.mostrar();
        getch();
        break;

      case 5:
        if(ag1.esVacia()){
          std::cout << "\n   LA LISTA SE ENCUENTRA VACIA" << '\n';
          getch();
          break;
        }

        F<<ag1;
        std::cout << "\n    CARGA DE ARCHIVO CORRECTA" << '\n';
        getch();
        break;

        case 6:
          ag1.leer_archivo();
          std::cout << "\n   ARCHIVO CARGA" << '\n';
          getch();
          break;

      default:
        std::cout << "\n    LA OPCION INGRESADA ES INCORRECTA" << '\n';
        getch();
        break;
    }

  } while(opcion != 0);

  return 0;
}
