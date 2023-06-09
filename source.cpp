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

/** include files **/
#include "source.h"      // class Source
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )


/** public functions **/

/*******************************************************************
* Function Name: Source
* Description:
********************************************************************/
Source::Source( const string &name )
: Atomic( name )
, packetOut( addOutputPort( "packetOut" ) )
, packetTotal( addOutputPort( "packetTotal" ) )
, preparationTime( 0, 0, 10, 0 )
{	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description:
********************************************************************/
Model &Source::initFunction()
{
	packetNum = 0;

	state = generate;
	holdIn(active, preparationTime );
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &Source::externalFunction( const ExternalMessage &msg )
{
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &Source::internalFunction( const InternalMessage & )
{
	switch (state){
		case generate:
			packetNum++;
//			sinkAddr = packetNum % 2;
			sinkAddr = rand() % 3;
			state = generate;
			holdIn(active, preparationTime );
	};
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &Source::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), packetOut, sinkAddr ) ;
	sendOutput( msg.time(), packetTotal, packetNum + 1 ) ;
	return *this ;
}
