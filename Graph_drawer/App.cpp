#include "Drawer.h"
#include "Json_Parser.h"

int main()
{
	Json_Parser parser = Json_Parser();
	auto small_graph = parser.createGraph("big_graph.json");
	Drawer drawer = Drawer(800, 600, "Drawer");
	drawer.graphToShapes(small_graph);
	drawer.drawAll();
	return 0;
}