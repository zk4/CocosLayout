#include "HelloWorldScene.h"
#include "Layout2.h"
USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild (layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    //make white in center of the layer
    auto white=CCSprite::create ("1.png");
    addChild (white);
    _CENTER (this, white);


    //make red in right bottom corner  of the sprite

    auto red = CCSprite::create ("1.png");
    red->setColor ({ 255, 0, 0 });
    addChild (red);
    _CENTER (white, red, { 0, 1 }, { 1, 0 });

    //make yellow center of the sprite1,then move to left boarder of layer
    auto yellow = CCSprite::create ("1.png");
    yellow->setColor ({ 255, 255, 0 });
    addChild (yellow);
    _LEFT (0, this,   _CENTER (red, yellow));


    //make blue between yellow & red
    auto blue = CCSprite::create ("1.png");
    blue->setColor ({ 0, 255, 0 });
    addChild (blue);
    _MIDDLE (yellow, red, blue);

    //make gray in the left top corner,and offset ccp(10,-10) from that corner.
    auto gray = CCSprite::create ("1.png");
    gray->setColor ({ 155, 155, 155 });
    addChild (gray);
    _MOVE ({ 10, -10 }, _CENTER (this, gray, {0,1}, {0,1}));


    //make blue between yellow & red
    auto a = CCSprite::create ("1.png");
    a->setColor ({ 255, 0, 255 });
    a ->setScale  (.5f);
    addChild (a);
    _CENTER (  white, a, {0,0}, {1,1});
    return true;
}


 
