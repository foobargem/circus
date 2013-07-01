#include "ControllerLayer.h"

using namespace cocos2d;


bool ControllerLayer::init()
{
    bool bRet = false;
    do 
    {
        CC_BREAK_IF(! CCLayer::init());  

		{
			CCDirector *pDirector = CCDirector::sharedDirector();
			pDirector->getTouchDispatcher()->addTargetedDelegate(this,0,true);

		}

		btn_left = CCSprite :: create (BTN_LEFT_NORMAL);
		btn_left->setAnchorPoint(ccp(0, 0));
		btn_left->setPosition(ccp(15, 15));
		this->addChild(btn_left);
		
		btn_right = CCSprite :: create (BTN_RIGHT_NORMAL);
		btn_right->setAnchorPoint(ccp(0, 0));
		btn_right->setPosition(ccp(65, 15));
		this->addChild(btn_right);
		
		btn_jump = CCSprite :: create (BTN_JUMP_NORMAL);
		btn_jump->setAnchorPoint(ccp(0, 0));
		btn_jump->setPosition(ccp(420, 15));
		btn_jump->setTag(10);
		this->addChild(btn_jump);



        bRet = true;
    } while (0);

    return bRet;
}

void ControllerLayer::setCharacterLayer(CharacterLayer *layer)
{

	this->characterlayer = layer;


}


 bool ControllerLayer::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
 {
	CCPoint pos = pTouch->getLocation();

	if ((fabsf(pos.x - btn_jump->getPositionX()) <= 50.0f) && (fabsf(pos.y - btn_jump->getPositionY()) <= 50.0f)) {
		this->characterlayer->doJump();
	}
 
	 return true;
 }


 void ControllerLayer::ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent)
 {
	CCPoint pos = pTouch->getLocation();

	if ((fabsf(pos.x - btn_jump->getPositionX()) <= 50.0f) && (fabsf(pos.y - btn_jump->getPositionY()) <= 50.0f)) {
		this->characterlayer->afterJump();
	}





 }
