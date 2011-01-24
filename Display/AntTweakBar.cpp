#include "AntTweakBar.h"
#include <Logging/Logger.h>
#include <Meta/OpenGL.h>
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

    TwStructMember vec3fStruct[] = {
        {"x", TW_TYPE_FLOAT, offsetof(antVec3f, x), ""},
        {"y", TW_TYPE_FLOAT, offsetof(antVec3f, y), ""},
        {"z", TW_TYPE_FLOAT, offsetof(antVec3f, z), ""},
    };
    antVec3fType = TwDefineStruct("AntVec3F", 
                                  vec3fStruct,
                                  3,sizeof(antVec3f),
                                  NULL,NULL);


    TwStructMember vec4fStruct[] = {
        {"x", TW_TYPE_FLOAT, offsetof(antVec4f, x), ""},
        {"y", TW_TYPE_FLOAT, offsetof(antVec4f, y), ""},
        {"z", TW_TYPE_FLOAT, offsetof(antVec4f, z), ""},
        {"w", TW_TYPE_FLOAT, offsetof(antVec4f, w), ""},
    };
    antVec4fType = TwDefineStruct("AntVec4F", 
                                  vec4fStruct,
                                  4,sizeof(antVec4f),
                                  NULL,NULL);


    initialized = true;
    for (list<ITweakBar*>::iterator itr = barQueue.begin();
         itr != barQueue.end();
         itr++) {
        _AddBar(*itr);
    }
}

void AntTweakBar::Handle(RenderingEventArg arg) {
    glUseProgram(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glClientActiveTexture(GL_TEXTURE0);
    TwDraw();
}
void AntTweakBar::Handle(KeyboardEventArg arg) {
    int handled = 0;
    if (arg.type == EVENT_PRESS) {
        handled = TwKeyPressed(arg.sym, arg.mod);
    }

    if (!handled) {
        // TODO this will send more ups than downs :/
        uke.Notify(arg);
    }
}
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
    b->SetupBar(*this);
}

void AntTweakBar::AttachTo(IRenderer& renderer) { 
    renderer.InitializeEvent().Attach(init);
    renderer.DeinitializeEvent().Attach(deinit);
    renderer.PostProcessEvent().Attach(*this);
}


}
}
