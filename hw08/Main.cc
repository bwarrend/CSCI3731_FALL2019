#include <iostream>
#include "Image.h"


int main(){

    Image img;
    std::cout << "got here";
    img.createImageDataArray("test.ppm");
    std::cout << "and here";
    img.write_JPEG_file("Jpeg_copy.jpeg", 100);
    std::cout << "no chance";




    return 0;
}