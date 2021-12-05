#pragma once
// Including all necessary libraries
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <random>
#include <windows.h>

class game
{

private:
	// Set width and height of window
	const int window_w = 1280;
	const int window_h = 720;
	// Set players speed, counter for change texture and initial size
	float player_speed = 3;
	int playerSize = 60;
	int player_frame = 1;
	sf::RenderWindow* window; // window object

	// Players and enemies shapes and textures
	sf::RectangleShape pshape;
	sf::RectangleShape eshape;
	sf::RectangleShape eshape1;
	sf::RectangleShape eshape2;
	sf::RectangleShape eshape3;
	sf::RectangleShape eshape4;
	sf::RectangleShape eshape5;
	sf::RectangleShape eshape6;
	sf::RectangleShape eshape7;
	sf::RectangleShape eshape8;
	sf::RectangleShape eshape9;
	sf::RectangleShape eshape10;
	sf::Texture player_texture;
	sf::Texture enemy1_texture;
	sf::Texture enemy2_texture;
	sf::Texture enemy3_texture;
	sf::Texture enemy4_texture;
	sf::Texture enemy5_texture;
	sf::Texture enemy6_texture;
	sf::Texture enemy7_texture;
	sf::Texture enemy8_texture;
	sf::Texture enemy9_texture;
	sf::Texture enemy10_texture;
	sf::Texture enemies_texture;

	float enemiesSize = 60;

	sf::Event sfmlEvent;

	// Initial backgrounds sprite and texture
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	// Initial games clock
	sf::Clock clock;
	sf::Time elapsed;
	int timeCount = 1;

	// Initial number of enemies
	int enemiesNum = 5;
	int enemies[2][100];
	float enemiesTimeCount = 0;
	int i;
	int numIfNuclearFusion = 2000;

	void init_window();
	void initPLayer();

	// Initial electron
	sf::RectangleShape electron;
	sf::Texture electron_texture;
	int ifElectronMove = 1;

	// Arrays with values of enemies textures
	int enemiesTextures[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	sf::Text text;

public:

	game(); // Constructor for initializing different values
	~game(); // Deconstructor for deleting values

	void pollEvents(); // Function to close window
	bool running(); // Function to check whether game is running
	void Start(); // Function to start game
	void update(); // Main function to change values every iteration
	void playerMove(); // Function to move your player using W, A, S and D keyboard keys
	void render(); // Main function to render objects every iteration
	sf::RectangleShape checkBounds(sf::RectangleShape shape); // Function to limit position
	void setBackground(); // Function to display background
	void player_animation(); // Function for animating players texture
	void init_enemies(); // Function to set random positions of enemies
	int randomNum(int n); // Function for returning random value
	void move_enemies(); // Function for random moving enemies
	void render_enemies(); // Function to draw enemies
	void nuclearFusion(); // Function for absorbing enemies by player based on real scinetific phenomenon
	void electron_shoot();
	sf::RectangleShape returnEnemy();
	sf::RectangleShape randomMove(sf::RectangleShape);
	bool checkObjectsContact(sf::RectangleShape, sf::RectangleShape);
	void checkRender(sf::RectangleShape);
	void for_every_enemy(void fun());
};

