#include "compress_file.h"

using namespace cimg_library;

int main() {
  Compress_Image File("cube.png",string("matrix.txt"));
  File.visualization(File.getCompressFile());

  return 0;
}
