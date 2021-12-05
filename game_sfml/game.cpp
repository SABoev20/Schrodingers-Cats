#include "game.h"



void game::init_window()
{
	this->window = new sf::RenderWindow(sf::VideoMode(window_w, window_h), "GAME");
	this->window->setFramerateLimit(80);
}

void game::initPLayer()
{
	this->pshape.setSize(sf::Vector2f(this->playerSize, this->playerSize));
	this->player_texture.loadFromFile("assets/player.png");
	this->player_texture.setSmooth(true);
	this->pshape.setTexture(&player_texture);
	this->pshape.setPosition((this->window_w / 2) - (this->playerSize / 2), (this->window_h / 2) - (this->playerSize / 2));
}

void game::player_animation()
{
	this->elapsed = this->clock.getElapsedTime();
	if (this->elapsed.asSeconds() >= this->timeCount)
	{
		this->timeCount++;
		if (this->player_frame == 1)
		{
			this->player_texture.loadFromFile("assets/frame1.png");
			this->player_texture.setSmooth(true);
			this->pshape.setTexture(&player_texture);
		}
		else if (this->player_frame == 2)
		{
			this->player_texture.loadFromFile("assets/frame2.png");
			this->player_texture.setSmooth(true);
			this->pshape.setTexture(&player_texture);
		}
		if (this->player_frame == 3)
		{
			this->player_texture.loadFromFile("assets/frame3.png");
			this->player_texture.setSmooth(true);
			this->pshape.setTexture(&player_texture);
		}
		if (this->player_frame == 4)
		{
			this->player_texture.loadFromFile("assets/frame2.png");
			this->player_texture.setSmooth(true);
			this->pshape.setTexture(&player_texture);
		}
		this->player_frame++;
		if (this->player_frame > 4) this->player_frame = 1;
	}
}

int game::randomNum(int n)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, n);
	return dis(gen);
}

sf::RectangleShape game::returnEnemy()
{
	sf::RectangleShape shape;


	shape.setPosition(randomNum(this->window_w), randomNum(this->window_h));
	shape.setSize(sf::Vector2f(this->enemiesSize, this->enemiesSize));

	this->enemies_texture.loadFromFile("assets/enemy1.png");
	this->enemies_texture.setSmooth(true);
	shape.setTexture(&enemies_texture);

	return shape;
}

sf::RectangleShape game::randomMove(sf::RectangleShape shape)
{
	int a = randomNum(4);
	int x = shape.getPosition().x;
	int y = shape.getPosition().y;
	if (x != numIfNuclearFusion)
	{
		if (a == 1)
		{
			shape.setPosition(x - player_speed, y);
		}
		else if (a == 2)
		{
			shape.setPosition(x + player_speed, y);
		}
		else if (a == 3)
		{
			shape.setPosition(x, y - player_speed);
		}
		else if (a == 4)
		{
			shape.setPosition(x, y + player_speed);
		}
	}
	return shape;
}

bool game::checkObjectsContact(sf::RectangleShape shape1, sf::RectangleShape shape2)
{
	int pw = shape1.getGlobalBounds().width;
	int ph = shape1.getGlobalBounds().height;
	int ew = shape2.getGlobalBounds().width;
	int eh = shape2.getGlobalBounds().height;

	int playerCurPos_x = shape1.getPosition().x;
	int playerCurPos_y = shape1.getPosition().y;
	int enemyCurPos_x = shape2.getPosition().x;
	int enemyCurPos_y = shape2.getPosition().y;

	if ((playerCurPos_x >= enemyCurPos_x and playerCurPos_x <= enemyCurPos_x + ew)
		and (playerCurPos_y >= enemyCurPos_y and playerCurPos_y <= enemyCurPos_y + eh)
		or ((enemyCurPos_x >= playerCurPos_x and enemyCurPos_x <= playerCurPos_x + pw)
			and (enemyCurPos_y >= playerCurPos_y and enemyCurPos_y <= playerCurPos_y + ph)))
	{
		return 1;
	}
	else return 0;
}

