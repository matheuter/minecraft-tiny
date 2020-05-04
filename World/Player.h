//
// Created by bainsky on 2020/4/27.
//

#ifndef MINECRAFT_PLAYER_H
#define MINECRAFT_PLAYER_H

#include "../GL/gl_imp.h"
#include "../Model/Attribute.h"
#include "ActionType.h"

using namespace minecraft;

class Player
{
private:
	using Direction = ActionType::AC_TYPE;
private:
	glm::vec3 m_position;
	Attribute m_attribute;

public:
	void drawPlayer();
	void run(Direction& dir);
	void walk(Direction& dir);

	void jump();
};

#endif //MINECRAFT_PLAYER_H
