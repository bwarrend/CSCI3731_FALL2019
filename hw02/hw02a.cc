#include <cstdio>

int main(int argc, char** argv)
{
  int counter;
  //Initialize the pointer our file.
  FILE* saveFile;
  //Does the file exist?
  if( (saveFile = fopen("savefile", "r")) == NULL)
  {
    //If it doesn't, let's create it and write a 1, because
    //this is our first time running the program. Close file.
    saveFile = fopen("savefile", "w");
    fprintf(saveFile, "1");
    fclose(saveFile);
  }

  //Open the file for reading
  saveFile = fopen("savefile", "r");
  //Grab the first line, a decimal, and store it in counter
  fscanf(saveFile, "%d", &counter);
  //Print current counter to console, increment counter
  counter++;
  printf("%d\n", counter);
  //Close the file
  fclose(saveFile);
  //Re-open file with w flag so that it is ready to write and clears the data
  saveFile = fopen("savefile", "w");
  //Print the new counter to the file and then close the file
  fprintf(saveFile, "%d", counter);
  fclose(saveFile);

  return 0;
}
