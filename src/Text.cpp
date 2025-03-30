#include "../include/Text.hpp"

void Text::update()
{
	glm::vec2 pos = { m_Pos.x, m_Pos.y};
	for (auto& e : m_SpriteVector)
	{
		e->setPosition(pos);
		e->setScale(m_Scale);
		e->setOrigin(pos);
		e->setRotation(m_Angle);
		pos.x += m_Space;
	}
}

Text::Text(const std::string& text)
{
	m_Content = text;
}

Text::~Text()
{
	for (auto* sprite : m_SpriteVector) 
	{
		delete sprite;
	}
}

void Text::setText(const std::string& text)
{
	m_Content = text;
	m_SpriteVector.clear();
	for (size_t i = 0; i < m_Content.size(); ++i)
	{
		Sprite* sprite = new Sprite(m_CharMap->getCharacterSprite(m_Content[i]));
		m_SpriteVector.push_back(sprite);
	}
}

const std::string Text::getText() const
{
	return m_Content;
}

void Text::bindMap(CharacterMap& charMap)
{
	m_CharMap = &charMap;
}

void Text::unbindMap()
{
	m_CharMap = nullptr;
}

std::string Text::operator+(const std::string& rv)
{
	return m_Content + rv;
}

std::string Text::operator+(int rv)
{
	char num = '0' + rv;
	return m_Content + num;
}

std::string Text::operator+=(const std::string& rv)
{
	m_Content += rv;
	this->setText(m_Content);
	return m_Content;
}

std::string Text::operator+=(int rv)
{
	char num = '0' + rv;
	m_Content += num;
	this->setText(m_Content);
	return m_Content;
}

const char Text::operator[](size_t index)
{
	return m_Content[index];
}

void Text::setPosition(glm::vec2 pos)
{
	m_Pos = pos;
}

void Text::setScale(glm::vec2 scale)
{
	m_Scale = scale;
}

void Text::setRotation(float angle)
{
	m_Angle = angle;
}

glm::vec2 Text::getPosition() const
{
	return m_Pos;
}

glm::vec2 Text::getScale() const
{
	return m_Scale;
}

float Text::getRotation() const
{
	return m_Angle;
}

void Text::setCharacterSpace(float space)
{
	m_Space = space;
}
