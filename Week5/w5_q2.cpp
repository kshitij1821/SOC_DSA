#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int testCases;
    cin >> testCases; 

    while(testCases--) 
    {
        int numElements;
        cin >> numElements; 

        long long currentMin = 0, currentMax = 0;
        long long minCount = 1, maxCount = 0;
        
        // Iterate through each element in the array
        for(int i = 0; i < numElements; i++)
        {
            int element;
            cin >> element; // Read the current element
            
            long long prevMin = currentMin;
            long long prevMax = currentMax;

            currentMin += element;
            currentMax = max(abs(currentMin), abs(currentMax + element));

            long long tempMinCount = 0, tempMaxCount = 0;

            // Update counts based on the new currentMin
            if(currentMin == prevMin + element) tempMinCount += minCount;
            if(currentMin == abs(prevMin + element)) tempMinCount += minCount;
            if(currentMin == prevMax + element) tempMinCount += maxCount;
            if(currentMin == abs(prevMax + element)) tempMinCount += maxCount;

            // Update counts based on the new currentMax
            if(currentMax == prevMin + element) tempMaxCount += minCount;
            if(currentMax == abs(prevMin + element)) tempMaxCount += minCount;
            if(currentMax == prevMax + element) tempMaxCount += maxCount;
            if(currentMax == abs(prevMax + element)) tempMaxCount += maxCount;

           
            if(currentMin == currentMax) tempMinCount = 0;

            // Ensure counts are within the given modulus
            minCount = tempMinCount % 998244353;
            maxCount = tempMaxCount % 998244353;
        }

        cout << maxCount << endl; // Output the result for the current test case
    }

    return 0;
}
