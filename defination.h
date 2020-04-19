//
// Created by bainsky on 2020/4/19.
// tips: a header to define const value
//

#ifndef MINECRAFT_DEFINATION_H
#define MINECRAFT_DEFINATION_H

#include "GL/gl_imp.h"
namespace minecraft
{
	constexpr int SCREEN_WIDTH = 1000;
	constexpr int SCREEN_HEIGHT = 680;

	constexpr int WINDOW_POS_X = 200;
	constexpr int WINDOW_POS_Y = 200;

	constexpr GLint CHUNK_WIDHT = 16;
	constexpr GLint CHUNK_HEIGHT = 16;
	constexpr GLint CHUNK_DEPTH = 256;

	bool g_window_flag = true;
	bool g_render_flag = true;

}// namespace minecraft

#endif //MINECRAFT_DEFINATION_H
