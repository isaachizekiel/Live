/* Stream.cc */
#include <string>

class Stream {
  std::string name;
  std::string description;
  long max_sustained_bitrate;

  enum stream_key {RTMP, HLS};
  std::string stream_url; // rtmp://a.rtmp.youtube.com/live2
  std::string backup_server_url; // rtmp://b.rtmp.youtube.com/live2?backup=1

  enum stream_latency {NORMAL, LOW, ULTRALOW};
  
  bool enable_vdr;
  bool three60_video;
  bool closed_captions;

  bool unlist_live_replay_once_stream_ends;


  // encoder settings 
  // protocol RTMP Flash Streaming
  // video codeec H.264, Main 4.1
  // frame rate 30 FPS
  // key frame frequency 2 seconds
  // audio codec AAC-LC (Audio Required)
  // Audio samplerate 44.1 KHz
  // audio bitrate 128 Kbps sterio

};
