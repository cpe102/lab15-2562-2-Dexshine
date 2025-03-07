#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[N] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,result,N,M);
	showData(result,N,1);
	cout << " ";
}

//Write definition of randData(), showData() and findRowSum()
void randData(double *dPtr,int N,int M){
	for(int j=0;j<(N*M);j++){
		int i = rand()%100;
		*(dPtr+j) = i/100.0;
	}
}
void findRowSum(const double *dPtr,double *result,int N,int M){
	int p=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			result[i] += *(dPtr+(p+j));
		}
		p+=7;
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
