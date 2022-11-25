#ifndef __END_SCENE_H__
#define __END_SCENE_H__


class EndScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void EndCloseCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(EndScene);

private:
    Layer* m_layer;
};

#endif // __END_SCENE_H__
