namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Trade command type
    /// </summary>
    public enum TradeCommand
    {
        /// <summary>
        /// Buy
        /// </summary>
        Buy = 0,
        /// <summary>
        /// Sell
        /// </summary>
        Sell,
        /// <summary>
        /// Buy limit
        /// </summary>
        BuyLimit,
        /// <summary>
        /// Sell limit
        /// </summary>
        SellLimit,
        /// <summary>
        /// Buy stop
        /// </summary>
        BuyStop,
        /// <summary>
        /// Sell stop
        /// </summary>
        SellStop,
        /// <summary>
        /// Balance
        /// </summary>
        Balance,
        /// <summary>
        /// Credit
        /// </summary>
        Credit
    }
}