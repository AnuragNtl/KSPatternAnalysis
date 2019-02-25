#ifndef EXTRACTION_H
#define EXTRACTION_H
#include<string>
#include<vector>
#include<functional>
/*
 1-9:2-10
 11:0
 Q-P:16-25
 A-L:30-38
 Z-M:44-50
 */
using namespace std;

class Sequence
{

};
  
class SimpleExraction
{
  private:
    vector<vector<bool> > &data;
  public:
    SimpleExraction();
    SimpleExtraction(vector<vector<bool> >&);
    float getSpeed();
    short getCharacterLength();
    short getWordsLength();
    short getSentenceLength();
    string getRaw();
    vector<string> getWords();
    template<class Arg,class Result>
    Result apply(unary_function<Arg,Result>);
};

#endif

