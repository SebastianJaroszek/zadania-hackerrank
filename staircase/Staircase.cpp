#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {

    for (int i = n; i > 0; i--) {
        std::string staircase(n, '#');
        string result = staircase.replace(0, i - 1, std::string(i - 1, ' '));
        cout << result << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
