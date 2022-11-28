#ifndef __WIN_END_SCENE_H__
#define __WIN_END_SCENE_H__


class WinEndScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void WinEndCloseCallback(cocos2d::Ref* pSender);

    void WinRestartCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(WinEndScene);

protected:
    float m_timeMax;
    float m_timeStart;

    Label m_timer;
private:
    Layer* m_layer;
};

#endif // __WIN_END_SCENE_H__
