#include<iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "View.h"
#include <sstream>
#include <SFML/Audio.hpp>
#include <vector>
#include <list>
#include "Menu.h"
#include "death.h"

using namespace sf;


class Entity {
public:
	float dx, dy, x, y, speed, moveTimer;
	int w, h, health;
	bool life, isMove , onGround ;
	Texture texture;
	Sprite sprite;
	String name;
	enum { left, right, up, down, jump, stay }state;
	Entity(Image &image, float X, float Y, int W, int H, String Name) {
		x = X; y = Y; w = W; h = H; name = Name; moveTimer = 0;
		speed = 0; health = 100; dx = 0; dy = 0;
		life = true; onGround = false; isMove = false;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
	}
		FloatRect getRect() {
			return FloatRect(x, y, w, h);
		
	}
		virtual void update(float time) = 0;
};
class Player {

public:
	FloatRect rect;
	float w, h, dx, dy, x, y, speed;
	int dir, playerScore, health;
	bool life, isMove, onGround;
	enum { left, right, up, down, jump, stay }state;
	String File;
	Image im;
	Texture t;
	Sprite s;

	Player(String F, float X, float Y, float W, float H) {
		dir = 0; speed = 0; playerScore = 0; health = 100; dx = 0; dy = 0;
		life = true; isMove = false; onGround = false;
		File = F;
		w = W; h = H;
		im.loadFromFile("C:\\ekzz\\11.png");
		t.loadFromImage(im);
		s.setTexture(t);
		x = X; y = Y;
		s.setTextureRect(IntRect(0, 0, w, h));
		s.setOrigin(w / 2, h / 2);
		s.setPosition(5, 5);
	}
	FloatRect getRect() {
		return FloatRect(x, y, w, h);
	}
	



	void control() {
		
		if (life == true) {
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				
				state = right;
				speed = 0.15;
			}

			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				state = left;
				speed = 0.15;
			}
			if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround)) {
				state = jump; dy = -0.7; onGround = false; 
			}
		}
	}
	void update(float time)
	{
		
		control();
		switch (state)
		{
		case right: dx = speed; break;
		case left: dx = -speed; break;
		case jump: break;

		}


		x += dx * time;
		checkCollisionWithMap(dx, 0);
		y += dy * time;
		checkCollisionWithMap(0, dy);
		if (!isMove) speed = 0;

		s.setPosition(x + w / 2, y + h / 1.62);

		if (health <= 0) {
			life = false; 

		}
		
		dy = dy + 0.0015*time;
	}

	float getplayercoordinateX() {
		return x;
	}
	float getplayercoordinateY() {
		return y;
		
	}



	void checkCollisionWithMap(float Dx, float Dy)
	{
		for (int i = y / 50; i < (y + h) / 50; i++)
			for (int j = x / 50; j < (x + w) / 50; j++)
			{
				if (TileMap[i][j] == 't')
				{
					if (Dy > 0) { y = i * 50 - h;  dy = 0; onGround = true; }
					if (Dy < 0) { y = i * 50 + 50;  dy = 0; }
					if (Dx > 0) { x = j * 50 - w; }
					if (Dx < 0) { x = j * 50 + 50; }
				}
				if (TileMap[i][j] == 'q')
				{
					if (Dy > 0) { y = i * 50 - h;  dy = 0; onGround = true; }
					if (Dy < 0) { y = i * 50 + 50;  dy = 0; }
					if (Dx > 0) { x = j * 50 - w; }
					if (Dx < 0) { x = j * 50 + 50; }
				}
				if (TileMap[i][j] == 'a') {
					playerScore++;
					TileMap[i][j] = ' ';
				}

				if (TileMap[i][j] == 'd') {
					health -= 40;
					TileMap[i][j] = ' ';
				}
				if (TileMap[i][j] == 'l') {
					health += 40;
					TileMap[i][j] = ' ';
				}
			}
	}
};
class Enemy :public Entity {
public:

	Enemy(Image &image, float X, float Y, int W, int H, String Name) :Entity(image, X, Y, W, H, Name) {
		if (name == "EasyEnemy") {
			sprite.setTextureRect(IntRect(0, 0, w, h));
			dx = 0.1;
			FloatRect rect;
			

		}
	}
	void set(int x, int y)
	{
		float currentFrame = 0;
	}

	void checkCollisionWithMap(float Dx, float Dy)
	{
		for (int i = y / 50; i < (y + h) / 50; i++)
			for (int j = x / 50; j < (x + w) / 50; j++)
			{
				if (TileMap[i][j] == 't')
				{
					if (Dy > 0) { y = i * 50 - h;  dy = 0; }
					if (Dy < 0) { y = i * 50 + 50; }
					if (Dx > 0) { x = j * 50 - w; dx = -0.1; sprite.scale(-1, 1); }
					if (Dx < 0) { x = j * 50 + 50; dx = 0.1; sprite.scale(-1, 1); }
				}

			}
	};
	void update(float time)
	{
		if (name == "EasyEnemy") {
			if (onGround = "t") { onGround = false; }
			moveTimer += time;
			if (moveTimer > 9000000000000000) { dx *= -1; moveTimer = 0; }
			sprite.setPosition(x + w / 2, y + h / 2);
			if (health <= 0) { life = false; }
			x += dx * time;
			checkCollisionWithMap(dx, 0);
			y += dy * time;
			checkCollisionWithMap(0, dy);
			if (!isMove) speed = 0;
			dy = dy + 0.0015*time;

			float currentFrame = 0;
			currentFrame += time * 0.005;
			if (currentFrame > 3) currentFrame -= 3;

			sprite.setTextureRect(IntRect(80 * int(currentFrame), 0, 80, 60));
		}
	}
};

