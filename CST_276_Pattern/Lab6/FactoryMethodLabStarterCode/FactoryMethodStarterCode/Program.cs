using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Logger;
using System.Configuration;

namespace FactoryMethodStarterCode
{
    class Program
    {
        private static ILoggerFactory LoadFactory(string factoryName)
        {
            string factoryTypeAsString = ConfigurationManager.AppSettings[factoryName];
            Type factoryType = Type.GetType(factoryTypeAsString);
            return (ILoggerFactory)Activator.CreateInstance(factoryType);
        }

            static void Main(string[] args)
        {
            ILoggerFactory factory = LoadFactory("ConsoleFactory");
            ILogger logger1 = factory.CreateLogger();


            ILoggerFactory factory2 = LoadFactory("FileFactory");

            logger1.Log("Log message");

            ILogger logger2 = factory.CreateLogger(LogLevel.ERROR);
            logger2.Log(LogLevel.WARN, "Should not see this");
            logger2.Log(LogLevel.ERROR, "Error Message");
            logger2.Log(LogLevel.FATAL, "Fatal Message");

            ILogger flogger1 = factory2.CreateLogger();
            flogger1.Log("Log message");

            ILogger flogger2 = factory2.CreateLogger(LogLevel.ERROR);
            flogger2.Log(LogLevel.WARN, "Should not see this");
            flogger2.Log(LogLevel.ERROR, "Error Message");
            flogger2.Log(LogLevel.FATAL, "Fatal Message");
        }
    }
}
