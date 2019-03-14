#ifndef EXTRACTION_H
#define EXTRACTION_H
#include<string>
#include<vector>
#include<functional>
#include<map>
/*
 1-9:2-10
 0:11
 Q-P:16-25
 A-L:30-38
 Z-M:44-50
 */
using namespace std;

class SymbolCheck
{
    public:
    bool operator()(int index)
    {
        return true;
    }
};
bool controlCheck(int index)
{
    return true;
}
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
class SimpleExtraction
{
  private:
    vector<vector<bool> > &data;
    vector<vector<int> > positions;
    const map<int,int> keyCharacterMap;
  protected:
      void applyToAllLists(function<void(vector<int>)>) const;
  public:
    SimpleExtraction(vector<vector<bool> >&);
    void initKeyCharacterMap();
    float getSpeed();
    short getCharacterLength();
    short getWordsLength();
    short getSentenceLength();
    string getRaw();
    vector<string> getWords();
    vector<string> getTypedCharacters();
    int countActionKeys();
    int countAlphas();
    int countAlnums();
    int countDigits();
    int countSymbols();
    template<class Arg,class Result>
    Result apply(unary_function<Arg,Result>);
};
void SimpleExtraction :: initKeyCharacterMap()
{
    /*
 1-9:2-10
 0:11
 Q-P:16-25
 A-L:30-38
 Z-M:44-50
 */

}
SimpleExtraction :: SimpleExtraction(vector<vector<bool> > &data)
{
    this->data=data;
    for(auto it=data.begin();it!=data.end();it++)
    {
        vector<int> ss;
        for(int i=0;i<it->size();i++)
        {
            if((*it)[i])
                ss.push_back(i);
        }
        positions.push_back(ss);
    }
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
short SimpleExtraction :: getCharacterLength()
{
  int ct=0;
  for_each(data.begin(),data.end(),[&,ct](vector<bool> &v){
ct+=count_if(data.begin(),data.end(),[](bool indx){
return indx;
    });
      });
}
short SimpleExtraction :: countAlphas()
{
   short ct=0;
    for_each(positions.begin(),positions.end(),
        [&,ct](vector<int> &v)
        {
            ct+=count_if(v.begin(),v.end(),AlphaCheck());
        });
    return ct;
}
bool digitCheck(int indx)
{
  return indx>=2 && indx<=11;
}
short SimpleExtraction :: countDigits()
{
short ct=0;
for_each(positions.begin(),positions.end(),[&ct](vector<int> &data)
    {
    ct+=count_if(data.begin(),data.end(),digitCheck);
    });
return ct;
}
short SimpleExtraction :: countAlnums()
{
return countAlphas()+countDigits();
}
bool spaceCheck(int index)
{
    return true;
}
vector<string> SimpleExtraction :: getTypedCharacters()
{
    vector<string> words;
applyToAllLists([&words](vector<int> data) -> void
{
    string word="";
    for(int i=0;i<data.size();i++)
    {
    if(controlCheck(data[i]))
    break;
    else if(spaceCheck(data[i]))
    word=word+
}

    if(i<data.size())
    return;
});
return words;
}
vector<string> SimpleExtraction :: getTypedWords()
{
    
}
void SimpleExtractions :: applyToAllLists(function<void(vector<int>)> f) const
{
    for_each(positions.begin(),positions.end(),f);
}
#endif

