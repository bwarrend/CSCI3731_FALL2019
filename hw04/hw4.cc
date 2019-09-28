#include <cstdio>
#include "hw4Functions.h"




int main(int argc, char** argv)
{
    int width = 0, height = 0;

    int** imageDataArray2D = createImageDataArray2D(&width, &height);

    writeCopyImage(imageDataArray2D, width, height, "copy.ppm");

    /*
    I spent many more hours than I should have trying
    to figure out how go straight from a 2d array of ints
    to the bytes within each int without seg fault.  Seg
    fault seg fault seg fault.  I'll include a snippet of my
    broken code so you can see what I was going for.  Maybe then
    I can actually understand.  I finally gave up and decided 
    to convery the 2d array to a flat and then casted down to
    the byte level.  Anyway, this program is obviously waaaaaaaay
    longer and more complicated than it needs to be.  I am also
    struggling with the newline after the 255.  Sometimes it
    automatically new lines, sometimes it doesn't.  I tried a
    workaround but even that doesn't work.  Obviously, I am 
    missing something.  I planned on doing a lot more but
    ran out of time.
    */


    int** redArray = redify(imageDataArray2D, width, height);
    writeCopyImage(redArray, width, height, "copy_red.ppm");
    int** greenArray = greenify(imageDataArray2D, width, height);
    writeCopyImage(greenArray, width, height, "copy_green.ppm");
    int** blueArray = blueify(imageDataArray2D, width, height);
    writeCopyImage(blueArray, width, height, "copy_blue.ppm");

    flipItHorizontal(imageDataArray2D, width, height);
    writeCopyImage(imageDataArray2D, width, height, "copy_flip_h.ppm");
    flipItHorizontal(imageDataArray2D, width, height); 
    

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