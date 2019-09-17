#ifndef HW3FUNCTIONS_H
#define HW3FUNCTIONS_H

int headerReader(char fileName[], int* wdith, int* height);
unsigned char* imageDataToArray(char fileName[], int length);
void createImageCopy(unsigned char* imageDataArray, int length);

#endif