#include "AntTweakBar.h"
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Display {

AntTweakBar::AntTweakBar() : init(Initializer(*this)), deinit(Deinitializer(*this)) {
    
}

void AntTweakBar::Deinitialize(RenderingEventArg arg) {
    TwTerminate();
}

void AntTweakBar::Initialize(RenderingEventArg arg) {
    ICanvas& c = arg.canvas;
    
    TwInit(TW_OPENGL, NULL);
    TwWindowSize(c.GetWidth(), c.GetHeight());
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

void AntTweakBar::AttachTo(IRenderer& renderer) { 
    renderer.InitializeEvent().Attach(init);
    renderer.DeinitializeEvent().Attach(deinit);
    renderer.PostProcessEvent().Attach(*this);
}


}
}
