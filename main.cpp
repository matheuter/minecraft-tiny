#include <iostream>
#include "defination.h"
#include "GL/gl_imp.h"

void test()
{
	glBegin(GL_LINES);
	glVertex2d(1.0f,1.0f);
	glVertex2d(-1.0f,-1.0f);
	glEnd();
}
int main()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL Initialize is fail" << std::endl;
		exit(1);
	}

	//use opengl 3.3
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//init SDL windows,
	SDL_Window *window = nullptr;
	window = SDL_CreateWindow(
		"minecraft",
		minecraft::WINDOW_POS_X,
		minecraft::WINDOW_POS_Y,
		minecraft::SCREEN_WIDTH,
		minecraft::SCREEN_HEIGHT,
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if(NULL == window)
	{
		std::cout <<"Create Window is fail.Error:"<<SDL_GetError()<<std::endl;
		exit(0);
	}

	bool running = true;
	while (running) {
		SDL_Event event;
		while( SDL_PollEvent( &event ) ) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}
		test();
		SDL_GL_SwapWindow(window);
		SDL_Delay( 50 );
	}
	return 1;
}

