#include <cstdio>

#include "hw5Func.h"



void cls()
{
	printf("\e[1;1H\e[2J");
}

int main()
{
	int width = 0;
	int height = 0;
	unsigned char* imageDataArray;
	const char* fileName = "test.ppm";
	int jpegQuality = 90; //1%-100%

	imageDataArray = createImageDataArray(fileName, &width, &height);

	
	int menuChoice = 0;
	cls();
	
    while(menuChoice != 9)
    {        
        printf("**%s**\n%dx%d\n\n", fileName, width, height);
		printf("1) Create jpeg copy\n");
		printf("2) Create BLUE jpeg copy\n");
		printf("3) Create RED jpeg copy\n");
		printf("4) Create GREEN jpeg copy\n");
		printf("5) Create Greyscale jpeg copy\n\n");
		printf("9) Exit\n:");
		
		scanf("%d",&menuChoice);
		
		switch(menuChoice)
		{
			case 1: 
				cls();
				printf("Jpeg copy created...\n");
				write_JPEG_file ("copy.jpeg", jpegQuality, imageDataArray, width, height);
				break;
			case 2:
				unsigned char* blueArray;
				cls();
				printf("Blue copy created...\n");
				blueArray = blueify(imageDataArray, width, height);
				write_JPEG_file ("copy_blue.jpeg", jpegQuality, blueArray, width, height);
				
				clearArray(blueArray);
								
				break;
			case 3:
				unsigned char* redArray;
				cls();
				printf("Red copy created...\n");
				redArray = redify(imageDataArray, width, height);
				write_JPEG_file ("copy_red.jpeg", jpegQuality, redArray, width, height);
				
				clearArray(redArray);
								
				break;
			case 4:
				unsigned char* greenArray;
				cls();
				printf("Green copy created...\n");
				greenArray = greenify(imageDataArray, width, height);
				write_JPEG_file ("copy_green.jpeg", jpegQuality, greenArray, width, height);
				
				clearArray(greenArray);
								
				break;
			case 5:
				unsigned char* greyArray;
				cls();
				printf("Greyscale copy created...\n");
				greyArray = greyScale(imageDataArray, width, height);
				write_JPEG_file ("copy_greyscale.jpeg", jpegQuality, greyArray, width, height);
				
				clearArray(greyArray);
								
				break;
			case 9:
				cls();
				clearArray(imageDataArray);
				return 0;				
			default:
				cls();
				printf("Bad selection...\n");				
		}

    }
	return 0;
}