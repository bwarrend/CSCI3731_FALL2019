#include <cstdio>
#include "hw3Functions.h"


int main(int argc, char** argv)
{
    unsigned char* imageDataArray;
    char* fileName = nullptr;
    FILE* imageFile = nullptr;
    int width = 0, height = 0;

    //If there are 2 command line arguments, let's begin, otherwise cut it out
    if(argc == 2)
    {
        fileName = argv[1];

        //Check to see if the file exists, if it does, proceed to the functions
        if( (imageFile = fopen(fileName, "r")) != NULL)
        {   
            /*createImageDataArray returns an array of unsigned characters from
            /the image data of the file specified in the command line argument.
            /Send a pointer for height and width so we can use that later
            */
            imageDataArray = createImageDataArray(fileName, &width, &height);
            createImageCopy(imageDataArray, width, height);

            //Just messing around with color manipulation
            greenify(imageDataArray, width, height);
            redify(imageDataArray, width, height);
            blueify(imageDataArray, width, height);
            greyScale(imageDataArray, width, height);
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