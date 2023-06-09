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

/** include files **/
#include "sink.h"      // class Sink
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )


/** public functions **/

/*******************************************************************
* Function Name: Sink
* Description:
********************************************************************/
Sink::Sink( const string &name )
: Atomic( name )
, sinkIn( addInputPort( "sinkIn" ) )
, packetsReceived( addOutputPort( "packetsReceived" ) )
, preparationTime( 0, 0, 1, 0 )
{	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
	
	string sinkaddress( MainSimulator::Instance().getParameter( description(), "address" ) ) ;
	myAddr = str2float( sinkaddress ) ;
} 


/*******************************************************************
* Function Name: initFunction
* Description: 
********************************************************************/
Model &Sink::initFunction()
{
	packets = 0;
	//myAddr = 0;
	this-> passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &Sink::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == sinkIn ) 
	{
		incomingAddr = static_cast < int > (msg.value());
		if ( incomingAddr == myAddr )
		{
			packets++;
			holdIn(active, preparationTime );
		}
	}
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &Sink::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &Sink::outputFunction( const InternalMessage &msg )
{	
	sendOutput( msg.time(), packetsReceived, packets ) ;
	return *this ;
}
