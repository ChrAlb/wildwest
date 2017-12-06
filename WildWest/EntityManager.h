#pragma once
#include <unordered_map>
#include "PlayableCharacter.h"

enum class EntityType { Base, Enemy, Player };

using EntityContainer = std::unordered_map <unsigned int, PlayableCharacter*>;

class EntityManager 

{
	
public:
	EntityManager();
	~EntityManager();

	int Add(PlayableCharacter& object);
	void Remove(unsigned int l_id);
	PlayableCharacter* Find(unsigned int l_id);

	void Update(float dt);
	void Draw();
	void Purge();

private:
	EntityContainer m_entities;

};


