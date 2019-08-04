#include "OutputFormat.h"

OutputFormat :: OutputFormat(ptree data) {
	this->data = data;
}

ostream& operator<<(ostream &out, OutputFormat &conversionFormat) {
  out << conversionFormat.print();
  return out;
}
