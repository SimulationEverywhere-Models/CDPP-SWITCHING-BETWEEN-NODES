/*******************************************************************
*
*  DESCRIPTION: Atomic Model Sink
*
*  AUTHOR: Aizaz Chaudhry
*
*  EMAIL: mailto://auhchaud@sce.carleton.ca
*
*  DATE: 04/11/2010
*
*******************************************************************/

#ifndef __SINK_H
#define __SINK_H


#include "atomic.h"     // class Atomic

class Sink : public Atomic
{
public:
	Sink( const string &name = "Sink" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &sinkIn;
	Port &packetsReceived;
	Time preparationTime;
	int incomingAddr;
	int myAddr;
	int packets;
};	// class Sink

// ** inline ** //
inline
string Sink::className() const
{
	return "Sink" ;
}

#endif   //__SINK_H
