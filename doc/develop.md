#### Parse Design

include/BtParse.h

```C++
#pragma once

#include <iostream>
class AbsParse {
public:
    virtual get
}
```

It's difficult to return different objects of key words. How I split it into two areas which defined by changing.

**Just Write the simple version.**

Just Using the Primitive Method to parse the bittorrent file.

```C++
class ParseBittorrentFileT {
   public:
    std::map<std::string,std::string> getDiction(const std::string&);
    const std::string getString(const std::string&);
}
```





