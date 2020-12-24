#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ifstream f;
    int counter=0; //final result
    string initial;
    int min; //minimum
    string end;
    int max; //maximum
    char req; //letter that has requirment
    string temp; 
    int point; //point to current char
    int charCount=0; //counts characters per password of desired word
    string pass;
    vector<string> all;

    f.open("input.txt");
    if(!f){
        cerr<<"Bruh"<<endl;
        exit(0);
    }
    string line;
    while (getline(f, line)){
        all.push_back(line);
    }
    for (int i=0; i<all.size(); i++){
        point = 0;
        while (all.at(i).at(point) != '-'){
            initial+=all.at(i).at(point);
            point++;
        }
        min = stoi(initial);
        initial = "";
        point++;
        while (all.at(i).at(point) != ' '){
            end+=all.at(i).at(point);
            point++;
        }
        max = stoi(end);
        end = "";
        point++;
        req = all.at(i).at(point);
        point+=3;
        pass=all.at(i).substr(point,all.at(i).size());
        for (int i=0; i<pass.size(); i++){
            if (pass.at(i) == req){
                charCount++;
            }
        }
        if (charCount<=max && charCount>=min){
            counter++;
        }
        charCount=0;

    }
    cout<<counter<<endl;
}