#include "AntTweakBar.h"
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Display {

AntTweakBar::AntTweakBar() : init(Initializer(*this)), 
                             deinit(Deinitializer(*this)),
                             initialized(false) {
    
}

void AntTweakBar::Deinitialize(RenderingEventArg arg) {
    TwTerminate();
}

void AntTweakBar::Initialize(RenderingEventArg arg) {
    ICanvas& c = arg.canvas;
    
    TwInit(TW_OPENGL, NULL);
    TwWindowSize(c.GetWidth(), c.GetHeight());
    initialized = true;
    for (list<ITweakBar*>::iterator itr = barQueue.begin();
         itr != barQueue.end();
         itr++) {
        _AddBar(*itr);
    }
}

void AntTweakBar::Handle(RenderingEventArg arg) {
    TwDraw();
}
void AntTweakBar::Handle(KeyboardEventArg arg) {}
void AntTweakBar::Handle(MouseButtonEventArg arg) {
    int handled = TwMouseButton(arg.type == EVENT_PRESS?TW_MOUSE_PRESSED:TW_MOUSE_RELEASED,
                                (TwMouseButtonID)arg.button);
    if (!handled)
        umbe.Notify(arg);
}
void AntTweakBar::Handle(MouseMovedEventArg arg) {
    int handled = TwMouseMotion(arg.x, arg.y);
    if (!handled)
        umme.Notify(arg);
}

void AntTweakBar::AddBar(ITweakBar* b) {
    if (!initialized) {
        barQueue.push_back(b);
    } else {
        _AddBar(b);
    }
}

void AntTweakBar::_AddBar(ITweakBar* b) {
    bars.push_back(b);
    b->SetupBar();
}

void AntTweakBar::AttachTo(IRenderer& renderer) { 
    renderer.InitializeEvent().Attach(init);
    renderer.DeinitializeEvent().Attach(deinit);
    renderer.PostProcessEvent().Attach(*this);
}


}
}
