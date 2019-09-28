#include <cstdio>
#include <string.h>


int** create2DFromInt(int* flatInt, int width, int height)
{
        int length = width * height;

        int** imageDataArray2D = new int* [height];
        imageDataArray2D[0] = new int[length];
        
        for(int j = 1; j < height; ++j) 
        {
            imageDataArray2D[j] = imageDataArray2D[j-1] + width;
        }


        for(int i = 0; i < length; ++i)
        {
            (*imageDataArray2D)[i] = flatInt[i];
        }

        return imageDataArray2D;    
}

int* createFlatIntFrom2D(int** array2D, int width, int height)
{
    int length = width * height;
    int* flatArray = new int[length];
    
    for(int i = 0; i < length; ++i)
    {
        flatArray[i] = (*array2D)[i];
    }

    return flatArray;    
}

unsigned char* createFlatCharFromInt(int* flatInt, int width, int height)
{
    int length = width * height;
    unsigned char* flatChar = new unsigned char[length*3];

    
    for(int i = 0; i < length; i++)
    {
        unsigned char* bytes = (unsigned char*)(&flatInt[i]);
        flatChar[i*3] = bytes[1];
        flatChar[i*3+1] = bytes[2];
        flatChar[i*3+2] = bytes[3];
    }
    return flatChar;    
}

int* createFlatIntFromChar(unsigned char* flatChar, int width, int height)
{
    int length =  width * height;
    int* flatInt = new int[length];

    for(int i = 0; i < length; i++)
    {
        unsigned char* bytes = (unsigned char*)(&flatInt[i]);
        bytes[1] = flatChar[i*3];
        bytes[2] = flatChar[i*3+1];
        bytes[3] = flatChar[i*3+2];
    }
    return flatInt;
}

int** redify(int** imageDataArray2D, int width, int height)
{
    int length = width * height;
    
    int* flatInt = createFlatIntFrom2D(imageDataArray2D, width, height);
    unsigned char* flatChar = createFlatCharFromInt(flatInt, width, height);
    
    for(int i = 1; i < length * 3; i++)
    {    
        flatChar[i] = 255;   
        i++;        
        i++;
    }

    flatInt = createFlatIntFromChar(flatChar, width, height);

    int** returnArray = new int* [height];
    returnArray[0] = new int[length];        
    for(int j = 1; j < height; ++j) 
    {
        imageDataArray2D[j] = imageDataArray2D[j-1] + width;
    }    
    
    returnArray = create2DFromInt(flatInt, width, height);

    delete[] flatChar;
    delete[] flatInt;
    flatChar = NULL;
    flatInt = NULL;

    return returnArray;
}


int** greenify(int** imageDataArray2D, int width, int height)
{
    int length = width * height;
    
    int* flatInt = createFlatIntFrom2D(imageDataArray2D, width, height);
    unsigned char* flatChar = createFlatCharFromInt(flatInt, width, height);
    
    for(int i = 1; i < length * 3; i++)
    {       
        i++;        
        flatChar[i] = 255;
        i++;
    }

    flatInt = createFlatIntFromChar(flatChar, width, height);

    int** returnArray = new int* [height];
    returnArray[0] = new int[length];        
    for(int j = 1; j < height; ++j) 
    {
        imageDataArray2D[j] = imageDataArray2D[j-1] + width;
    }    
    
    returnArray = create2DFromInt(flatInt, width, height);

    delete[] flatChar;
    delete[] flatInt;
    flatChar = NULL;
    flatInt = NULL;

    return returnArray;
}


int** blueify(int** imageDataArray2D, int width, int height)
{
    int length = width * height;
    
    int* flatInt = createFlatIntFrom2D(imageDataArray2D, width, height);
    unsigned char* flatChar = createFlatCharFromInt(flatInt, width, height);
    
    for(int i = 1; i < length * 3 -2; i++)
    {       
        i++;        
        i++;
        flatChar[i] = 255;
    }

    flatInt = createFlatIntFromChar(flatChar, width, height);

    int** returnArray = new int* [height];
    returnArray[0] = new int[length];        
    for(int j = 1; j < height; ++j) 
    {
        imageDataArray2D[j] = imageDataArray2D[j-1] + width;
    }    
    
    returnArray = create2DFromInt(flatInt, width, height);

    delete[] flatChar;
    delete[] flatInt;
    flatChar = NULL;
    flatInt = NULL;

    return returnArray;
}

void flipItHorizontal(int** array2D, int width, int height) 
{ 
    int temp[width]; 
    

    for(int j = 0; j < height; j++)
    {
        int count = width-1;
        for(int i = 0; i < width; i++)
        {
            temp[count] = array2D[j][i];
            count--;            
        }

        for(int i = 0; i < width; i++)
        {
            array2D[j][i] = temp[i];
        }        
    }
  
} 

int** createImageDataArray2D( int* width, int* height)
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
        unsigned char* imageDataArrayFlatChar = new unsigned char[length];
        //fread fills the array with data it gets from the file in size char
        fread(imageDataArrayFlatChar, sizeof(char), length, imageFile);
        //always close
        fclose(imageFile);


        int* imageDataArrayFlatInt =  createFlatIntFromChar(imageDataArrayFlatChar, *width, *height);

        int** imageDataArray2D = create2DFromInt(imageDataArrayFlatInt, *width, *height);
        
        delete[] imageDataArrayFlatInt;
        imageDataArrayFlatInt = NULL;
                

        return imageDataArray2D;
    }
    else
    {
        printf("\n!Invalid or corrupt header!\n");
        return NULL;
    }                                                                                                                                                                                                                                                                                                              
}

void writeCopyImage(int** imageDataArray2D, const int width, const int height, const char* fileName)
{

    int* imageDataArrayFlatInt = createFlatIntFrom2D(imageDataArray2D, width, height);

    unsigned char* imageDataArrayFlatChar = createFlatCharFromInt(imageDataArrayFlatInt, width, height);
    
    delete[] imageDataArrayFlatInt;
    imageDataArrayFlatInt = NULL;


    FILE* copyImageFile = fopen(fileName, "w");
    fprintf(copyImageFile, "P6\n%d %d\n255",width, height);
    if(strcmp(fileName, "copy_flip_h.ppm") == 0)
    {
        fprintf(copyImageFile, "\n");
    }

    fwrite(imageDataArrayFlatChar, sizeof(char),width * height * 3, copyImageFile);

    fclose(copyImageFile);

    delete[] imageDataArrayFlatInt;
    imageDataArrayFlatInt = NULL;  

}