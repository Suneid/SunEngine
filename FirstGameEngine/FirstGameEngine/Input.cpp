#include "Engine.h"

void Engine::input() {
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		m_Window.close();
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		m_Bob.MoveLeft();
	}
	else {
		m_Bob.StopLeft();
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		m_Bob.MoveRight();
	}
	else {
		m_Bob.StopRight();
	}
	
}