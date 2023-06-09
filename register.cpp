/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#include "modeladm.h"
#include "mainsimu.h"
#include "source.h"
#include "switch.h"
#include "sink.h"
#include "queue.h"


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Source>() , "source" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Switch>() , "switch" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Sink>() , "sink" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "queue" ) ;
}
