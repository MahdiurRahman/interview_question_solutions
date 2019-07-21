/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

#include <iostream>
#include <vector>
using namespace std;

    vector<int> distribute(vector<int> &line, vector<int> &candies, bool forwards) {
        int mover = 1; 
        int inc = 1;
        if (!forwards) {
            mover = line.size() - 2;
            inc = -1;
        }
        while (((!forwards) and (mover > -1)) or (forwards and (mover < line.size()))) {
            if (line[mover] > line[mover - inc]) {
                if (candies[mover] <= candies[mover - inc])
                    candies[mover] = candies[mover - inc] + 1;
            }
            mover += inc;
        }

        return candies;
    }

    int sum(vector<int> &arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        return sum;
    }
    
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        distribute(ratings, candies, true);
        distribute(ratings, candies, false);
        return sum(candies);
    }

int main() {
    vector<int> run;
    run.push_back(1);
    run.push_back(0);
    run.push_back(2);
    cout << candy(run) << endl;
    return 0;
}