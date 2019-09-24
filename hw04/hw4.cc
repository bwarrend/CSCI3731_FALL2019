#include <cstdio>
#include "hw4Functions.h"


int main(int argc, char** argv)
{
    unsigned char* imageDataArray;
    char* fileName;
    FILE* imageFile;
    int width = 0, height = 0;

    //If there are 2 command line arguments, let's begin, otherwise cut it out
    if(argc == 2)
    {
        fileName = argv[1];

        //Check to see if the file exists, if it does, proceed to the functions
        if( (imageFile = fopen(fileName, "r")) != NULL)
        {   
            /*
            /createImageDataArray returns an array of unsigned characters from
            /the image data of the file specified in the command line argument.
            /Send a pointer for height and width so we can use that later
            */
            imageDataArray = createImageDataArray(fileName, &width, &height);
            writeImage(imageDataArray, width, height, "copy.ppm");

            int length = width * height * 3;

            //Just messing around with color manipulation

            unsigned char* greenArray = greenify(imageDataArray, length);
            writeImage(greenArray, width, height, "green_copy.ppm");
            unsigned char* blueArray = blueify(imageDataArray, length);
            writeImage(blueArray, width, height, "blue_copy.ppm");
            unsigned char* redArray = redify(imageDataArray, length);
            writeImage(redArray, width, height, "red_copy.ppm");
            unsigned char* greyArray = greyscale(imageDataArray, length);
            writeImage(greyArray, width, height, "grey_copy.ppm");

            //Collecting some garbage
            delete []imageDataArray;
            imageDataArray = NULL;            
            delete []blueArray;
            blueArray = NULL;
            delete []greenArray;
            greenArray = NULL;
            delete []redArray;
            redArray = NULL;
            delete []greyArray;
            greyArray = NULL;
        }
        else
        {
            printf("File '%s' does not exist or otherwise cannot be opened.\n", fileName);
        }
    }
    else
    {
        printf("Invalid console argument provided. Try ./hw3 FILENAME\n");    
    }
    
    return 0;
}
