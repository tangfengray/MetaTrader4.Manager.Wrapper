using System;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents backup configuration
    /// </summary>
    public class Backup
    {
        /// <summary>
        /// Path to backup
        /// </summary>
        public string FullBackupPath { get; set; }

        /// <summary>
        /// Full backup's period-BACKUP_1HOUR, BACKUP_4HOURS, BACKUP_1DAY
        /// </summary>
        public int FullBackupPeriod { get; set; }

        /// <summary>
        /// Full backup's store time-BU_STORE_1MONTH, BU_STORE_3MONTHS, BU_STORE_6MONTHS,BU_STORE_1YEAR
        /// </summary>
        public int FullBackupStore { get; set; }

        /// <summary>
        /// Full backup's last execution time
        /// </summary>
        public UInt32 FullBackupLastTime { get; set; }

        /// <summary>
        /// Full backup timeshift in minutes
        /// </summary>
        public short FullBackupShift { get; set; }

        /// <summary>
        /// Path to external processing directory
        /// </summary>
        public string ExternalPath { get; set; }

        /// <summary>
        /// Period of archive backup-ARC_BACKUP_5MIN, ARC_BACKUP_15MIN, ARC_BACKUP_30MIN, ARC_BACKUP_1HOUR
        /// </summary>
        public int ArchivePeriod { get; set; }

        /// <summary>
        /// Archive backup's store time-ARC_STORE_1WEEK, ARC_STORE_2WEEKS, ARC_STORE_1MONTH, ARC_STORE_3MONTH, ARC_STORE_6MONTH
        /// </summary>
        public int ArchiveStore { get; set; }

        /// <summary>
        /// Archive backup's last execution time
        /// </summary>
        public UInt32 ArchiveLastTime { get; set; }

        /// <summary>
        /// Comma separated list of exported securities
        /// </summary>
        public string ExportSecurities { get; set; }

        /// <summary>
        /// Path to export script
        /// </summary>
        public string ExportPath { get; set; }

        /// <summary>
        /// Export period-enumeration EXPORT_1MIN, EXPORT_5MIN, EXPORT_15MIN, EXPORT_30MIN,EXPORT_1HOUR
        /// </summary>
        public int ExportPeriod { get; set; }

        /// <summary>
        /// Export's last execution time
        /// </summary>
        public UInt32 ExportLastTime { get; set; }

        /// <summary>
        /// Server role { WATCH_STAND_ALONE, WATCH_MASTER, WATCH_SLAVE }
        /// </summary>
        public int WatchRole { get; set; }

        /// <summary>
        /// Slave server password
        /// </summary>
        public string WatchPassword { get; set; }

        /// <summary>
        /// Opposite server IP address and port
        /// </summary>
        public string WatchOpposite { get; set; }

        /// <summary>
        /// Watch dog ip
        /// </summary>
        public int WatchIp { get; set; }

        /// <summary>
        /// Shift of archive backup time in minutes
        /// </summary>
        public char ArchiveShift { get; set; }

        /// <summary>
        /// Watch dog state
        /// </summary>
        public char WatchState { get; set; }

        /// <summary>
        /// Watch dog failover mode
        /// </summary>
        public char WatchFailover { get; set; }

        /// <summary>
        /// Watch dog timeout
        /// </summary>
        public int WatchTimeout { get; set; }

        /// <summary>
        /// Watch dog login
        /// </summary>
        public int WatchLogin { get; set; }

        /// <summary>
        /// Watch dog timestamp
        /// </summary>
        public UInt32 WatchTimestamp { get; set; }
    }
}
