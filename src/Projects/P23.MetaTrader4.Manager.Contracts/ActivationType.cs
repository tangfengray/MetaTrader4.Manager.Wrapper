namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Activation type
    /// </summary>
    public enum ActivationType
    {
        /// <summary>
        /// None
        /// </summary>
        None = 0,
        /// <summary>
        /// Stop Loss
        /// </summary>
        SL,
        /// <summary>
        /// Take Profit
        /// </summary>
        TP,
        /// <summary>
        /// Pending order activation
        /// </summary>
        Pending,
        /// <summary>
        /// Stopout
        /// </summary>
        Stopout,
        /// <summary>
        /// SL rollback
        /// </summary>
        SLRollback = -SL,
        /// <summary>
        /// TP rollback
        /// </summary>
        TPRollback = -TP,
        /// <summary>
        /// Pending rollback
        /// </summary>
        PendingRollback = -Pending,
        /// <summary>
        /// Stopout rollback
        /// </summary>
        StopoutRollback = -Stopout
    }
}