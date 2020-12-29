#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

int main(){
    ifstream f;
    f.open("input.txt");
    vector<string> list; //raw list

    if (!f){
        cerr<<"Bruh"<<endl;
        exit(0);
    }
    string line;
    while (getline(f,line)){
        list.push_back(line);
    }
    vector <string> needed = {"byr","iyr","eyr","hgt","hcl","ecl","pid"};
    int valid = 0;
    int ans=0;
    size_t str;
    string compare=list[2];
    for (auto& s: list){
        for (auto&p: needed){
            if (s==compare){
                if (valid==7){
                    ans++;
                }
                valid=0;
            }
            str = s.find(p);
            if(str != string::npos){
                valid++;
            }
        }
        cout<<valid<<endl;
    }
    cout<<ans<<endl;
}