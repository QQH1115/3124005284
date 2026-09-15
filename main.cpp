#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

using namespace std;

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

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "用法: " << argv[0] << " <原文> <抄袭版> <结果>" << endl;
        return 1;
    }

    string orig = readfile(argv[1]);
    string cop  = readfile(argv[2]);


    return 0;
}