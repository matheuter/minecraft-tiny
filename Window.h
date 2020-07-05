//
// Created by bainsky on 2020/5/6.
//

#ifndef MINECRAFT_WINDOW_H
#define MINECRAFT_WINDOW_H
#include "GL/gl_imp.h"
#include "defination.h"

struct Rect{
	int x;
	int y;
};

class Window
{
private:
	Rect m_rect;
	void application();
	void destoryWindow();
	void createWindow();
}; 
#endif //MINECRAFT_WINDOW_H
