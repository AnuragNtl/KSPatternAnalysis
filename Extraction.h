#ifndef EXTRACTION_H
#define EXTRACTION_H
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
#include<map>
#include<set>

/*
 1-9:2-10
 0:11
 Q-P:16-25
 A-L:30-38
 Z-M:44-50
 Space:57
 Controls:1,15,28,29,42,54,56,57(space),58,59-248
 Symbols:12-14,26,27,29,39-41,43,51-54,55
 */
using namespace std;
///////////////////////////////////
ostream& operator<<(ostream &out,set<int> &data)
{
    set<int> :: iterator it=data.begin();
    out <<"[";
    for(it=it;it!=data.end();it++)
        cout <<*it <<" ";
    out <<"]\n";
return out;
}
///////////////////////////////////
struct KeyCodeMap
{
set<int> controlKeys;
set<int> symbols;
int space;
int bkspace,tab;
set<int> alphabets;
int enter1,enter2;
set<int> numbers;
void initializeDefaultControlKeys();
void initializeDefaultAlphaKeys();
void initializeDefaultSymbolKeys();
void initializeDefaultNumberKeys();
void initializeDefaultEnter();
void initializeDefaultSpaces();
KeyCodeMap();
void printAll()
{
    cout <<controlKeys <<symbols <<alphabets <<numbers;
}
}defaultKeyCodeMap;
KeyCodeMap :: KeyCodeMap()
{
initializeDefaultSpaces();
initializeDefaultEnter();
initializeDefaultNumberKeys();
initializeDefaultAlphaKeys();
initializeDefaultSymbolKeys();
initializeDefaultControlKeys();
printAll();
}

void KeyCodeMap :: initializeDefaultEnter()
{
    this->enter1=0x001c;
    this->enter2=0x0060;
}
void KeyCodeMap :: initializeDefaultSpaces()
{
    this->bkspace=14;
    this->space=57;
    this->tab=15;
}
void KeyCodeMap :: initializeDefaultNumberKeys()
{
    for(int i=2;i<=11;i++)
        numbers.insert(i);
}
void KeyCodeMap :: initializeDefaultAlphaKeys()
{
    int ranges[][2]={{16,25},{30,38},{44,50}};
    for(int i=0;i<3;i++)
    {
        int p=ranges[i][0],q=ranges[i][1];
        for(int k=p;k<=q;k++)
        alphabets.insert(k);
    }
}
void KeyCodeMap :: initializeDefaultSymbolKeys()
{
    int symbolList[]={
0x000c,0x000d,0x001a,0x001b,0x002b,0x0027,0x0028,0x0029,0x0033,0x0034,0x0035,0x0062,0x0037,0x004a,0x004e,0x0053,0x0075};
for(int i=0;i<16;i++)
symbols.insert(symbolList[i]);
}
void KeyCodeMap :: initializeDefaultControlKeys()
{
    for(int i=0;i<=248;i++)
    {
        if(symbols.find(i)==symbols.end() && alphabets.find(i)==alphabets.end() && numbers.find(i)==numbers.end())
            controlKeys.insert(i);
    }
}
class SymbolCheck
{
private:
    KeyCodeMap &kMap;
    public:
        SymbolCheck() : kMap(defaultKeyCodeMap){}
        SymbolCheck(KeyCodeMap &kMap) : kMap(kMap){}
    bool operator()(int index)
    {
        return kMap.symbols.find(index)!=kMap.symbols.end();
    }
};
bool controlCheck(int index)
{
    return defaultKeyCodeMap.controlKeys.find(index)!=defaultKeyCodeMap.controlKeys.end();
}
class AlphaCheck : public unary_function<bool,int>
{
  public:
    bool operator()(int) const;
}; 
bool AlphaCheck :: operator()(int index) const
{
return defaultKeyCodeMap.alphabets.find(index)!=defaultKeyCodeMap.alphabets.end();
}
class DigitCheck
{
  public:
    bool operator()(int index)
    {
    return defaultKeyCodeMap.numbers.find(index)!=defaultKeyCodeMap.numbers.end();
    }
};
class SimpleExtraction
{
  private:
    vector<vector<int> > data;
    vector<vector<int> > positions;
    map<int,int> keyCharacterMap;
    void initKeyCharacterMap();
  protected:
      void applyToAllLists(function<void(vector<int>)>) const;
  public:
    SimpleExtraction(vector<vector<int> >);
    float getSpeed();
    short getCharacterLength();
    short getWordsLength();
    short getSentenceLength();
    vector<vector<int> > getRaw();
    vector<string> getTypedWords();
    vector<string> getTypedCharacters();
    short countActionKeys();
    short countAlphas();
    short countAlnums();
    short countDigits();
    short countSymbols();
    vector<vector<int> > getTypedKeyCodes();
    //Deprecated in C++14. Need to change that.
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
  Space:57
 Controls:1,15,28,29,42,54,56,57(space),58,59-248
 Symbols:12-14,26,27,29,39-41,43,51-54,55
 
