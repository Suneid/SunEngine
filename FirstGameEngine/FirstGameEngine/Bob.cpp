#include <Bob.h>
#include <iostream>
Bob::Bob() {
	m_Speed = 400;

	m_Texture.loadFromFile("skin.png");
	m_Sprite.setTexture(m_Texture);
	m_Position.x = 300;
	m_Position.y = 300;
	m_needReverse = false;
	m_reversedSprite = -1;
}

Sprite Bob::GetSprite() {
	return m_Sprite;
}

void Bob::MoveLeft() {
	//Проверка направления движения, если игрок движется в обратную сторону, нужно развернуть спрайт
	if (m_reversedSprite != -1) {
		m_reversedSprite = -1;
		m_needReverse = true;
		std::cout << -1 << std::endl;
	}
	m_LeftPressed = true;
}

void Bob::MoveRight() {
	//Проверка направления движения, если игрок движется в обратную сторону, нужно развернуть спрайт
	if (m_reversedSprite != 1) {
		m_reversedSprite = 1;
		m_needReverse = true;
	}
	m_RightPressed = true;
}


void Bob::StopLeft() {
	m_LeftPressed = false;
}

void Bob::StopRight() {
	m_RightPressed = false;
}

void Bob::update(float elapsedTime) {
	if (m_RightPressed && !m_LeftPressed) {
		if (m_needReverse) {
			m_needReverse = false;
			m_Sprite.setScale(-1, 1);
			m_Position.x += m_Texture.getSize().x;
			std::cout << 1 << std::endl;
		}
		m_Position.x += m_Speed * elapsedTime;
	}
	else if (m_LeftPressed && !m_RightPressed) {
		if (m_needReverse) {
			m_needReverse = false;
    		m_Sprite.setScale(1, 1);
			m_Position.x -=  m_Texture.getSize().x;
			std::cout << -1 << std::endl;
			
		}
		m_Position.x -= m_Speed * elapsedTime;
	}
	
	m_Sprite.setPosition(m_Position);
}