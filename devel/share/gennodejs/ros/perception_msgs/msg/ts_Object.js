// Auto-generated. Do not edit!

// (in-package perception_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let ts_3DPose = require('./ts_3DPose.js');
let ts_Geometry = require('./ts_Geometry.js');

//-----------------------------------------------------------

class ts_Object {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.object_id = null;
      this.rel_pose = null;
      this.geometry_state = null;
      this.geometry = null;
    }
    else {
      if (initObj.hasOwnProperty('object_id')) {
        this.object_id = initObj.object_id
      }
      else {
        this.object_id = 0;
      }
      if (initObj.hasOwnProperty('rel_pose')) {
        this.rel_pose = initObj.rel_pose
      }
      else {
        this.rel_pose = new ts_3DPose();
      }
      if (initObj.hasOwnProperty('geometry_state')) {
        this.geometry_state = initObj.geometry_state
      }
      else {
        this.geometry_state = false;
      }
      if (initObj.hasOwnProperty('geometry')) {
        this.geometry = initObj.geometry
      }
      else {
        this.geometry = new ts_Geometry();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ts_Object
    // Serialize message field [object_id]
    bufferOffset = _serializer.int32(obj.object_id, buffer, bufferOffset);
    // Serialize message field [rel_pose]
    bufferOffset = ts_3DPose.serialize(obj.rel_pose, buffer, bufferOffset);
    // Serialize message field [geometry_state]
    bufferOffset = _serializer.bool(obj.geometry_state, buffer, bufferOffset);
    // Serialize message field [geometry]
    bufferOffset = ts_Geometry.serialize(obj.geometry, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ts_Object
    let len;
    let data = new ts_Object(null);
    // Deserialize message field [object_id]
    data.object_id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [rel_pose]
    data.rel_pose = ts_3DPose.deserialize(buffer, bufferOffset);
    // Deserialize message field [geometry_state]
    data.geometry_state = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [geometry]
    data.geometry = ts_Geometry.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 77;
  }

  static datatype() {
    // Returns string type for a message object
    return 'perception_msgs/ts_Object';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2fab78d59d066c44e1549d3ee0b45ece';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    int32 object_id
    
    ts_3DPose rel_pose
    
    bool geometry_state
    ts_Geometry geometry
    
    ================================================================================
    MSG: perception_msgs/ts_3DPose
    float64 x
    float64 y
    float64 z
    float64 phi
    float64 theta
    float64 psi
    
    ================================================================================
    MSG: perception_msgs/ts_Geometry
    float64 length
    float64 width
    float64 height
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ts_Object(null);
    if (msg.object_id !== undefined) {
      resolved.object_id = msg.object_id;
    }
    else {
      resolved.object_id = 0
    }

    if (msg.rel_pose !== undefined) {
      resolved.rel_pose = ts_3DPose.Resolve(msg.rel_pose)
    }
    else {
      resolved.rel_pose = new ts_3DPose()
    }

    if (msg.geometry_state !== undefined) {
      resolved.geometry_state = msg.geometry_state;
    }
    else {
      resolved.geometry_state = false
    }

    if (msg.geometry !== undefined) {
      resolved.geometry = ts_Geometry.Resolve(msg.geometry)
    }
    else {
      resolved.geometry = new ts_Geometry()
    }

    return resolved;
    }
};

module.exports = ts_Object;
