#include<bits/stdc++.h>
using namespace std;

bool check_validity(int possible_speed, vector<int> &distances, int threshold_time){
    int time_required = 0;
    for(auto distance:distances){
        time_required += ceil(distance/possible_speed);
    }
    if(time_required<=threshold_time)
        return true;
    return false;
}

int main(){
    int size;
    cin >> size;
    int max_element = INT_MIN;
    vector<int> distances;
    for(int distance = 0; distance < size; distance++){
        int distance_input;
        cin >> distance_input;
        max_element = max(max_element,distance_input);
        distances.push_back(distance_input);
    }
    int threshold_time;
    cin >> threshold_time;
    int left_of_range = 1, right_of_range = max_element;
    int min_speed = 1;
    while(left_of_range<=right_of_range){
        int possible_speed = left_of_range + (right_of_range - left_of_range)/2;
        if(check_validity(possible_speed,distances,threshold_time)){
            min_speed = possible_speed;
            right_of_range = possible_speed-1;
        } else{
            left_of_range = possible_speed+1;
        }
    }
    cout << min_speed << endl;
    return 0;
}
