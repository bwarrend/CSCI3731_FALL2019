#ifndef HW4FUNC_H
#define HW5FUNC_H

unsigned char* createImageDataArray(const char* fileName, int* width, int* height);
void write_JPEG_file (const char* filename, int quality, unsigned char* image_buffer, int image_width, int image_height);

#endif