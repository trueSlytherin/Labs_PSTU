#include <iostream>
using namespace std;

int main() {
	const int n=7;
	int a[n]={53,32,421,3126,41,12,23};
	for (int i=0; i<n; i++){
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	int tmp[2*n];
	int j=0;
	for (int i=0; i<n; i++){
	    if (a[i]%2==0){
	        tmp[j]=-1;
	        j+=1;
	    }
	    tmp[j]=a[i];
	    j+=1;
	}
	for (int i=0; i<j; i++){
	    cout<<tmp[i]<<" ";
	}
	cout<<endl;
	return 0;
}
