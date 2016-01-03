namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Trade reason
    /// </summary>
    public enum TradeReason : sbyte
    {
        /// <summary>
        /// Client
        /// </summary>
        Client,
        /// <summary>
        /// Expert
        /// </summary>
        Expert,
        /// <summary>
        /// Dealer
        /// </summary>
        Dealer,
        /// <summary>
        /// Signal
        /// </summary>
        Signal,
        /// <summary>
        /// Gateway
        /// </summary>
        Gateway
    }
}