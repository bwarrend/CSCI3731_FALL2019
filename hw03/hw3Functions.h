#ifndef HW3FUNCTIONS_H
#define HW3FUNCTIONS_H

unsigned char* createImageDataArray(char fileName[], int* wdith, int* height);
void createImageCopy(unsigned char* imageDataArray, int*width, int* height);
void greenify(unsigned char* imageDataArray, int* width, int*height);
void redify(unsigned char* imageDataArray, int* width, int*height);
void blueify(unsigned char* imageDataArray, int* width, int*height);
void greyScale(unsigned char* imageDataArray, int* width, int* height);

#endif