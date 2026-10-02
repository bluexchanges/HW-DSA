#include<iostream>
#include<vector>
using namespace std;

struct Coc{
    char name;
    vector<int>dia;
};
void Move(Coc &c1,Coc &c2,long long steps){
    if(c1.dia.empty()){
        c1.dia.push_back(c2.dia.back());
        c2.dia.pop_back();
        cout<<"Buoc "<<steps<<": Chuyen dia "<<c1.dia.back()<<" tu cot "<<c2.name<<" sang cot "<<c1.name<<'\n';
    } else if (c2.dia.empty()){
        c2.dia.push_back(c1.dia.back());
        c1.dia.pop_back();
        cout<<"Buoc "<<steps<<": Chuyen dia "<<c2.dia.back()<<" tu cot "<<c1.name<<" sang cot "<<c2.name<<'\n';
    } else if (c1.dia.back()<c2.dia.back()){
        c2.dia.push_back(c1.dia.back());
        c1.dia.pop_back();
        cout<<"Buoc "<<steps<<": Chuyen dia "<<c2.dia.back()<<" tu cot "<<c1.name<<" sang cot "<<c2.name<<'\n';
    } else {
        c1.dia.push_back(c2.dia.back());
        c2.dia.pop_back();
        cout<<"Buoc "<<steps<<": Chuyen dia "<<c1.dia.back()<<" tu cot "<<c2.name<<" sang cot "<<c1.name<<'\n';
    }
}
void hanoi_tower(int n,char dau,char cuoi, char giua){
    Coc coc[3];
    coc[0].name=dau;
    if(n%2==0){
        coc[1].name=giua;
        coc[2].name=cuoi;
    } else{
        coc[1].name=cuoi;
        coc[2].name=giua;
    }
    for(int i=n;i>=1;i--){
        coc[0].dia.push_back(i);
    }
    int pos_dia1=0;
    long long total_step = (1LL << n) - 1;
    cout << "Tong so buoc can thuc hien: " << total_step << '\n';
    for(long long i=1;i<=total_step;i++){
        if(i%2 !=0){
            int nextPos=(pos_dia1+1)%3;
            coc[nextPos].dia.push_back(1);
            coc[pos_dia1].dia.pop_back();
            cout<<"Buoc "<<i<<": Chuyen dia 1 tu cot "<<coc[pos_dia1].name<<" sang cot "<<coc[nextPos].name<<'\n';
            pos_dia1=nextPos;
        }else{
            int cocA=(pos_dia1+1)%3;
            int cocB=(pos_dia1+2)%3;
            Move(coc[cocA],coc[cocB],i);
        }
    }
}
int main(){
    int n;
    cout<<"Nhap so dia: ";
    if(!(cin>>n)||n<=0){
        return 1;
    }
    hanoi_tower(n,'A','C','B');
    return 0;
}