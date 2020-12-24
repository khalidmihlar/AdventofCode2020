#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

int main(){
    stringstream ss;
    string a,b,c,d,e;
    
    ss << "Hello this is a string";
    ss>>a>>b>>c>>d>>e;
    cout<<a<<"|||"<<b<<"|||"<<c<<"|||"<<d<<"|||"<<e<<endl;
    return 0;
}