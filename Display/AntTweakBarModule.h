#ifndef _ANT_TWEAK_BAR_MODULE_H_
#define _ANT_TWEAK_BAR_MODULE_H_

#include <Core/IModule.h>
#include <Renderers/IRenderNode.h>
#include <AntTweakBar/include/AntTweakBar.h>
#include <Devices/SDLInput.h>
#include <Display/ITweakBar.h>

using namespace OpenEngine::Core;
using namespace OpenEngine::Renderers;

namespace OpenEngine {
    namespace Display {

class AntRenderNode : public IRenderNode {
public:
    AntRenderNode();
    ~AntRenderNode();
    
    void Apply(IRenderingView* rv);
};


class AntTweakBarModule : public IModule {

private:

    AntRenderNode* rn;
    int width;
    int height;
    list<ITweakBar*> bars;
public:
    AntTweakBarModule(int,int);
    ~AntTweakBarModule();

    void Initialize();
    void Deinitialize();
    void Process(const float deltaTime, const float percent);
    bool IsTypeOf(const std::type_info& inf);

    IRenderNode* RenderNode();
    void AddBar(ITweakBar* bar);
    static int HandleEvent(SDL_Event* e);
};

    }
}

#endif
