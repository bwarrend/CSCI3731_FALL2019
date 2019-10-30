#ifndef IMAGE_H
#define IMAGE_H

//Class Image
//
//
class Image {

private:

    int width;
    int height;
    unsigned char* imageDataArray;    

public:

    Image();
    Image(Image&& img);
    Image(const Image& img);

    void createImageDataArray(std::string fileName);
    void writeJPEG (std::string fileName, int quality);
    void writePPM(std::string fileName);

    Image& operator=(Image&& img);
    Image& operator=(const Image& img);

    Image& operator++();


    virtual ~Image();
};


#endif