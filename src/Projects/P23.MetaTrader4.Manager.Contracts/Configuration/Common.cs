using System;
using System.Collections.Generic;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class Common
    {
        public string Owner { get; set; }              // servers owner (include version & build)
        public string Name { get; set; }               // server name
        public UInt32 Address { get; set; }            // IP address assigned to the server
        public int Port { get; set; }                  // port
        public UInt32 Timeout { get; set; }            // sockets timeout
        public int TypeOfDemo { get; set; }            // demo-accounts type (DEMO_DISABLED, DEMO_PROLONG, DEMO_FIXED)
        public int TimeOfDemo { get; set; }            // demo-account living time
        public int DayLightCorrection { get; set; }    // allow daylight correction

        public int TimeZone { get; set; }              // time zone 0-GMT{get;set;}-1=GMT-1{get;set;}1=GMT+1{get;set;}
        public string TimeSync { get; set; }           // time synchronization server address
        //---
        public int MinClient { get; set; }             // minimal authorized client version
        public int MinApi { get; set; }                // minimal authorized client version
        public UInt32 FeederTimeout { get; set; }      // data feed switch timeout
        public int KeepEmails { get; set; }            // internal mail keep period
        public int EndHour { get; set; }               // end of day time-hour
        public int EndMinute { get; set; }             // end of day time-minute
        //---
        public int OptimizationTime { get; set; }      // optimization start time (minutes)
        public int OptimizationLasttime { get; set; }  // optimization last time
        public int OptimizationCounter { get; set; }   // internal variable   
        //---
        public int AntiFlood { get; set; }             // enable antiflood control
        public int FloodControl { get; set; }          // max. antiflood connections
        //---
        public int LiveUpdateMode { get; set; }        // LiveUpdate mode (LIVE_UPDATE_NO,LIVE_UPDATE_ALL,LIVE_UPDATE_NO_SERVER)
        //---
        public int LastOrder { get; set; }             // last order's ticket     (read only)
        public int LastLogin { get; set; }             // last account's number   (read only)
        public int LostLogin { get; set; }             // lost commission's login (read only)
        //---
        public int RolloversMode { get; set; }         // rollover mode (ROLLOVER_NORMAL,ROLLOVER_REOPEN_BY_CLOSE_PRICE,ROLLOVER_REOPEN_BY_BID)
        //---
        public string PathDatabase { get; set; }       // path to databases
        public string PathHistory { get; set; }        // path to history bases
        public string PathLog { get; set; }            // path to log
        //--- overnigths
        public UInt32 OverNightLastDay { get; set; }   // day of last overnight
        public UInt32 OverNightLastTime { get; set; }  // time of last overnight
        public UInt32 OverNightPrevTime { get; set; }  // time of время next to last overnight
        //--- month reports
        public UInt32 OverMonthLastMonth { get; set; } // month of last report
        //--- performance base
        public string Adapters { get; set; }           // network adapters list (read-only)
        public List<UInt32> BindAdresses { get; set; } // array of avaible IP addresses
        public short ServerVersion { get; set; }       // server version
        public short ServerBuild { get; set; }         // server build
        public List<UInt32> WebAdresses { get; set; }  // web services access list (comma separated IP addresses)
        public int StatementMode { get; set; }         // statement generation time (STATEMENT_END_DAY,STATEMENT_START_DAY)
        public int MonthlyStateMode { get; set; }      // monthly statement generation day (MONTHLY_STATEMENT_END_MONTH,MONTHLY_STATEMENT_START_MONTH)
        public int KeepTicks { get; set; }             // ticks keep period
        public int StatementWeekend { get; set; }      // generate statements at weekends
    }
}
