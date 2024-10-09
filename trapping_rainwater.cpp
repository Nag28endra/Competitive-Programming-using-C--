#include<bits/stdc++.h>
using namespace std;
int Optimal_Approach(vector<int> heights){
    int leftCurrentBuilding = 0;
    int rightCurrentBuilding = heights.size() - 1;
    int leftMostTallerBuilding = 0;
    int rightMostTallerBuilding = 0;
    int total = 0;

    while(leftCurrentBuilding < rightCurrentBuilding){

        //check which building is smaller among both right and left buildings
        if (heights[leftCurrentBuilding] <= heights[rightCurrentBuilding]){

            // check is there any left most taller building existed.
            // if existed find the total water trapped on the current building
            if (leftMostTallerBuilding > heights[leftCurrentBuilding])
                total += leftMostTallerBuilding - heights[leftCurrentBuilding];
            // make the current building as the left most taller building
            else 
                leftMostTallerBuilding = heights[leftCurrentBuilding];
            leftCurrentBuilding += 1;

        }
        else{

            // check is there any right most taller building existed.
            // if existed find the total water trapped on the current building
            if (rightMostTallerBuilding > heights[rightCurrentBuilding])
                total += rightMostTallerBuilding - heights[rightCurrentBuilding];
            // make the current building as the right most taller building
            else 
                rightMostTallerBuilding = heights[rightCurrentBuilding];
            rightCurrentBuilding -= 1;

        }
    }
    return total;
}
int Naive_Approach(vector<int> heights){

    /*
        Time complexity : O(3N)
        Space Complexity: o(2N)
    */
    int totalWaterTrapped = 0;
    int len = heights.size();
    // prefixMax and suffixMax are used for finding the left most and right most tall buildings for the current building.
    int prefixMax[len], suffixMax[len];
    prefixMax[0] = heights[0];
    suffixMax[len-1] = heights[len-1];
    for(int i = 1 ; i<len; i++){
        prefixMax[i] = max(prefixMax[i-1], heights[i]);
    }
    for(int i = len-2 ; i>=0; i--){
        suffixMax[i] = max(suffixMax[i+1], heights[i]);
    }

    for(int i = 0; i<len; i++){
        int leftMax = prefixMax[i];
        int rightMax = suffixMax[i];

        if(heights[i] < leftMax && heights[i] < rightMax) 
            totalWaterTrapped += min(leftMax,rightMax) - heights[i];
    }
    return totalWaterTrapped;

}
int main()
{
    vector<int> heights = {4,2,0,3,2,5};
    cout<<Optimal_Approach(heights);
    return 0;
}