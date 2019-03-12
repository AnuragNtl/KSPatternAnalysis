#ifndef EXTRACTION_H
#define EXTRACTION_H
#include<string>
#include<vector>
#include<functional>
/*
 1-9:2-10
 0:11
 Q-P:16-25
 A-L:30-38
 Z-M:44-50
 */
using namespace std;

class Sequence
{

};

class AlphaCheck : public unary_function<bool,int>
{
  public:
    bool operator()(int) const;
}; 
bool AlphaCheck :: operator()(int index) const
{
return (index>=16 && index<=25) || (index>=30 && index<=38) || (index>=44 && index<=50);
}
class DigitCheck
{
  public:
    bool operator()(int index)
    {
    return index>=2 && index<=11;
    }
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
    int countActionKeys();
    int countAlphas();
    int countAlnums();
    int countDigits();
    int countSymbols();
    template<class Arg,class Result>
    Result apply(unary_function<Arg,Result>);
};
SimpleExtraction :: SimpleExtraction(){}
SimpleExtraction :: SimpleExtraction(vector<vector<bool> > &data)
{
    this->data=data;
}
float SimpleExtraction :: getSpeed()
{
    int ct=0,len=0;
    for(int i=0;i<data.size();i++)
    {
        for(int k=0;k<data[i].size();k++)
            if(data[i][k])
                ct++;
            len++;
    }
    return (len>0?ct/len:0);
}
short SimpleExraction :: getCharacterLength()
{
  int ct=0;
  for_each(data.begin(),data.end(),[&,ct](vector<int> &v){
ct+=count_if(data.begin(),data.end(),[](int indx){
return indx>0;
    });
      });
}
short SimpleExraction :: countAlphas()
{

}
#endif

