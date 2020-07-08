#include<stdio.h>

//Define a structure type named vector2_t which contains x and y components of a vector. 
//Define a function to prompt user to enter x and y values for a vector. 
//Define a function to print a vector on console. 
//Define a function to compute sum of two vectors. 
//Test your functions in a program that asks user how many vectors is going to be entered and then computes sum of all the vectors. 
//Program should create an output like given below and information about points and summation should be added to the text file neatly. 

//how many vectors will be summed? 3 
 
/*enter x component of vector: -1.1 enter y component of vector: -1.1 
 
enter x component of vector: 2.2 enter y component of vector: 2.2 
 
enter x component of vector: 3.3 enter y component of vector: 3.3 
 
    (-  1.100x -  1.100y)     
	(+  2.200x +  2.200y)     
	(+  3.300x +  3.300y) 
+________________________    
    (+  4.400x +  4.400y) */
    
struct  vector2_t{
	float x;
	float y;
};   
int main(){
	
	FILE *f=fopen("vector.txt","w+");
	
	int n;
	printf("How many vectors will be summed?:");
	scanf("%d",&n);
	struct vector2_t v[n];
	int i;
	for(i=0;i<n;i++){
		printf("Enter x of vector %d:",i+1);
     	scanf("%f",&v[i].x);
	    printf("\nEnter y of vector %d:",i+1);
	    scanf("%f",&v[i].y);
	    printf("\n");
	
	}
	float sum_x=0,sum_y=0;
	int k;
	for(k=0;k<n;k++){
		sum_x+=v[k].x;
		sum_y+=v[k].y;
	}
	
	int l;
	for(l=0;l<n;l++){
		fprintf(f,"Vector %d:\nx=%.2f\ny=%.2f\n",l+1,v[l].x,v[l].y);
	}
	for(l=0;l<n;l++){
		fprintf(f,"\n(%.2f)x+(%.2f)y",v[l].x,v[l].y);
		if(l<n-1){
			fprintf(f,"\n");
		}
		if(l==n-1){
			fprintf(f,"\n+-------------------\n(%.2f)x+(%.2f)y",sum_x,sum_y);
		}
	}
	
	fclose(f);
	
	
	return 0;
}
 
 
