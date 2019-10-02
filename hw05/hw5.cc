#include <cstdio>

#include "hw5Func.h"





int main()
{
	int width = 0;
	int height = 0;
	unsigned char* imageDataArray;

	imageDataArray = createImageDataArray("test.ppm", &width, &height);
	write_JPEG_file ("copy.jpeg", 100, imageDataArray, width, height);

	delete[] imageDataArray;
	imageDataArray = NULL;

	
	return 0;

}

