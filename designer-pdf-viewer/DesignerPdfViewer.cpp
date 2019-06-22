#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<char> alphabet{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vector<char> stringToArray(string s) {
    int n = s.length(); 
    char chars[n]; 
    strcpy(chars, s.c_str());
    vector<char> charsVector;
    for (int i = 0; i < n; i++) {
        charsVector.push_back(chars[i]);
    }

    return charsVector;
}

int findIndexForChar(char ch) {
    for (int i = 0; i < alphabet.size(); i++) {
        if (alphabet[i] == ch) {
            return i;
        }
    }
    return 0;
}

int getHeightForChar(vector<int> h, char ch) {
    int index = findIndexForChar(ch);
    return h[index];
}

// Complete the designerPdfViewer function below.
int designerPdfViewer(vector<int> h, string word) {
    vector<char> chars = stringToArray(word);
    vector<int> heights{};
    for (int i = 0; i < chars.size(); i++) {
        heights.push_back(getHeightForChar(h, chars[i]));
    }
    int max = heights[0];
    for (int i = 1; i < heights.size(); i++) {
        if (heights[i] > max) {
            max = heights[i];
        }
    }
    return word.length() * max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(26);

    for (int i = 0; i < 26; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    string word;
    getline(cin, word);

    int result = designerPdfViewer(h, word);

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
