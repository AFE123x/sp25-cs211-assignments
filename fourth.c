#include<stdio.h>
#include<stdlib.h>
#define a 100
/**
  * This sample code is to help you get accustomed to basic C syntax,
  * and how to read from text files.
  **/
  
  double mod(double x){
	return(x<0)?-x:x;
	}
  
  int printarr( double arr[a][a+1], int n)
  {
  	for (int i=0;i<n;i++)
  	{
  		for(int j=0;j<n+1;j++)
  		{	if(mod(arr[i][j]<1e-9)){
  			printf("0.000000 ");
  			}
  			else{
  			printf("%.6f ", arr[i][j]);
  			}}
  			printf("\n");
  			}
  			return 0;
  	
  	
}
	
void operationswap( double arr[a][a+1], int r1, int r2, int n)
  {
  	for(int i=0;i<=n;i++){
  		double c=arr[r1][i];
  		arr[r1][i]=arr[r2][i];
  		arr[r2][i]=c;
  		}
  }
  
void coef(double arr[a][a+1], int r1, int n, double co)
{
	for(int i=0;i<=n;i++)
	{
	arr[r1][i]=arr[r1][i]/co;
	}
	
}	
  
  void adding(double arr[a][a+1], int r1, int r2, double coef, int n)
  {
  	for(int i=0;i<=n;i++)
  	{
  		arr[r2][i]=arr[r2][i]-(coef * arr[r1][i]);
  		}
  }

void gaussing(double arr[a][a+1], int n){

for(int i=0;i<n;i++){
	
	if(mod(arr[i][i])<1e-9){
		for(int j=i+1;j<n;j++)
		{
		if(mod(arr[j][i])>1e-9){
		operationswap(arr,i,j,n);
		break;
		}
		}
		}
		
		if(mod(arr[i][i])>1e-9){
		coef(arr,i,n,arr[i][i]);
		}
		for(int j=i+1;j<n;j++){
		adding(arr,i,j,arr[j][i],n);
		}
		}
		for(int i=n-1;i>=0;i--){
		for(int j=i-1;j>=0;j--){
		adding(arr,i,j,arr[j][i],n);
		}
		}

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

  int n,m;

  fscanf(file,"%d %d",&n, &m); //attempts to read two integers, and stores them in x and y. fscanf returns the number of items successfully read.
 
   double arr[a][a+1];
   for(int i=0;i<n;i++)
   {
   	for(int j=0;j<m;j++)
   	{
   		fscanf(file, "%lf",&arr[i][j]);
   		}
   		}
   		gaussing(arr,n);
   		printarr(arr,n);
   
  return 0;

}


