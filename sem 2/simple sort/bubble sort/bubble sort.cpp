#include <iostream>
using namespace std;

int main() {
	const int n=7;
	int a[n]={2,3,6,8,4,1,9};
	for (int i=0; i<n; i++){
	    cout<<a[i]<<" ";
	}
    cout<<endl;
	int tmp;
	for (int i=0; i<n-1; i++){
	    for (int j=0; j<n-1-i; j++){
	        if (a[j]>a[j+1]){
	            tmp=a[j];
	            a[j]=a[j+1];
	            a[j+1]=tmp;
	        }
	    }
	}
	for (int i=0; i<n; i++){
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
