#pragma once

#include "PlayableCharacter.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"


class Bullet : public PlayableCharacter

{
public:
	Bullet();
    bool handleInput();
	void update(float dt);

	
private:

	TextureHolder m_Textures;

};
