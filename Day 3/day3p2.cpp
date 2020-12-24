#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

int main(){
    double maptree; //trees on each map
    double ans=0;; //trees multiplied on each other
    ifstream f;
    f.open("input.txt");
    vector<string> map;
    vector<double> treecount;
    if (!f){
        cerr<<"Bruh"<<endl;
        exit(0);
    }
    string line;
    while (getline(f,line)){
        map.push_back(line);
    }
    int counter;
    int placeholder=1;
    for (int k=0; k<4; k++){
        counter=0;
        for (int i=0; i<map.size(); i++){
            if (map.at(i)[counter] == '#'){
                maptree+=1.0;
            }
            counter+=placeholder;
            if (counter>30){
                counter=counter-31;
            }
        }
        placeholder+=2;
        treecount.push_back(maptree);
        cout<<maptree<<endl;
        maptree=0;
    }
    counter=0;
    maptree=0;
    for (int i=0; i<map.size(); i+=2){
        if (map.at(i)[counter] == '#'){
            maptree++;
        }
        counter+=1;
        if (counter>30){
            counter=counter-31;
        }
    }
    treecount.push_back(maptree);
    ans = treecount.at(0);
    for (int i=1; i<treecount.size(); i++){
        ans*=treecount.at(i);
    }
    cout.precision(30);
    cout << ans << endl;
}