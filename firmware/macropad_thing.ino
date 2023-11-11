#include <FastLED.h>
#include <array>
#include <unordered_map>

// Row and Column pin definitions
#define NUM_KEYS 24
#define ROW1 10
#define ROW2 4
#define ROW3 3
#define ROW4 2
#define ROW5 1
#define COL1 8
#define COL2 7
#define COL3 6
#define COL4 5
#define COL5 0

CRGB all_the_colors[] = {
  CRGB::AliceBlue,
  CRGB::Amethyst,
  CRGB::AntiqueWhite,
  CRGB::Aqua,
  CRGB::Aquamarine,
  CRGB::Azure,
  CRGB::Beige,
  CRGB::Bisque,
  CRGB::Black,
  CRGB::BlanchedAlmond,
  CRGB::Blue,
  CRGB::BlueViolet,
  CRGB::Brown,
  CRGB::BurlyWood,
  CRGB::CadetBlue,
  CRGB::Chartreuse,
  CRGB::Chocolate,
  CRGB::Coral,
  CRGB::CornflowerBlue,
  CRGB::Cornsilk,
  CRGB::Crimson,
  CRGB::Cyan,
  CRGB::DarkBlue,
  CRGB::DarkCyan,
  CRGB::DarkGoldenrod,
  CRGB::DarkGray,
  CRGB::DarkGrey,
  CRGB::DarkGreen,
  CRGB::DarkKhaki,
  CRGB::DarkMagenta,
  CRGB::DarkOliveGreen,
  CRGB::DarkOrange,
  CRGB::DarkOrchid,
  CRGB::DarkRed,
  CRGB::DarkSalmon,
  CRGB::DarkSeaGreen,
  CRGB::DarkSlateBlue,
  CRGB::DarkSlateGray,
  CRGB::DarkSlateGrey,
  CRGB::DarkTurquoise,
  CRGB::DarkViolet,
  CRGB::DeepPink,
  CRGB::DeepSkyBlue,
  CRGB::DimGray,
  CRGB::DimGrey,
  CRGB::DodgerBlue,
  CRGB::FireBrick,
  CRGB::FloralWhite,
  CRGB::ForestGreen,
  CRGB::Fuchsia,
  CRGB::Gainsboro,
  CRGB::GhostWhite,
  CRGB::Gold,
  CRGB::Goldenrod,
  CRGB::Gray,
  CRGB::Grey,
  CRGB::Green,
  CRGB::GreenYellow,
  CRGB::Honeydew,
  CRGB::HotPink,
  CRGB::IndianRed,
  CRGB::Indigo,
  CRGB::Ivory,
  CRGB::Khaki,
  CRGB::Lavender,
  CRGB::LavenderBlush,
  CRGB::LawnGreen,
  CRGB::LemonChiffon,
  CRGB::LightBlue,
  CRGB::LightCoral,
  CRGB::LightCyan,
  CRGB::LightGoldenrodYellow,
  CRGB::LightGreen,
  CRGB::LightGrey,
  CRGB::LightPink,
  CRGB::LightSalmon,
  CRGB::LightSeaGreen,
  CRGB::LightSkyBlue,
  CRGB::LightSlateGray,
  CRGB::LightSlateGrey,
  CRGB::LightSteelBlue,
  CRGB::LightYellow,
  CRGB::Lime,
  CRGB::LimeGreen,
  CRGB::Linen,
  CRGB::Magenta,
  CRGB::Maroon,
  CRGB::MediumAquamarine,
  CRGB::MediumBlue,
  CRGB::MediumOrchid,
  CRGB::MediumPurple,
  CRGB::MediumSeaGreen,
  CRGB::MediumSlateBlue,
  CRGB::MediumSpringGreen,
  CRGB::MediumTurquoise,
  CRGB::MediumVioletRed,
  CRGB::MidnightBlue,
  CRGB::MintCream,
  CRGB::MistyRose,
  CRGB::Moccasin,
  CRGB::NavajoWhite,
  CRGB::Navy,
  CRGB::OldLace,
  CRGB::Olive,
  CRGB::OliveDrab,
  CRGB::Orange,
  CRGB::OrangeRed,
  CRGB::Orchid,
  CRGB::PaleGoldenrod,
  CRGB::PaleGreen,
  CRGB::PaleTurquoise,
  CRGB::PaleVioletRed,
  CRGB::PapayaWhip,
  CRGB::PeachPuff,
  CRGB::Peru,
  CRGB::Pink,
  CRGB::Plaid,
  CRGB::Plum,
  CRGB::PowderBlue,
  CRGB::Purple,
  CRGB::Red,
  CRGB::RosyBrown,
  CRGB::RoyalBlue,
  CRGB::SaddleBrown,
  CRGB::Salmon,
  CRGB::SandyBrown,
  CRGB::SeaGreen,
  CRGB::Seashell,
  CRGB::Sienna,
  CRGB::Silver,
  CRGB::SkyBlue,
  CRGB::SlateBlue,
  CRGB::SlateGray,
  CRGB::SlateGrey,
  CRGB::Snow,
  CRGB::SpringGreen,
  CRGB::SteelBlue,
  CRGB::Tan,
  CRGB::Teal,
  CRGB::Thistle,
  CRGB::Tomato,
  CRGB::Turquoise,
  CRGB::Violet,
  CRGB::Wheat,
  CRGB::White,
  CRGB::WhiteSmoke,
  CRGB::Yellow,
  CRGB::YellowGreen
};

