#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 250

int main(void)
{
   FILE* fp;
   fp = fopen("a.txt", "r");

   // In the case that the txt file cannot be opened
   // Return the error before the program crashes

   if(fp == NULL){
       perror("Failed: ");
       return 1;
   }

   char *buffer = (char *)malloc(MAX_LEN * sizeof(char));
   
   while (fgets(buffer, MAX_LEN, fp))
   {
       // Remove trailing newline
       // Save file to buffer character by character
       buffer[strcspn(buffer, "\n")] = 0;
       
   }

   //fclose(fp);
   return 0;

}