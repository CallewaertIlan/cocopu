#ifndef __END_SCENE_H__
#define __END_SCENE_H__


class EndScene : public cocos2d::Scene
{
public:
    enum
    {
        WIN = 0,
        LOSE,
    };
    static cocos2d::Scene* createScene();

    void initialisation(int value);
    virtual bool init();

    // a selector callback
    void EndCloseCallback(cocos2d::Ref* pSender);

    void RestartCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(EndScene);

protected:
    float m_timeMax;
    float m_timeStart;

    int m_type;

    Label m_timer;
private:
    Layer* m_layer;
};

#endif // __END_SCENE_H__
