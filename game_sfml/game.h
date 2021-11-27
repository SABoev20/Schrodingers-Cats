#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <random>

class game
{

private:
	const int window_w = 1280;
	const int window_h = 720;
	float player_speed = 5;
	int playerSize = 50;

	sf::RenderWindow* window;
	sf::RectangleShape pshape;
	sf::RectangleShape eshape;
	sf::Texture player_texture;
	sf::Texture enemies_texture;
	sf::Event sfmlEvent;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	sf::Clock clock;
	sf::Time elapsed;
	int timeCount = 1;
	int player_frame = 1;
	int enemiesNum = 10;
	int enemies[2][100];
	float enemiesTimeCount = 0;
	int i;
	int numIfNuclearFusion = 2000;

	void init_window();
	void initPLayer();

public:

	game();
	~game();

	void pollEvents();
	bool running();
	void Start();
	void update();
	void playerMove();
	void render();
	void checkBounds();
	void setBackground();
	void player_animation();
	void init_enemies();
	int randomNum(int n);
	void move_enemies();
	void render_enemies();
	void nuclearFusion();
};

