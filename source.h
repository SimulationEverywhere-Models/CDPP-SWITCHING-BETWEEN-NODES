/*******************************************************************
*
*  DESCRIPTION: Atomic Model Source
*
*  AUTHOR: Aizaz Chaudhry
*
*  EMAIL: mailto://auhchaud@sce.carleton.ca
*
*  DATE: 04/11/2010
*
*******************************************************************/

#ifndef __SOURCE_H
#define __SOURCE_H


#include "atomic.h"     // class Atomic

class Source : public Atomic
{
public:
	Source( const string &name = "Source" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &packetOut;
	Port &packetTotal;
	Time preparationTime;
	int sinkAddr;
	int packetNum;
	enum State{
		generate
	};
	State state;
};	// class Source

// ** inline ** //
inline
string Source::className() const
{
	return "Source" ;
}

#endif   //__SOURCE_H
