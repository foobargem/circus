#include "BackgroundLayer.h"

using namespace cocos2d;


bool BackgroundLayer::init()
{
    bool bRet = false;
    do 
    {
        CC_BREAK_IF(! CCLayer::init());  

		measurer=1;

		bg1_pos_x=0;
		background1 = CCSprite :: create (BTN_BACKGROUND_NORMAL);
		background1->setAnchorPoint(ccp(0, 1));
		background1->setPosition(ccp(bg1_pos_x,0));
		this->addChild(background1);


		bg2_pos_x=480;
		background2 = CCSprite :: create (BTN_BACKGROUND_NORMAL);
		background2->setAnchorPoint(ccp(0, 1));
		background2->setPosition(ccp(bg2_pos_x,0));
		this->addChild(background2);
	     
		this->schedule(schedule_selector(BackgroundLayer::flowScheduler));
        
		
		bRet = true;
    } while (0);
    
	 

    return bRet;
}


void BackgroundLayer::flowScheduler(float f)
{

	bg1_pos_x -=1;
	bg2_pos_x -=1;

	if ( bg1_pos_x <=-480 ) bg1_pos_x=480;
	if ( bg2_pos_x <=-480 ) {
		 bg2_pos_x=480;
		 measurer++;
	}

	if ( measurer ==2 ) { 
		this->unschedule(schedule_selector(BackgroundLayer::flowScheduler));
	}

	background1->setPosition(ccp(bg1_pos_x,background1->getPositionY()));
	background2->setPosition(ccp(bg2_pos_x,background2->getPositionY()));






}
