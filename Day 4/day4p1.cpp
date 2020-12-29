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
    vector<string> list;
    if (!f){
        cerr<<"Bruh"<<endl;
        exit(0);
    }
    string line;
    while (getline(f,line)){
        list.push_back(line);
    }
    
    int valid=0;
    vector<string> words = {"byr","iyr","eyr","hgt","hcl","ecl","pid"};
    int counter=0;
    vector<string> order;
    string lol = list[2];
    for (int i=0; i<list.size();i++){
        if (list[i]==lol){
            for (int k=0; k<7; k++){
                for (int m=0; m<order.size();m++){
                    if (order[m] == words[k]){
                        counter++;
                        m=order.size();
                    }
                }
            }
            if (counter==7){
                valid+=1;
            }
            order.clear();
            counter=0;
        }

        else{
            while (counter<list[i].size()){
                if (list[i][counter]==':'){
                    order.push_back(list[i].substr(counter-3,3));
                }
                counter++;
            }
            counter=0;
        }
    }  
    cout<<valid<<endl;
}