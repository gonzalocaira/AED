#include "sparse_matrix_.h"
#include <fstream>
#include <string>
#define cimg_display 0
#include "CImg.h"
using namespace cimg_library;

class Compress_Image{
  private:
    IndexE Iwidth;
    IndexE Iheight;|
    char * filename;
    char * compressFile;
  public:
    SparseMatrixL<int>* Matrix;
  public:
    Compress_Image(char * _filename, char * output):compressFile(output), filename(_filename){ //el constructor comprime la imagen en 1s y 0s
      CImg<unsigned char> Image(filename);
      Iwidth = Image.width();
      Iheight = Image.height();
      std::cout << "rows: " << Iheight << " columns: " << Iwidth << std::endl;
      Matrix = new SparseMatrixL<int>(Iheight, Iwidth);
      IndexE i,j;
      for (i = 0; i < Iheight; ++i){
        for (j = 0; j < Iwidth; ++j){
          if ((int)Image(j,i,0,0) != 255 )
            Matrix->add(1,i,j);
        }
      }

      std::ofstream file(compressFile);
      Matrix->print(file);
    }
    char* getCompressFile() {return compressFile;}
    void visualization(char *); //imagen usa txt para visualizar la imagen
};
void Compress_Image::visualization(char * _filename){
  std::ifstream file(_filename);
  std::string character;
  CImg<float> Image(Iwidth, Iheight, 1, 3, "255,255,255", true);
  int i,j;
  std::cout << "rows: " << Iheight << " columns: " << Iwidth << std::endl;
  for (i = 0; i < Iheight; ++i){
    for (j = 0; j < Iwidth; ++j){
      file>>character;
      if(character == "1"){
        Image(j,i,0,0) = 0;
        Image(j,i,0,1) = 0;
        Image(j,i,0,2) = 0;
      }
    }
  }
  Image.display();
}
