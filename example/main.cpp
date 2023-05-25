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