#include <iostream>
using namespace std;

int main() {
	const int n=7;
	int a[n]={3,21,1,31,0,12,132};
	for (int i=0; i<n; i++){
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	int j=0;
	int b[n];
	for (int i=0; i<n; i++){
	    if (a[i]%2==0){
	        b[j]=a[i];
	        j+=1;
	    }
	}
    for (int i=0; i<j; i++){
        cout<<b[i]<<" ";
    }
	cout<<endl;
	return 0;
}
