// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------

#include "TweakVar.h"

#include <Display/ITweakBar.h>
#include <Utils/TweakBar.h>

namespace OpenEngine {
namespace Utils {

    

void TweakVar::AntSetCallback(const void *value, void* ctx) {
    // const std::string *srcPtr = static_cast<const std::string *>(value);
    // PropertyTreeNode* node = static_cast<PropertyTreeNode*>(ctx);
    // node->SetValue(*srcPtr);

}
void TweakVar::AntGetCallback(void *value, void* ctx) {
    std::string *destPtr = static_cast<std::string *>(value);
    //PropertyTreeNode* node = static_cast<PropertyTreeNode*>(ctx);
    string val = "asd";
    TwCopyStdStringToLibrary(*destPtr, val);
}


} // NS Utils
} // NS OpenEngine

