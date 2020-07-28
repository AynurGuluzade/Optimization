#include <iostream>
#include <typeinfo>
#include "shape.h"
#include "optimization/optimization.h"

shape* testexample(){

	double width = 25.0;//for floor, ceiling, front and back wall
	double length = 20.0;//floor, ceiling, left anf rigth wall
	double height = 10.0;//only for walls
	auto door = new shape("door", "door");
	door->setTexture("resources/door/door.jpg");
	auto window = new shape("window", "window");
	window->setTexture("resources/window/window.jpg");
	auto fwall = new shape("fwall", "wall");
	fwall->setLength(height);
	fwall->setWidth(width);
	fwall->setTexture("resources/wall/wall_1.jpg");
	fwall->children.push_back(door);
	auto bwall = new shape("bwall", "wall");
	bwall->setLength(height);
	bwall->setWidth(length);
	bwall->setTexture("resources/wall/wall_1.jpg");
	bwall->children.push_back(window);
	auto lwall = new shape("lwall", "wall");
	lwall->setLength(height);
	lwall->setWidth(length);
	lwall->setTexture("resources/wall/wall_1.jpg");
	auto rwall = new shape("rwall", "wall");
	rwall->setLength(height);
	rwall->setWidth(width);
	rwall->setTexture("resources/wall/wall_1.jpg");
	auto ceiling = new shape("ceiling", "ceiling");
	ceiling->setLength(length);
	ceiling->setWidth(width);
	ceiling->setTexture("resources/ceiling.png");
	auto floor = new shape("floor", "floor");
	floor->setLength(length);
	floor->setWidth(width);
	floor->setTexture("resources/floor/floor.jpg");
	auto sofa = new shape("sofa", "furniture");
	sofa->setPosition(-2.0f, -3.6f, -7.0f);
	sofa->setScale(6.0f, 3.0f, 4.0f);
	sofa->setAngle(0.0);
	sofa->setModelName("resources/sofa/sofa.obj");
	auto tv = new shape("tv", "furniture");
	tv->setPosition(-2.0f, -3.0f, 7.0f);
	tv->setScale(4.0f, 3.0f, 2.0f);
	tv->setAngle(180.0);
	tv->setModelName("resources/tv/tv.obj");
	auto table = new shape("table", "furniture");
	table->setPosition(-11.0f, -3.0f, 0.0f);
	table->setScale(5.0f, 3.0f, 2.0f);
	table->setAngle(270.0);
	table->setModelName("resources/table/table.obj");
	auto chair = new shape("chair", "furniture");
	chair->setPosition(-9.0f, -3.0f, 0.0f);
	chair->setScale(2.0f, 3.0f, 2.0f);
	chair->setAngle(270.0);
	chair->setPair(table->getName());
	chair->setModelName("resources/chair/chair.obj");
	table->setPair(chair->getName());
	auto rack = new shape("rack", "furniture");
	rack->setPosition(11.0f, -2.0f, -6.0f);
	rack->setScale(4.0f, 6.0f, 2.0f);
	rack->setAngle(270.0);
	rack->setModelName("resources/rack/rack.obj");
	auto box1 = new shape("box1", "furniture");
	box1->setPosition(5.0f, -4.0f, 4.0f);
	box1->setScale(2.0f, 2.0f, 2.0f);
	box1->setAngle(0);
	box1->setModelName("resources/cube_1/cube.obj");
	auto box2 = new shape("box2", "furniture");
	box2->setPosition(2.0f, -4.0f, -3.0f);
	box2->setScale(3.0f, 2.0f, 4.0f);
	box2->setAngle(0);
	box2->setModelName("resources/cube_2/cube.obj");
	auto box3 = new shape("box3", "furniture");
	box3->setPosition(-4.0f, -4.0f, 0.0f);
	box3->setScale(1.0f, 2.0f, 1.0f);
	box3->setAngle(0);
	box3->setModelName("resources/cube_3/cube.obj");

	floor->children.push_back(sofa);
	floor->children.push_back(tv);
	floor->children.push_back(table);
	floor->children.push_back(chair);
	floor->children.push_back(rack);
	//floor->children.push_back(box1);
	//floor->children.push_back(box2);
	//floor->children.push_back(box3);

	auto room = new shape("room", "room");
	room->children.push_back(fwall);
	room->children.push_back(bwall);
	room->children.push_back(lwall);
	room->children.push_back(rwall);
	room->children.push_back(ceiling);
	room->children.push_back(floor);

	return room;
}

int main()
{

	auto room = new shape("room", "room");
	room = testexample();

	optimization::optimize optimizer(room);

}