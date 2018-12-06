#include "MAVINT.h"
#include <Arduino.h>
#include <mavlink.h>

MAVINT::MAVINT(){
  
}

void MAVINT::MAV_sendHB(){
  mavlink_msg_heartbeat_pack(1,0,&msg,MAV_TYPE_OCTOROTOR,MAV_AUTOPILOT_INVALID,MAV_MODE_PREFLIGHT,0,MAV_STATE_STANDBY);
  len = mavlink_msg_to_send_buffer(buf, &msg);
}

void MAVINT::reqStream(){
  mavlink_msg_request_data_stream_pack(2,200,&msg,1,0,MAV_DATA_STREAM_ALL,0x02,1);
  len = mavlink_msg_to_send_buffer(buf, &msg);
}

void MAVINT::getMAVpres(uint8_t c){
  if(mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)){
    switch(msg.msgid) {
      case MAVLINK_MSG_ID_RAW_PRESSURE:
        {
          MAVdat = mavlink_msg_raw_pressure_get_press_abs(&msg);
        }
        break;
     default:
        break;
    }
  }
}

void MAVINT::getMAVlat(uint8_t c){
  if(mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)){
    switch(msg.msgid) {
      case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
        {
          MAVdat = mavlink_msg_global_position_int_get_lat(&msg);
        }
        break;
     default:
        break;
    }
  }
}

void MAVINT::getMAVlon(uint8_t c){
  if(mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)){
    switch(msg.msgid) {
      case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
        {
          MAVdat = mavlink_msg_global_position_int_get_lon(&msg);
        }
        break;
     default:
        break;
    }
  }
}

void MAVINT::getMAVgpsalt(uint8_t c){
  if(mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)){
    switch(msg.msgid) {
      case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
        {
          MAVdat = mavlink_msg_global_position_int_get_alt(&msg);
        }
        break;
     default:
        break;
    }
  }
}

void MAVINT::getMAVgpsvz(uint8_t c){
  if(mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)){
    switch(msg.msgid) {
      case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
        {
          MAVdat = mavlink_msg_global_position_int_get_vz(&msg);
        }
        break;
     default:
        break;
    }
  }
}