 */
keyCharacterMap[11]=48;
for(int i=1;i<=9;i++)
{
    keyCharacterMap[i+1]=48+i;
}
char layout[]="qwertyuiopasdfghjklzxcvbnm";
int ranges[][2]={{16,25},{30,38},{44,50}};
int i1=0;
for(int i=0;i<3;i++)
{
    int p=ranges[i][0],q=ranges[i][1];
    for(int k=p;k<=q;k++,i1++)
    keyCharacterMap[k]=(int)layout[i1];
}
keyCharacterMap[57]=32;
}
vector<vector<int> > SimpleExtraction :: getTypedKeyCodes() {
    return positions;
}
vector<vector<int> > SimpleExtraction :: getRaw() {
    return data;
}
SimpleExtraction :: SimpleExtraction(vector<vector<int> > data)
{
    initKeyCharacterMap();
    this->data=data;
    for(auto it=data.begin();it!=data.end();it++)
    {
        map<int,int> order;
        vector<int> ss;
        for(int i=0;i<it->size();i++)
        {
            if((*it)[i])
            {
                order.insert(pair<int,int>((*it)[i],i));
            }
        }
        for(auto it=order.begin();it!=order.end();it++)
            ss.push_back(it->second);
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
    return (len>0?(float)ct/(float)len:0);
}
short SimpleExtraction :: countSymbols() {
    short symbolCount = 0;
    applyToAllLists([&symbolCount](vector<int> list) {
        symbolCount += count_if(list.begin(), list.end(), [](int typed) {
            return SymbolCheck()(typed);
        });
    });
}
short SimpleExtraction :: countActionKeys() {
    short actionKeyCount = 0;
    applyToAllLists([&actionKeyCount](vector<int> list) {
        actionKeyCount += count_if(list.begin(), list.end(), [](int typed) {
            return controlCheck(typed);
        });
    });
}
short SimpleExtraction :: getCharacterLength()
{
  int ct=0;
  for_each(data.begin(),data.end(),[&ct](vector<int> &v){
ct+=count_if(v.begin(),v.end(),[](bool indx){
return indx;
    });
      });
  return ct;
}
short SimpleExtraction :: countAlphas()
{
   short ct=0;
    for_each(positions.begin(),positions.end(),
        [&ct](vector<int> &v)
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
    return defaultKeyCodeMap.space==index || defaultKeyCodeMap.tab==index;
}
vector<string> SimpleExtraction :: getTypedCharacters()
{
    vector<string> words;
applyToAllLists([&words,this](vector<int> data) -> void
{
    string word="";
    if(words.size()>0)
    {
        word=words[words.size()-1];
        words.resize(words.size()-1);
    }
    int i=0;
    for(i=0;i<data.size();i++)
    {
    if(controlCheck(data[i]) && !spaceCheck(data[i]))
 {
cout <<"Control Detected\n";
 }
    else if(spaceCheck(data[i]) || digitCheck(data[i]) || SymbolCheck()(data[i]))
    {
        cout <<"Other detected\n";
    if(word.size()>0)
    {
    words.push_back(word);
    word="";
    }
     }
     else if(AlphaCheck()(data[i]))
     {
        cout <<"Character Detected\n";
     word=word+(char)keyCharacterMap[data[i]];
 }
 else
    cout <<data[i] <<", ";
}
if(word.size()>0)
words.push_back(word);

    if(i<data.size())
    return;
});
return words;
}
vector<string> SimpleExtraction :: getTypedWords()
{
   return getTypedCharacters();
}
void SimpleExtraction :: applyToAllLists(function<void(vector<int>)> f) const
{
    for_each(positions.begin(),positions.end(),f);
}
#endif
