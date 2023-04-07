#include "controller_api.h"
#if defined(__ANDROID__)
    int curInputSource=VK_INPUTTYPE_TOUCHSCREEN;
#else
    int curInputSource=VK_INPUTTYPE_OTHER;
#endif


void set_current_input(int in){
    curInputSource=in;
}

int get_current_input(){
    return curInputSource;
}