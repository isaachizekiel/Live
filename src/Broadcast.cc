/* Broadcast.cc */

#include <string>



class Broadcast {
  std::string title;
  std::string category;
  std::string description;
  std::string tags;
  long startTime, endTime;
  enum privacy {PUBLIC, PRIVATE};
  enum lifecycle {CREATED, READY, PREVIEW, LIVE, COMPLETED}; 
};
