/*
 * TxtHighBayWarehouseRun.cpp
 *
 *  Created on: 07.02.2019
 *      Author: steiger-a
 */

#include <iostream>
#include <stdio.h>          // for printf()
#include <string.h>         // for memset()
#include <unistd.h>         // for sleep()
#include <cmath>			// for pow()
#include <fstream>

#include <cstring>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "mqtt/async_client.h"


const std::string SERVER_ADDRESS("tcp://localhost:1883");
const std::string CLIENT_ID("mqtt_cpp_async_subscriber");
const std::string TOPIC("fl/vgr/do");



// #ifndef __DOCFSM__
#include "TxtHighBayWarehouse.h"

// #include "TxtMqttFactoryClient.h"
// #include "Utils.h"
// #endif

#ifdef FSM_INIT_FSM
#undef FSM_INIT_FSM
#endif
#define FSM_INIT_FSM( startState, attr... )                                \
		currentState = startState;                                         \
		newState = startState;

#ifdef FSM_TRANSITION
#undef FSM_TRANSITION
#endif
#ifdef _DEBUG
#define FSM_TRANSITION( _newState, attr... )                               \
		do                                                                 \
		{                                                                  \
			std::cerr << state2str( currentState ) << " -> "               \
			<< state2str( _newState ) << std::endl;                        \
			newState = _newState;                                          \
		}                                                                  \
		while( false )
#else
#define FSM_TRANSITION( _newState, attr... )  newState = _newState
#endif


namespace ft {


class mqtt_callback : public virtual mqtt::callback
{
public:
    void connection_lost(const std::string& cause) override {
        std::cout << "\nConnection lost" << std::endl;
        if (!cause.empty())
            std::cout << "cause: " << cause << std::endl;
    }

    void delivery_complete(mqtt::delivery_token_ptr token) override {
        std::cout << "\nDelivery complete for token: "
                  << (token ? token->get_message_id() : -1) << std::endl;
    }

