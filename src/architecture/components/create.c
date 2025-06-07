#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "components.h"
#include "create.h"

Information createInformation(int id, char *name, unsigned int lengthName);
Position createPosition(int id, float x, float y, float oldX, float oldY);
Direction createDirection(int id, float x, float y);
Velocity createVelocity(int id, float x, float y);
Acceleration createAcceleration(int id, float x, float y);
Size createSize(int id, float width, float height);
Color createColor(int id, int red, int green, int blue, int alpha);
Collider createCollider(int id, int isItColliding, int *direction, int isStatic);
Layer createLayer(int id, int number);

Information createInformation(int id, char *name, unsigned int lengthName){
	Information information;
	information.id = id;
	information.name = name;
	information.lengthName = lengthName;
	return information;
}
Position createPosition(int id, float x, float y, float oldX, float oldY){
	Position position;
	position.id = id;
	position.current2.x = x;
	position.current2.y = y;
	position.old2.x = oldX;
	position.old2.y = oldY;
	return position;
}
Direction createDirection(int id, float x, float y){
	Direction direction;
	direction.id = id;
	direction.vector2.x = x;
	direction.vector2.y = y;
	return direction;
}
Velocity createVelocity(int id, float x, float y){
	Velocity velocity;
	velocity.id = id;
	velocity.vector2.x = x;
	velocity.vector2.y = y;
	return velocity;
}
Acceleration createAcceleration(int id, float x, float y){
	Acceleration acceleration;
	acceleration.id = id;
	acceleration.vector2.x = x;
	acceleration.vector2.y = y;
	return acceleration;
}
Size createSize(int id, float width, float height){
	Size size;
	size.id = id;
	size.vector2.x = width;
	size.vector2.y = height;
	return size;
}
Color createColor(int id, int red, int green, int blue, int alpha){
	Color color;
	color.id = id;
	color.vector4.x = red;
	color.vector4.y = green; 
	color.vector4.z = blue;
	color.vector4.w = alpha;
	return color;
}
Collider createCollider(int id, int isItColliding, int *direction, int isStatic){
	Collider collision;

	collision.id = id;

	collision.isItColliding = isItColliding;

	if(direction == NULL){
		for (size_t i = 0; i < 4; i++){
			collision.collisionDirection[i] = false;
		}
	}else{
		for (size_t i = 0; i < TOTALCOORDENATE; i++){
			collision.collisionDirection[i] = *(direction + i);
		}
	}

	collision.isStatic = isStatic;

	return collision;
}
Layer createLayer(int id, int number){
	Layer layer;
	layer.id = id;
	layer.layer = number;
	return layer;
}

Player createPlayer(int id){
	Player player;
	player.id = id;
	return player;
}