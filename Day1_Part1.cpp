#include<bits/stdc++.h>
using namespace std;
int main() {
    fstream file;
    file.open("input.txt",ios::in);
    string line;
    int dial_point = 50;
    int max_point = 100;
    int password_count = 0;
    while(getline(file, line)) {
        char direction = line[0];
        int distance = stoi(line.substr(1));
        if(direction == 'R') {
            dial_point += distance;
            dial_point %= max_point;
        } else {
            dial_point -= distance;
            while(dial_point < 0) {
                dial_point += max_point;
            }
        }
        if(dial_point == 0) password_count++;
    }
    cout<<password_count;
}