using System;
using System.Collections.Generic;
using P23.MetaTrader4.Manager.Contracts.Configuration.Enums;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents common configuration
    /// </summary>
    public class Common
    {
        /// <summary>
        /// Servers owner (include version and build)
        /// </summary>
        public string Owner { get; set; }

        /// <summary>
        /// Server name
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// IP address assigned to the server
        /// </summary>
        public UInt32 Address { get; set; }

        /// <summary>
        /// Port
        /// </summary>
        public int Port { get; set; }

        /// <summary>
        /// Sockets timeout
        /// </summary>
        public UInt32 Timeout { get; set; }

        /// <summary>
        /// Demo-accounts type (DEMO_DISABLED, DEMO_PROLONG, DEMO_FIXED)
        /// </summary>
        public DemoAccountsType TypeOfDemo { get; set; }

        /// <summary>
        /// Demo-account living time
        /// </summary>
        public int TimeOfDemo { get; set; }

        /// <summary>
        /// Allow daylight correction
        /// </summary>
        public int DayLightCorrection { get; set; }

        /// <summary>
        /// Time zone 0-GMT{get;set;}-1=GMT-1{get;set;}1=GMT+1{get;set;}
        /// </summary>
        public int TimeZone { get; set; }

        /// <summary>
        /// Time synchronization server address
        /// </summary>
        public string TimeSync { get; set; }

        /// <summary>
        /// Minimal authorized client version
        /// </summary>
        public int MinClient { get; set; }

        /// <summary>
        /// Minimal authorized client version
        /// </summary>
        public int MinApi { get; set; }

        /// <summary>
        /// Data feed switch timeout
        /// </summary>
        public UInt32 FeederTimeout { get; set; }

        /// <summary>
        /// Internal mail keep period
        /// </summary>
        public int KeepEmails { get; set; }

        /// <summary>
        /// End of day time-hour
        /// </summary>
        public int EndHour { get; set; }

        /// <summary>
        /// End of day time-minute
        /// </summary>
        public int EndMinute { get; set; }

        /// <summary>
        /// Optimization start time (minutes)
        /// </summary>
        public int OptimizationTime { get; set; }

        /// <summary>
        /// Optimization last time
        /// </summary>
        public int OptimizationLastTime { get; set; }

        /// <summary>
        /// Internal variable   
        /// </summary>
        public int OptimizationCounter { get; set; }

        /// <summary>
        /// Enable antiflood control
        /// </summary>
        public int AntiFlood { get; set; }

        /// <summary>
        /// Max. antiflood connections
        /// </summary>
        public int FloodControl { get; set; }

        /// <summary>
        /// LiveUpdate mode (LIVE_UPDATE_NO,LIVE_UPDATE_ALL,LIVE_UPDATE_NO_SERVER)
        /// </summary>
        public LiveUpdateMode LiveUpdateMode { get; set; }

        /// <summary>
        /// Last order's ticket (read only)
        /// </summary>
        public int LastOrder { get; set; }

        /// <summary>
        /// Last account's number (read only)
        /// </summary>
        public int LastLogin { get; set; }

        /// <summary>
        /// Lost commission's login (read only)
        /// </summary>
        public int LostLogin { get; set; }

        /// <summary>
        /// Rollover mode (ROLLOVER_NORMAL,ROLLOVER_REOPEN_BY_CLOSE_PRICE,ROLLOVER_REOPEN_BY_BID)
        /// </summary>
        public RolloverMode RolloversMode { get; set; }

        /// <summary>
        /// Path to databases
        /// </summary>
        public string PathDatabase { get; set; }

        /// <summary>
        /// Path to history bases
        /// </summary>
        public string PathHistory { get; set; }

        /// <summary>
        /// Path to log
        /// </summary>
        public string PathLog { get; set; }

        /// <summary>
        /// Day of last overnight
        /// </summary>
        public UInt32 OverNightLastDay { get; set; }

        /// <summary>
        /// Time of last overnight
        /// </summary>
        public UInt32 OverNightLastTime { get; set; }

        /// <summary>
        /// Time of next to last overnight
        /// </summary>
        public UInt32 OverNightPrevTime { get; set; }

        /// <summary>
        /// Month of last report
        /// </summary>
        public UInt32 OverMonthLastMonth { get; set; } // 

        /// <summary>
        /// Network adapters list (read-only)
        /// </summary>
        public string Adapters { get; set; }

        /// <summary>
        /// Array of avaible IP addresses
        /// </summary>
        public List<UInt32> BindAdresses { get; set; }

        /// <summary>
        /// Server version
        /// </summary>
        public short ServerVersion { get; set; }

        /// <summary>
        /// Server build
        /// </summary>
        public short ServerBuild { get; set; }

        /// <summary>
        /// Web services access list (comma separated IP addresses)
        /// </summary>
        public List<UInt32> WebAdresses { get; set; }

        /// <summary>
        /// Statement generation time (STATEMENT_END_DAY,STATEMENT_START_DAY)
        /// </summary>
        public StatementMode StatementMode { get; set; }

        /// <summary>
        /// Monthly statement generation day (MONTHLY_STATEMENT_END_MONTH,MONTHLY_STATEMENT_START_MONTH)
        /// </summary>
        public MonthlyStatementMode MonthlyStateMode { get; set; }

        /// <summary>
        /// Ticks keep period
        /// </summary>
        public int KeepTicks { get; set; }

        /// <summary>
        /// Generate statements at weekends
        /// </summary>
        public int StatementWeekend { get; set; }

        /// <summary>
        /// Last activation Datetime
        /// </summary>
        public UInt32 LastActivate { get; set; }

        /// <summary>
        /// Last stop Datetime
        /// </summary>
        public UInt32 StopLast { get; set; }

        /// <summary>
        /// Last stop delay
        /// </summary>
        public int StopDelay { get; set; }

        /// <summary>
        /// Last stop reason
        /// </summary>
        public int StopReason { get; set; }

        /// <summary>
        /// Account allocation URL
        /// </summary>
        public string AccountUrl { get; set; }
    }
}
