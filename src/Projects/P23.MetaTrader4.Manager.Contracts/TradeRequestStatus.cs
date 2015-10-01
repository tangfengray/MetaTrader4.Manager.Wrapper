namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Trade request status
    /// </summary>
    public enum TradeRequestStatus : sbyte
    {
        /// <summary>
        /// Empty
        /// </summary>
        Empty,
        /// <summary>
        /// Request
        /// </summary>
        Request,
        /// <summary>
        /// Locked
        /// </summary>
        Locked,
        /// <summary>
        /// Answered
        /// </summary>
        Answered,
        /// <summary>
        /// Reseted
        /// </summary>
        Reseted,
        /// <summary>
        /// Cancelled
        /// </summary>
        Canceled
    }
}