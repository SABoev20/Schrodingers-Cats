#include "game.h"



void game::init_window()
{
	this->window = new sf::RenderWindow(sf::VideoMode(window_w, window_h), "GAME");
	this->window->setFramerateLimit(80);
}

void game::initPLayer()
{
	this->pshape.setSize(sf::Vector2f(this->playerSize, this->playerSize));
	this->player_texture.loadFromFile("assets/frame1.png");
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

void game::init_enemies()
{
	for (this->i = 0; this->i < this->enemiesNum; this->i++)
	{
		this->enemies[0][i] = randomNum(this->window_w);
		this->enemies[1][i] = randomNum(this->window_h);

		std::cout << enemies[0][i] << " " << this->enemies[1][i] << std::endl;
	}
	this->eshape.setSize(sf::Vector2f(80.f, 80.f));
	this->enemies_texture.loadFromFile("assets/player1.png");
	this->enemies_texture.setSmooth(true);
	this->eshape.setTexture(&enemies_texture);
}

void game::move_enemies()
{
	this->elapsed = this->clock.getElapsedTime();
	if (this->elapsed.asSeconds() > this->enemiesTimeCount)
	{
		enemiesTimeCount += 0.2;

		for (this->i = 0; this->i < this->enemiesNum; this->i++)
		{
			int a = randomNum(4);

			if (this->enemies[0][this->i] != this->numIfNuclearFusion and this->enemies[1][this->i] != this->numIfNuclearFusion)
			{
				if (a == 1)
				{
					this->enemies[0][i] += player_speed * 2;
				}
				else if (a == 2)
				{
					this->enemies[0][i] -= player_speed * 2;
				}
				else if (a == 3)
				{
					this->enemies[1][i] += player_speed * 2;
				}
				else if (a == 4)
				{
					this->enemies[1][i] -= player_speed * 2;
				}

				int w = eshape.getGlobalBounds().width;
				int h = eshape.getGlobalBounds().height;

				// Check whether enemiy is out of windows bounds

				if (this->enemies[0][i] + w > window_w)
				{
					this->enemies[0][i] = window_w - w;
				}
				if (this->enemies[0][i] < 0)
				{
					this->enemies[0][i] = 0;
				}
				if (this->enemies[1][i] + h > window_h)
				{
					this->enemies[1][i] = window_h - h;
				}
				if (this->enemies[1][i] < 0)
				{
					this->enemies[1][i] = 0;
				}
			}

		}
	}
}

void game::render_enemies()
{
	for (this->i = 0; this->i < this->enemiesNum; this->i++)
	{
		if (this->enemies[0][this->i] != this->numIfNuclearFusion and this->enemies[1][this->i] != this->numIfNuclearFusion)
		{
			this->eshape.setPosition(enemies[0][this->i], enemies[1][this->i]);
			this->window->draw(eshape);
		}

		this->eshape.setPosition(enemies[0][i], enemies[1][i]);
		this->window->draw(eshape);
	}
}

void game::nuclearFusion()
{
	int pw = this->pshape.getGlobalBounds().width;
	int ph = this->pshape.getGlobalBounds().height;


	int ew = this->eshape.getGlobalBounds().width;
	int eh = this->eshape.getGlobalBounds().height;
	for (i = 0; i < this->enemiesNum; i++)
	{
		if (enemies[0][i] != this->numIfNuclearFusion and enemies[1][i] != this->numIfNuclearFusion)
		{
			int playerCurPos_x = this->pshape.getPosition().x;
			int playerCurPos_y = this->pshape.getPosition().y;
			int enemyCurPos_x = enemies[0][i];
			int enemyCurPos_y = enemies[1][i];

			if ((playerCurPos_x >= enemyCurPos_x and playerCurPos_x <= enemyCurPos_x + ew)
				and (playerCurPos_y >= enemyCurPos_y and playerCurPos_y <= enemyCurPos_y + eh)
				or ((enemyCurPos_x >= playerCurPos_x and enemyCurPos_x <= playerCurPos_x + pw)
					and (enemyCurPos_y >= playerCurPos_y and enemyCurPos_y <= playerCurPos_y + ph)))
			{
				enemies[0][i] = numIfNuclearFusion;
				enemies[1][i] = numIfNuclearFusion;
				this->playerSize += 2;
				this->pshape.setSize(sf::Vector2f(this->playerSize, this->playerSize));
			}
		}
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


void game::checkBounds()
{
	int w = pshape.getGlobalBounds().width;
	int h = pshape.getGlobalBounds().height;

	if (pshape.getPosition().x + w > window_w)
	{
		pshape.setPosition(window_w - w, pshape.getPosition().y);
	}
	if (pshape.getPosition().x < 0)
	{
		pshape.setPosition(0, pshape.getPosition().y);
	}
	if (pshape.getPosition().y + h > window_h)
	{
		pshape.setPosition(pshape.getPosition().x, window_h - h);
	}
	if (pshape.getPosition().y < 0)
	{
		pshape.setPosition(pshape.getPosition().x, 0);
	}
}

void game::playerMove()
{
	if (this->window->hasFocus())
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

	checkBounds();

}

void game::setBackground()
{
	this->backgroundTexture.loadFromFile("assets/background-2.jpg");

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
	this->window->display();
}


void game::update()
{
	this->game::pollEvents();

	player_animation();
	move_enemies();
	playerMove();
	player_animation();
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
}