void game::init_enemies()
{
		enemies_texture.loadFromFile("assets/enemy1.png");
		enemies_texture.setSmooth(true);
		eshape1 = returnEnemy();
		eshape2 = returnEnemy();
		eshape3 = returnEnemy();
		eshape4 = returnEnemy();
		eshape5 = returnEnemy();
		eshape6 = returnEnemy();
		eshape7 = returnEnemy();
		eshape8 = returnEnemy();
		eshape9 = returnEnemy();
		eshape10 = returnEnemy();
}

void game::move_enemies()
{
	this->elapsed = this->clock.getElapsedTime();
	if (this->elapsed.asSeconds() > this->enemiesTimeCount)
	{
		enemiesTimeCount += 0.1;
		this->eshape1 = randomMove(eshape1);
		eshape1 = checkBounds(eshape1);
		this->eshape2 = randomMove(eshape2);
		eshape2 = checkBounds(eshape2);
		this->eshape3 = randomMove(eshape3);
		eshape3 = checkBounds(eshape3);
		this->eshape4 = randomMove(eshape4);
		eshape4 = checkBounds(eshape4);
		this->eshape5 = randomMove(eshape5);
		eshape5 = checkBounds(eshape5);
		this->eshape6 = randomMove(eshape6);
		eshape6 = checkBounds(eshape6);
		this->eshape7 = randomMove(eshape7);
		eshape7 = checkBounds(eshape7);
		this->eshape8 = randomMove(eshape8);
		eshape8 = checkBounds(eshape8);
		this->eshape9 = randomMove(eshape9);
		eshape9 = checkBounds(eshape9);
		this->eshape10 = randomMove(eshape10);
		eshape10 = checkBounds(eshape10);
	}
}

void game::checkRender(sf::RectangleShape shape)
{
	int x = shape.getPosition().x;
	if (x != 2000)
	{
		this->window->draw(shape);
	}
}

void game::render_enemies()
{
		checkRender(eshape1);
		checkRender(eshape2);
		checkRender(eshape3);
		checkRender(eshape4);
		checkRender(eshape5);
		checkRender(eshape6);
		checkRender(eshape7);
		checkRender(eshape8);
		checkRender(eshape9);
		checkRender(eshape10);
}

void game::nuclearFusion()
{
	if (checkObjectsContact(pshape, eshape1) and enemiesTextures[0] >= 3)
	{
		eshape1.setPosition(2000, 0);
		playerSize += 5;
		pshape.setSize(sf::Vector2f(playerSize, playerSize));
	}
	else if (checkObjectsContact(pshape, eshape2) and enemiesTextures[1] >= 3)
	{
		eshape2.setPosition(2000, 0);
		playerSize += 5;
		pshape.setSize(sf::Vector2f(playerSize, playerSize));
	}
	else if (checkObjectsContact(pshape, eshape3) and enemiesTextures[2] >= 3)
	{
		eshape3.setPosition(2000, 0);
		playerSize += 5;
		pshape.setSize(sf::Vector2f(playerSize, playerSize));
	}
	else if (checkObjectsContact(pshape, eshape4) and enemiesTextures[3] >= 3)
	{
		eshape4.setPosition(2000, 0);
		playerSize += 5;
		pshape.setSize(sf::Vector2f(playerSize, playerSize));
	}
	else if (checkObjectsContact(pshape, eshape5) and enemiesTextures[4] >= 3)
	{
		eshape5.setPosition(2000, 0);
		playerSize += 5;
		pshape.setSize(sf::Vector2f(playerSize, playerSize));
	}
	else if (checkObjectsContact(pshape, eshape6) and enemiesTextures[5] >= 3)
	{
		eshape6.setPosition(2000, 0);
		playerSize += 5;
		pshape.setSize(sf::Vector2f(playerSize, playerSize));
	}
	else if (checkObjectsContact(pshape, eshape7) and enemiesTextures[6] >= 3)
	{
		eshape7.setPosition(2000, 0);
		playerSize += 5;
		pshape.setSize(sf::Vector2f(playerSize, playerSize));
	}
	else if (checkObjectsContact(pshape, eshape8) and enemiesTextures[7] >= 3)
	{
		eshape8.setPosition(2000, 0);
		playerSize += 5;
		pshape.setSize(sf::Vector2f(playerSize, playerSize));
	}
	else if (checkObjectsContact(pshape, eshape9) and enemiesTextures[8] >= 3)
	{
		eshape9.setPosition(2000, 0);
		playerSize += 5;
		pshape.setSize(sf::Vector2f(playerSize, playerSize));
	}
	else if (checkObjectsContact(pshape, eshape10) and enemiesTextures[9] >= 3)
	{
		eshape10.setPosition(2000, 0);
		playerSize += 5;
		pshape.setSize(sf::Vector2f(playerSize, playerSize));
	}
}

