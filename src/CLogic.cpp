#include "CLogic.h"

CLogic::CLogic() : m_pRenderer(nullptr), m_nWindowHeight(0), m_nWindowWidth(0){
	
}


// Use this for any startup required things
void CLogic::Init(SDL_Renderer* renderer, int WindowWidth, int WindowHeight) {
	m_nWindowWidth = WindowWidth;
	m_nWindowHeight = WindowHeight;
	player.Init();
	m_pEntities.push_back(&player);
}

void CLogic::AdjustResolution(int x, int y) {

	for (size_t it = 0; it < m_pEntities.size(); ++it) {
		m_pEntities[it]->AdjustForResolution(Vector2(x, y), Vector2(m_nWindowWidth, m_nWindowHeight));
	}
	m_nWindowWidth = x;
	m_nWindowHeight = y;
}




void CLogic::Update(float dt) {
	
	player.Move(dt);
}

// Draw calls
void CLogic::Render(){
	// Clear the background with all white
	SDL_SetRenderDrawColor(CRenderer::Get().GetRenderer(), 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(CRenderer::Get().GetRenderer());

	// Rendering entities
	SDL_SetRenderDrawColor(CRenderer::Get().GetRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);

	for (size_t i = 0; i < m_pEntities.size(); ++i) {
		m_pEntities[i]->Render();
	}
	
	

	// Presenting entities
	SDL_RenderPresent(CRenderer::Get().GetRenderer());
}

// Main games input handler
void CLogic::InputHandler(const SDL_Event& key) {

	player.InputHandler(key);
	// Pass input wherever it is required
}





void CLogic::Cleanup() {

}
CLogic::~CLogic() {
	LOG("Cleaning up logic..");
	Cleanup();
}