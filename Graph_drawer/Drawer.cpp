#include "Drawer.h"


Drawer::Drawer(int w_sizeX_, int w_sizeY_ , std::string w_name_, sf::Color w_background_color_, sf::Color w_shapes_color_)
{
	font.loadFromFile("font.ttf");
	w_sizeX = w_sizeX_;
	w_sizeY = w_sizeY_;
	w_name = w_name_;
	w_background_color = w_background_color_;
	w_shapes_color = w_shapes_color_;
}

Drawer::Drawer(int w_sizeX_, int w_sizeY_, std::string w_name_)
{
	font.loadFromFile("font.ttf");
	w_sizeX = w_sizeX_;
	w_sizeY = w_sizeY_;
	w_name = w_name_;
}

Drawer::~Drawer()
{
}

bool Drawer::graphToShapes(Graph graph)
{
	if (graph.getPoints().empty()) return false;
	int x_ratio = w_sizeX / std::gcd(w_sizeX, w_sizeY);
	int y_ratio = w_sizeY / std::gcd(w_sizeX, w_sizeY);
	int scale = 1;
	if (graph.getPoints().size() > x_ratio * y_ratio)
	{
		scale = (int)std::ceil(graph.getPoints().size() / x_ratio * y_ratio);
	}
	int rad = std::min(w_sizeX /(4 * x_ratio * scale), w_sizeY / (4 * y_ratio * scale));
	int x_mark = 0;
	int y_mark = 0;
	lines.setPrimitiveType(sf::Lines);
	lines.resize(graph.getLines().size());
	for (auto point : graph.getPoints())
	{
		sf::Text text(std::to_string(point.first), font, 18);
		text.setFillColor(sf::Color::Blue);
		sf::CircleShape shape;
		shape.setRadius(float(rad));
		shape.setFillColor(w_shapes_color);
		shape.setPosition((x_mark % x_ratio) * 4 * rad + rad, (y_mark % y_ratio) * 4 * rad + rad);
		shapes_to_draw.emplace_back(shape);
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		text.setPosition(shape.getPosition().x + rad , shape.getPosition().y + rad);
		text_to_draw.emplace_back(text);
		x_mark++;
		y_mark++;
	}
	return true;
}

void Drawer::drawAll()
{
	sf::RenderWindow window(sf::VideoMode(w_sizeX, w_sizeY), w_name.c_str());
	sf::View camera(sf::FloatRect(0.f, 0.f, w_sizeX, w_sizeY));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear(w_background_color);
		for (auto shape : shapes_to_draw)
		{
			window.draw(shape);
		}
		for (auto text : text_to_draw)
		{
			window.draw(text);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			camera.zoom(1.005);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			camera.zoom(0.995);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			camera.move(-3, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			camera.move(3, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			camera.move(0, -3);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			camera.move(0, 3);
		}

		window.setView(camera);
		window.display();
	}
}
