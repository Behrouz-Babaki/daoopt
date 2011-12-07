/*
 * BoundPropagatorMaster.h
 *
 *  Copyright (C) 2011 Lars Otten
 *  Licensed under the MIT License, see LICENSE.TXT
 *  
 *  Created on: Feb 14, 2010
 *      Author: Lars Otten <lotten@ics.uci.edu>
 */

#ifndef BOUNDPROPAGATORMASTER_H_
#define BOUNDPROPAGATORMASTER_H_

#include "BoundPropagator.h"

#ifdef PARALLEL_DYNAMIC


class BoundPropagatorMaster : public BoundPropagator {

protected:
  /* same as m_space, but different type */
  SearchSpaceMaster* m_spaceMaster;

public:
  /* threading operator for master process */
  void operator () ();

protected:
  bool isMaster() const { return true; }

public:
  /* simple constructor */
  BoundPropagatorMaster(Problem* p, SearchSpaceMaster* s) : BoundPropagator(p,s), m_spaceMaster(s) {}

};


#endif /* PARALLEL_DYNAMIC */

#endif /* BOUNDPROPAGATORMASTER_H_ */
