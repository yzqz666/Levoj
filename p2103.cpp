#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 比较两个大浮点数的大小，如果 a >= b 返回 true，否则返回 false
bool isGreaterOrEqual(string a, string b) {
    size_t dotA = a.find('.');
    size_t dotB = b.find('.');
    string intA = (dotA == string::npos) ? a : a.substr(0, dotA);
    string decA = (dotA == string::npos) ? "" : a.substr(dotA + 1);
    string intB = (dotB == string::npos) ? b : b.substr(0, dotB);
    string decB = (dotB == string::npos) ? "" : b.substr(dotB + 1);

    if (intA.length() > intB.length()) return true;
    if (intA.length() < intB.length()) return false;
    if (intA > intB) return true;
    if (intA < intB) return false;

    if (decA.length() > decB.length()) {
        string tempB = decB;
        tempB.append(decA.length() - decB.length(), '0');
        return decA >= tempB;
    } else if (decA.length() < decB.length()) {
        string tempA = decA;
        tempA.append(decB.length() - decA.length(), '0');
        return tempA >= decB;
    } else {
        return decA >= decB;
    }
}

// 大整数减法，假设 a >= b
string subtractLargeIntegers(string a, string b) {
    string result = "";
    int n = a.length();
    int m = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    for (int i = 0; i < n; ++i) {
        int digitA = a[i] - '0';
        int digitB = (i < m) ? (b[i] - '0') : 0;
        int diff = digitA - digitB - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result += to_string(diff);
    }
    reverse(result.begin(), result.end());
    size_t firstNonZero = result.find_first_not_of('0');
    if (string::npos == firstNonZero) {
        return "0";
    }
    return result.substr(firstNonZero);
}

// 大浮点数减法
string subtractLargeFloats(string a, string b) {
    bool negative = false;
    if (!isGreaterOrEqual(a, b)) {
        swap(a, b);
        negative = true;
    }

    size_t dotA = a.find('.');
    size_t dotB = b.find('.');
    string intA = (dotA == string::npos) ? a : a.substr(0, dotA);
    string decA = (dotA == string::npos) ? "" : a.substr(dotA + 1);
    string intB = (dotB == string::npos) ? b : b.substr(0, dotB);
    string decB = (dotB == string::npos) ? "" : b.substr(dotB + 1);

    int maxDecLen = max(decA.length(), decB.length());
    while (decA.length() < maxDecLen) decA += '0';
    while (decB.length() < maxDecLen) decB += '0';

    string combinedA = intA + decA;
    string combinedB = intB + decB;

    string diffCombined = subtractLargeIntegers(combinedA, combinedB);

    string intPart = (diffCombined.length() > (size_t)maxDecLen) ? diffCombined.substr(0, diffCombined.length() - maxDecLen) : "0";
    string decPart = (diffCombined.length() > (size_t)maxDecLen) ? diffCombined.substr(diffCombined.length() - maxDecLen) : diffCombined;

    while (decPart.length() > 1 && decPart.back() == '0') {
        decPart.pop_back();
    }

    if (intPart == "0" && decPart == "0") {
        return "0.0";
    }

    string result = "";
    if (negative) {
        result += "-";
    }
    result += intPart;
    result += ".";
    result += (decPart.empty() ? "0" : decPart);

    return result;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    cout << subtractLargeFloats(num1, num2) << endl;
    return 0;
}