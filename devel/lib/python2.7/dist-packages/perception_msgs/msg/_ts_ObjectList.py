# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from perception_msgs/ts_ObjectList.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import perception_msgs.msg
import std_msgs.msg

class ts_ObjectList(genpy.Message):
  _md5sum = "ada8e9075049a493d6740fe5140a812a"
  _type = "perception_msgs/ts_ObjectList"
  _has_header = True #flag to mark the presence of a Header object
  _full_text = """Header header
string sensor
ts_Object[] objects
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

================================================================================
MSG: perception_msgs/ts_Object

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
float64 height"""
  __slots__ = ['header','sensor','objects']
  _slot_types = ['std_msgs/Header','string','perception_msgs/ts_Object[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,sensor,objects

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ts_ObjectList, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.sensor is None:
        self.sensor = ''
      if self.objects is None:
        self.objects = []
    else:
      self.header = std_msgs.msg.Header()
      self.sensor = ''
      self.objects = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.sensor
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      length = len(self.objects)
      buff.write(_struct_I.pack(length))
      for val1 in self.objects:
        buff.write(_get_struct_i().pack(val1.object_id))
        _v1 = val1.rel_pose
        _x = _v1
        buff.write(_get_struct_6d().pack(_x.x, _x.y, _x.z, _x.phi, _x.theta, _x.psi))
        buff.write(_get_struct_B().pack(val1.geometry_state))
        _v2 = val1.geometry
        _x = _v2
        buff.write(_get_struct_3d().pack(_x.length, _x.width, _x.height))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.objects is None:
        self.objects = None
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.sensor = str[start:end].decode('utf-8')
      else:
        self.sensor = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.objects = []
      for i in range(0, length):
        val1 = perception_msgs.msg.ts_Object()
        start = end
        end += 4
        (val1.object_id,) = _get_struct_i().unpack(str[start:end])
        _v3 = val1.rel_pose
        _x = _v3
        start = end
        end += 48
        (_x.x, _x.y, _x.z, _x.phi, _x.theta, _x.psi,) = _get_struct_6d().unpack(str[start:end])
        start = end
        end += 1
        (val1.geometry_state,) = _get_struct_B().unpack(str[start:end])
        val1.geometry_state = bool(val1.geometry_state)
        _v4 = val1.geometry
        _x = _v4
        start = end
        end += 24
        (_x.length, _x.width, _x.height,) = _get_struct_3d().unpack(str[start:end])
        self.objects.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.sensor
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      length = len(self.objects)
      buff.write(_struct_I.pack(length))
      for val1 in self.objects:
        buff.write(_get_struct_i().pack(val1.object_id))
        _v5 = val1.rel_pose
        _x = _v5
        buff.write(_get_struct_6d().pack(_x.x, _x.y, _x.z, _x.phi, _x.theta, _x.psi))
        buff.write(_get_struct_B().pack(val1.geometry_state))
        _v6 = val1.geometry
        _x = _v6
        buff.write(_get_struct_3d().pack(_x.length, _x.width, _x.height))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.objects is None:
        self.objects = None
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.sensor = str[start:end].decode('utf-8')
      else:
        self.sensor = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.objects = []
      for i in range(0, length):
        val1 = perception_msgs.msg.ts_Object()
        start = end
        end += 4
        (val1.object_id,) = _get_struct_i().unpack(str[start:end])
        _v7 = val1.rel_pose
        _x = _v7
        start = end
        end += 48
        (_x.x, _x.y, _x.z, _x.phi, _x.theta, _x.psi,) = _get_struct_6d().unpack(str[start:end])
        start = end
        end += 1
        (val1.geometry_state,) = _get_struct_B().unpack(str[start:end])
        val1.geometry_state = bool(val1.geometry_state)
        _v8 = val1.geometry
        _x = _v8
        start = end
        end += 24
        (_x.length, _x.width, _x.height,) = _get_struct_3d().unpack(str[start:end])
        self.objects.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_i = None
def _get_struct_i():
    global _struct_i
    if _struct_i is None:
        _struct_i = struct.Struct("<i")
    return _struct_i
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_B = None
def _get_struct_B():
    global _struct_B
    if _struct_B is None:
        _struct_B = struct.Struct("<B")
    return _struct_B
_struct_6d = None
def _get_struct_6d():
    global _struct_6d
    if _struct_6d is None:
        _struct_6d = struct.Struct("<6d")
    return _struct_6d
_struct_3d = None
def _get_struct_3d():
    global _struct_3d
    if _struct_3d is None:
        _struct_3d = struct.Struct("<3d")
    return _struct_3d
