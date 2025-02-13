#include<stdio.h>
#include<stdlib.h>

/**
  * This sample code is to help you get accustomed to basic C syntax,
  * and how to read from text files.
  **/
  
  double det(double** arr, int n)
  {
  	if ( n==1) return arr[0][0];
  	if ( n==2) return(arr[0][0] * arr[1][1]- arr[0][1]*arr[1][0]);
  
 	 double d=0;
  	for(int c=0;c<n;c++){
  		double** smol=(double**)malloc((n-1)*sizeof(double*));
  		for(int i=0;i<n-1;i++)
  		{ smol[i]=(double*)malloc ((n-1) * sizeof(double));}
  		
  		for(int i=1;i<n;i++){
  		  int somn=0;
  		  for(int j=0;j<n;j++){
  		     if(j==c)continue;
  		     smol[i-1][somn]=arr[i][j];
  		     somn++;
  		     }
  		}
  		
  		double smold= det(smol,n-1);
  		
  		for(int i=0;i<n-1;i++) free(smol[i]);
  		free(smol);
  		
  		d+= (c%2==0?1:-1)* arr[0][c]*smold;
  		}
  		return d;
  		}
  
  
  
  	

  
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

  int n;

  fscanf(file,"%d",&n); //attempts to read two integers, and stores them in x and y. fscanf returns the number of items successfully read.
 
   double** arr = (double**)malloc(n*sizeof(double*));
   for(int i=0;i<n;i++)
   	{	arr[i]=(double*)malloc(n*sizeof(double));
   		}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		fscanf(file, "%lf", &arr[i][j]);
		}}
		fclose(file);
	double determinant=det(arr, n);
	printf(" Determinant is %.6f\n", determinant);
	
	for(int i=0;i<n;i++)free(arr[i]);
	free(arr);
	   
  return 0;

}


