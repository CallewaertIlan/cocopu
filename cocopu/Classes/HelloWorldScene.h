#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__


class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuPlayCallback(Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
private:
    bool m_side_right;
};

#endif // __HELLOWORLD_SCENE_H__
