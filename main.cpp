#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <GL/glut.h>
#include "defination.h"

bool  g_window_flage = true;
bool  g_render_quad = true;

void InitializeOpengl()
{
	GLenum error = GL_NO_ERROR;


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	error = glGetError();
	if( error != GL_NO_ERROR )
	{
		printf(" Initiailizie OpenGl is fail.Error: %s \n", gluErrorString( error ));
		exit(0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	error = glGetError();
	if( error != GL_NO_ERROR )
	{
		printf(" Initiailizie OpenGl is fail.Error:", gluErrorString( error ));
		exit(0);
	}

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	error = glGetError();
	if( error != GL_NO_ERROR)
	{
		printf(" Initiailizie OpenGl is fail.Error:", gluErrorString( error ));
		exit(0);
	}


	glEnable(GL_TEXTURE_2D);
}

void OpenglDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	if(g_render_quad)
	{
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(-0.5f, -0.5f);

		glTexCoord2f(1.0, 1.0);
		glVertex2f(0.5f, -0.5f);

		glTexCoord2f(1.0, 0.0);
		glVertex2f(0.5f, 0.5f);

		glTexCoord2f(0.0, 0.0);
		glVertex2f(-0.5f, 0.5f);
		glEnd();
		}
}

void EventDeal()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_ESCAPE:
				g_window_flage = false;
				break;
			case SDLK_r:
				g_render_quad = !g_render_quad;
				break;
			default:
				break;
		}
	}
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
	SDL_Window *window = SDL_CreateWindow(
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

	SDL_GLContext gcontext = SDL_GL_CreateContext(window);

	if(NULL == gcontext)
	{
		std::cout <<"Create SDL_Context is fail.Error:"<<SDL_GetError()<<std::endl;
		exit(0);
	}

	InitializeOpengl();


	SDL_Surface* background = IMG_Load("empress.png");
	SDL_Surface *image_sur = SDL_ConvertSurfaceFormat(background, SDL_PIXELFORMAT_ABGR8888 /*SDL_PIXELFORMAT_RGBA8888*/ /*SDL_PIXELFORMAT_ARGB8888*/, 0);


	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, image_sur->w, image_sur->h, GL_RGBA/*GL_ABGR_EXT*/, GL_UNSIGNED_BYTE, image_sur->pixels);
	SDL_FreeSurface(background);

	if(SDL_GL_SetSwapInterval(1) < 0)
	{
		printf(" Warnning: unable to set VSync! Error: %s \n", SDL_GetError());
	}


	while(g_window_flage)
	{
		OpenglDisplay();
		EventDeal();

		SDL_GL_SwapWindow(window);
		SDL_Delay(40);
	}


	return 0;
}
