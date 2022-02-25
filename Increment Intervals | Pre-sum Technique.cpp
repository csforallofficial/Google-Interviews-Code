#include<bits/stdc++.h>
using namespace std;

//The presum_technique Function Will Give Us The Final Answer.
vector<int> presum_technique(vector<int> Arr, vector<vector<int>> Intervals){
    vector<int> ans;        //ans -> Will Store The Final Array.
    int N = Arr.size();     //N -> Will Contain Size Of The Original Array.
    vector<int> dummy(N+1,0);       //Creating Dummy Array Of Size (N+1). Initially All Elements = 0.
    
    //Step 1 -> Incrementing and Decrementing Simultaneously.
    for(auto Interval:Intervals){       //Iterate Through Each Interval.
        int left = Interval[0];     //left -> Storing Start of Interval.
        int right = Interval[1];        //right -> Storing Start of Interval.
        dummy[left] += 1;       //Incrementing Value In The Dummy Array At left Index by (+1).
        dummy[right+1] -= 1;        //Decrementing Value In The Dummy Array At (right+1) Index by (-1).
    }
    
    //Step 2 -> Prefix Sum.
    for(int i = 1; i < (N+1); i++){
        dummy[i] += dummy[i-1];     //Value At Current Index += Value At Previous Index. 
    }
    
    //Step 3 -> Add Dummy Array Values To The Original Array.
    for(int i = 0; i < N; i++){
        ans[i] = Arr[i] + dummy[i];
    }
    
    return ans;
}

int main(){
    
    int N;      //N -> Size Of The Original Array.
    cin >> N;
    vector<int> Arr;        //Arr -> Original Array.
    for(int i = 0; i < N; i++){     //Taking N Inputs In The Array.
        int inp;
        cin >> inp;
        Arr.push_back(inp);
    }
    
    int M;      //M -> Size Of The List Of Intervals.
    cin >> M;
    vector<vector<int>> Intervals(M,vector<int>(2));      //Intervals -> The List Of Intervals.
    for(int i = 0; i < M; i++){     //Taking M Inputs Each Of Size 2 In the List (Vector Of Vectors).
        vector<int> Interval(2,0);       //Creating A Vector To Store The Start And End Of Each Interval.
        int left;
        cin >> left;        //left -> Starting Of The Interval Range.
        int right;
        cin >> right;       //right -> Ending Of The Interval Range.
        Interval[0] = left;       //Storing Start Of Each Interval.
        Interval[1] = right;      //Storing End Of Each Interval.
        Intervals[i] = Interval;      //Storing Each Interval Into The List Of Intervals.
    }
    
    vector<int> resultant = presum_technique(Arr,Intervals);        //Resultant Will Store Final Ans.
    
    for(int i = 0; i < resultant.size(); i++)     //Printing The Final Answer.
        cout << resultant[i] << " ";
    cout << endl;
    
    return 0;
}
