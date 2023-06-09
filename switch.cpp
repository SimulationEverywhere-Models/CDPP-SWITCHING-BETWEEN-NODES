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

/** include files **/
#include "switch.h"      // class Switch
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )


/** public functions **/

/*******************************************************************
* Function Name: Switch
* Description:
********************************************************************/
Switch::Switch( const string &name )
: Atomic( name )
, switchIn( addInputPort( "switchIn" ) )
, switchOut1( addOutputPort( "switchOut1" ) )
, switchOut2( addOutputPort( "switchOut2" ) )
, gateWay( addOutputPort( "gateWay" ) )
, preparationTime( 0, 0, 1, 0 )
{	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description:
********************************************************************/
Model &Switch::initFunction()
{
	this-> passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &Switch::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == switchIn )
	{
		destAddr = static_cast < int > (msg.value());
		holdIn(active, preparationTime );
	}
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &Switch::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &Switch::outputFunction( const InternalMessage &msg )
{
	if ( destAddr == 0 )
	{
		sendOutput( msg.time(), switchOut1, destAddr ) ;
	}
	else if (destAddr == 1)
	{
		sendOutput( msg.time(), switchOut2, destAddr ) ;
	}
	else
	{
		sendOutput( msg.time(), gateWay, destAddr ) ;
	}
	return *this ;
}
