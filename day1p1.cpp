#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream f;
    int ans = 0;
    vector<int> all;
    f.open("input.txt");
    if(!f){
        cerr<<"Bruh"<<endl;
        exit(0);
    }
    string line;
    while (getline(f, line)){
        all.push_back(stoi(line));
    }
    for (int i=0; i<all.size(); i++){
        for (int j=i+1; j<all.size(); j++){
            if (all.at(i)+all.at(j)==2020){
                ans = all.at(i)*all.at(j);
                i=all.size();
                j=all.size();
            }
        }
    }
    cout<<ans<<endl;

    
}