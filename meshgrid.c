#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"

double **meshgrid(int len, int begin, int addX, int addY);
void saveMat(double** mat, char*str, int m, int n);


int main(){
	int len = 10;
	double c1=1,c2=1,c3=0;
	double **x = meshgrid(len, 0, 1, 0);
	double **y = meshgrid(len, 0, 0, 1);
	saveMat(x, "meshX.dat", len, len);
	saveMat(y, "meshY.dat", len, len);
	
	
	double ** n1 = createMat(3, 1);
	    n1[0][0] = 1 ; n1[1][0] = 1 ; n1[2][0] = 1 ;	      
	double **z1 = createMat(len,len);
	for (int i=0; i<len; i++)
		for (int j=0; j<len; j++)
	z1[i][j] = (c1- (n1[0][0]*x[i][j]+n1[1][0]*y[i][j])*1.0)/(n1[2][0]);
	print(z1,len,len);
	printf("\n\n\n\n");
	
	double ** n2 = createMat(3, 1);
	    n2[0][0] = 1 ; n2[1][0] = 1 ; n2[2][0] = 1 ;	      
	double **z2 = createMat(len,len);
	for (int i=0; i<len; i++)
		for (int j=0; j<len; j++)
	z2[i][j] = (c2- (n2[0][0]*x[i][j]+n2[1][0]*y[i][j]))/(n2[2][0]);
	print(z2,len,len);
	printf("\n\n\n\n");
	
	double ** n3 = createMat(3, 1);
	    n3[0][0] = 1 ; n3[1][0] = 1 ; n3[2][0] = 1 ;	      
	double **z3 = createMat(len,len);
	for (int i=0; i<len; i++)
		for (int j=0; j<len; j++)
	z3[i][j] = (c3- (n3[0][0]*x[i][j]+n3[1][0]*y[i][j]))/(n3[2][0]);
	print(z3,len,len);
	printf("\n\n\n\n");
	
	double ** n4 = createMat(3, 1);
	    n4[0][0] = 1 ; n4[1][0] = 5 ; n4[2][0] = 1 ;	      
	double **z4 = createMat(len,len);
	for (int i=0; i<len; i++)
		for (int j=0; j<len; j++)
	z4[i][j] = (c3- (n4[0][0]*x[i][j]+n4[1][0]*y[i][j]))/(n4[2][0]);
	print(z4,len,len);
	printf("\n\n\n\n");
	
	double ** n5 = createMat(3, 1);
	    n5[0][0] = 1 ; n5[1][0] = 3 ; n5[2][0] = 1 ;	      
	double **z5 = createMat(len,len);
	for (int i=0; i<len; i++)
		for (int j=0; j<len; j++)
	z5[i][j] = (c3- (n5[0][0]*x[i][j]+n5[1][0]*y[i][j]))/(n5[2][0]);
	print(z5,len,len);
	
	saveMat(z1, "meshz1.dat", len, len);
	saveMat(z2, "meshz2.dat", len, len);
	saveMat(z3, "meshz3.dat", len, len);
	saveMat(z4, "meshz4.dat", len, len);
	saveMat(z5, "meshz5.dat", len, len);
	
	return 0;
	
}


double **meshgrid(int len, int begin, int addX, int addY)
{
	double ** ret = createMat(len, len);
	for (int i=0; i<len; i++)
		for (int j=0; j<len; j++){
			ret[i][j] = begin + i*addY + j*addX;
		}
	return ret;
}

void saveMat(double** mat, char *str, int m, int n){
	FILE *fp;
	fp = fopen(str,"w");
	for (int i=0; i < m; i++){
		for (int j=0; j < n; j++){
			fprintf(fp, "%lf ", mat[i][j]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	
}