void game::electron_shoot()
{
	if (ifElectronMove != 0)
	{
		
		if (checkObjectsContact(electron, eshape1))
		{
			ifElectronMove = 0;

			if (enemiesTextures[0] < 4) enemiesTextures[0] += 1;
			if (enemiesTextures[0] == 2)
			{
				this->enemy1_texture.loadFromFile("assets/enemy2.png");
				this->enemy1_texture.setSmooth(true);
				eshape1.setTexture(&enemy1_texture);
			}
			else if (enemiesTextures[0] == 3)
			{
				this->enemy1_texture.loadFromFile("assets/enemy3.png");
				this->enemy1_texture.setSmooth(true);
				eshape1.setTexture(&enemy1_texture);
			}
		}
		if (checkObjectsContact(electron, eshape2))
		{
			ifElectronMove = 0;
			if (enemiesTextures[1] < 4) enemiesTextures[1] += 1;
			if (enemiesTextures[1] == 2)
			{
				this->enemy2_texture.loadFromFile("assets/enemy2.png");
				this->enemy2_texture.setSmooth(true);
				eshape2.setTexture(&enemy2_texture);
			}
			else if (enemiesTextures[1] == 3)
			{
				this->enemy2_texture.loadFromFile("assets/enemy3.png");
				this->enemy2_texture.setSmooth(true);
				eshape2.setTexture(&enemy2_texture);
			}
		}
		if (checkObjectsContact(electron, eshape3))
		{
			ifElectronMove = 0;
			if (enemiesTextures[2] < 4) enemiesTextures[2] += 1;
			if (enemiesTextures[2] == 2)
			{
				this->enemy3_texture.loadFromFile("assets/enemy2.png");
				this->enemy3_texture.setSmooth(true);
				eshape3.setTexture(&enemy3_texture);
			}
			else if (enemiesTextures[2] == 3)
			{
				this->enemy3_texture.loadFromFile("assets/enemy3.png");
				this->enemy3_texture.setSmooth(true);
				eshape3.setTexture(&enemy3_texture);
			}
		}
		if (checkObjectsContact(electron, eshape4))
		{
			ifElectronMove = 0;
			if (enemiesTextures[3] < 4) enemiesTextures[3] += 1;
			if (enemiesTextures[3] == 2)
			{
				this->enemy4_texture.loadFromFile("assets/enemy2.png");
				this->enemy4_texture.setSmooth(true);
				eshape4.setTexture(&enemy4_texture);
			}
			else if (enemiesTextures[3] == 3)
			{
				this->enemy4_texture.loadFromFile("assets/enemy3.png");
				this->enemy4_texture.setSmooth(true);
				eshape4.setTexture(&enemy4_texture);
			}
		}
		if (checkObjectsContact(electron, eshape5))
		{
			ifElectronMove = 0;
			if (enemiesTextures[4] < 4) enemiesTextures[4] += 1;
			if (enemiesTextures[4] == 2)
			{
				this->enemy5_texture.loadFromFile("assets/enemy2.png");
				this->enemy5_texture.setSmooth(true);
				eshape5.setTexture(&enemy5_texture);
			}
			else if (enemiesTextures[4] == 3)
			{
				this->enemy5_texture.loadFromFile("assets/enemy3.png");
				this->enemy5_texture.setSmooth(true);
				eshape5.setTexture(&enemy5_texture);
			}
		}
		if (checkObjectsContact(electron, eshape6))
		{
			ifElectronMove = 0;
			if (enemiesTextures[5] < 4) enemiesTextures[5] += 1;
			if (enemiesTextures[5] == 2)
			{
				this->enemy6_texture.loadFromFile("assets/enemy2.png");
				this->enemy6_texture.setSmooth(true);
				eshape6.setTexture(&enemy6_texture);
			}
			else if (enemiesTextures[5] == 3)
			{
				this->enemy6_texture.loadFromFile("assets/enemy3.png");
				this->enemy6_texture.setSmooth(true);
				eshape6.setTexture(&enemy6_texture);
			}
		}
		if (checkObjectsContact(electron, eshape7))
		{
			ifElectronMove = 0;
			if (enemiesTextures[6] < 4) enemiesTextures[6] += 1;
			if (enemiesTextures[6] == 2)
			{
				this->enemy7_texture.loadFromFile("assets/enemy2.png");
				this->enemy7_texture.setSmooth(true);
				eshape7.setTexture(&enemy7_texture);
			}
			else if (enemiesTextures[6] == 3)
			{
				this->enemy7_texture.loadFromFile("assets/enemy3.png");
				this->enemy7_texture.setSmooth(true);
				eshape7.setTexture(&enemy7_texture);
			}
		}
		if (checkObjectsContact(electron, eshape8))
		{
			ifElectronMove = 0;
			if (enemiesTextures[7] < 4) enemiesTextures[7] += 1;
			if (enemiesTextures[7] == 2)
			{
				this->enemy8_texture.loadFromFile("assets/enemy2.png");
				this->enemy8_texture.setSmooth(true);
				eshape8.setTexture(&enemy8_texture);
			}
			else if (enemiesTextures[7] == 3)
			{
				this->enemy8_texture.loadFromFile("assets/enemy3.png");
				this->enemy8_texture.setSmooth(true);
				eshape8.setTexture(&enemy8_texture);
			}
		}
		if (checkObjectsContact(electron, eshape9))
		{
			ifElectronMove = 0;
			if (enemiesTextures[8] < 4) enemiesTextures[8] += 1;
			if (enemiesTextures[8] == 2)
			{
				this->enemy9_texture.loadFromFile("assets/enemy2.png");
				this->enemy9_texture.setSmooth(true);
				eshape9.setTexture(&enemy9_texture);
			}
			else if (enemiesTextures[8] == 3)
			{
				this->enemy9_texture.loadFromFile("assets/enemy3.png");
				this->enemy9_texture.setSmooth(true);
				eshape9.setTexture(&enemy9_texture);
			}
		}
		if (checkObjectsContact(electron, eshape10))
		{
			ifElectronMove = 0;
			if (enemiesTextures[9] < 4) enemiesTextures[9] += 1;
			if (enemiesTextures[9] == 2)
			{
				this->enemy10_texture.loadFromFile("assets/enemy2.png");
				this->enemy10_texture.setSmooth(true);
				eshape10.setTexture(&enemy10_texture);
			}
			else if (enemiesTextures[9] == 3)
			{
				this->enemy10_texture.loadFromFile("assets/enemy3.png");
				this->enemy10_texture.setSmooth(true);
				eshape10.setTexture(&enemy10_texture);
			}
		}
		

		if(this->electron.getPosition().x > window_w or this->electron.getPosition().y > window_h
			or this->electron.getPosition().x < 0 or this->electron.getPosition().y < 0)	ifElectronMove = 0;

		if (ifElectronMove == 1)
		{
			this->electron.move(-player_speed * 4, 0);
			this->window->draw(this->electron);
		}
		else if (ifElectronMove == 2)
		{
			this->electron.move(player_speed * 4, 0);
			this->window->draw(this->electron);
		}
		else if (ifElectronMove == 3)
		{
			this->electron.move(0, -player_speed * 4);
			this->window->draw(this->electron);
		}
		else if (ifElectronMove == 4)
		{
			this->electron.move(0, player_speed * 4);
			this->window->draw(this->electron);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		float playerCurPos_x = this->pshape.getPosition().x;
		float playerCurPos_y = this->pshape.getPosition().y;
		float pw = this->pshape.getGlobalBounds().width;
		float ph = this->pshape.getGlobalBounds().height;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) and playerSize > 40)
		{
			this->electron.setPosition(playerCurPos_x, playerCurPos_y + ph / 2 - 4);
			ifElectronMove = 1;
			this->window->draw(this->electron);
			playerSize -= 1;
			pshape.setSize(sf::Vector2f(playerSize, playerSize));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) and playerSize > 40)
		{
			this->electron.setPosition(playerCurPos_x+pw, playerCurPos_y + ph / 2 - 4);
			ifElectronMove = 2;
			this->window->draw(this->electron);
			playerSize -= 1;
			pshape.setSize(sf::Vector2f(playerSize, playerSize));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and playerSize > 40)
		{
			this->electron.setPosition(playerCurPos_x + pw / 2 - 4, playerCurPos_y);
			ifElectronMove = 3;
			this->window->draw(this->electron);
			playerSize -= 1;
			pshape.setSize(sf::Vector2f(playerSize, playerSize));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and playerSize > 40)
		{
			this->electron.setPosition(playerCurPos_x + pw / 2 - 4, playerCurPos_y+ph);
			ifElectronMove = 4;
			this->window->draw(this->electron);
			playerSize -= 1;
			pshape.setSize(sf::Vector2f(playerSize, playerSize));
		}
		if(playerSize < 30) playerSize = 30;
		pshape.setSize(sf::Vector2f(playerSize, playerSize));
	}
}

