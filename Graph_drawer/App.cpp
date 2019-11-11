#include "Drawer.h"
#include "Json_Parser.h"

int main()
{


	Drawer drawer = Drawer(800, 600, "Drawer");
	//drawer.graphToShapes(Json_Parser::createGraph("small_graph.json"));
	drawer.graphToShapes(Json_Parser::createGraph("big_graph.json"));
	drawer.drawAll();

	return 0;
}