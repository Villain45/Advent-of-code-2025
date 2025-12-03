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
            password_count += (dial_point/max_point);
            dial_point %= max_point;
        } else {
            password_count += (distance/max_point);
            if(dial_point != 0 && (distance % max_point)>=dial_point) {
                password_count++;
            }
            dial_point = (dial_point - (distance % max_point) + max_point) % max_point;
        }
    }
    cout<<password_count;
}