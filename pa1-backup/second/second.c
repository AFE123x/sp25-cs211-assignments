#include<stdio.h>
#include<stdlib.h>

/**
  * This sample code is to help you get accustomed to basic C syntax,
  * and how to read from text files.
  **/
  
  int printarr( int b, int (*arr)[b], int a)
  {
  	for (int i=0;i<a;i++)
  	{
  		for(int j=0;j<b;j++)
  		{
  			printf("%d ", arr[i][j]);
  			}
  			printf("\n");
  			}
  	for (int i1=0;i1<a;i1++)
  	{
  		for(int j1=a-1;j1>=0;j1--)
  		{
  			printf("%d ", arr[j1][i1]);
  			}
  			printf("\n");
  			}
  			return 0;}
  
int main(int argc, char** argv){ //similar to String[] args it java. argc is /args.length, argv is the args array itself.
  if(argc < 2) { //checks if there are 2 arguments!
    fprintf(stderr,"./first {text file}"); //prints messages to stderr. Primarily for error messages
    exit(1); //exits the program with a return code 1.
  }

  FILE* file = fopen(argv[1],"r"); //this will open a file specified by the user.

  if(file == NULL){ //if fopen fails to open the file, it returns NULL
    fprintf(stderr,"%s failed to open",argv[1]);
    exit(1); //exits your program
  }

  int x, y;

  fscanf(file,"%d %d",&x, &y); //attempts to read two integers, and stores them in x and y. fscanf returns the number of items successfully read.
   int arr[x][y];
   for(int i=0;i<x;i++)
   {
   	for(int j=0;j<y;j++)
   	{
   		fscanf(file, "%d",&arr[i][j]);
   		}
   		}
   		
   		printarr(y,arr,x);
   
  return 0;

}


