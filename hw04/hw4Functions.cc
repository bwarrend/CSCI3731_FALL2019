#include <cstdio>

/*
/Takes in a filename and pointer for width and height and returns an array of image data
/Will return null and possibly crash the whole system if the header doesn't correctly 
/match that of a .ppm file.
*/
unsigned char* createImageDataArray(char fileName[], int* width, int* height)
{
    FILE* imageFile;
    char isP6[2];
    int colorsN = 0;

    //Open the file
    imageFile = fopen(fileName, "rb");
    //Parse the header data
    fscanf(imageFile, "%s", isP6);
    fscanf(imageFile, "%d %d", width, height);
    fscanf(imageFile, "%d\n", &colorsN);

    //Big check to make sure we are indeed dealing with a PPM file
    if(isP6[0] == 'P' && isP6[1] == '6' && *width > 0 && *height > 0 && colorsN == 255)
    {   
        //Make sure the user is ready for what comes next
        printf("Name: \t%s\nStyle: \t%s\nSize: \t%dx%d\nColors: %d\n",fileName, isP6, *width, *height, colorsN);
        printf("Press <Enter> to proceed with copy...");
        getchar();
        printf("\e[1;1H\e[2J");
        //Set the array length, height x width x 3
        int length = *height * *width * 3;
        //Create an array of unsigned characters with the length we got above
        unsigned char* imageDataArray = new unsigned char[length];
        //fread fills the array with data it gets from the file in size char
        fread(imageDataArray, sizeof(char), length, imageFile);
        //always close
        fclose(imageFile);        

        return imageDataArray;
    }
    else
    {
        printf("\n!Invalid or corrupt header!\n");
        return NULL;
    }                                                                                                                                                                                                                                                                                                              
}

/*
/Creates a 1 to 1 copy of the original image, given the imagedata in an
/array and the length
*/
void writeImage(unsigned char* imageDataArray, int width, int height, const char fileName[])
{   
    //Find the length of the array
    int length = height * width * 3;
    //Create the file
    FILE* copyImageFile = fopen(fileName, "wb");
    //Place the header information, based on the standard and the given lxw
    fprintf(copyImageFile, "P6\n%d %d\n255\n",width, height);
    //write in the image data from the array
    fwrite(imageDataArray, sizeof(char), length, copyImageFile);
    //close her up
    fclose(copyImageFile);    
}


unsigned char* blueify(unsigned char* imageDataArray, int length)
{
    unsigned char* blueArray = new unsigned char[length];   
    
    for(int i = 0; i < length; i+=3)
    {
        blueArray[i] = imageDataArray[i];
        blueArray[i+1] = imageDataArray[i+1];
        blueArray[i+2] = 255;
    }
    return blueArray;
}


unsigned char* greenify(unsigned char* imageDataArray, int length)
{
    unsigned char* greenArray = new unsigned char[length];   
    
    for(int i = 0; i < length; i+=3)
    {
        greenArray[i] = imageDataArray[i];
        greenArray[i+1] = 255;
        greenArray[i+2] = imageDataArray[i+2];
    }
    return greenArray;
}


unsigned char* redify(unsigned char* imageDataArray, int length)
{
    unsigned char* redArray = new unsigned char[length];   
    
    for(int i = 0; i < length; i+=3)
    {
        redArray[i] = 255;
        redArray[i+1] = imageDataArray[i+1];
        redArray[i+2] = imageDataArray[i+2];
    }
    return redArray;
}

unsigned char* greyscale(unsigned char* imageDataArray, int length)
{    
    unsigned char* greyArray = new unsigned char[length]; 

    for(int i = 0; i < length; i+=3)
    {
        int mean = 0;
        mean += imageDataArray[i];
        mean += imageDataArray[i+1];
        mean += imageDataArray[i+2];

        mean /= 3;

        greyArray[i] = mean;
        greyArray[i+1] = mean;
        greyArray[i+2] = mean;
    }
    return greyArray;    
}
