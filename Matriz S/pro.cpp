#include<iostream>
#include<fstream>
#include<map>
using namespace std;

template<class T>
class NodoEs
{
	  public:
	  	T           m_Dato;
	  	NodoEs<T> * m_pSigFil;
	    NodoEs<T> * m_pSigCol;
	    int         m_Fil;
	    int         m_Col;
      public:
      	NodoEs(int x, int y, T D)
      	{
      		m_Dato = D;
      		m_Fil = x;
      		m_Col = y;
      	     m_pSigFil = m_pSigCol =0;

      	}

};

template<class T, int fil =5, int col=5>
class Matrix
{
   private:

      NodoEs<T> ** m_filas;
      NodoEs<T> ** m_columnas;
   public:
     Matrix()
     {
     	 m_filas = new NodoEs<T>    *[fil];
         m_columnas = new NodoEs<T> * [col];

     }


     bool find_fil(int f, int c, NodoEs<T> ** & p)
     {

     	p = &m_columnas[c];
     	while(*p)
     	{
     		if((*p)->m_Fil == f) return true;
     	    if((*p)->m_Fil > f) return false;
     	    p = &((*p)->m_pSigFil);

     	}
     	return false;

     }


     bool find_col(int f, int c, NodoEs<T> ** & p)
     {

     	p = &m_filas[f];
     	while(*p)
     	{
     		if((*p)->m_Col == c) return true;
     	    if((*p)->m_Col > c) return false;
     	    p = &((*p)->m_pSigCol);

     	}
     	return false;

     }

     void Add(int f, int c, T D)
     {
            NodoEs<T> ** p;
            NodoEs<T> ** q;
            bool ff = find_fil(f,c,q);
            bool cc = find_col(f,c,p);
            if(!cc && !ff)
            {
            	NodoEs<T> * pNuevo = new NodoEs<T>(f,c,D);
                pNuevo->m_pSigCol = *q;
                pNuevo->m_pSigFil = *p;
                *q = *p = pNuevo;

            }

     }

     void Print(ostream & os)
     {
     	    NodoEs<T> ** p;
           for(int i=0;i<fil;i++)
           {
           	 os<<endl;
             for(int j=0;j<col;j++)
             	if (find_col(i,j,p))
             		os<<(*p)->m_Dato<<" ";
             	else
     	            os<<"0 ";
     	    }
     }


};

typedef map< int, map<int, float> > TMatriz;

int main()
{
    TMatriz M;
    M[3][3] = 6.1;
   	return 1;
}
