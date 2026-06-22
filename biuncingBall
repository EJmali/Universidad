#include <iostream>
#include <thread>
/***************************************
Bouncing Ball
dev: stecnoem
email: erickliendo@stecnoem.pro
****************************************/
using namespace std;
struct Screen {
	int
		width = 30,
		height = 15;
	char
		wall = '#';
	string
		ttl = "Pelota rebotando, estilo dvd";
};
struct Ball {
	int
		x, y,
		dirx = 1, diry = 1;
	char
		body = 'O';
};
Screen screen;
Ball ball;

void drawScreen();
void clearScreen();

int main(int argc, char *argv[]){
	while(true){
		cout << screen.ttl << endl;
		drawScreen();
		cout <<
			"direccion x:" << ball.dirx<<endl;
		cout <<
			"direccion y:" << ball.diry<<endl;
		cout << "Pisicion :" <<
			ball.x << ", " << ball.y << endl; 	this_thread::sleep_for(chrono::milliseconds(10));
		ball.x = ball.x + ball.dirx;
		ball.y = ball.y + ball.diry;
		if ( ball.x >= screen.width-3 )
			ball.dirx = -1;
		if ( ball.x <= 0 )
			ball.dirx = 1;
		if ( ball.y >= screen.height-3 )
			ball.diry = -1;
		if ( ball.y <= 0 ) ball.diry=1;
		clearScreen();
	}
return 0;
}
void drawScreen(){
	for(int i=0; i < screen.width; i++){
		cout << screen.wall;
	} cout << endl;
	for(int y=0; y < screen.height -2; y++){
		cout << screen.wall;
		for(int x=0; x < screen.width-2; x++){
			if( x == ball.x and y == ball.y )
				cout << ball.body;
			else cout << ' ';
		}cout << screen.wall << endl;
	}
	for(int i=0; i < screen.width; i++){
		cout << screen.wall;
	} cout << endl;
}

void clearScreen() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
