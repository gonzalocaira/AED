#include "arbol.h"


template <typename T>
bool Tree<T>::find_R(T d,Nodo<T> *p){
  if(!p)return false;
  if(p->m_dato== d)return true;
  return find_R(d,p->m_pSon[p->m_dato<d]);
}
template <typename T>
bool Tree<T>::find_I(T d,Nodo<T> *p){
  if(!*p)return false;
  else{
    if((*p)->m_dato== d)return true;
    if((*p)->m_dato > d)return find_R(d,p->m_pSon[0]);
    if((*p)->m_dato < d)return find_R(d,p->m_pSon[1]);
    return false;
  }
}

template <typename T>
bool Tree<T>::find(T d){
  Nodo<T> *tmp=m_pRoot;
  if(tmp->m_dato== d)return true;
  tmp=tmp->m_pSig;
  while(tmp){
    if(tmp->m_dato==d)return true;
    //Esto reemplaza a los dos if de abajo
    //tmp=tmp->m_pSon[tmp->m_dato<d];
    if(tmp->m_dato>d)tmp=tmp->m_pSon[0];
    if(tmp->m_dato<d)tmp=tmp->m_pSon[1];
  }
  return false;
}
template <typename T>
bool Tree<T>::add_R(T d,Nodo<T> *&p){
      if(!p){p=new Nodo<T>(d);return true;}
      if(p->m_dato==d) return false;
      return add_R(d,p->m_pSon[p->m_dato<d]);
}
template <typename T>
void Tree<T>::add(T d){
  add_R(d,m_pRoot);
}
/*
template <typename T>
void Tree<T>::add_I(T d){
  Nodo<T> *p,*q;
  p=q=m_pRoot;
  while(p){
    q=p;
    if(p->m_dato==d) return;
    p=p->m_pSon[p->m_dato<d];
  }
  q->m_pSon[p->m_dato<d]=new Nodo<T>(d);
  if(!q)m_pRoot=q;
  //else if(q-)
}*/

template <typename T>
bool Tree<T>::find_E(T d,Nodo<T> **&p){
  p=&m_pRoot;
  while(*p){

    if((*p)->m_dato==d) return true;
    p=&((*p)->m_pSon[(*p)->m_dato<d]);
  }
  return false;
}

template <typename T>
void Tree<T>::show_pre(Nodo<T> *p) {
  if(!p) return;
  cout<<p->m_dato<<" ";
  show_pre(p->m_pSon[0]);
  show_pre(p->m_pSon[1]);
}

template <typename T>
void Tree<T>::show_pos(Nodo<T> *p) {
  if(!p) return;
  show_pos(p->m_pSon[0]);
  show_pos(p->m_pSon[1]);
  cout<<p->m_dato<<" ";
}

template <typename T>
void Tree<T>::show_in(Nodo<T> *p) {
  if(!p) return;
  show_in(p->m_pSon[0]);
  cout<<p->m_dato<<" ";
  show_in(p->m_pSon[1]);
}

template <typename T>
void Tree<T>::show(int q){
  if(q=1)show_pre(m_pRoot);
  else if(q=2)show_pos(m_pRoot);
  else if(q=3)show_in(m_pRoot);
}

template <typename T>
void Tree<T>::add_I(T d){
  Nodo<T> **q;
  //if(m_pRoot==NULL)m_pRoot=*q;
  if(find_E(d,q))return;
  *q=new Nodo<T>(d);
}

template<typename T>
int Tree<T>::altitude_R(Nodo<T> *p){
  if(!p)return 0;
  return max(altitude_R(p->m_pSon[0]),altitude_R(p->m_pSon[1]))+1;
}

template <typename T>
void Tree<T>::altitude()
{
  cout<<altitude_R(m_pRoot);
}

template <typename T>
void Tree<T>::print_R(Nodo <T> *p,ostream &os){
  if(!p){return ;}
  print_R(p->m_pSon[0],os);
  os<<p->m_dato<<" ";
  print_R(p->m_pSon[1],os);
}
template <typename T>
void Tree<T>::lectura() {

      FILE *archivo,*archivo2;
      //File *archivo2;

      char caracteres[100];

      archivo = fopen("English.txt","r");
      archivo2 = fopen("Spanish.txt","r");
      if (archivo == NULL)
        exit(1);
      else
            {
        //  cout<<"\nEl contenido del archivo de prueba es \n\n";
          while (feof(archivo) == 0)
          {
        fgets(caracteres,100,archivo);
        //add_I(caracteres);
        cout<<caracteres;
        add(caracteres);
          }
          char c[]={"nether"};
          //cout<<find(c);
            }
            fclose(archivo);
}


/*
void Tree<T>::lectura(){
        string contenido;
        string contenido2;
        cout << "Ingresa el nombre del archivo que quieres leer(sin el .txt): ";
        cin.ignore();
        getline(cin, contenido2);
        contenido2 += ".txt";
        ifstream fs(contenido2.c_str(), ios:: in );
        char linea[128];
        long contador = 0L;
        if (fs.fail())
          cerr << "El fichero no existe" << endl;
        else
          while (!fs.eof()) {
            fs.getline(linea, sizeof(linea));
            cout << linea << endl;
            if ((++contador % 24) == 0) {
              cout << "continuar...";
              cin.get();
            }
          }
fs.close();
}*/
int main(int argc, char const *argv[]) {
  /* code */
  Tree<int > Binary;
  //Binary.add_I(a);
  Binary.add_I(3);
  Binary.add_I(1);
  Binary.add_I(5);
  Binary.add_I(4);
  Binary.show(1);

  //Binary.lectura();
  //Binary.show(1);
  //char palabra[]={"hello"};
  //Binary.find(palabra);
  Binary.altitude();
  //ofstream F("file.txt");
  //F<<Binary;

  return 0;
}
