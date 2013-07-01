#ifndef __CHARACTER_LAYER_H__
#define __CHARACTER_LAYER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;


#define SPR_BOY_NORMAL "boy.png"

#define SPR_VEHICLE_NORMAL "lion.png"




class CharacterLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

  
    CREATE_FUNC(CharacterLayer);

	CCSprite *boy;
	CCSprite *vehicle;

	void runningSchedule(float f);

	char boy_spr_state;
	char vehicle_spr_state;

	void doJump();
	void afterJump();
	
};

#endif  // __CONTROLLER_LAYER_H__