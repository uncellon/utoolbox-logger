#include <ut/logger/logger.h>
#include <ut/logger/defaultmessagelayout.h>
#include <ut/logger/filerotateloggerhandler.h>
#include <ut/logger/terminalloggerhandler.h>

using UT::Logger;

int main(int argc, char* argv[]) {
    auto fileRotateLoggerHandler = std::shared_ptr<UT::FileRotateLoggerHandler>(new UT::FileRotateLoggerHandler());
    fileRotateLoggerHandler->setLogPath("log/common.log");
    fileRotateLoggerHandler->setMaxLogBytes(1000000);
    fileRotateLoggerHandler->setMaxLogs(3);

    auto terminalLoggerHandler = std::shared_ptr<UT::TerminalLoggerHandler>(new UT::TerminalLoggerHandler());

    Logger::create("common", std::shared_ptr<UT::DefaultMessageLayout>(new UT::DefaultMessageLayout), { fileRotateLoggerHandler, terminalLoggerHandler });

    Logger::write("common", "MY_PREFIX", "My message");

    return 0;

    // // Configure handlers
    // auto fileRotateLoggingHandler = std::shared_ptr<UT::FileRotateLoggerHandler>(new UT::FileRotateLoggerHandler());
    // fileRotateLoggingHandler->setLogPath("log/common.log");
    // fileRotateLoggingHandler->setMaxLogBytes(300);
    // fileRotateLoggingHandler->setMaxLogs(3);

    // auto terminalLoggerHandler = std::shared_ptr<UT::TerminalLoggerHandler>(new UT::TerminalLoggerHandler());

    // // Configure loggers

    // std::shared_ptr<UT::Logger> commonLogger(new UT::Logger());

    // commonLogger->pushHandler(terminalLoggerHandler);
    // commonLogger->pushHandler(fileRotateLoggingHandler);

    // // UT::Logger<UT::DefaultMessageLayout> commonInfoLogger;
    // // UT::Logger<UT::DefaultMessageLayout> commonErrorLogger;
    
    // // commonInfoLogger.pushHandler(terminalLoggerHandler);
    // // commonInfoLogger.pushHandler(fileRotateLoggingHandler);

    // // commonErrorLogger.pushHandler(terminalLoggerHandler);
    // // commonErrorLogger.pushHandler(fileRotateLoggingHandler);

    // // // Write logs
    // // commonInfoLogger.write("INFO", "My info message");
    // // commonErrorLogger.write("ERROR", "My error message");

    // std::shared_ptr<UT::DefaultMessageLayout> ml(new UT::DefaultMessageLayout());
    // commonLogger->setMessageLayout(ml);
    
    // std::any a[] = { "dsa" };
    // commonLogger->write("INFO", "Test");
    // std::string message = "dsa";
    // commonLogger->write("INFO", message);

    // UT::LoggerService::add("common", commonLogger);

    // UT::LoggerService::write("common", "INFO", "Is it work?");

    // // auto log = UT::Logger<UT::BasicMessageLayout>::getInstance("my-log");
    // // log->pushHandler(terminalLoggerHandler);
    // // log->write("CUSTOM", "My error from registered log");

    // // UT::MiniLogger::write("info", "log/mini.log", "My message from MiniLog");

    // return 0;
}