using System;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class Backup
    {
        //---
        public string FullBackupPath { get; set; }      // path to backup
        public int FullBackupPeriod { get; set; }       // full backup's period-BACKUP_1HOUR, BACKUP_4HOURS, BACKUP_1DAY
        public int FullBackupStore { get; set; }        // full backup's store time-BU_STORE_1MONTH, BU_STORE_3MONTHS, BU_STORE_6MONTHS,BU_STORE_1YEAR
        public UInt32 FullBackupLastTime { get; set; }  // full backup's last execution time
        public short FullBackupShift { get; set; }      // full backup timeshift (minutes)
        //---
        public string ExternalPath { get; set; }        // path to external processing directory
        //---
        public int ArchivePeriod { get; set; }          // period of archive backup-ARC_BACKUP_5MIN, ARC_BACKUP_15MIN, ARC_BACKUP_30MIN, ARC_BACKUP_1HOUR
        public int ArchiveStore { get; set; }           // archive backup's store time-ARC_STORE_1WEEK, ARC_STORE_2WEEKS, ARC_STORE_1MONTH, ARC_STORE_3MONTH, ARC_STORE_6MONTH
        public UInt32 ArchiveLastTime { get; set; }     // archive backup's last execution time
        //---
        public string ExportSecurities { get; set; }    // comma separated list of exported securities
        public string ExportPath { get; set; }          // path to export script
        public int ExportPeriod { get; set; }           // export period-enumeration EXPORT_1MIN, EXPORT_5MIN, EXPORT_15MIN, EXPORT_30MIN,EXPORT_1HOUR
        public UInt32 ExportLastTime { get; set; }      // export's last execution time
        //--- watch dog
        public int WatchRole { get; set; }              // server role { WATCH_STAND_ALONE, WATCH_MASTER, WATCH_SLAVE }
        public string WatchPassword { get; set; }       // slave server password
        public string WatchOpposite { get; set; }       // opposite server IP address and port
        public int WatchIp { get; set; }                // watch dog ip
        //--- 
        public char ArchiveShift { get; set; }          // shift of archive backup time (in minutes)
        //---
        public char WatchState { get; set; }            // watch dog state
        public char WatchFailover { get; set; }         // watch dog failover mode
        public int WatchTimeout { get; set; }           // watch dog timeout
        public int WatchLogin { get; set; }             // watch dog login
        public UInt32 WatchTimestamp { get; set; }      // watch dog timestamp
    }
}
