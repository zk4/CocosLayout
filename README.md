CocosLayout
===========
#DEMO
##red block left to white left  
![demo](https://github.com/cubase01/CocosLayout/blob/master/demo/left.png)
##red block right to white left  
![demo](https://github.com/cubase01/CocosLayout/blob/master/demo/left3.png)
##red block right to white left then move left 40 points  
![demo](https://github.com/cubase01/CocosLayout/blob/master/demo/left4.png)

##middle to left  
![demo](https://github.com/cubase01/CocosLayout/blob/master/demo/left2.png)

##right 
![demo](https://github.com/cubase01/CocosLayout/blob/master/demo/right.jpg)
##middle
![demo](https://github.com/cubase01/CocosLayout/blob/master/demo/middle.png)
##between
![demo](https://github.com/cubase01/CocosLayout/blob/master/demo/between.jpg)
##mix
![demo](https://github.com/cubase01/CocosLayout/blob/master/demo/demo.png)
 
Ignore Hierarchies of nodes. make it easy to layout CCNodes in cocos2d-x.

 
#USE
include "Layout2.h" 

there are mainly  7 type of layout command,and will satisfied most circumstance
```cpp
//These four are the same args. 
 _LEFT(target,follower,follower_anchor)
 _RIGHT(target,follower,follower_anchor) 
 _TOP(target,follower,follower_anchor)   
 _BOTTOM(target,follower,follower_anchor)

//This is the most import command.You will use it mostly.
 _CENTER(target,follower,follower_anchor,target_anchor)

//tweak position 
 _MOVE(move_pos,follower) 

//set middle between two node  
 _MIDDLE(target1,target2,follower)


//make sprite in center of the layer
    auto white=CCSprite::create ("1.png");
    addChild (white);
    _CENTER (this, white);


    //make sprite1 in right bottom corner  of the sprite

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
    auto purple = CCSprite::create ("1.png");
    purple->setColor ({ 255, 0, 255 });
    purple ->setScale  (.5f);
    addChild (purple);
    _CENTER (  white, purple, {0,0}, {1,1});

 //if you wanna debug where the btn is,try  _DEBUG_LAYOUT
    auto btn = CCSprite::create ("2.png");
    addChild (btn);
    _CENTER (this, btn, { 2, 0 }, {.5f,.5f});
    btn->setVisible (false);
    _DEBUG_LAYOUT (btn);
    
```

some of the child node does not have the right ContentSize,like *CCScrollView*,*CCLabelTTF*,I already make compatiable in GetContentSize function.If you encounter any other type does not get right ContentSize.do the same as I did in GetContentSize function in layout2.cpp


