# Uncellon's Toolbox Logger

![UToolbox Logo](logo.png)

- [Description](#description)
- [Prerequisites](#prerequisites)
- [Example](#example)
- [License](#license)

## Description

Logging library for C++ with the following features:

1. You can create your own log handler class, thereby overriding the destination of the log file, etc.
2. You can create your own log layout class, thereby changing the log message format

Fuck knows why I did it, but it seems to work.

## Prerequisites

- C++17 or higher
- CMake >= 3.16

## Example

Two logger creation with different location but with same format and terminal output.

```cpp
#include <ut/logger/logger.h>
#include <ut/logger/defaultmessagelayout.h>
#include <ut/logger/filerotateloggerhandler.h>
#include <ut/logger/terminalloggerhandler.h>

using UT::Logger;

int main(int argc, char* argv[]) {
    // Logger handler with file rotation
    auto commonFRLoggerHandler = std::shared_ptr<UT::FileRotateLoggerHandler>(new UT::FileRotateLoggerHandler());
    commonFRLoggerHandler->setLogPath("log/common.log");
    commonFRLoggerHandler->setMaxLogBytes(100);
    commonFRLoggerHandler->setMaxLogs(3);

    auto customFRLoggerHandler = std::shared_ptr<UT::FileRotateLoggerHandler>(new UT::FileRotateLoggerHandler());
    customFRLoggerHandler->setLogPath("log/custom.log");
    customFRLoggerHandler->setMaxLogBytes(100);
    customFRLoggerHandler->setMaxLogs(3);

    // Terminal logger handler
    auto terminalLoggerHandler = std::shared_ptr<UT::TerminalLoggerHandler>(new UT::TerminalLoggerHandler());

    auto messageLayout = std::shared_ptr<UT::DefaultMessageLayout>(new UT::DefaultMessageLayout);

    // Register logger
    Logger::create("common", messageLayout, { commonFRLoggerHandler, terminalLoggerHandler });
    Logger::create("custom", messageLayout, { customFRLoggerHandler, terminalLoggerHandler });

    Logger::write("common", "INFO", "Hello, World!");
    Logger::write("custom", "ERR", "My error message");

    return 0;
}
```

## License
<img align="right" src="https://www.gnu.org/graphics/lgplv3-with-text-154x68.png">

The library is licensed under [GNU Lesser General Public License 3.0](https://www.gnu.org/licenses/lgpl-3.0.txt):

Copyright © 2023 Dmitry Plastinin

UT Logger is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as pubblished by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

UT Logger is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more details