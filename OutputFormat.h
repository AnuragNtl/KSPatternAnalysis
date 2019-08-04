#ifndef OUTPUT_FORMAT_H
#define OUTPUT_FORMAT_H
#include <boost/property_tree/ptree.cpp>

using namespace boost :: property_tree;

class OutputFormat {

private:
  ptree data;
public:
	OutputFormat(ptree data);
	virtual string print(ptree &input) = 0 const;
  friend ostream& operator<<(ostream &out, OutputFormat &);
};
#endif
