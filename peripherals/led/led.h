#include "../../hardware.h"

typedef struct sLed tLed;

void ledInit(void);
void ledSetColor(unsigned long);
void ledSetGamma(unsigned short);
void ledSet(unsigned long, unsigned short);

void ledModulate(void);
void ledTransfer(void);

struct sLed
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	
	unsigned short gamma;
};

// Red colors
#define INDIANRED				0xCD5C5C
#define LIGHTCORAL				0xF08080
#define SALMON					0xFA8072
#define DARKSALMON				0xE9967A
#define LIGHTSALMON				0xFFA07A
#define CRIMSON					0xDC143C
#define RED						0xFF0000
#define FIREBRICK				0xB22222
#define DARKRED					0x8B0000

// Pink colors
#define PINK					0xFFC0CB
#define LIGHTPINK				0xFFB6C1
#define HOTPINK					0xFF69B4
#define DEEPPINK				0xFF1493
#define MEDIUMVIOLETRED			0xC71585
#define PALEVIOLETRED			0xDB7093

// Orange colors
#define LIGHTSALMON				0xFFA07A
#define CORAL					0xFF7F50
#define TOMATO					0xFF6347
#define ORANGERED				0xFF4500
#define DARKORANGE				0xFF8C00
#define ORANGE					0xFFA500

// Yellow colors
#define GOLD					0xFFD700
#define YELLOW					0xFFFF00
#define LIGHTYELLOW				0xFFFFE0
#define LEMONCHIFFON			0xFFFACD
#define LIGHTGOLDENRODYELLOW	0xFAFAD2
#define PAPAYAWHIP				0xFFEFD5
#define MOCCASIN				0xFFE4B5
#define PEACHPUFF				0xFFDAB9
#define PALEGOLDENROD			0xEEE8AA
#define KHAKI					0xF0E68C
#define DARKKHAKI				0xBDB76B

// Purple colors
#define LAVENDER				0xE6E6FA
#define THISTLE					0xD8BFD8
#define PLUM					0xDDA0DD
#define VIOLET					0xEE82EE
#define ORCHID					0xDA70D6
#define FUCHSIA					0xFF00FF
#define MAGENTA					0xFF00FF
#define MEDIUMORCHID			0xBA55D3
#define MEDIUMPURPLE			0x9370DB
#define AMETHYST				0x9966CC
#define BLUEVIOLET				0x8A2BE2
#define DARKVIOLET				0x9400D3
#define DARKORCHID				0x9932CC
#define DARKMAGENTA				0x8B008B
#define PURPLE					0x800080
#define INDIGO					0x4B0082
#define SLATEBLUE				0x6A5ACD
#define DARKSLATEBLUE			0x483D8B
#define MEDIUMSLATEBLUE			0x7B68EE

// Green colors
#define GREENYELLOW				0xADFF2F
#define CHARTREUSE				0x7FFF00
#define LAWNGREEN				0x7CFC00
#define LIME					0x00FF00
#define LIMEGREEN				0x32CD32
#define PALEGREEN				0x98FB98
#define LIGHTGREEN				0x90EE90
#define MEDIUMSPRINGGREEN		0x00FA9A
#define SPRINGGREEN				0x00FF7F
#define MEDIUMSEAGREEN			0x3CB371
#define SEAGREEN				0x2E8B57
#define FORESTGREEN				0x228B22
#define GREEN					0x008000
#define DARKGREEN				0x006400
#define YELLOWGREEN				0x9ACD32
#define OLIVEDRAB				0x6B8E23
#define OLIVE					0x808000
#define DARKOLIVEGREEN			0x556B2F
#define MEDIUMAQUAMARINE		0x66CDAA
#define DARKSEAGREEN			0x8FBC8F
#define LIGHTSEAGREEN			0x20B2AA
#define DARKCYAN				0x008B8B
#define TEAL					0x008080

// Blue/Cyan colors
#define AQUA					0x00FFFF
#define CYAN					0x00FFFF
#define LIGHTCYAN				0xE0FFFF
#define PALETURQUOISE			0xAFEEEE
#define AQUAMARINE				0x7FFFD4
#define TURQUOISE				0x40E0D0
#define MEDIUMTURQUOISE			0x48D1CC
#define DARKTURQUOISE			0x00CED1
#define CADETBLUE				0x5F9EA0
#define STEELBLUE				0x4682B4
#define LIGHTSTEELBLUE			0xB0C4DE
#define POWDERBLUE				0xB0E0E6
#define LIGHTBLUE				0xADD8E6
#define SKYBLUE					0x87CEEB
#define LIGHTSKYBLUE			0x87CEFA
#define DEEPSKYBLUE				0x00BFFF
#define DODGERBLUE				0x1E90FF
#define CORNFLOWERBLUE			0x6495ED
#define MEDIUMSLATEBLUE			0x7B68EE
#define ROYALBLUE				0x4169E1
#define BLUE					0x0000FF
#define MEDIUMBLUE				0x0000CD
#define DARKBLUE				0x00008B
#define NAVY					0x000080
#define MIDNIGHTBLUE			0x191970

// Brown colors
#define CORNSILK				0xFFF8DC
#define BLANCHEDALMOND			0xFFEBCD
#define BISQUE					0xFFE4C4
#define NAVAJOWHITE				0xFFDEAD
#define WHEAT					0xF5DEB3
#define BURLYWOOD				0xDEB887
#define TAN						0xD2B48C
#define ROSYBROWN				0xBC8F8F
#define SANDYBROWN				0xF4A460
#define GOLDENROD				0xDAA520
#define DARKGOLDENROD			0xB8860B
#define PERU					0xCD853F
#define CHOCOLATE				0xD2691E
#define SADDLEBROWN				0x8B4513
#define SIENNA					0xA0522D
#define BROWN					0xA52A2A
#define MAROON					0x800000

// White colors
#define WHITE					0xFFFFFF
#define SNOW					0xFFFAFA
#define HONEYDEW				0xF0FFF0
#define MINTCREAM				0xF5FFFA
#define AZURE					0xF0FFFF
#define ALICEBLUE				0xF0F8FF
#define GHOSTWHITE				0xF8F8FF
#define WHITESMOKE				0xF5F5F5
#define SEASHELL				0xFFF5EE
#define BEIGE					0xF5F5DC
#define OLDLACE					0xFDF5E6
#define FLORALWHITE				0xFFFAF0
#define IVORY					0xFFFFF0
#define ANTIQUEWHITE			0xFAEBD7
#define LINEN					0xFAF0E6
#define LAVENDERBLUSH			0xFFF0F5
#define MISTYROSE				0xFFE4E1

// Grey colors
#define GAINSBORO				0xDCDCDC
#define LIGHTGREY				0xD3D3D3
#define SILVER					0xC0C0C0
#define DARKGRAY				0xA9A9A9
#define GRAY					0x808080
#define DIMGRAY					0x696969
#define LIGHTSLATEGRAY			0x778899
#define SLATEGRAY				0x708090
#define DARKSLATEGRAY			0x2F4F4F
#define BLACK					0x000000
