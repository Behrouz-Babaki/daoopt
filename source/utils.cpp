/*
 * utils.cpp
 *
 *  Created on: Oct 10, 2008
 *      Author: lars
 */

#include "utils.h"

extern time_t time_start;

void myprint(std::string s) {
  time_t now; time(&now);
  double T = difftime(now,time_start);
  {
    GETLOCK(mtx_io, lk);
    std::cout << '[' << T << "] " << s << std::flush;
  }
}

void myerror(std::string s) {
  time_t now; time(&now);
  double T = difftime(now,time_start);
  {
    GETLOCK(mtx_io, lk);
    std::cerr << '[' << T << "] " << s << std::flush;
  }
}


/***************************************/
/*        some cout functions          */

ostream& operator <<(ostream& os, const vector<int>& s) {
  os << '[';
  for (vector<int>::const_iterator it = s.begin(); it != s.end(); ) {
    os << *it;
    if (++it != s.end()) os << ',';
  }
  os << ']';
  return os;
}

ostream& operator <<(ostream& os, const vector<uint>& s) {
  os << '[';
  for (vector<uint>::const_iterator it = s.begin(); it != s.end(); ) {
    os << *it;
    if (++it != s.end()) os << ',';
  }
  os << ']';
  return os;
}

ostream& operator <<(ostream& os, const vector<signed short>& s) {
  os << '[';
  for (vector<signed short>::const_iterator it = s.begin(); it != s.end(); ) {
    os << (int) *it;
    if (++it != s.end()) os << ',';
  }
  os << ']';
  return os;
}

ostream& operator <<(ostream& os, const vector<signed char>& s) {
  os << '[';
  for (vector<signed char>::const_iterator it = s.begin(); it != s.end(); ) {
    os << (int) *it;
    if (++it != s.end()) os << ',';
  }
  os << ']';
  return os;
}

ostream& operator <<(ostream& os, const vector<int*>& s) {
  os << '[';
  for (vector<int*>::const_iterator it = s.begin(); it != s.end(); ) {
    os << **it;
    if (++it != s.end()) os << ',';
  }
  os << ']';
  return os;
}

ostream& operator <<(ostream& os, const set<int>& s) {
  os << '{';
  for (set<int>::const_iterator it = s.begin(); it != s.end(); ) {
    os << *it;
    if (++it != s.end()) os << ',';
  }
  os << '}';
  return os;
}

ostream& operator <<(ostream& os, const set<uint>& s) {
  os << '{';
  for (set<uint>::const_iterator it = s.begin(); it != s.end(); ) {
    os << *it;
    if (++it != s.end()) os << ',';
  }
  os << '}';
  return os;
}

ostream& operator <<(ostream& os, const vector<double>& s) {
  os << '[';
  for (vector<double>::const_iterator it = s.begin(); it != s.end(); ) {
    os << *it;
    if (++it != s.end()) os << ',';
  }
  os << ']';
  return os;
}


#ifdef PARALLEL_DYNAMIC
 #ifdef USE_GMP
double mylog10(bigint a) {
  double l = 0;
  while (!a.fits_sint_p()) {
    a /= 10;
    ++l;
  }
  l += log10(a.get_si());
  return l;
}
 #endif
#endif

