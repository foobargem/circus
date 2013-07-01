#include "CharacterLayer.h"

using namespace cocos2d;


bool CharacterLayer::init()
{
    bool bRet = false;
    do 
    {
        CC_BREAK_IF(! CCLayer::init());  

		boy_spr_state = 0;
	    vehicle_spr_state = 0; 

		boy = CCSprite :: create (SPR_BOY_NORMAL);
		boy->setTextureRect(CCRectMake(0,0,15,24));
		boy->setAnchorPoint(ccp(0,0));

		vehicle = CCSprite :: create (SPR_VEHICLE_NORMAL);
		vehicle->setTextureRect(CCRectMake(0,0,32,16));
		vehicle->setAnchorPoint(ccp(0,1));
		vehicle->setPosition(ccp(-8,0));

		boy->addChild(vehicle);
		this->addChild(boy);
		this->schedule(schedule_selector(CharacterLayer::runningSchedule), 0.2);

        bRet = true;
    } while (0);

    return bRet;
}


void CharacterLayer::runningSchedule (float f)
{

	boy_spr_state +=1;
	vehicle_spr_state +=1;


	if (boy_spr_state == 2) boy_spr_state =0;
	if (vehicle_spr_state ==2 ) vehicle_spr_state =0;


	switch (boy_spr_state) {
	case 0:
		boy->setTextureRect(CCRectMake(15,0,15,24));
		break;
	case 1:
		boy->setTextureRect(CCRectMake(0,0,15,24));
		break;
	}

	switch (vehicle_spr_state) {
	case 0:
		vehicle->setTextureRect(CCRectMake(32,0,32,16));
		break;
	case 1:
		vehicle->setTextureRect(CCRectMake(0,0,32,16));
		break;
	}



}

void CharacterLayer::doJump()
{
	this->unschedule(schedule_selector(CharacterLayer::runningSchedule));
	vehicle->setTextureRect(CCRectMake(64, 0, 32, 16));
	CCActionInterval* action = CCJumpTo::create(1, ccp(boy->getPositionX(), boy->getPositionY()), 80, 1);
	
	CCActionInterval* act2 = CCCallFuncND::create(this, callfuncND_selector(afterJump), NULL);

	CCSequence* seq = CCSequence::create(action, act2, NULL);
	boy->runAction(seq);

}

void CharacterLayer::afterJump()
{

	this->schedule(schedule_selector(CharacterLayer::runningSchedule));
}