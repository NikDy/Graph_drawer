#pragma once



class Graph_Point
{
public:
	int idx = 0;
	int post_idx = 0;

	Graph_Point(int idx_, int post_idx_);

	Graph_Point(int idx);

	~Graph_Point();
};

