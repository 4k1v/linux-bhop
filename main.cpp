#include<iostream>
#include<unistd.h>
#include<X11/Xlib.h>
#include<stdio.h>
#include<termios.h>
#include<X11/keysym.h>
#include<X11/keysymdef.h>


    bool GetState(KeySym ks)
    {
        Display *dpy = XOpenDisplay(":0");
        char keys_return[32];
        XQueryKeymap(dpy, keys_return);
        KeyCode kc2 = XKeysymToKeycode(dpy, ks);
        bool isPressed = !!(keys_return[kc2 >> 3] & (1 << (kc2 & 7)));
        XCloseDisplay(dpy);
        return isPressed;                
    }

int main()
{
    while(true)
    {   
        if(GetState(XK_space))
        {
            sleep(0.05);
            system("xdotool key l");
        }
        
    }
    
}