int main()
{
	RenderWindow window(sf::VideoMode(1204, 768),"GAME1");
	menu(window);

	
	Image map_image;
	map_image.loadFromFile("C:\\ekzz\\tileset.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite play_map;
	play_map.setTexture(map);

	int count = 0;
	int count1 = 10;


	Music music;
	music.openFromFile("C:\\ekzz\\4.ogg");
	music.play();
	music.setLoop(true);


	SoundBuffer buffer;
	buffer.loadFromFile("C:\\ekzz\\3.ogg");
	Sound sound(buffer);

	Sprite tile(play_map);
	{
		RenderWindow window(sf::VideoMode(550, 400), "Lesson 1. kychka-pc.ru");
		view.reset(sf::FloatRect(0, 0, 550, 400));



		Font font;
		font.loadFromFile("C:\\ekzz\\CyrilicOld.ttf");
		Text text("", font, 20);
		text.setFillColor(Color::Red);
		text.setStyle(Text::Bold);

		Image map_image;
		map_image.loadFromFile("C:\\ekzz\\tileset.png");
		Texture map;
		map.loadFromImage(map_image);
		Sprite play_map;
		play_map.setTexture(map);

		Image easyEnemyImage;
		easyEnemyImage.loadFromFile("C:\\ekzz\\enemy12.png");

		Player p("C:\\ekzz\\11.png", 0, 0, 49, 112);
		Enemy easyEnemy(easyEnemyImage, 0, 0, 80, 60, "EasyEnemy");
		
		std::list<Entity*>  entities;
		std::list<Entity*>::iterator it;
		
		

		float CurrentFrame = 0;
		Clock clock;
		Clock gameTimeClock;
		int gameTime = 0;
		while (window.isOpen())
		{
			float time = clock.getElapsedTime().asMicroseconds();
			if (p.life) gameTime = gameTimeClock.getElapsedTime().asSeconds();
			clock.restart();
			time = time / 800;


			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape)) { return true; }

			float coordinatePlayerX, coordinatePlayerY = 0;
			coordinatePlayerX = p.getplayercoordinateX();
			coordinatePlayerY = p.getplayercoordinateY();
			
			
			if (p.life == true) {
				if (Keyboard::isKeyPressed(Keyboard::Right)) {
					p.dir = 0; p.speed = 0.1;
					CurrentFrame += 0.008*time;
					if (CurrentFrame > 8) CurrentFrame -= 8;
					p.s.setTextureRect(IntRect(49 * int(CurrentFrame), 0, 49, 112));

				}

				if (Keyboard::isKeyPressed(Keyboard::Left)) {
					p.dir = 1; p.speed = 0.1;
					CurrentFrame += 0.008*time;
					if (CurrentFrame > 8) CurrentFrame -= 8;
					p.s.setTextureRect(IntRect(49 * int(CurrentFrame), 112, 49, 112));
				}
				if (Keyboard::isKeyPressed(Keyboard::Up))sound.play(); {
				}
				if (p.life == false){
					RenderWindow window(sf::VideoMode(1204, 768), "GAME1");
					menu(window);
				}
				}
			

			setPlayerCoordinateForView(coordinatePlayerX, coordinatePlayerY);

			p.update(time);
			for (it = entities.begin(); it != entities.end();)
			{
				Entity *b = *it;
				b->update(time);
				if (b->life == false) { it = entities.erase(it); delete b; }
				else it++;
			}
			for (it = entities.begin(); it != entities.end(); it++)
			{
				if ((*it)->getRect().intersects(p.getRect()))
				{
					if ((*it)->name == "EasyEnemy") {

						if ((p.dy > 0) && (p.onGround == false)) { (*it)->dx = 0; p.dy = -0.2; (*it)->health = 0; }
						else {
							p.health -= 5;	
						}
					}
				}
			}

			easyEnemy.update(time);
			for (it = entities.begin(); it != entities.end(); it++) { (*it) ->update(time); }
			window.setView(view);
			window.clear();


			for (int i = 0; i < height; i++)
				for (int j = 0; j < width; j++)
				{
					if (TileMap[i][j] == ' ') play_map.setTextureRect(IntRect(50 * 0, 0, 50, 50));
					if (TileMap[i][j] == 't') play_map.setTextureRect(IntRect(50 * 1, 0, 50, 50));
					if (TileMap[i][j] == 'o') play_map.setTextureRect(IntRect(50 * 4, 0, 50, 50));
					if (TileMap[i][j] == 's') play_map.setTextureRect(IntRect(50 * 2, 0, 50, 50));
					if (TileMap[i][j] == 'a') play_map.setTextureRect(IntRect(50 * 6, 0, 50, 50));
					if (TileMap[i][j] == 'd') play_map.setTextureRect(IntRect(50 * 7, 0, 50, 50));
					if (TileMap[i][j] == 'l') play_map.setTextureRect(IntRect(50 * 8, 0, 50, 50));
					if (TileMap[i][j] == 'q') play_map.setTextureRect(IntRect(50 * 5, 0, 50, 50));

					play_map.setPosition(j * 50, i * 50);


					window.draw(play_map);
				}
			std::ostringstream playerHealthString, gameTimeString, playerScoreString;
			playerHealthString << p.health; gameTimeString << gameTime;
			playerScoreString << p.playerScore;
			text.setString("Здоровье:" + playerHealthString.str() + "\nВремя игры:" + gameTimeString.str() + "   Собрано шестерёнок:" + playerScoreString.str());
			text.setPosition(view.getCenter().x - 165, view.getCenter().y - 200);
			window.draw(text);
			window.draw(easyEnemy.sprite);
			window.draw(p.s);
			window.display();
		

		}
		return 0;

	}
}

