#include "HelloWorldScene.h"
#include "ControllerLayer.h"
#include "BackgroundLayer.h"
#include "CharacterLayer.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

		ControllerLayer *controllerLayer = ControllerLayer::create ();
		controllerLayer->setPosition(ccp(0, 0));
		controllerLayer->setAnchorPoint(ccp(0, 0));
		this->addChild(controllerLayer,10);

		BackgroundLayer *backgroundlayer = BackgroundLayer::create();
		backgroundlayer->setPosition(ccp(0,280));
		backgroundlayer->setAnchorPoint(ccp(0,1));
		this->addChild(backgroundlayer,1);

		CharacterLayer *characterLayer = CharacterLayer:: create();
		characterLayer->setPosition(ccp(50,100));
		characterLayer->setAnchorPoint(ccp(0,0));
		this->addChild(characterLayer,4);

		controllerLayer->setCharacterLayer(characterLayer);


		
        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

