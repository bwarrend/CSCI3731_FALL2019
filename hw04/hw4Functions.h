#ifndef HW4FUNCTIONS_H
#define HW4FUNCTIONS_H

int** createImageDataArray2D( int* width, int* height);
void writeCopyImage(int** imageDataArray2D, const int width, const int height, const char* fileName);
int** blueify(int** imageDataArray2D, int width, int height);
int** greenify(int** imageDataArray2D, int width, int height);
int** redify(int** imageDataArray2D, int width, int height);

#endif