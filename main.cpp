#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <iterator>

using namespace std;
using ll = long long;

string readfile(const string& x) {
    ifstream file(x);
    if (!file.is_open()) {
        throw runtime_error("无法打开文件: " + x);
    }
    string content((istreambuf_iterator<char>(file)),
                    istreambuf_iterator<char>());
    file.close();
    return content;
}

map<string, ll> tokenize(const string& x) {
    map<string, ll> collect;
    string word;

    for (size_t i = 0; i < x.size(); i++) {
        unsigned char c = static_cast<unsigned char>(x[i]);
        if (isalpha(c)) {
            word += tolower(c);
        }
        else if (c >= 0x80) {
            if (!word.empty()) {
                collect[word]++;
                word.clear();
            }
            ll len = 1;
            if ((c & 0xE0) == 0xC0) len = 2;
            else if ((c & 0xF0) == 0xE0) len = 3;
            else if ((c & 0xF8) == 0xF0) len = 4;
            word = x.substr(i, len);
            collect[word]++;
            word = "";
            i = i + len - 1;
        }
        else {
            if (!word.empty()) {
                collect[word]++;
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        collect[word]++;
    }
    return collect;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "用法: " << argv[0] << " <原文> <抄袭版> <结果>" << endl;
        return 1;
    }

    string orig = readfile(argv[1]);
    string cop  = readfile(argv[2]);

    map<string, ll> ori = tokenize(orig);
    map<string, ll> co  = tokenize(cop);



    return 0;
}