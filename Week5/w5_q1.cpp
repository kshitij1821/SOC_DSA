#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    getline(cin, input);

    int max_length = 0;
    int occurrence = 0;

    int length = input.size();
    int* dp = new int[length + 1];
    dp[length] = 0;

    for(int i = length - 1; i >= 0; i--)
    {
        if(input[i] == ')') { dp[i] = 0; continue; }
        int next_index = i + 1;
        while(true)
        {
            if(next_index >= length) { dp[i] = 0; break; }
            if(input[next_index] == ')') { dp[i] = next_index - i + 1 + dp[next_index + 1]; break; }
            else
            {
                if(dp[next_index] == 0) { dp[i] = 0; break; }
                else { next_index += dp[next_index]; }
            }
        }

        if(max_length < dp[i]) { occurrence = 1; max_length = dp[i]; }
        else if(max_length == dp[i]) { occurrence += 1; }
    }

    cout << max_length << " ";
    if(max_length == 0) { cout << 1 << endl; }
    else { cout << occurrence << endl; }

    delete[] dp;
    return 0;
}