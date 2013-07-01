#ifndef __CONTROLLER_LAYER_H__
#define __CONTROLLER_LAYER_H__

#include "cocos2d.h"
#include "CharacterLayer.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;


#define BTN_LEFT_NORMAL "leftB.png"
#define BTN_RIGHT_NORMAL "RightB.png"
#define BTN_JUMP_NORMAL "jumpB.png"

class ControllerLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
   
    // implement the "static node()" method manually
    CREATE_FUNC(ControllerLayer);

	CCSprite *btn_left;
	CCSprite *btn_right;
	CCSprite *btn_jump;


	void setCharacterLayer (CharacterLayer *layer);


	virtual bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent);
	virtual void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent);

	
private:
	CharacterLayer *characterlayer;


};

#endif  // __CONTROLLER_LAYER_H__