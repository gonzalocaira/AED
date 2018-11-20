#include<fstream>
#include<iostream>
typedef unsigned int IndexE;
template<class T>
class NodeE{
  public:
    NodeE<T>* p_row;
    NodeE<T>* p_column;
    T data;
    IndexE row;
    IndexE column;
    NodeE(T d, IndexE r, IndexE c): data(d), row(r), column(c), p_row(0), p_column(0) {}
};
template<class T>
class SparseMatrixL{
  private:
    NodeE<T>** array_row;
    NodeE<T>** array_column;
    IndexE rows;
    IndexE columns;
  public:
    SparseMatrixL(IndexE r, IndexE c): rows(r), columns(c){
      array_row = new NodeE<T>*[rows];
      array_column = new NodeE<T>*[columns];
      for(IndexE j = 0; j < rows; ++j)
        array_row[j] = 0;
      for(IndexE i = 0; i < columns; ++i)
        array_column[i] = 0;
    }
    void add(T, IndexE, IndexE);
    bool findRow(IndexE, IndexE, NodeE<T>**&);
    bool findColumn(IndexE, IndexE, NodeE<T>**&);
    void print(std::ostream &);
};
template<class T>
bool SparseMatrixL<T>::findRow(IndexE r, IndexE c, NodeE<T>**& p){
  p = &(array_column[c]);
  while(*p){
    if ((*p)->row == r) return true;
    if ((*p)->row > r) return false;
    p = &((*p)->p_row);
  }
  return false;
}
template<class T>
bool SparseMatrixL<T>::findColumn(IndexE r, IndexE c, NodeE<T>**& p){
  p = &(array_row[r]);
  while(*p){
    if ((*p)->column == c) return true;
    if ((*p)->column > c) return false;
    p = &((*p)->p_column);
  }
  return false;
}
template<class T>
void SparseMatrixL<T>::add(T d, IndexE r, IndexE c){
  NodeE<T>** p_c;
  bool ifc= findColumn(r, c , p_c);
  NodeE<T>** p_r;
  bool ifr = findRow(r, c , p_r);
  if(!ifc){
    NodeE<T>* new_node = new NodeE<T>(d, r, c);
    new_node->p_column = *p_c;
    new_node->p_row = *p_r;
    *p_c = *p_r = new_node;
  }
}
template<class T>
void SparseMatrixL<T>::print(std::ostream &o){
  NodeE<T> ** ptr;
  int i,j;
  for (i = 0; i < rows; ++i){
    o << '\n';
    for(j = 0; j < columns; ++j)
      if(findRow(i,j,ptr))
        o << (*ptr)->data << " ";
      else
        o << "0 ";
  }
}
