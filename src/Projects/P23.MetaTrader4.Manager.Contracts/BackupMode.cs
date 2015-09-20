namespace P23.MetaTrader4.Manager.Contracts
{
    public enum BackupMode
    {
        All,             // all backup
        Periodical,      // periodical backups
        Startup,         // backups on startup
        Delete           // backups on delete
    };
}