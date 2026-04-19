#include <iostream>
using namespace std;

int main() {
	const int n=7;
	int key;
	int a[n]={2,3,6,8,4,1,9};
	for (int i=0; i<n; i++){
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	for (int i=1; i<n; i++){
	    key = a[i];
	    int j=i-1;
	    while(j>=0 && a[j]>key)
	    {
	        a[j+1]=a[j];
	        j--;
	    }
        a[j+1]=key;
	}
	for (int i=0; i<n; i++){
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
