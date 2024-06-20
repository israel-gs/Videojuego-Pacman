#include <array>
#include <SFML/Graphics.hpp>

#include "Headers/Global.hpp"
#include "Headers/DrawMap.hpp"

void draw_map(const std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &i_map, sf::RenderWindow &i_window)
{
	sf::RectangleShape wall_shape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	sf::RectangleShape door_shape(sf::Vector2f(CELL_SIZE, CELL_SIZE / 4));
	sf::CircleShape pellet_shape(CELL_SIZE / 8);
	sf::CircleShape energizer_shape(CELL_SIZE / 4);

	for (unsigned char a = 0; a < MAP_WIDTH; a++)
	{
		for (unsigned char b = 0; b < MAP_HEIGHT; b++)
		{
			wall_shape.setPosition(static_cast<float>(CELL_SIZE * a), static_cast<float>(CELL_SIZE * b));

			switch (i_map[a][b])
			{
			case Cell::Door:
			{
				door_shape.setFillColor(sf::Color::White);
				door_shape.setPosition(static_cast<float>(CELL_SIZE * a), static_cast<float>(CELL_SIZE * b));
				i_window.draw(door_shape);
				break;
			}
			case Cell::Energizer:
			{
				energizer_shape.setFillColor(sf::Color::White);
				energizer_shape.setPosition(static_cast<float>(CELL_SIZE * a + (CELL_SIZE / 2 - energizer_shape.getRadius())), static_cast<float>(CELL_SIZE * b + (CELL_SIZE / 2 - energizer_shape.getRadius())));
				i_window.draw(energizer_shape);
				break;
			}
			case Cell::Pellet:
			{
				pellet_shape.setFillColor(sf::Color::White);
				pellet_shape.setPosition(static_cast<float>(CELL_SIZE * a + (CELL_SIZE / 2 - pellet_shape.getRadius())), static_cast<float>(CELL_SIZE * b + (CELL_SIZE / 2 - pellet_shape.getRadius())));
				i_window.draw(pellet_shape);
				break;
			}
			case Cell::Wall:
			{
				wall_shape.setFillColor(sf::Color::Blue);
				i_window.draw(wall_shape);
				break;
			}
			}
		}
	}
}