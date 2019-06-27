#include <bits/stdc++.h>

using namespace std;

/*
korzystając z wiedzy o tym, że:
5 to 12345 % 10
4 to 12345 / 10 % 10
3 to 12345 / 100 % 10
2 to 12345 / 1000 % 10
1 to 12345 / 10000 % 10
*/

// Complete the findDigits function below.
int findDigits(int n) {
    int numberLength = to_string(n).length();

    int divisor = 1;
    int result = 0;
    for (int i = 0; i < numberLength; i++) {
        int figure = (n / divisor) % 10;
        if (figure == 0) {
            divisor = divisor * 10;
            continue;
        } else if (n % figure == 0) {
            result = result + 1;
        }
        divisor = divisor * 10;
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
