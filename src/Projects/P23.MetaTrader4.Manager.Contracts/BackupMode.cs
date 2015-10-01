namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Backup mode
    /// </summary>
    public enum BackupMode
    {
        /// <summary>
        /// All backup
        /// </summary>
        All,
        /// <summary>
        /// Periodical backups
        /// </summary>
        Periodical,
        /// <summary>
        /// Backups on startup
        /// </summary>
        Startup,
        /// <summary>
        /// Backups on delete
        /// </summary>
        Delete
    };
}