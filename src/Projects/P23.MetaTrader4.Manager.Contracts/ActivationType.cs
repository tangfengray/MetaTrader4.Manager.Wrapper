namespace P23.MetaTrader4.Manager.Contracts
{
    public enum ActivationType
    {
        None = 0,
        SL,
        TP,
        Pending,
        Stopout,
        SLRollback = -SL,
        TPRollback = -TP,
        PendingRollback = -Pending,
        StopoutRollback = -Stopout
    }
}