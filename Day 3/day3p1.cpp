#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

int main(){
    int ans;
    ifstream f;
    f.open("input.txt");
    vector<string> map;
    if (!f){
        cerr<<"Bruh"<<endl;
        exit(0);
    }
    string line;
    while (getline(f,line)){
        map.push_back(line);
    }
    int counter=0;
    for (int i=0; i<map.size(); i++){
        if (map.at(i)[counter] == '#'){
            ans++;
        }
        counter+=7;
        if (counter>30){
            counter=counter-31;
            
        }
    }
    cout<<ans<<endl;
}