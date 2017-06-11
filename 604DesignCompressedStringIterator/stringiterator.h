//
// Created by leslie-fang on 2017/6/11.
//

#ifndef C_SOLUTION2LEETCODE_STRINGITERATOR_H
#define C_SOLUTION2LEETCODE_STRINGITERATOR_H
#include <string>
#include <vector>
using namespace std;
class StringIterator {
public:
    vector<char> uncompressedString;
    StringIterator(string compressedString);
    string::iterator snit= compressedString.begin();
    char next();

    bool hasNext();
};

#endif //C_SOLUTION2LEETCODE_STRINGITERATOR_H
