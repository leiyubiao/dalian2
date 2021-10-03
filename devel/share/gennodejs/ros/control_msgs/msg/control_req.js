// Auto-generated. Do not edit!

// (in-package control_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class control_req {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Vel_req = null;
      this.Angle_req = null;
      this.Gear_req = null;
    }
    else {
      if (initObj.hasOwnProperty('Vel_req')) {
        this.Vel_req = initObj.Vel_req
      }
      else {
        this.Vel_req = 0.0;
      }
      if (initObj.hasOwnProperty('Angle_req')) {
        this.Angle_req = initObj.Angle_req
      }
      else {
        this.Angle_req = 0.0;
      }
      if (initObj.hasOwnProperty('Gear_req')) {
        this.Gear_req = initObj.Gear_req
      }
      else {
        this.Gear_req = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type control_req
    // Serialize message field [Vel_req]
    bufferOffset = _serializer.float64(obj.Vel_req, buffer, bufferOffset);
    // Serialize message field [Angle_req]
    bufferOffset = _serializer.float64(obj.Angle_req, buffer, bufferOffset);
    // Serialize message field [Gear_req]
    bufferOffset = _serializer.int32(obj.Gear_req, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type control_req
    let len;
    let data = new control_req(null);
    // Deserialize message field [Vel_req]
    data.Vel_req = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Angle_req]
    data.Angle_req = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Gear_req]
    data.Gear_req = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'control_msgs/control_req';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f755ac002e0891a7af88d03d37522ace';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 Vel_req
    float64 Angle_req
    int32 Gear_req
    # 0x0:P 0x1:R 0x2:N 0x3:D
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new control_req(null);
    if (msg.Vel_req !== undefined) {
      resolved.Vel_req = msg.Vel_req;
    }
    else {
      resolved.Vel_req = 0.0
    }

    if (msg.Angle_req !== undefined) {
      resolved.Angle_req = msg.Angle_req;
    }
    else {
      resolved.Angle_req = 0.0
    }

    if (msg.Gear_req !== undefined) {
      resolved.Gear_req = msg.Gear_req;
    }
    else {
      resolved.Gear_req = 0
    }

    return resolved;
    }
};

module.exports = control_req;
