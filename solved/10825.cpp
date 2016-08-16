#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef struct student{
    string name;
    int kor, eng, math;
    student(){}
    student(string name, int kor, int eng, int math):name(name),kor(kor),eng(eng),math(math){}
    bool operator<(const student& s) const{
        if(this->kor != s.kor) return this->kor > s.kor;
        if(this->eng != s.eng) return this->eng < s.eng;
        if(this->math != s.math ) return this->math > s.math;
        return this->name < s.name;
    }
}student;
int main(){
    int n; scanf("%d",&n);
    student list[100000];
    for( int i = 0 ; i < n ; ++i ){
        string n;int k,e,m; cin >> n >> k >> e >> m;
        list[i] = student(n,k,e,m);
    }
    sort(list,list+n);
    for( int i = 0 ; i < n ; ++i ){
        printf("%s\n",list[i].name.c_str());
    }
    return 0;
}