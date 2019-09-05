#include <bits/stdc++.h>

using namespace std;

#define NUM_LETTERS 26
#define ASCII_OFFSET 97

char construct[5001];

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {
    int n = s.size();
    int total[NUM_LETTERS] = {};
    int need[NUM_LETTERS];

    for(int i = 0; i < n; ++i) {
        ++total[s[i]-ASCII_OFFSET];
    }

    for(int i = 0; i < NUM_LETTERS; ++i) {
        need[i] = total[i]/2;
    }
    
    int ind = 0;
    for(int i = n-1; i >= 0; --i) {
        if (need[s[i]-ASCII_OFFSET] > 0) {
            while(ind > 0 && s[i] < construct[ind-1] && need[construct[ind-1]-ASCII_OFFSET] < total[construct[ind-1]-ASCII_OFFSET]) {
                --ind;
                ++need[construct[ind]-ASCII_OFFSET];
            }
            construct[ind] = s[i];
            --need[s[i]-ASCII_OFFSET];
            ++ind;
        }
        --total[s[i]-ASCII_OFFSET];
    }
	construct[ind] = 0;

    return construct;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
