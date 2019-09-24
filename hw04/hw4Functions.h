#ifndef HW4FUNCTIONS_H
#define HW4FUNCTIONS_H

unsigned char* createImageDataArray(char fileName[], int* wdith, int* height);
void writeImage(unsigned char* imageDataArray, int width, int height, const char fileName[]);

//Just for fun
unsigned char* greenify(unsigned char* imageDataArray, int length);
unsigned char* redify(unsigned char* imageDataArray, int length);
unsigned char* blueify(unsigned char* imageDataArray, int length);
unsigned char* greyscale(unsigned char* imageDataArray, int length);

#endif