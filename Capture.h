#ifndef CAPTURE_H
#define CAPTURE_H

#include <boost/property_tree/ptree.hpp>

using namespace boost :: property_tree;


struct CaptureSource {
  CaptureSource();
  virtual ptree capture() = 0;
};

#endif
