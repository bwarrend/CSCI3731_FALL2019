#ifndef HW4FUNC_H
#define HW5FUNC_H

void clearArray(unsigned char* deleteMe);
unsigned char* createImageDataArray(const char* fileName, int* width, int* height);
void write_JPEG_file (const char* filename, int quality, unsigned char* image_buffer, int image_width, int image_height);
unsigned char* blueify(unsigned char* imageDataArray, int width, int height);
unsigned char* redify(unsigned char* imageDataArray, int width, int height);
unsigned char* greenify(unsigned char* imageDataArray, int width, int height);
unsigned char* greyScale(unsigned char* imageDataArray, int width, int height);



#endif