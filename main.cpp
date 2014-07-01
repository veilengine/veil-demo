#include <Veil/Veil.h>
#include <Veil/Systems/Lambda.h>
#include <Veil/SDL/Renderer.h>
#include <Veil/SDL/Window.h>
#include <Veil/SDL/Input.h>
#include <Veil/SDL/Sound.h>

using namespace Veil;

SDL::Window* createWindow(const char* title, int x, int y, int width, int height, bool fullscreen) {
	SDL::Window* window = new SDL::Window();
	window->setTitle(title);
	window->setFullscreen(fullscreen);
	window->setSize(width, height);
	window->setPosition(x, y);
	return window;
}

Entity* createPlayer() {
	Entity* player = new Entity();
	player->add(new Texture("assets/sprite.png"));
	player->add(new Position(100, 200));
	player->add(new Size(105, 153));
	player->add(new Scale(2.0));
	return player;
}

Entity* createText(const char* msg) {
	Entity* text = new Entity();
	text->add(new Typeface("assets/Amble-Bold.ttf", 60));
	text->add(new Text(msg));
	text->add(new Position(100, 100));
	text->add(new Rotation(0.01));
	return text;
}

int main (int argc, char* argv[]) {
	// Create world and add player to it
	World* world = new World();

	// Initialize renderer
	SDL::Renderer::instance()->init();

	// Create and attach window system
	world->add(createWindow("test", 100, 100, 640, 480, false));

	// Add input handling
	world->add(new SDL::Input());

	// Play some music
	SDL::Sound* sound = SDL::Sound::instance();
	sound->playMusic("assets/song.mp3");

	// Create person entity
	Entity* player = createPlayer();
	world->add(player);

	// Add some text
	world->add(createText("hello, world!"));

	// Lambda updater
	double accumulated = 0;
	world->add(new Lambda([&](World* world, double dt) {
		accumulated += dt;

		// Reset every second
		if (accumulated > 1) {
			accumulated -= 1;
		}

		// Update position
		Position* p1 = player->as<Position>();
		player->remove<Position>();
		int x = p1->x + int(accumulated * 40) % 2;
		if (x > 500) {
			x = 0;
		}
		Position* p2 = new Position(x, p1->y);
		player->add(p2);

		// Update offset
		int offset = int(accumulated * 4) % 4;
		if (player->has<Offset>()) {
			player->remove<Offset>();
		}
		Offset* o2 = new Offset(offset * 105, 0);
		player->add(o2);
	}));

	world->start();

	return 0;
}
