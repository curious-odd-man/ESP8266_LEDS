#ifndef LEDS_SOLIDCOLORPROGRAM_H_
#define LEDS_SOLIDCOLORPROGRAM_H_

#include "ImageProgram.h"
#include "../util/Leds.h"

class SolidColorProgram: public ImageProgram {
private:
	CRGB color;
	bool isSet;
public:
	SolidColorProgram(const CRGB &color);
	SolidColorProgram() :
			SolidColorProgram(randomColor()) {

	}
	virtual void loop() override;
	virtual ~SolidColorProgram();

};

#endif /* LEDS_SOLIDCOLORPROGRAM_H_ */
