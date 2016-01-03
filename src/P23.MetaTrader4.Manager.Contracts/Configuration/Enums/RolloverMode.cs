namespace P23.MetaTrader4.Manager.Contracts.Configuration.Enums
{
    /// <summary>
    /// Rollover mode
    /// </summary>
    public enum RolloverMode
    {
        /// <summary>
        /// Normal
        /// </summary>
        Normal,
        /// <summary>
        /// Reopen by close price
        /// </summary>
        ReopenByClosePrice,
        /// <summary>
        /// Reopen by bid
        /// </summary>
        ReopenByBid
    }
}