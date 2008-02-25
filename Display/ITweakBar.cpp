#include "ITweakBar.h"

namespace OpenEngine {
namespace Display {


    ITweakBar::ITweakBar(string name) : name(name) {}
    
    ITweakBar::~ITweakBar() {}

    void ITweakBar::SetupBar() {

        bar = TwNewBar(name.c_str());

        AddFields();
    }
}
}
