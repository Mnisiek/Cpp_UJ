
#include <iostream>


static int number = 5;

class Log
{
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

private:
    int m_LogLevel = LogLevelInfo;

public:
    void SetLevel(int level)
    {
        m_LogLevel = level;
    }

    void LogError(const char* message)
    {
        if (m_LogLevel >= LogLevelError) {
            std::cout << "[ERROR]: " << message << std::endl;
        }
    }

    void LogWarning(const char* message)
    {
        if (m_LogLevel >= LogLevelWarning) {
            std::cout << "[WARNING]: " << message << std::endl;
        }
    }

    void LogInfo(const char* message)
    {
        if (m_LogLevel >= LogLevelInfo) {
            std::cout << "[INFO]: " << message << std::endl;
        }
    }
};


int main()
{
    Log log1;
    log1.SetLevel(log1.LogLevelWarning);

    log1.LogError("Wiadomość");
    log1.LogInfo("Wiadomość");

    return 0;
}