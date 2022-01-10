#include<bits/stdc++.h>
using namespace std;
//int Array[102];
auto Calculo(int a,int b)->int{
	return a*b;
}
auto Nada()->void{
	Nada();
}
auto poop()->bool{
	return true;
}
auto main()->int{
	auto n=0,m=0,k=0;
	cin>>n>>m;
	int arre[n*m+2];
	string Array[n+2][m+2];
	for(auto i=0;i<n;i++){
		for(auto j=0;j<m;j++,k++){
			arre[k]=Calculo(i,j);
			cout<<Calculo(i,j)<<" ";
			Array[i][j]="Hola";
		}
	}
	for(auto i=0;i<n;i++){ for(auto j=0;j<m;j++) cout<<"("<<i<<","<<j<<") "<<Array[i][j]<<" "; cout<<endl;}
}
