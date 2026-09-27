      #include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        PlayLayer::destroyPlayer(player, object);
        
        if (this->getChildByID("vortrox-jumpscare")) return;

        double currentPos = player->m_position.x;
        double levelLength = this->m_levelLength;
        
        int percent = 0;
        if (levelLength > 0) {
            percent = static_cast<int>((currentPos / levelLength) * 100.0);
        }

        if (percent == 92) {
            auto sprite = CCSprite::create("vortrox.png");
            
            if (sprite) {
                sprite->setID("vortrox-jumpscare");
                
                auto winSize = CCDirector::sharedDirector()->getWinSize();
                sprite->setPosition({winSize.width / 2, winSize.height / 2});
                
                sprite->setScale(1.5f); 
                sprite->setZOrder(10000);
                
                this->addChild(sprite);

                FMODAudioEngine::sharedEngine()->playEffect("vortrox_scream.mp3");
                FMODAudioEngine::sharedEngine()->playEffect("vine_boom.mp3");

                auto delay = CCDelayTime::create(1.2f);   
                auto fadeOut = CCFadeOut::create(0.3f);    
                auto remove = CCRemoveSelf::create();      
                
                auto sequence = CCSequence::create(delay, fadeOut, remove, nullptr);
                sprite->runAction(sequence);
            }
        }
    }
};
                                                                                                                                                                                   
