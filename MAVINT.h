#ifndef _mavint
#define _mavint
#endif

#include <Arduino.h>
#include <mavlink.h>

class MAVINT
{
public:
  //Constructor
  MAVINT(); 

  //Functions
  void MAV_sendHB();
  void getMAVpres(uint8_t c);
  void getMAVlon(uint8_t c);
  void getMAVlat(uint8_t c);
  void getMAVgpsalt(uint8_t c);
  void getMAVgpsvz(uint8_t c);
  void reqStream();
  
  //Variables
  uint16_t len;
  uint8_t buf[MAVLINK_MAX_PACKET_LEN];
  mavlink_message_t msg;
  mavlink_status_t status;
  int32_t MAVdat;
  
private:
  //Functions
  
  
};
