#include "HomeLayer.h"
#include "Language.h"
#include "GameScene.h"
using namespace cocos2d;

CCScene* HomeLayer::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HomeLayer *layer = HomeLayer::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HomeLayer::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

        //////////////////////////////////////////////////////////////////////////
        // add your codes below...
        //////////////////////////////////////////////////////////////////////////

        // 1. Add a menu item with "X" image, which is clicked to quit the program.
		CCMenuItemLabel *pMenuItem[5] = {NULL};

		CCLabelBMFont *pNewGameLabel = CCLabelBMFont::create(CLanguage::shareLanguage()->GetByKey("NewGame"),"data/font/mario.fnt");
		CC_BREAK_IF(! pNewGameLabel);
		pMenuItem[0] = CCMenuItemLabel ::create(pNewGameLabel,this,menu_selector(HomeLayer::menuCloseCallback));
		pMenuItem[0]->setTag(0);
		pMenuItem[0]->setPosition(ccp(130, 390));

		CCLabelBMFont *pContinueGameLabel = CCLabelBMFont::create(CLanguage::shareLanguage()->GetByKey("ContinueGame"),"data/font/mario.fnt");
		CC_BREAK_IF(! pContinueGameLabel);
		pMenuItem[1] = CCMenuItemLabel ::create(pContinueGameLabel,this,menu_selector(HomeLayer::menuCloseCallback));
		pMenuItem[1]->setTag(1);
		pMenuItem[1]->setPosition(ccp(130, 320));

		CCLabelBMFont *pMenuLabel = CCLabelBMFont::create(CLanguage::shareLanguage()->GetByKey("Setting"),"data/font/mario.fnt");
		CC_BREAK_IF(! pMenuLabel);
		pMenuItem[2] = CCMenuItemLabel ::create(pMenuLabel,this,menu_selector(HomeLayer::menuCloseCallback));
		pMenuItem[2]->setTag(2);
		pMenuItem[2]->setPosition(ccp(130, 245));

		CCLabelBMFont *pMenuLabel3 = CCLabelBMFont::create(CLanguage::shareLanguage()->GetByKey("Help"),"data/font/mario.fnt");
		CC_BREAK_IF(! pMenuLabel3);
		pMenuItem[3] = CCMenuItemLabel ::create(pMenuLabel3,this,menu_selector(HomeLayer::menuCloseCallback));
		pMenuItem[3]->setTag(3);
		pMenuItem[3]->setPosition(ccp(130, 165));

		CCLabelBMFont *pMenuLabel4 = CCLabelBMFont::create(CLanguage::shareLanguage()->GetByKey("About"),"data/font/mario.fnt");
		CC_BREAK_IF(! pMenuLabel4);
		pMenuItem[4] = CCMenuItemLabel ::create(pMenuLabel4,this,menu_selector(HomeLayer::menuCloseCallback));
		pMenuItem[4]->setTag(4);
		pMenuItem[4]->setPosition(ccp(130, 95));

        // Place the menu item bottom-right conner.

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::create(pMenuItem[0],pMenuItem[1],pMenuItem[2],pMenuItem[3],pMenuItem[4],NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // Add the menu to HomeLayer layer as a child layer.
        this->addChild(pMenu, 1);

        // 2. Add a label shows "Hello World".

       CCLabelBMFont *pTitleLabel = CCLabelBMFont::create(CLanguage::shareLanguage()->GetByKey("Title"),"data/font/mario.fnt");
	   pTitleLabel->setPosition(ccp(540,420));
	   pTitleLabel->setScale(1.5f);
	   this->addChild(pTitleLabel, 1);

	   CCLabelBMFont *pVersionLabel = CCLabelBMFont::create(CLanguage::shareLanguage()->GetByKey("Version"),"data/font/mario.fnt");
	   pVersionLabel->setPosition(ccp(600,380));
	   pVersionLabel->setScale(0.7f);
	   this->addChild(pVersionLabel, 1);
       // CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
		

        // Get window size and place the label upper. 
        CCSize size = CCDirector::sharedDirector()->getWinSize();


        // Add the label to HomeLayer layer as a child layer.
       // this->addChild(pLabel, 1);


		CCTexture2D *texture=CCTextureCache::sharedTextureCache()->addImage("data/home.png");

		CCSpriteFrame *frame =CCSpriteFrame::createWithTexture(texture,CCRectMake(0,0,800,480));
		CCSprite* pSprite = CCSprite::createWithSpriteFrame(frame);
        CC_BREAK_IF(! pSprite);

        // Place the sprite on the center of the screen
        pSprite->setPosition(ccp(size.width/2, size.height/2));
        // Add the sprite to HomeLayer layer as a child layer.
        this->addChild(pSprite, 0);



		//CCLabelBMFont *pLable = CCLabelBMFont::create("ĞÂÓÎÏ·","data/font/mario.fnt");



        bRet = true;
    } while (0);

    return bRet;
}

void HomeLayer::menuCloseCallback(CCObject* pSender)
{
	CCMenuItemLabel *pMenuItem = (CCMenuItemLabel*)pSender;
	switch (pMenuItem->getTag())
	{
	case 0:
		CCDirector::sharedDirector()->replaceScene(CGameScene::scene());
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}
    //CCDirector::sharedDirector()->end();
}

