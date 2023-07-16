#include <iostream>

#include<string>

#include <cstdio>

using namespace std;

string spaceCorrector(string text) {

    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (i == 0 && text[i] == ' ') {
            continue;
        }
        else if (i + 1 == text.length()) {
            if (text[i] == ' ') {
                break;
            }
            else {
                result += text[i];
                break;
            }

        }
        else if (text[i] == ' ' && text[i + 1] == ' ') {
            continue;
        }
        else {

            result += text[i];

        }

    }

    return result;

}
string strCutter(string text, int startIndex, int endIndex) {

    string result = "";

    for (int i = startIndex; i <= endIndex; i++) {
        result += text[i];
    }

    return result;

}
string spaceAdder(string text, int numSpace) {

    string tempText = text;
    string result = "";
    int maxLen = tempText.length();

    for (int i = 0; i < maxLen; i++) {
        if (text[i] == ' ') {
            if (numSpace > 0) {
                result += "  ";
                --numSpace;
                while (true) {
                    if (text[i + 1] == ' ') {
                        i++;
                        result += " ";
                    }
                    else {
                        break;
                    }
                }
            }
            else {

                result += text[i];

            }

        }
        else {
            result += text[i];
        }
        if (numSpace == 0 && i == tempText.length() - 1) {
            return result;
        }
        else if (i == tempText.length() - 1 && numSpace > 0) {

            return spaceAdder(result, numSpace);

        }

    }

    return result;
}
void textAligner(string text, int lineLength) {

    int startIndex = 0;
    int endIndex = lineLength;
    string temp = "";
    int lastSpaceIndex = 0;
    for (int i = startIndex; i < endIndex; i++) {

        if (strCutter(text, startIndex, text.length() - 1).length() < lineLength) {
            temp = strCutter(text, startIndex, text.length() - 1);
            temp = spaceAdder(temp, lineLength - temp.length());
            cout << temp << endl;
            break;
        }
        if (i + 1 == endIndex) {

            if (text[i] != ' ' && text[i + 1] == ' ') {
                temp = strCutter(text, startIndex, endIndex - 1);
                cout << temp << endl;
                startIndex = i + 2;
                i = i + 2;
                endIndex = startIndex + lineLength;
            }
            else if (text[i] == ' ') {
                temp = strCutter(text, startIndex, lastSpaceIndex) + " " + strCutter(text, lastSpaceIndex + 1, i - 1);
                cout << temp << endl;
                startIndex = i + 1;
                i = i + 1;
                endIndex = startIndex + lineLength;
            }
            else if (text[i] != ' ' && text[i + 1] != ' ') {

                temp = strCutter(text, startIndex, lastSpaceIndex - 1);
                temp = spaceAdder(temp, lineLength - temp.length());
                cout << temp << endl;
                startIndex = lastSpaceIndex + 1;
                i = lastSpaceIndex + 1;
                endIndex = startIndex + lineLength;
            }

        }
        if (text[i] == ' ') {
            lastSpaceIndex = i;
        }

    }

}
int main() {

    string text;
    getline(cin, text);
    cout << endl << endl;
    text = spaceCorrector(text);
    textAligner(text, 60);

    return 0;
}