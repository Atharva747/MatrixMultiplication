#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
		ios_base::sync_with_stdio(false);
		int n,k,m;
		cin>>n>>k>>m;
		vector<vector<int> > a(n,vector<int>(k));
		vector<vector<int> > b(k,vector<int>(m));
		vector<vector<int> > c(n,vector<int>(m));
//#pragma omp parallel for
		for(int i = 0; i<n; i++) {
				for(int j = 0; j<k; j++) {
						cin>>a[i][j];
				}
		}
//#pragma omp parallel for
		for(int i = 0; i<k; i++) {
				for(int j = 0; j<m; j++) {
						cin>>b[i][j];
				}
		}
//#pragma omp parallel for
		for(int i = 0; i<n; i++) {
				for(int j = 0; j<m; j++) {
						int entry = 0;
						for(int y = 0; y<k; y++) {
								entry+=(a[i][y]*b[y][j]);
						}
						c[i][j] = entry;
				}
		}
		for(int i = 0; i<n; i++) {
				for(int j = 0; j<m; j++) {
						cout<<c[i][j]<<"\t";
				}
				cout<<endl;
		}
}