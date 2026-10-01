#include<iostream>
using namespace std;
void hanoi_tower(int n, char dau,char cuoi,char giua,long long &step_count){
if(n==1){
    step_count++;
    cout<< "Buoc "<<step_count<<": Chuyen dia 1 tu cot"<<dau<<" sang cot "<<cuoi<<'\n';
    return;
}
hanoi_tower(n-1,dau,giua,cuoi,step_count);
step_count++;
cout<< "Buoc "<<step_count<<": Chuyen dia " <<n<< "tu cot"<<dau<<" sang cot "<<cuoi<<'\n';
hanoi_tower(n-1,giua,cuoi,dau,step_count);
}
int main(){
    int n;
    cout<<"Nhap so dia: ";
    if(!(cin>>n)||n<=0){
        return 1;
    }
    long long steps=0;
    hanoi_tower(n,'A','C','B',steps);
    cout<<"So buoc: "<<steps;
}