const std::array< int, 5 > columns =   { COL1, COL2, COL3, COL4, COL5 };
const std::array< int, 5 > rows = { ROW1, ROW2, ROW3, ROW4, ROW5 };
// const std::array< int, NUM_KEYS > row_order_thing = { ROW1, ROW2,       ROW4, ROW5,
//                                                       ROW5, ROW4, ROW3, ROW2, ROW1,
//                                                       ROW1, ROW2, ROW3, ROW4, ROW5,
//                                                       ROW5, ROW4, ROW3, ROW2, ROW1,
//                                                       ROW1, ROW2, ROW3, ROW4, ROW5 };

int key_idxs[NUM_KEYS] = {0,8,9,18,19,
                          1,7,10,17,20,
                            6,11,16,21,
                          2,5,12,15,22,
                          3,4,13,14,23
                          };

CRGB key_color[NUM_KEYS] = {
  CRGB::Azure,
  CRGB::BlueViolet,
  CRGB::Chocolate,
  CRGB::Crimson,
  CRGB::DeepPink,
  CRGB::Fuchsia,
  CRGB::Goldenrod,
  CRGB::Green,
  CRGB::Indigo,
  CRGB::Lavender,
  CRGB::LimeGreen,
  CRGB::Magenta,
  CRGB::MintCream,
  CRGB::Orange,
  CRGB::PapayaWhip,
  CRGB::Purple,
  CRGB::SteelBlue,
  CRGB::Teal,
  CRGB::Tomato,
  CRGB::Turquoise,
  CRGB::Violet,
  CRGB::Yellow,
  CRGB::Red,
  CRGB::Blue
};

bool key_status[NUM_KEYS];

// key keys[ NUM_KEYS ];

// LED stuff
#define NUM_LEDS NUM_KEYS
#define LED_DIN 9
CRGB macpad_leds[ NUM_LEDS ];

void setup()
{
  FastLED.addLeds< SK6812, LED_DIN, RGB > ( macpad_leds, NUM_LEDS );
  for( const int & row : rows ) { pinMode( row, INPUT ); }
  for( const int & column : columns ) { pinMode( column, OUTPUT ); }
  for( auto & key : key_status ) { key = false; }
}

int cnt{0};

