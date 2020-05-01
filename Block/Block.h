#ifndef MINECRAFT_BLOCK_H
#define MINECRAFT_BLOCK_H

#include "../Texture/Texture.h"
#include "../GL/gl_imp.h"
class Block
{
private:
	glm::vec3 m_position;
	Texture* m_pTexture;
	bool m_isVisable;
public:
	Block() = default;
	~Block();
	virtual void drawBlock();
};
#endif //MINECRAFT_BLOCK_H