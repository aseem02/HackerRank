#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the pylons function below.
int pylons(int k, vector<int> arr) {
    int counter = 0;
    int prev = -1;
    int curr = 0;

    for(int i = 0; i < k; ++i) {
        if (arr[i] == 1) {
            prev = i;
        }
    }

    if(prev < 0) {
        return -1;
    }
    ++counter;

    for(int i = k; i < arr.size(); ++i) {
        if (arr[i] == 1) {
            curr = i;
        }
        if (i == prev + 2*k - 1) {
            if (curr > prev) {
                ++counter;
                prev = curr;
            } else {
                return -1;
            }
        }
    }

    if (prev + k < arr.size()) {
        if(curr + k >= arr.size()) {
            ++counter;
        } else {
            return -1;
        }
    }

    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pylons(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}