    void message_arrived(mqtt::const_message_ptr msg) override {
    //std::cout << "msg topic addr: " << &msg->get_topic() << std::endl;
    //printf("Topic from src: %s\n", msg->get_topic().c_str()); 
    //printf("Message Content Length: %lu\n", msg->get_payload().length());        
    //std::cout << "Message received on topic: " << msg->get_topic() << std::endl;
        std::cout << "Message content: " << msg->to_string() << std::endl;
		//run();	

		if(msg->to_string() == "BLUE"){
			std::cout<<"BLUE workpiece ordered\n";
			char newState = 'F';
			//FSM_TRANSITION( newState, color=green, label='req\nquit' );
			fsmStep(newState);	
		}
    }
//};


enum State {
    FAULT,
    IDLE,
    CALIB_HBW,
    // Add more states here as needed
};

// void TxtHighBayWarehouse::fsmStep()
void fsmStep(char currentState)
{
	std::cout << "fsmStep" << std::endl;
	//spdloG_LOGGER_TRACE(spdlog::get("console"), "fsmStep",0);
	char newState;
	// std::cout<<"Enter new state: ";
	// std::cin >> newState;
	std::cout<<"Current state is: "<<currentState << std::endl;
	if(currentState != 'F'){
		std::cin >> currentState;
	}

// 	// Entry activities ===================================================
	// if( newState != currentState )
	// {
	// 	switch( newState )
	// 	{
	// 	//-------------------------------------------------------------
	// 	case 'F':
	// 	{
	// 		// printEntryState(FAULT);
	// 		// setStatus(SM_ERROR);
	// 		// sound.error();
	// 		break;
	// 	}
	// 	//-----------------------------------------------------------------
	// 	case 'I':
	// 	{
	// 		// printEntryState(IDLE);
	// 		// setSpeed(512);
	// 		// moveRef();
	// 		// setActStatus(false, SM_READY);
	// 		// publishStorage();
	// 		break;
	// 	}
	// 	//-----------------------------------------------------------------
	// 	case 'C':
	// 	{
	// 		// printEntryState(CALIB_HBW);
	// 		// sound.info2();
	// 		// moveRef();
	// 		break;
	// 	}
	// 	//-----------------------------------------------------------------
	// 	default: break;
	// 	}
	// 	currentState = newState;
	// }

	// Do activities ==================================================
	switch( currentState )
	{
	//-----------------------------------------------------------------
	case 'u':
	{
		std::cout << "FAULT" << std::endl;
// 		printState(FAULT);
// 		if (reqQuit)
// 		{
// 			setStatus(SM_READY);
// 			FSM_TRANSITION( IDLE, color=green, label='req\nquit' );
// 			reqQuit = false;
// 		}
// #ifdef __DOCFSM__
// 		FSM_TRANSITION( FAULT, color=red, label='wait' );
// #endif
// 		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		break;
	}
	//-----------------------------------------------------------------
	case 'I':
	{
		std::cout << "INIT" << std::endl;
// 		printState(INIT);
// #ifdef __DOCFSM__ //TODO remove, needed for graph
// 		FSM_TRANSITION( INIT );
// #endif
// 		moveRef();
// 		FSM_TRANSITION( IDLE, color=green, label='initialized' );
		break;
	}
	//-----------------------------------------------------------------
	case 'D':
	{
		std::cout << "IDLE" << std::endl;
		// FSM_TRANSITION( FETCH_CONTAINER, color=blue, label='req fetch\ncontainer' );
		//printState(IDLE);
// 		if (reqVGRfetchContainer)
// 		{
// 			FSM_TRANSITION( FETCH_CONTAINER, color=blue, label='req fetch\ncontainer' );
// 			reqVGRfetchContainer = false;
// 		}
// 		else if (reqVGRfetch)
// 		{
// 			FSM_TRANSITION( FETCH_WP, color=blue, label='req fetch\nworkpiece' );
// 			reqVGRfetch = false;
// 		}
// 		else if (reqVGRcalib)
// 		{
// 			FSM_TRANSITION( CALIB_HBW, color=orange, label='req\ncalib'  );
// 			reqVGRcalib = false;
// 		}
// 		else if (reqVGRresetStorage)
// 		{
// 			storage.resetStorageState();
// 			sound.info1();
// 			reqVGRresetStorage = false;
// 		}
// #ifdef __DOCFSM__
// 		FSM_TRANSITION( IDLE, color=green, label='wait' );
// #endif
		break;
	}
	//-----------------------------------------------------------------
	case 'F':
	{
		std::cout << "FETCH_CONTAINER" << std::endl;
		storage.fetchContainer();
// 		printState(FETCH_CONTAINER);
// 		if (fetchContainer())
// 		{
// 			assert(mqttclient);
// 			mqttclient->publishHBW_Ack(HBW_FETCHED, reqVGRwp, TIMEOUT_MS_PUBLISH);

// 			FSM_TRANSITION( STORE_WP, color=blue, label='req\nstore' );
// 		}
// 		else
// 		{
// 			FSM_TRANSITION( FAULT, color=red, label='error' );
// 		}
// #ifdef __DOCFSM__
// 		FSM_TRANSITION( FETCH_CONTAINER, color=blue, label='wait' );
// #endif
		break;
	}
	//-----------------------------------------------------------------
	case 'S':
	{
		std::cout << "STORE_WP" << std::endl;
// 		printState(STORE_WP);
// 		if (reqVGRstore)
// 		{
// 			if (reqVGRwp && store(*reqVGRwp))
// 			{
// 				FSM_TRANSITION( IDLE, color=green, label='workpiece\nstored' );
// 			}
// 			else
// 			{
// 				FSM_TRANSITION( FAULT, color=red, label='error' );
// 			}
// 			reqVGRstore = false;
// 		}
// #ifdef __DOCFSM__
// 		FSM_TRANSITION( STORE_WP, color=blue, label='wait' );
// #endif
		break;
	}
	//-----------------------------------------------------------------
	case 'W':
	{
		std::cout << "FETCH_WP" << std::endl;
// 		printState(FETCH_WP);
// 		if (reqVGRwp && fetch(reqVGRwp->type))
// 		{
// 			assert(mqttclient);
// 			mqttclient->publishHBW_Ack(HBW_FETCHED, reqVGRwp, TIMEOUT_MS_PUBLISH);
// 			FSM_TRANSITION( FETCH_WP_WAIT, color=blue, label='wait req' );
// 		}
// 		else
// 		{
// 			FSM_TRANSITION( FAULT, color=red, label='error' );
// 		}
// #ifdef __DOCFSM__
// 		FSM_TRANSITION( FETCH_WP, color=blue, label='wait' );
// #endif
		break;
	}
	//-----------------------------------------------------------------
	case 'T':
	{
		std::cout << "FETCH_WP_WAIT" << std::endl;
// 		printState(FETCH_WP_WAIT);
// 		if (reqVGRstoreContainer)
// 		{
// 			FSM_TRANSITION( STORE_CONTAINER, color=blue, label='req store\ncontainer' );
// 			reqVGRstoreContainer = false;
// 		}
// #ifdef __DOCFSM__
// 		FSM_TRANSITION( FETCH_WP_WAIT, color=blue, label='wait' );
// #endif
		break;
	}
	//-----------------------------------------------------------------
	case 'O':
	{
		std::cout << "STORE_CONTAINER" << std::endl;
// 		printState(STORE_CONTAINER);
// 		if (storeContainer())
// 		{
// 			FSM_TRANSITION( IDLE, color=green, label='container\nstored' );
// 		}
// 		else
// 		{
// 			FSM_TRANSITION( FAULT, color=red, label='error' );
// 		}
// #ifdef __DOCFSM__
// 		FSM_TRANSITION( STORE_CONTAINER, color=blue, label='wait' );
// #endif
		break;
	}
	//-----------------------------------------------------------------
	case 'C':
	{
		std::cout << "CALIB_HBW" << std::endl;
		// printState(CALIB_HBW);
		// setStatus(SM_CALIB);
		// calibPos = (TxtHbwCalibPos_t)0;
		// FSM_TRANSITION( CALIB_HBW_NAV, color=orange, label='init' );
		break;
	}
	//-----------------------------------------------------------------
	case 'N':
	{
		std::cout << "CALIB_HBW_NAV" << std::endl;
// 		printState(CALIB_HBW_NAV);
// 		bool reqmove = true;
// 		while(true)
// 		{
// 			if (joyData.b1) {
// 				break;
// 			} else if (joyData.b2) {
// 				assert(mqttclient);
// 				mqttclient->publishHBW_Ack(HBW_CALIB_END, 0, TIMEOUT_MS_PUBLISH);
// 				FSM_TRANSITION( IDLE, color=green, label='cancel' );
// 				break;
// 			} else if (joyData.aX2 > 500) {
// 				calibPos=(TxtHbwCalibPos_t)(calibPos-1);
// 				std::cout << ft::toString(calibPos) << std::endl;
// 				reqmove = true;
// 			} else if (joyData.aX2 < -500) {
// 				calibPos=(TxtHbwCalibPos_t)(calibPos+1);
// 				std::cout << ft::toString(calibPos) << std::endl;
// 				reqmove = true;
// 			}
// 			//check pos valid
// 			if (calibPos < 0)
// 			{
// 				calibPos = (TxtHbwCalibPos_t)(HBWCALIB_END-1);
// 			} else if (calibPos >= HBWCALIB_END)
// 			{
// 				calibPos = (TxtHbwCalibPos_t)0;
// 			}
// 			//move pos
// 			if (reqmove)
// 			{
// 				moveCalibPos();
// 				setStatus(SM_CALIB);
// 				assert(mqttclient);
// 				mqttclient->publishHBW_Ack(HBW_CALIB_NAV, 0, TIMEOUT_MS_PUBLISH);
// 				FSM_TRANSITION( CALIB_HBW_MOVE, color=orange, label='calib pos' );
// 				reqmove = false;
// 				break;
// 			}
// 			std::this_thread::sleep_for(std::chrono::milliseconds(10));
// 		}
// #ifdef __DOCFSM__
// 		FSM_TRANSITION( CALIB_HBW_NAV, color=orange, label='select pos' );
// #endif
		break;
	}
	//-----------------------------------------------------------------
	case 'M':
	{
		std::cout << "CALIB_HBW_MOVE" << std::endl;
// 		printState(CALIB_HBW_MOVE);
// 		//reset();
// 		while(true)
// 		{
// 			if (joyData.b2) {
// 				break; //-> NAV
// 			} else if (joyData.b1) {
// 				EncPos2 p2 = getPos2();
// 				switch(calibPos)
// 				{
// 				case HBWCALIB_A1:
// 					calibData.hbx[0] = p2.x;
// 					calibData.hby[0] = p2.y;
// 					calibData.save();
// 					break;
// 				case HBWCALIB_B2:
// 					calibData.hbx[1] = p2.x;
// 					calibData.hby[1] = p2.y;
// 					calibData.save();
// 					break;
// 				case HBWCALIB_C3:
// 					calibData.hbx[2] = p2.x;
// 					calibData.hby[2] = p2.y;
// 					calibData.save();
// 					break;
// 				case HBWCALIB_CV:
// 					calibData.conv.x = p2.x;
// 					calibData.conv.y = p2.y;
// 					calibData.save();
// 					break;
// 				default:
// 					break;
// 				}
// 				//same pos again
// 				break; //-> NAV
// 			} else if ((joyData.aX2 > 500)|(joyData.aX2 < -500)) {
// 				break; //-> NAV
// 			}
// 			moveJoystick();
// #ifdef __DOCFSM__
// 			FSM_TRANSITION( CALIB_MOVE, color=orange, label='move' );
// #endif
// 			std::this_thread::sleep_for(std::chrono::milliseconds(10));
// 		}
// 		FSM_TRANSITION( CALIB_HBW_NAV, color=green, label='ok' );
		break;
	}
	//-----------------------------------------------------------------
	default: 
		std::cout <<"default" << std::endl;
		break;
	}

// 	if( newState == currentState )
// 		return;

// 	// Exit activities ================================================
// 	switch( currentState )
// 	{
// 	//-----------------------------------------------------------------
// 	//-----------------------------------------------------------------
// 	default: break;
// 	}
}

// void TxtHighBayWarehouse::moveCalibPos()
void moveCalibPos()
{
	std::cout << "moveCalibPos" << std::endl;
	//spdloG_LOGGER_TRACE(//spdlog::get("console"), "moveCalibPos",0);
	// switch(calibPos)
	// {
	// case HBWCALIB_CV:
	// 	moveRef();
	// 	moveConv(false);
	// 	break;
	// case HBWCALIB_A1:
	// 	moveRef();
	// 	moveCR(0,0);
	// 	break;
	// case HBWCALIB_B2:
	// 	moveRef();
	// 	moveCR(1,1);
	// 	break;
	// case HBWCALIB_C3:
	// 	moveRef();
	// 	moveCR(2,2);
	// 	break;
	// default:
	// 	assert(0);
	// 	break;
	// }
}

// void TxtHighBayWarehouse::run()
void run()
{
	std::cout<<"run" << std::endl;
	fsmStep('U');
	// //spdloG_LOGGER_TRACE(spdlog::get("console"), "run",0);
	// assert(mqttclient);
	// obs_hbw = new TxtHighBayWarehouseObserver(this, mqttclient);
	// obs_storage = new TxtHighBayWarehouseStorageObserver(getStorage(), mqttclient);

	// FSM_INIT_FSM(INIT, color=black, label='init' );
	// while (!m_stoprequested)
	// {
	// 	fsmStep();
	// 	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	// }

	// assert(mqttclient);
	// mqttclient->publishHBW_Ack(HBW_EXIT, 0, TIMEOUT_MS_PUBLISH);
}


// bool fetchContainer()
// {
// 	std::cout << "fetchContainer" << std::endl;
// 	// if (storage.fetchContainer())
// 	// {

// 	// }
// 	return false;
// }

};

} /* namespace ft */

int main()
{
	std::cout << "main" << std::endl;
	//ft::run();
	mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);
    ft::mqtt_callback cb;
    client.set_callback(cb);

    mqtt::connect_options connOpts;
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);

    try {
        std::cout << "Connecting to MQTT server: '" << SERVER_ADDRESS << "'..." << std::flush;
        mqtt::token_ptr conntok = client.connect(connOpts);
        conntok->wait();
        std::cout << "OK\n" << std::endl;

        std::cout << "Subscribing to topic: " << TOPIC << "..." << std::flush;
        mqtt::token_ptr subtok = client.subscribe(TOPIC, 0);
        subtok->wait();
        std::cout << "OK\n" << std::endl;

        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        std::cout << "Disconnecting from MQTT server..." << std::flush;
        mqtt::token_ptr disconntok = client.disconnect();
        disconntok->wait();
        std::cout << "OK" << std::endl;
		//ft::run();
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return 1;
    }

    return 0;

}

