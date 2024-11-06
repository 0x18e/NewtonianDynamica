#pragma once
#include "Utilities.h"
#include<SDL.h>
#include "CEntity.h"
#include "CBasePlayer.h"
#include "CRenderer.h"
 class CLogic {
	
private:
	SDL_Renderer* m_pRenderer;
	
	CBasePlayer player;
	std::vector<CEntity*> m_pEntities;
	
	// Set local window widths and heights
	int m_nWindowWidth;
	int m_nWindowHeight;
public:
	CLogic();
	~CLogic();
	
	void Init(SDL_Renderer* renderer, int WindowWidth, int WindowHeight);
	void AdjustResolution(int x, int y);


	// Core functions
	void Update(float dt);
	void Render();
	void Cleanup();
	void InputHandler(const SDL_Event &key);
};