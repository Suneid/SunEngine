#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Bob {
private:
	Vector2f m_Position;
	Sprite m_Sprite;
	Texture m_Texture;
	
	bool m_LeftPressed;
	bool m_RightPressed;
	int m_reversedSprite;
	bool m_needReverse;
	float m_Speed;

public:
	Bob();

	Sprite GetSprite();
	void MoveLeft();
	void MoveRight();
	void StopLeft();
	void StopRight();
	void update(float elapsedTime);
};