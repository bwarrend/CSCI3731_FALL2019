#include <iostream>
#include "Image.h"
#include <string>


int main(){

    Image img;
    const std::string FILE_NAME = "test";
    const std::string FILE_SUFFIX = ".ppm";
    const int JPEG_QUALITY = 90;

    img.createImageDataArray(FILE_NAME+FILE_SUFFIX);

    img.writeJPEG(FILE_NAME, JPEG_QUALITY);
    img.writePPM(FILE_NAME);

    Image newimg;
    newimg = img;
    
    newimg.writeJPEG("newimg", JPEG_QUALITY);

    Image& imgRef = img;
    Image newerimg = Image(imgRef);

    newimg.writeJPEG("newerimg", JPEG_QUALITY);
    
    //newimg.writeJPEG("newimg", JPEG_QUALITY);
    img.writeJPEG("oldimg", JPEG_QUALITY);

    ++img;

    img.writeJPEG("stretch", JPEG_QUALITY);
    
    ++img;

    img.writeJPEG("extrastretchy", JPEG_QUALITY);

    --newimg;
    newimg.writeJPEG("shrunk", JPEG_QUALITY);
    

    
    //Just making it easier on myself to test program out several times.
    //
    std::cout << "Remove copies? (WARNING: system call)  [y/N]: ";
    std::string a = "no";
    getline(std::cin, a);    
    if(a == "y" || a == "Y" || a == "yes" || a == "YES"){
        system("rm test.jpeg test_copy.ppm oldimg.jpeg newimg.jpeg newerimg.jpeg stretch.jpeg extrastretchy.jpeg shrunk.jpeg");
    }  
    //
    //

    return 0;
}