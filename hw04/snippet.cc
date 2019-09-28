#include <cstdio>

int** createFlatArray( int* width, int* height)
{
    FILE* imageFile;
    char isP6[2];
    int colorsN = 0;

    //Open the file
    imageFile = fopen("test.ppm", "rb");
    //Parse the header data
    fscanf(imageFile, "%s", isP6);
    fscanf(imageFile, "%d %d", width, height);
    fscanf(imageFile, "%d", &colorsN);

    //Big check to make sure we are indeed dealing with a PPM file
    if(isP6[0] == 'P' && isP6[1] == '6' && *width > 0 && *height > 0 && colorsN == 255)
    {   

        int length = *height * *width * 3;
        //Create an array of unsigned characters with the length we got above
        unsigned char* imageDataArray = new unsigned char[length];
        //fread fills the array with data it gets from the file in size char
        fread(imageDataArray, sizeof(char), length, imageFile);
        //always close
        fclose(imageFile);


        length /=3;

        int** imageDataArray2D = new int*[*height];
        imageDataArray2D[0] = new int[*width * *height];

        for(int j = 1; j < *height; ++j)
        {
            imageDataArray2D[j] = imageDataArray2D[j-1] + *width;
        }


        for(int i = 0; i < length; i++)
        {
            unsigned char* bytes = (unsigned char*)(imageDataArray2D[i]);
            bytes[0] = 0;
            bytes[1] = imageDataArray[i*3];
            bytes[2] = imageDataArray[i*3+1];
            bytes[3] = imageDataArray[i*3+2];
        }


        
       

        return imageDataArray2D;
    }
    else
    {
        printf("\n!Invalid or corrupt header!\n");
        return NULL;
    }                                                                                                                                                                                                                                                                                                              
}



int main(int argc, char** argv)
{
    int** imageDataArray2D;
    int width = 0, height = 0;

    imageDataArray2D = createFlatArray(&width, &height);
    int length = width * height;
    //int intArray[length];
    
    

    int imageDataArray[length*3];

    for(int i = 0; i < length; i++)
    {
        unsigned char* bytes = (unsigned char*)(imageDataArray2D[i]);
        imageDataArray[i*3] = bytes[1];
        imageDataArray[i*3+1] = bytes[2];
        imageDataArray[i*3+2] = bytes[3];
    }
    


    FILE* copyImageFile = fopen("copy.ppm", "w");
    fprintf(copyImageFile, "P6\n%d %d\n255",width, height);
    


    fwrite(imageDataArray, sizeof(char),length*3, copyImageFile);

    delete [] *imageDataArray2D;
    delete [] imageDataArray2D;

    fclose(copyImageFile);



    return 0;
}