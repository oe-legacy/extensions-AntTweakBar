#include "AntTweakBarModule.h"


namespace OpenEngine {
namespace Display {

    AntTweakBarModule::AntTweakBarModule(int w, int h) : width(w),height(h) {
        rn = new AntRenderNode();
}
    AntTweakBarModule::~AntTweakBarModule() {}

    void AntTweakBarModule::Initialize() {
        TwInit(TW_OPENGL, NULL);
        TwWindowSize(width,height);

        for(list<ITweakBar*>::iterator itr = bars.begin();
            itr != bars.end();
            itr++) {
            ITweakBar* bar = *itr;
            bar->SetupBar();
        }
    }
    void AntTweakBarModule::Deinitialize() {}
    void AntTweakBarModule::Process(const float deltaTime, const float percent) {
        
    }
    bool AntTweakBarModule::IsTypeOf(const std::type_info& inf) {
        return (typeid(AntTweakBarModule) == inf);
    }

    IRenderNode* AntTweakBarModule::RenderNode() {
        return rn;
    }

    int AntTweakBarModule::HandleEvent(SDL_Event* e) {
        
        return TwEventSDL(e);
    }

    void AntTweakBarModule::AddBar(ITweakBar* bar) {
        bars.push_back(bar);
    }


    AntRenderNode::AntRenderNode() {}
    AntRenderNode::~AntRenderNode() {}

    void AntRenderNode::Apply(IRenderingView* rv) {
        TwDraw();
    }



}
}
