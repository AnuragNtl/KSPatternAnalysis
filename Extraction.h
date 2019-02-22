#ifndef EXTRACTION_H
#define EXTRACTION_H
#include<string>
#include<vector>

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
};
#endif

