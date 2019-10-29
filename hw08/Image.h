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

    void createImageDataArray(const char* fileName);
    void write_JPEG_file (const char* filename, int quality);


    virtual ~Image();
};


#endif