#ifndef __BACKGROUND_LAYER_H__
#define __BACKGROUND_LAYER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;


#define BTN_BACKGROUND_NORMAL "Background.png"


class BackgroundLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
   
    // implement the "static node()" method manually
    CREATE_FUNC(BackgroundLayer);

	CCSprite *background1;
	CCSprite *background2;

	int bg1_pos_x;
	int bg2_pos_x;

	void flowScheduler (float f);

	int measurer;

	
};

#endif  // __CONTROLLER_LAYER_H__