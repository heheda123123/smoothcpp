// goal
// basic function
// log level: debug info error
// default output to console, can turn off
// can set output to file,support rotate and max setting
// 
// Usage
/*
    Logger log;
    log.set_level(Logger::L_DEBUG);
    log.to_console(false);
    log.to_file("xx.txt");
    log.info("hello");  // [2023-12-20 16:26:11] [LEVEL] info


    class Logger{
    public:
        enum LogLevel {};
        set_level
        to_console
        info
        debug
        error

    private:
        LogLevel m_log_level = L_INFO;
        bool m_to_console = true;
        std::string m_log_file;
    };

*/