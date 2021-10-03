// Auto-generated. Do not edit!

// (in-package location_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class RTK {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.gpstime = null;
      this.longitude = null;
      this.latitude = null;
      this.height = null;
      this.heading = null;
      this.pitch = null;
      this.roll = null;
      this.velocity = null;
      this.AccelX = null;
      this.AccelY = null;
      this.AccelZ = null;
      this.status = null;
    }
    else {
      if (initObj.hasOwnProperty('gpstime')) {
        this.gpstime = initObj.gpstime
      }
      else {
        this.gpstime = 0.0;
      }
      if (initObj.hasOwnProperty('longitude')) {
        this.longitude = initObj.longitude
      }
      else {
        this.longitude = 0.0;
      }
      if (initObj.hasOwnProperty('latitude')) {
        this.latitude = initObj.latitude
      }
      else {
        this.latitude = 0.0;
      }
      if (initObj.hasOwnProperty('height')) {
        this.height = initObj.height
      }
      else {
        this.height = 0.0;
      }
      if (initObj.hasOwnProperty('heading')) {
        this.heading = initObj.heading
      }
      else {
        this.heading = 0.0;
      }
      if (initObj.hasOwnProperty('pitch')) {
        this.pitch = initObj.pitch
      }
      else {
        this.pitch = 0.0;
      }
      if (initObj.hasOwnProperty('roll')) {
        this.roll = initObj.roll
      }
      else {
        this.roll = 0.0;
      }
      if (initObj.hasOwnProperty('velocity')) {
        this.velocity = initObj.velocity
      }
      else {
        this.velocity = 0.0;
      }
      if (initObj.hasOwnProperty('AccelX')) {
        this.AccelX = initObj.AccelX
      }
      else {
        this.AccelX = 0.0;
      }
      if (initObj.hasOwnProperty('AccelY')) {
        this.AccelY = initObj.AccelY
      }
      else {
        this.AccelY = 0.0;
      }
      if (initObj.hasOwnProperty('AccelZ')) {
        this.AccelZ = initObj.AccelZ
      }
      else {
        this.AccelZ = 0.0;
      }
      if (initObj.hasOwnProperty('status')) {
        this.status = initObj.status
      }
      else {
        this.status = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RTK
    // Serialize message field [gpstime]
    bufferOffset = _serializer.float64(obj.gpstime, buffer, bufferOffset);
    // Serialize message field [longitude]
    bufferOffset = _serializer.float64(obj.longitude, buffer, bufferOffset);
    // Serialize message field [latitude]
    bufferOffset = _serializer.float64(obj.latitude, buffer, bufferOffset);
    // Serialize message field [height]
    bufferOffset = _serializer.float64(obj.height, buffer, bufferOffset);
    // Serialize message field [heading]
    bufferOffset = _serializer.float64(obj.heading, buffer, bufferOffset);
    // Serialize message field [pitch]
    bufferOffset = _serializer.float64(obj.pitch, buffer, bufferOffset);
    // Serialize message field [roll]
    bufferOffset = _serializer.float64(obj.roll, buffer, bufferOffset);
    // Serialize message field [velocity]
    bufferOffset = _serializer.float64(obj.velocity, buffer, bufferOffset);
    // Serialize message field [AccelX]
    bufferOffset = _serializer.float64(obj.AccelX, buffer, bufferOffset);
    // Serialize message field [AccelY]
    bufferOffset = _serializer.float64(obj.AccelY, buffer, bufferOffset);
    // Serialize message field [AccelZ]
    bufferOffset = _serializer.float64(obj.AccelZ, buffer, bufferOffset);
    // Serialize message field [status]
    bufferOffset = _serializer.int32(obj.status, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RTK
    let len;
    let data = new RTK(null);
    // Deserialize message field [gpstime]
    data.gpstime = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [longitude]
    data.longitude = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [latitude]
    data.latitude = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [height]
    data.height = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [heading]
    data.heading = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [pitch]
    data.pitch = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [roll]
    data.roll = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [velocity]
    data.velocity = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [AccelX]
    data.AccelX = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [AccelY]
    data.AccelY = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [AccelZ]
    data.AccelZ = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [status]
    data.status = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 92;
  }

  static datatype() {
    // Returns string type for a message object
    return 'location_msgs/RTK';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6ebf4ab1d131fdca29632da4008b09ac';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 gpstime
    
    float64 longitude
    float64 latitude
    float64 height
    
    float64 heading
    float64 pitch
    float64 roll
    
    float64 velocity
    
    float64 AccelX
    float64 AccelY
    float64 AccelZ
    
    int32 status
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RTK(null);
    if (msg.gpstime !== undefined) {
      resolved.gpstime = msg.gpstime;
    }
    else {
      resolved.gpstime = 0.0
    }

    if (msg.longitude !== undefined) {
      resolved.longitude = msg.longitude;
    }
    else {
      resolved.longitude = 0.0
    }

    if (msg.latitude !== undefined) {
      resolved.latitude = msg.latitude;
    }
    else {
      resolved.latitude = 0.0
    }

    if (msg.height !== undefined) {
      resolved.height = msg.height;
    }
    else {
      resolved.height = 0.0
    }

    if (msg.heading !== undefined) {
      resolved.heading = msg.heading;
    }
    else {
      resolved.heading = 0.0
    }

    if (msg.pitch !== undefined) {
      resolved.pitch = msg.pitch;
    }
    else {
      resolved.pitch = 0.0
    }

    if (msg.roll !== undefined) {
      resolved.roll = msg.roll;
    }
    else {
      resolved.roll = 0.0
    }

    if (msg.velocity !== undefined) {
      resolved.velocity = msg.velocity;
    }
    else {
      resolved.velocity = 0.0
    }

    if (msg.AccelX !== undefined) {
      resolved.AccelX = msg.AccelX;
    }
    else {
      resolved.AccelX = 0.0
    }

    if (msg.AccelY !== undefined) {
      resolved.AccelY = msg.AccelY;
    }
    else {
      resolved.AccelY = 0.0
    }

    if (msg.AccelZ !== undefined) {
      resolved.AccelZ = msg.AccelZ;
    }
    else {
      resolved.AccelZ = 0.0
    }

    if (msg.status !== undefined) {
      resolved.status = msg.status;
    }
    else {
      resolved.status = 0
    }

    return resolved;
    }
};

module.exports = RTK;
