#include <iostream>
#include "Image.h"
#include <jpeglib.h>
#include <cstdio>
#include <cstdlib>
#include <string>


Image::Image() {
    width = -1;
    height = -1;
    imageDataArray = nullptr;
}

//Copy constructor
Image::Image(const Image& img){
    width = img.width;
    height = img.height;
    int length = width * height * 3;

    this->imageDataArray = new unsigned char[length];

    for(int i = 0; i < length; ++i){
        this->imageDataArray[i] = img.imageDataArray[i];
    }
}

//Move constructor
Image::Image(Image&& img){
    width = img.width;
    height = img.height;
    //delete[] imageDataArray;
    imageDataArray = img.imageDataArray;
    
    
    img.imageDataArray = nullptr;
}

void Image::createImageDataArray(std::string fileName){
    FILE* imageFile;
    char isP6[2];
    int colorsN = 0;


    if( (imageFile = fopen(fileName.c_str(), "rb")) != nullptr){  
        //Open the file
        imageFile = fopen(fileName.c_str(), "rb");
        //Parse the header data
        fscanf(imageFile, "%s", isP6);
        fscanf(imageFile, "%d %d", &width, &height);
        fscanf(imageFile, "%d\n", &colorsN);
        //Big check to make sure we are indeed dealing with a PPM file
        if(isP6[0] == 'P' && isP6[1] == '6' && width > 0 && height > 0 && colorsN == 255){
        
            //Set the array length, height x width x 3
            int length = height * width * 3;
            imageDataArray = new unsigned char[length];
            //fread fills the array with data it gets from the file in size char
            fread(imageDataArray, sizeof(char), length, imageFile);
            //always close
            fclose(imageFile);    

        }else{
            std::cout << std::endl << "!Invalid or corrupt header!" << std::endl;
            fclose(imageFile);
        }
    }else{
        std::cout << "Cannot find file: " << fileName << std::endl;
    }                                                                                                                                                                                                                                                                                                            
}

//Function to write a jpeg
//
void Image::writeJPEG (std::string fileName, int quality){
    
    //If our array is set to nullptr, let's bail.
    if(imageDataArray == nullptr){
        return;
    }    
    
    //Create the required structs cinfo and jerr
    //
	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;

	FILE * outfile;		
	JSAMPROW row_pointer[1];
	int row_stride;		

	cinfo.err = jpeg_std_error(&jerr);

	jpeg_create_compress(&cinfo);

    //Check if we can open the file with the given fileName
    //
	if ((outfile = fopen((fileName+".jpeg").c_str(), "wb")) == NULL) {
        std::cout << "Can't open " << fileName+".jpeg" << std::endl;
        exit(1);
	
	}

    //Set up the cinfo struct with width, height, amount of components and
    // an enum that we are setting to JCS_RGB
    //
	jpeg_stdio_dest(&cinfo, outfile);

	cinfo.image_width = width;
	cinfo.image_height = height;
	cinfo.input_components = 3;
	cinfo.in_color_space = JCS_RGB;

	jpeg_set_defaults(&cinfo);
	jpeg_set_quality(&cinfo, quality, TRUE);
	jpeg_start_compress(&cinfo, TRUE);

    //Set the length and write to the file
    //
	row_stride = width * 3;

	while (cinfo.next_scanline < cinfo.image_height){

        row_pointer[0] = & imageDataArray[cinfo.next_scanline * row_stride];
        (void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
        
	}

    //Finish the job
    //
	jpeg_finish_compress(&cinfo);

	fclose(outfile);
	jpeg_destroy_compress(&cinfo);
    
}

void Image::writePPM(std::string fileName){   
    //Create the file
    FILE* copyImageFile = fopen((fileName+"_copy.ppm").c_str(), "wb");
    //Place the header information, based on the standard and the given lxw
    fprintf(copyImageFile, "P6\n%d %d\n255\n", width, height);
    //write in the image data from the array
    fwrite(imageDataArray, sizeof(char), height * width * 3, copyImageFile);
    //close her up
    fclose(copyImageFile);    
}

//++ operator doubles up the pixels width wise to stretch the image
//
Image& Image::operator++() {
    int length = width * height * 3;
    
    unsigned char tmpData[length];
    
    for(int i = 0; i < length; ++i){
        tmpData[i] = imageDataArray[i]; 
    }
    
    delete[] imageDataArray;

    width *= 2;
    imageDataArray = new unsigned char[(length * 2)];

    int j = 0;

    for(int i = 0; i < length; ++i){
        imageDataArray[j] = tmpData[i];
        imageDataArray[j+3] = tmpData[i];
        ++i;
        ++j;
        imageDataArray[j] = tmpData[i];
        imageDataArray[j+3] = tmpData[i];
        ++i;
        ++j;
        imageDataArray[j] = tmpData[i];
        imageDataArray[j+3] = tmpData[i];
        j+=4;
        
    }

    return *this;
}

Image& Image::operator--() {
    int length = width * height * 3;
    
    unsigned char tmpData[length];
    
    for(int i = 0; i < length; ++i){
        tmpData[i] = imageDataArray[i]; 
    }
    
    delete[] imageDataArray;

    width /= 2;
    imageDataArray = new unsigned char[(length/2)];

    int j = 0;

    for(int i = 0; i < length; ++i){
        imageDataArray[++j] = tmpData[++i];
        imageDataArray[++j] = tmpData[++i];
        imageDataArray[++j] = tmpData[++i];
        i+=2;       
    }

    return *this;
}



//Move =
Image& Image::operator=(Image&& img) {
    width = img.width;
    height = img.height;
    delete[] imageDataArray;
    imageDataArray = img.imageDataArray;    
    img.imageDataArray = nullptr;

    return *this;
}

//Copy =
Image& Image::operator=(const Image& img){
    width = img.width;
    height = img.height;
    int length = width * height * 3;
    this->imageDataArray = new unsigned char[length];

    for(int i = 0; i < length; ++i){
        this->imageDataArray[i] = img.imageDataArray[i];
    }
    
    return *this;
}


Image::~Image(){
    delete[] imageDataArray;
    imageDataArray = nullptr;
}