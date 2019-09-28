#include <cstdio>
#include "hw4Functions.h"




int main(int argc, char** argv)
{
    int width = 0, height = 0;

    int** imageDataArray2D = createImageDataArray2D(&width, &height);

    writeCopyImage(imageDataArray2D, width, height, "copy.ppm");


    int** redArray = redify(imageDataArray2D, width, height);
    writeCopyImage(redArray, width, height, "copy_red.ppm");
    int** greenArray = greenify(imageDataArray2D, width, height);
    writeCopyImage(greenArray, width, height, "copy_green.ppm");
    int** blueArray = blueify(imageDataArray2D, width, height);
    writeCopyImage(blueArray, width, height, "copy_blue.ppm");    
    

    delete[] *imageDataArray2D;
    delete[] imageDataArray2D;
    delete[] *greenArray;
    delete[] greenArray;
    delete[] *blueArray;
    delete[] blueArray;
    delete[] *redArray;
    delete[] redArray;


    return 0;
}