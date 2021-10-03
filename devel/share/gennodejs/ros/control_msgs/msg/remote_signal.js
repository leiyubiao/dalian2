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

class remote_signal {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.description = null;
      this.remoteSig = null;
    }
    else {
      if (initObj.hasOwnProperty('description')) {
        this.description = initObj.description
      }
      else {
        this.description = '';
      }
      if (initObj.hasOwnProperty('remoteSig')) {
        this.remoteSig = initObj.remoteSig
      }
      else {
        this.remoteSig = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type remote_signal
    // Serialize message field [description]
    bufferOffset = _serializer.string(obj.description, buffer, bufferOffset);
    // Serialize message field [remoteSig]
    bufferOffset = _serializer.int64(obj.remoteSig, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type remote_signal
    let len;
    let data = new remote_signal(null);
    // Deserialize message field [description]
    data.description = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [remoteSig]
    data.remoteSig = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.description.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'control_msgs/remote_signal';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ef064086b30dd0b129639e1bf28f6fd1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string description
    int64 remoteSig
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new remote_signal(null);
    if (msg.description !== undefined) {
      resolved.description = msg.description;
    }
    else {
      resolved.description = ''
    }

    if (msg.remoteSig !== undefined) {
      resolved.remoteSig = msg.remoteSig;
    }
    else {
      resolved.remoteSig = 0
    }

    return resolved;
    }
};

module.exports = remote_signal;
