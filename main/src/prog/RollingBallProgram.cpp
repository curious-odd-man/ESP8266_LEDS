#include "RollingBallProgram.h"

#include "../util/Leds.h"
#include "../util/TimerMs.h"
#include "../util/common.h"

static CRGB color = CRGB::White;
static constexpr float WIDTH = Leds::width();
static constexpr float HEIGHT = Leds::height();
static TimerMs drawTimer(20);

#define MOV_VEC randomFloat(0.05, 0.1)

RollingBallProgram::RollingBallProgram(uint8_t size) :
		position(ceil(WIDTH / 2), ceil(HEIGHT / 2)), movement(MOV_VEC, MOV_VEC), size(
				size) {
	LOGF("Created ball at pos [%f,%f] with vector [%f,%f]\n", position.getX(),
			position.getY(), movement.getX(), movement.getY());
	movement.setY(movement.getX());
}

void RollingBallProgram::loop() {
	if (!drawTimer.isReady()) {
		return;
	}

	position.move(movement);
	if (position.getX() <= 0) {
		position.setX(0);
		movement.invertX();
	}

	if (position.getY() <= 0) {
		position.setY(0);
		movement.invertY();
	}

	if (position.getX() >= WIDTH - size) {
		position.setX(WIDTH - size);
		movement.invertX();
	}

	if (position.getY() >= HEIGHT - size) {
		position.setY(HEIGHT - size);
		movement.invertY();
	}

	Leds::clear();

	for (byte i = 0; i < size; i++) {
		for (byte j = 0; j < size; j++) {
			Leds::drawPixelAA(position.getX() + i, position.getY() + j, color);
		}
	}
}

RollingBallProgram::~RollingBallProgram() {
}

