/*******************************************************************
*
*  DESCRIPTION: Atomic Model Switch
*
*  AUTHOR: Aizaz Chaudhry
*
*  EMAIL: mailto://auhchaud@sce.carleton.ca
*
*  DATE: 04/11/2010
*
*******************************************************************/

#ifndef __SWITCH_H
#define __SWITCH_H


#include "atomic.h"     // class Atomic

class Switch : public Atomic
{
public:
	Switch( const string &name = "Switch" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &switchIn;
	Port &switchOut1;
	Port &switchOut2;
	Port &gateWay;
	Time preparationTime;
	int destAddr;
};	// class Switch

// ** inline ** //
inline
string Switch::className() const
{
	return "Switch" ;
}

#endif   //__SWITCH_H
