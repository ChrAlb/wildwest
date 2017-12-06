#include "EntityManager.h"
#include "PlayableCharacter.h"
#include "stdafx.h"


EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{
	Purge();
}

int EntityManager::Add(PlayableCharacter& object)

{
	
	m_entities.emplace(3,object);
	//entity->m_id 

}

