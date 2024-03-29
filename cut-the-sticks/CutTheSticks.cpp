#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> counts{};

int findMinimum(vector<int> arr) {
    int min = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

vector<int> cut(vector<int> arr) {
    int min = findMinimum(arr);
    vector<int> newArr{};
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = arr[i] - min;
        if (arr[i] > 0) {
            newArr.push_back(arr[i]);
        }
    }
    return newArr;
}

void recurrenceCutting(vector<int> arr) {
    counts.push_back(arr.size());
    arr = cut(arr);
    if (arr.size() > 0) {
        recurrenceCutting(arr);
    }
}

// Complete the cutTheSticks function below.
vector<int> cutTheSticks(vector<int> arr) {
    recurrenceCutting(arr);
    return counts;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = cutTheSticks(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
