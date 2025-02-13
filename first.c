#include<stdio.h>
#include<stdlib.h>


/**
  * This sample code is to help you get accustomed to basic C syntax,
  * and how to read from text files.
  **/
  int divisorsum(int x)
{	int sum=0;
	for(int i=1;i<x;i++)
	{ if(x%i==0)
		{sum=sum+i;}}
		return sum;}
		
double pow(double n, double m)
{ int ans=1;
for(int i=1;i<=m;i++)
	{ ans=ans*n;
	}
	return ans;
	
}		
int main(){
int a;
printf("enter the number");
scanf("%d",&a);
  
  /*int x, y;

  { //attempts to read two integers, and stores them in x and y. fscanf returns the number of items successfully read.
    printf("%d + %d = %d\n",x,y,x+y);*/
  
  
  int ans;
  int dsum= (int)divisorsum(6);
  if(dsum==a)
  { 	
  	for(int i=1;i<a;i++){
  	ans = ((int)pow((2),(i-1)))*((int)pow(2,i)-1);
  	if(ans==a)
  	{printf("%d",(int) pow(2,i)-1);
  	 break;}
  	}}
  	
  else{ int a=-1;
   printf("%d",a);}
  return 0;

}

		
int prime(int x)
{
	if(x<2)return 0;
	for(int i=0;i*i<=x;i++)
	{	if(x%i==0) return 0;}
	return 1;
		}

		
