#include<iostream>
#include<algorithm>
#include<vector>
//#include<thread>

using namespace std;

int n;
vector<long double> a;

void subrow(int row1, int row2) {

		double coef = a[row1*n+row2]/a[row2*n+row2];
#pragma omp parallel for
		for(int i = 0; i<n; i++) {
				a[row1*n+i]-=(coef*a[row2*n+i]);
		}
}

void swaprow(int row1, int row2) {
#pragma omp parallel for
		for(int i = 0; i<n; i++) {
				double temp = a[row1*n+i];
				a[row1*n+i] = a[row2*n+i];
				a[row2*n+i] = temp;
		}
}

void elim(int cur) {
		for(int i = 0; i<n; i++) {
				if(i!=cur&&a[i*n+cur]!=0) {
						subrow(i, cur);
				}
		}
}


int swap(int cur) {
		for(int i = cur+1; i<n; i++) {
				if(a[i*n+cur]!=0) {
						swaprow(i,cur);
						return 1;
				}
		}
		return 0;
}

int main() {
		ios_base::sync_with_stdio(false);
		cin>>n;
		a.assign(n*n,0);
		for(int i = 0; i<n; i++) {
				for(int j = 0; j<n; j++) {
						cin>>a[i*n + j];
				}
		}

		//row and column number is i
		double det = 1;
		for(int i = 0; i<n; i++) {
				if(a[i*n+i]!=0) {
						elim(i);
				}
				else if (swap(i)==1){
						swap(i);
						elim(i);
				}
				else {
						cout<<0;
						exit(0);
				}
				det=det*a[i*n+i];
		}
/*
		for(int i = 0; i<n; i++) {
				for(int j = 0; j < n; j++) {
						cout<<a[i*n+j]<<"\t";
				}
				cout<<"\n";
		}*/
		cout<<det;
}

