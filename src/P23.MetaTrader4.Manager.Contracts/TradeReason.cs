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
        Client = 0,
        /// <summary>
        /// Expert
        /// </summary>
        Expert = 1,
        /// <summary>
        /// Dealer
        /// </summary>
        Dealer = 2,
        /// <summary>
        /// Signal
        /// </summary>
        Signal = 3,
        /// <summary>
        /// Gateway
        /// </summary>
        Gateway = 4,
        /// <summary>
        /// Mobile terminal
        /// </summary>
        Mobile = 5,
        /// <summary>
        /// Web terminal
        /// </summary>
        Web = 6,
        /// <summary>
        /// API
        /// </summary>
        API = 7
    }
}