bool game::running()
{
	return this->window->isOpen();
}

void game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();

		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			break;
		}
	}
}


sf::RectangleShape game::checkBounds(sf::RectangleShape shape)
{
	int w = shape.getGlobalBounds().width;
	int h = shape.getGlobalBounds().height;
	if (shape.getPosition().x != numIfNuclearFusion)
	{
		if (shape.getPosition().x + w > window_w)
		{
			shape.setPosition(window_w - w, shape.getPosition().y);
		}
		if (shape.getPosition().x < 0)
		{
			shape.setPosition(0, shape.getPosition().y);
		}
		if (shape.getPosition().y + h > window_h)
		{
			shape.setPosition(pshape.getPosition().x, window_h - h);
		}
		if (shape.getPosition().y < 0)
		{
			shape.setPosition(shape.getPosition().x, 0);
		}
	}
	return shape;
}

void game::playerMove()
{
	if (this->window->hasFocus())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				this->pshape.move(-player_speed * 3, 0.f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				this->pshape.move(player_speed*3, 0.f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				this->pshape.move(0.f, -player_speed * 3);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				this->pshape.move(0.f, player_speed * 3);
			}
		}
		else if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::E)))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				this->pshape.move(-player_speed, 0.f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				this->pshape.move(player_speed, 0.f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				this->pshape.move(0.f, -player_speed);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				this->pshape.move(0.f, player_speed);
			}
		}
		pshape = checkBounds(pshape);
	}
}

void game::setBackground()
{
	this->backgroundTexture.loadFromFile("assets/background.png");

	this->backgroundSprite.setTexture(backgroundTexture);
	this->backgroundSprite.setScale(window_w / backgroundSprite.getGlobalBounds().width, window_h / backgroundSprite.getGlobalBounds().height);
}

void game::render()
{
	this->window->clear();
	this->window->draw(this->backgroundSprite);
	this->window->draw(this->pshape);
	render_enemies();
	/*this->window->clear();*/
	this->window->draw(this->backgroundSprite);
	render_enemies();
	this->window->draw(this->pshape);
	electron_shoot();
	this->window->display();
}


void game::update()
{
	this->game::pollEvents();
	move_enemies();
	playerMove();
	move_enemies();
	nuclearFusion();
}


game::game()
{
	init_window();
	initPLayer();
	setBackground();
	init_enemies();

	this->electron.setSize(sf::Vector2f(12, 10));
	this->electron_texture.loadFromFile("assets/elec.png");
	this->electron.setTexture(&electron_texture);
}

game::~game()
{
	delete this->window;
}

void game::Start()
{
	while (running())
	{
		update();
		render();
	}
};