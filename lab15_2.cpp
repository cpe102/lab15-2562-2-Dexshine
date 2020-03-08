#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
	cout << "\n";
}

//Write definition of randData(), showData() and findColSum()
void randData(double *dPtr,int N,int M){
	for(int j=0;j<(N*M);j++){
		int i = rand()%100;
		*(dPtr+j) = i/100.0;
	}
}
void findColSum(const double *dPtr,double *result,int N,int M){
	for(int j=0;j<M;j++){
		int p = 0;
		for(int i=0;i<N;i++){
			result[j] += *(dPtr+j+p+i);
			p += 6;
		}
	}
}
void showData(double *array,int N,int M){
	int p = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout.width(4);
			cout << left << *(array+p) << "  ";
			p++;
		}
		cout << "\n";
	}
}
