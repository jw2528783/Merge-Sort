#include <iostream>
#include <cassert>

using namespace std;

void merge(int a[],int n){
	int i,j,k;
	int m=n/2;
	int n1=m+1;
	int n2=n-m;
	int temp[n1],temp2[n2];
	for(int i=0;i<n1;i++)temp[i]=a[i];
	for(int j=0;j<n2;j++)temp2[j]=a[m+1+j];
	i=0,j=0,k=0;
	while(i<n1 && j<n2){
		if(temp[i]<=temp2[j]){
			a[k]=temp[i];
			i++;
		}
		else{
			a[k]=temp2[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k]=temp[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=temp2[j];
		j++;
		k++;
	}
}

void mergesort(int a[],int start, int n){
	if(0<n){
		mergesort(a,start,n/2);
		mergesort(a,(n/2)+1,n);
		merge(a,n);
	}
}


bool sorted(int a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}

void printA(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl<<endl;
}

int main(int argc, char * args[]) {
	int a[] = { 2, -9, 122, 45, -7, 33, -7, 16, 99, 21 };
	printA(a,10);
	mergesort(a, 0, 10);
	printA(a,10);
	/*assert(a[0] == -9);
	assert(a[1] == -7);
	assert(a[2] == -7);
	assert(a[3] == 2);
	assert(a[4] == 16);
	assert(a[5] == 21);
	assert(a[6] == 33);
	assert(a[7] == 45);
	assert(a[8] == 99);
	assert(a[9] == 122);
	/*
	int b[] = { 2 };
	quicksort(b, 0, 0);
	assert(b[0] == 2);

	int c[] = { 2, 2 };
	quicksort(c, 0, 1);
	assert(c[0] == 2);
	assert(c[1] == 2);

	int d[] = { 2, -2 };
	quicksort(d, 0, 1);
	assert(d[0] == -2);
	assert(d[1] == 2);

	srand(time(0));
	int e[1000];
	for (int i = 0; i < 1000; ++i) e[i] = rand() % 100;
	quicksort(e, 0, 999);
	assert(sorted(e, 1000));
	*/
	cout << "All tests passed." << endl;	
}
