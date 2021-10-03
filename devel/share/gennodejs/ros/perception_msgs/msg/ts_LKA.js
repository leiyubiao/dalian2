// Auto-generated. Do not edit!

// (in-package perception_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ts_LKA {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.lanetype = null;
      this.quality = null;
      this.model = null;
      this.View_range = null;
      this.Position_C0 = null;
      this.Headingangle_C1 = null;
      this.Curvature_C2 = null;
      this.dCurvature_C3 = null;
      this.Lane_width = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('lanetype')) {
        this.lanetype = initObj.lanetype
      }
      else {
        this.lanetype = 0;
      }
      if (initObj.hasOwnProperty('quality')) {
        this.quality = initObj.quality
      }
      else {
        this.quality = 0;
      }
      if (initObj.hasOwnProperty('model')) {
        this.model = initObj.model
      }
      else {
        this.model = 0;
      }
      if (initObj.hasOwnProperty('View_range')) {
        this.View_range = initObj.View_range
      }
      else {
        this.View_range = 0.0;
      }
      if (initObj.hasOwnProperty('Position_C0')) {
        this.Position_C0 = initObj.Position_C0
      }
      else {
        this.Position_C0 = 0.0;
      }
      if (initObj.hasOwnProperty('Headingangle_C1')) {
        this.Headingangle_C1 = initObj.Headingangle_C1
      }
      else {
        this.Headingangle_C1 = 0.0;
      }
      if (initObj.hasOwnProperty('Curvature_C2')) {
        this.Curvature_C2 = initObj.Curvature_C2
      }
      else {
        this.Curvature_C2 = 0.0;
      }
      if (initObj.hasOwnProperty('dCurvature_C3')) {
        this.dCurvature_C3 = initObj.dCurvature_C3
      }
      else {
        this.dCurvature_C3 = 0.0;
      }
      if (initObj.hasOwnProperty('Lane_width')) {
        this.Lane_width = initObj.Lane_width
      }
      else {
        this.Lane_width = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ts_LKA
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [lanetype]
    bufferOffset = _serializer.int64(obj.lanetype, buffer, bufferOffset);
    // Serialize message field [quality]
    bufferOffset = _serializer.int64(obj.quality, buffer, bufferOffset);
    // Serialize message field [model]
    bufferOffset = _serializer.int64(obj.model, buffer, bufferOffset);
    // Serialize message field [View_range]
    bufferOffset = _serializer.float64(obj.View_range, buffer, bufferOffset);
    // Serialize message field [Position_C0]
    bufferOffset = _serializer.float64(obj.Position_C0, buffer, bufferOffset);
    // Serialize message field [Headingangle_C1]
    bufferOffset = _serializer.float64(obj.Headingangle_C1, buffer, bufferOffset);
    // Serialize message field [Curvature_C2]
    bufferOffset = _serializer.float64(obj.Curvature_C2, buffer, bufferOffset);
    // Serialize message field [dCurvature_C3]
    bufferOffset = _serializer.float64(obj.dCurvature_C3, buffer, bufferOffset);
    // Serialize message field [Lane_width]
    bufferOffset = _serializer.float64(obj.Lane_width, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ts_LKA
    let len;
    let data = new ts_LKA(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [lanetype]
    data.lanetype = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [quality]
    data.quality = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [model]
    data.model = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [View_range]
    data.View_range = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Position_C0]
    data.Position_C0 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Headingangle_C1]
    data.Headingangle_C1 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Curvature_C2]
    data.Curvature_C2 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [dCurvature_C3]
    data.dCurvature_C3 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Lane_width]
    data.Lane_width = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 72;
  }

  static datatype() {
    // Returns string type for a message object
    return 'perception_msgs/ts_LKA';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '735c1f26da9c3fb23d10971553941226';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    int64 lanetype  #0-dashed 1-solid 2-undecided 3-road edge 4-double lane mark 5-Botts' dots 6-invalid
    int64 quality   #0,1-low quality 2,3-high quality
    int64 model     # 1-linear, 2-parabolic, 3-3rd degree model
    float64 View_range
    float64 Position_C0
    float64 Headingangle_C1
    float64 Curvature_C2
    float64 dCurvature_C3
    float64 Lane_width
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ts_LKA(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.lanetype !== undefined) {
      resolved.lanetype = msg.lanetype;
    }
    else {
      resolved.lanetype = 0
    }

    if (msg.quality !== undefined) {
      resolved.quality = msg.quality;
    }
    else {
      resolved.quality = 0
    }

    if (msg.model !== undefined) {
      resolved.model = msg.model;
    }
    else {
      resolved.model = 0
    }

    if (msg.View_range !== undefined) {
      resolved.View_range = msg.View_range;
    }
    else {
      resolved.View_range = 0.0
    }

    if (msg.Position_C0 !== undefined) {
      resolved.Position_C0 = msg.Position_C0;
    }
    else {
      resolved.Position_C0 = 0.0
    }

    if (msg.Headingangle_C1 !== undefined) {
      resolved.Headingangle_C1 = msg.Headingangle_C1;
    }
    else {
      resolved.Headingangle_C1 = 0.0
    }

    if (msg.Curvature_C2 !== undefined) {
      resolved.Curvature_C2 = msg.Curvature_C2;
    }
    else {
      resolved.Curvature_C2 = 0.0
    }

    if (msg.dCurvature_C3 !== undefined) {
      resolved.dCurvature_C3 = msg.dCurvature_C3;
    }
    else {
      resolved.dCurvature_C3 = 0.0
    }

    if (msg.Lane_width !== undefined) {
      resolved.Lane_width = msg.Lane_width;
    }
    else {
      resolved.Lane_width = 0.0
    }

    return resolved;
    }
};

module.exports = ts_LKA;
