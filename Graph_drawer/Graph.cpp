#include "Graph.h"


bool Graph::addPoint(int idx_, Graph_Point point_)
{
	return points.emplace(idx_, point_).second;
}

bool Graph::addLine(int idx_, Graph_Line line_)
{
	return lines.emplace(idx_, line_).second;
}

std::map<int, Graph_Point>& Graph::getPoints()
{
	return points;
}

std::map<int, Graph_Line>& Graph::getLines()
{
	return lines;
}

Graph::Graph(std::string name_, int idx_)
{
	name = name_;
	idx = idx_;
}

Graph::~Graph()
{

}
