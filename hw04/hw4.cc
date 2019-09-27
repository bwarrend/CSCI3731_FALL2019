#include <cstdio>
#include "hw4Functions.h"




int main(int argc, char** argv)
{
    int width = 0, height = 0;

    int** imageDataArray2D = createImageDataArray2D(&width, &height);

    writeCopyImage(imageDataArray2D, width, height, "copy.ppm");


    delete[] *imageDataArray2D;
    delete[] imageDataArray2D;

    return 0;
}