void loop()
{
  // if( scanKeys() ) { updateLeds(); }
  
  // checkThatOneKey();

  // dumbScanKeys();

  // stupidSingleReadLight( ROW1, COL1, 0  );
  // stupidSingleReadLight( ROW1, COL2, 1  );
  // stupidSingleReadLight( ROW1, COL4, 2  );
  // stupidSingleReadLight( ROW1, COL5, 3  );
  // stupidSingleReadLight( ROW2, COL5, 4  );
  // stupidSingleReadLight( ROW2, COL4, 5  );
  // stupidSingleReadLight( ROW2, COL3, 6  );
  // stupidSingleReadLight( ROW2, COL2, 7  );
  // stupidSingleReadLight( ROW2, COL1, 8  );
  // stupidSingleReadLight( ROW3, COL1, 9  );
  // stupidSingleReadLight( ROW3, COL2, 10 );
  // stupidSingleReadLight( ROW3, COL3, 11 );
  // stupidSingleReadLight( ROW3, COL4, 12 );
  // stupidSingleReadLight( ROW3, COL5, 13 );
  // stupidSingleReadLight( ROW4, COL5, 14 );
  // stupidSingleReadLight( ROW4, COL4, 15 );
  // stupidSingleReadLight( ROW4, COL3, 16 );
  // stupidSingleReadLight( ROW4, COL2, 17 );
  // stupidSingleReadLight( ROW4, COL1, 18 );
  // stupidSingleReadLight( ROW5, COL1, 19 );
  // stupidSingleReadLight( ROW5, COL2, 20 );
  // stupidSingleReadLight( ROW5, COL3, 21 );
  // stupidSingleReadLight( ROW5, COL4, 22 );
  // stupidSingleReadLight( ROW5, COL5, 23 );

  // CRGB color_of_the_day = all_the_colors[ (cnt++)%(166-19) ];
  // for( auto & led : macpad_leds ) { led = color_of_the_day; }
  for( auto & led : macpad_leds ) { led = CRGB::Grey; }
  FastLED.setBrightness( 20 );
  FastLED.show();
  // delay(1);
  while(1) { }
}

int key_idx{0};

bool scanKeys()
{
  bool state_change{ false };
  for( const auto & column : columns )
  {
    digitalWrite( column, HIGH );

    for( const auto & row : rows )
    {
      int sensor_reading = digitalRead( row );
      bool reading = (sensor_reading > 800);
      if( key_status[ key_idx ] != reading )
      {
        key_status[ key_idx ] = reading;
        registerKey( key_idx );
        state_change = true;
      }
    }
    digitalWrite( column, LOW );
  }

  key_idx++;
  return state_change;
}

bool registerKey( int key_idx )
{
  bool curr_key_status = key_status[key_idx];
  macpad_leds[key_idx] = curr_key_status ? CRGB::White : CRGB::Black;
  // Also HID stuff?
  return true;
}

bool checkThatOneKey()
{
  digitalWrite(COL3, HIGH);
  int analog_check{ 0 };
  bool check{ false };
  analog_check = analogRead(ROW3);
  if( analog_check > 800 ) { check = true; }
  digitalWrite(COL3, LOW);
  if(check) { macpad_leds[0] = CRGB::Blue; }
  else { macpad_leds[0] = CRGB::Black; }
  FastLED.show();
  return true;
}

bool updateLeds()
{
  FastLED.show();
  return true;
}


bool dumbScanKeys()
{
  dumbColumnRead(COL5);
  delay( 0.1 );
  dumbColumnRead(COL4);
  delay( 0.1 );
  dumbColumnRead(COL3);
  delay( 0.1 );
  dumbColumnRead(COL2);
  delay( 0.1 );
  dumbColumnRead(COL1);
  delay( 0.1 );
}

bool dumbColumnRead( int column )
{
  int col_offset[5] = {0,5,9,14,19};
  int offset_sel = (COL1 == column) ? col_offset[0] :
                   (COL2 == column) ? col_offset[1] :
                   (COL3 == column) ? col_offset[2] :
                   (COL4 == column) ? col_offset[3] :
                   col_offset[4];

  digitalWrite(column, HIGH);
  dumbRowRead( ROW1, key_idxs[offset_sel+0] );
  dumbRowRead( ROW2, key_idxs[offset_sel+1] );
  dumbRowRead( ROW3, key_idxs[offset_sel+2] );
  dumbRowRead( ROW4, key_idxs[offset_sel+3] );
  dumbRowRead( ROW5, key_idxs[offset_sel+4] );
  digitalWrite(column, LOW);
}

bool dumbRowRead( int row, int led )
{
  int temp_read_row{0};
  temp_read_row = analogRead(row);
  if( temp_read_row > 800 ) { macpad_leds[led] = CRGB::Green; }
  else { macpad_leds[led] = CRGB::Black; }
  FastLED.show();
  return true;
}

bool stupidSingleReadLight( int row, int col, int led )
{
  int read_val{ 0 };
  digitalWrite( col, HIGH );
  read_val = analogRead( row );
  digitalWrite( col, LOW );

  if( read_val > 900 ) { macpad_leds[ led ] = key_color[ led ]; }
  else { macpad_leds[ led ] = CRGB::Black; }

  return true;
}