#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, char symbol) {
    string foundPiece = s.substr(0, s.find(symbol));
    s.erase(0, s.find(symbol) + 1);
    vector<string> result{foundPiece, s};
    return result;
}

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    string amPm = s.substr(8, 9);
    s.erase(8, 9);
    vector<string> splittedHours = split(s, ':');
    string hour = splittedHours[0];
    s = splittedHours[1];

    if (hour == "12" && amPm == "AM") {
        hour = "00";
    } else if (amPm == "PM" && hour != "12") {

        if (hour.substr(0, 1) == "0") {
            hour = hour.substr(1, 1);
        }

        int hourAsInt = stoi(hour);
        hourAsInt = hourAsInt + 12;
        
        if (hourAsInt < 10) {
            hour = "0" + to_string(hourAsInt);
        } else {
            hour = to_string(hourAsInt);
        }
    }

    return hour + ":" + s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
