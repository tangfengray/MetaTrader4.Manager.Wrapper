namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Trade state
    /// </summary>
    public enum TradeState
    {
        /// <summary>
        /// Open normal
        /// </summary>
        OpenNormal,
        /// <summary>
        /// Open remand
        /// </summary>
        OpenRemand,
        /// <summary>
        /// Open restored
        /// </summary>
        OpenRestored,
        /// <summary>
        /// Close normal
        /// </summary>
        ClosedNormal,
        /// <summary>
        /// Closed part
        /// </summary>
        ClosedPart,
        /// <summary>
        /// Closed by
        /// </summary>
        ClosedBy,
        /// <summary>
        /// Deleted
        /// </summary>
        Deleted
    }
}