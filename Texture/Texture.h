#ifndef MINECRAFT_TEXTURE_H
#define MINECRAFT_TEXTURE_H
#include "../GL/gl_imp.h"

class Texture
{
public:
	unsigned int texture_id;
public:
	Texture(const char* texture_path);
};


#endif //MINECRAFT_TEXTURE_H
